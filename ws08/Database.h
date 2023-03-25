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
   enum class Err_Status
   {
      Err_Success,
      Err_NotFound,
      Err_OutOfMemory,
   };
   class Database
   {
      static std::shared_ptr<Database> m_instance;
      size_t m_entries{};
      std::string m_keys[20]{};
      std::string m_values[20]{};
      std::string m_filename{};
      Database(const std::string& filename);
   public:
      static std::shared_ptr<Database> getInstance(const std::string& filename);
      Err_Status GetValue(const std::string& key, std::string& value);
      Err_Status SetValue(const std::string& key, const std::string& value);
      ~Database();
   };
}
#endif