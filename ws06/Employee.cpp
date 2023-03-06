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
#include "Employee.h"
#include "Utilities.h"
using namespace std;
namespace sdds {
   Employee::Employee(istream& is)
   {
      string tag, age, temp;
      getline(is, tag, ','); // Tag has been processed by Utilities already, do a pass-by only
      getline(is, m_name, ',');
      trim(m_name);
      // Store value to a temporary string "age", use a function to check if the string is a digit or else throws error.
      getline(is, age, ',');
      if (my_isdigit(age)) m_age = age;
      else {
         string e = m_name + "++Invalid record!\n";
         throw (e);
      }
      getline(is, m_id, ',');
      trim(m_id);
      if (m_id[0] == 'e' || m_id[0] == 'E')
         m_id = m_id.erase(m_id.find_last_not_of(" ") + 1);
      else {
         string e = m_name + "++Invalid record!\n";
         throw (e);
      }
   }
   string Employee::status() const
   {
      return string("Employee");
   }
   string Employee::name() const
   {
      return m_name;
   }

   string Employee::age() const
   {
      return m_age;
   }

   string Employee::id() const
   {
      return m_id;
   }

   void Employee::display(ostream& os) const
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
      os << " | ";
      os.width(3);
      os << m_age;
      os << " |";
   }

}