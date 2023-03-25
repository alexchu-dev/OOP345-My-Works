/******************************************************************************
//                    OOP345NDD - WS08 @ 22 Mar 2023
//Module:      Database CPP
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/
#include "Database.h"
using namespace std;
namespace sdds {
   std::shared_ptr<Database> Database::m_instance = nullptr;
   Database::Database(const std::string& filename) : m_filename(filename) {
      cout << "[" << this << "] Database(const std::string&)" << endl;
      ifstream file(filename);
      string key, value{};
      while (file >> key >> value) {
         if (m_entries < 20) {
            std::replace(key.begin(), key.end(), '_', ' ');
            m_keys[m_entries] = key;
            m_values[m_entries] = value;
            m_entries++;
         }
      }
      file.close();
   };
   // As per the README it is supposed to be a shared_ptr. make_shared can also be used. NOTE: .get() can be used on the instance, will test it after compilable.
   shared_ptr<Database> Database::getInstance(const std::string& filename)
   {
      return (m_instance ? m_instance : m_instance = shared_ptr<Database>(new Database(filename)));
   }
   Err_Status Database::GetValue(const std::string& key, std::string& value)
   {
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

   Err_Status Database::SetValue(const std::string& key, const std::string& value)
   {
      Err_Status ret = Err_Status::Err_OutOfMemory;
      if (m_entries < 20) {
         m_keys[m_entries] = key;
         m_values[m_entries] = value;
         m_entries++;
         ret = Err_Status::Err_Success;
      }
      return ret;
   }
   // REMARK: This part seems repetition to the constructor above? Come back and check in part 2 later.
   Database::~Database()
   {
      cout << "[" << this << "] ~Database()" << endl;
      string bkp_filename = m_filename + ".bkp.txt";
      ofstream out_file(bkp_filename);
      for (size_t i = 0; i < m_entries; ++i) {
         out_file << setw(25) << m_keys[i] << " -> " << m_values[i] << endl;
      }
      out_file.close();
   }

}