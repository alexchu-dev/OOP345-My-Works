/******************************************************************************
//                    OOP345NDD - WS08 @ 22 Mar 2023
//Module:      Database Header
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/
#ifndef SDDS_DATABASE_H
#define SDDS_DATABASE_H
#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <iomanip>
#include <algorithm>
namespace sdds {
   //This line has to comment out :
   //std::shared_ptr<Database> Database::m_instance = nullptr;
   enum class Err_Status
   {
      Err_Success,
      Err_NotFound,
      Err_OutOfMemory,
   };
   template<typename T>
   class Database
   {
      inline static std::shared_ptr<Database> m_instance;
      size_t m_entries{};
      std::string m_keys[20]{};
      T m_values[20]{};
      std::string m_filename{};
      void encryptDecrypt(T& value) {};
      Database(const std::string& filename) : m_filename(filename) {
         std::cout << "[" << this << "] Database(const std::string&)" << std::endl;
         std::ifstream file(filename);
         std::string key{};
         T value{};
         while (file >> key >> value) {
            std::replace(key.begin(), key.end(), '_', ' ');
            encryptDecrypt(value);
            if (m_entries < 20) {
               m_keys[m_entries] = key;
               m_values[m_entries] = value;
               m_entries++;
            }
         }
         file.close();
      };
   public:
      static std::shared_ptr<Database> getInstance(const std::string& filename) {
         return (m_instance ? m_instance : m_instance = std::shared_ptr<Database>(new Database(filename)));
      }

      Err_Status GetValue(const std::string& key, T& value) {
         Err_Status ret = Err_Status::Err_NotFound;
         bool found = false;
         for (size_t i = 0; i < m_entries && !found; ++i) {
            if (key == m_keys[i]) {
               value = m_values[i];
               ret = Err_Status::Err_Success;
               found = true;
            }
         }
         return ret;
      }
      Err_Status SetValue(const std::string& key, const T& value) {
         Err_Status ret = Err_Status::Err_OutOfMemory;
         if (m_entries < 20) {
            m_keys[m_entries] = key;
            m_values[m_entries] = value;
            m_entries++;
            ret = Err_Status::Err_Success;
         }
         return ret;
      }
      ~Database()
      {
         std::cout << "[" << this << "] ~Database()" << std::endl;
         std::string bkp_filename = m_filename + ".bkp.txt";
         std::ofstream out_file(bkp_filename);
         for (size_t i = 0; i < m_entries; ++i) {
            encryptDecrypt(m_values[i]);
            out_file << std::left << std::setw(25) << m_keys[i] << " -> " << m_values[i] << std::endl;
         }
         out_file.close();
      }
   };
   template<>
   inline void Database<std::string>::encryptDecrypt(std::string& value) {
      const char secret[]{ "secret encryption key" };
      for (auto& C : value) {
         for (auto& K : secret) {
            C ^= K;
         }
      }
   }

   template<>
   inline void Database<long long>::encryptDecrypt(long long& value) {
      const char secret[]{ "super secret encryption key" };
      for (size_t i = 0; i < sizeof(value); ++i) {
         for (auto& K : secret) {
            reinterpret_cast<char*>(&value)[i] ^= K;
         }
      }
   }
}
#endif