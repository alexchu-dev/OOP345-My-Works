/******************************************************************************
//                    OOP345NDD - WS06 @ 28 Feb 2023
//Module:      Employee CPP
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/
#include <iostream>
#include <string>
#include "Employee.h"
using namespace std;
namespace sdds {
   Employee::Employee(std::istream& is)
   {
      string temp;
      getline(is, temp);
      temp.erase(0, temp.find(",") + 1); // Assume Tag has been processed by Utilities already, here do a pass-by and erase
      temp.erase(0, temp.find_first_not_of(" ")); // Erase leading spaces
      m_name = temp.substr(0, temp.find(","));
      m_name.erase(m_name.find_last_not_of(" ") + 1); // Erase trailing spaces
      temp.erase(0, temp.find(",") + 1); // Erase the name and delimiter from temp
      // Since age is an integer, if the data input is a string, it throws error
      try {
         m_age = stoi(temp);
      }
      catch (std::invalid_argument const& e)
      {
         cout << m_name << "++Invalid record!" << endl;
      }
      temp.erase(0, temp.find(",") + 1);
      temp.erase(0, temp.find_first_not_of(" "));
      try {
         if (temp[0] == 'e' || temp[0] == 'E')
            m_id = temp.erase(temp.find_last_not_of(" ") + 1);
         else {
            throw ("++Invalid record!");
         }
      }
      catch (const char* e) {
         cout << m_name << e << endl;
      }
   }
   std::string Employee::status() const
   {
      return std::string("Employee");
   }
   std::string Employee::name() const
   {
      return m_name;
   }

   std::string Employee::age() const
   {
      return to_string(m_age);
   }

   std::string Employee::id() const
   {
      return m_id;
   }

   void Employee::display(std::ostream& os) const
   {
      os.setf(ios::left);
      os << "| ";
      os.width(10);
      os << "Employee";
      os << "| ";
      os.width(10);
      os << m_id;
      os << "| ";
      os.width(20);
      os << m_name;
      os << "| ";
      os.width(3);
      os << m_age;
      os << "|";
   }

}