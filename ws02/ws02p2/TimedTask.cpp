/******************************************************************************
//                    OOP345NDD - WS02 @ 24 Jan 2023
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/
#include <iostream>
#include <chrono>
#include <iomanip>
#include "TimedTask.h"
using namespace std;
namespace sdds {
   // Using steady_clock as a stop watch to capture a current time
   void TimedTask::startClock()
   {
      m_timeStart = std::chrono::steady_clock::now();
   }
   // Using steady_clock as a stop watch to capture the next current time
   void TimedTask::stopClock()
   {
      m_timeEnd = std::chrono::steady_clock::now();
   }
   // Everytime when the "addTask" is run by each timed task, it addes the input taskName, the units and the difference of two time stamps. Then, noRecords plus one for the next task's use.
   void TimedTask::addTask(const char* src)
   {
      if (src != nullptr) {
         m_task[m_noRecords].n_taskName = src;
         m_task[m_noRecords].n_units = "nanoseconds";
         m_task[m_noRecords].n_duration = (m_timeEnd - m_timeStart);
         m_noRecords++;
      }
   }
   // This friend helper function is to grant access to the private function of TimedTask to w2_pX.cpp. It list the tasks and time consumed using a loop. 
   std::ostream& operator<<(std::ostream& ostr, const TimedTask& src)
   {
      ostr << "--------------------------" << endl;
      ostr << "Execution Times:" << endl;
      ostr << "--------------------------" << endl;
      for (int i = 0; i < src.m_noRecords; i++)
      {
         ostr.setf(ios::left);
         ostr.width(21);
         ostr << src.m_task[i].n_taskName << " ";
         ostr.unsetf(ios::left);
         ostr.setf(ios::right);
         ostr.width(13);
         ostr << src.m_task[i].n_duration.count() << " ";
         ostr.unsetf(ios::right);
         ostr << src.m_task[i].n_units << endl;
      }
      ostr << "--------------------------" << endl;
      return ostr;
   }
}
