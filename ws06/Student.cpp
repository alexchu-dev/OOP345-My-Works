/******************************************************************************
//                    OOP345NDD - WS06 @ 28 Feb 2023
//Module:      Student CPP
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/
#include "Student.h"
#include "Utilities.h"
using namespace std;
namespace sdds {
   Student::Student(istream& is)
   {
      string tag, age, courseNum, temp{};
      getline(is, tag, ','); // Tag has been processed by Utilities already, do a pass-by only
      getline(is, m_name, ',');
      trim(m_name);
      // Store value to a temporary string "age", use a function to check if the string is a digit or else throws error.
      getline(is, age, ',');
      trim(age);
      if (my_isdigit(age)) m_age = age;
      else {
         string e = m_name + "++Invalid record!\n";
         throw (e);
      }
      // Getting student ID and trimming.
      getline(is, m_id, ',');
      trim(m_id);
      if (m_id[0] == 's' || m_id[0] == 'S')
         m_id = m_id.erase(m_id.find_last_not_of(" ") + 1);
      else {
         string e = m_name + "++Invalid record!\n";
         throw (e);
      }
      // The following for the number of course works similar to the age above, however this one is to avoid if age and id passed but there is invalid courses number and courses detail. Throws error when it is invalid.
      getline(is, courseNum, ',');
      trim(courseNum);
      if (my_isdigit(courseNum)) m_count = stoi(courseNum);
      else {
         string e = m_name + "++Invalid record!\n";
         throw (e);
      }
      if (m_count > 0) {
         m_courses = new string[m_count];
         for (auto i = 0u; i < m_count - 1; ++i) {
            getline(is, m_courses[i], ',');
            trim(m_courses[i]);
         }
         getline(is, m_courses[m_count - 1], '\n');
         trim(m_courses[m_count - 1]);
      }
   }

   Student::~Student()
   {
      delete[] m_courses;
      m_courses = nullptr;
   }

   string Student::status() const
   {
      return string("Student");
   }

   string Student::name() const
   {
      return m_name;
   }

   std::string Student::age() const
   {
      return m_age;
   }

   std::string Student::id() const
   {
      return m_id;
   }

   void Student::display(ostream& os) const
   {
      os.setf(ios::left);
      os << "| ";
      os.width(10);
      os << "Student";
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
      for (auto i = 0u; i < m_count - 1; ++i) {
         os << m_courses[i] << ", ";
      }
      os << m_courses[m_count - 1];
   }
}