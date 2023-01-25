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
#include <iomanip>
#include "TimedTask.h"
using namespace std;
namespace sdds {
   void TimedTask::startClock()
   {
      m_timeStart = std::chrono::steady_clock::now();
   }

   void TimedTask::stopClock()
   {
      m_timeEnd = std::chrono::steady_clock::now();
   }

   void TimedTask::addTask(const char* src)
   {
      if (src != nullptr) {
         m_task->n_taskName = src;
         m_task->n_units = "nanoseconds";
         m_task->n_duration = m_timeEnd - m_timeStart;
         m_noRecords++;
      }
   }

   std::ostream& operator<<(std::ostream& ostr, const TimedTask& src)
   {
      if (!src.m_task->n_taskName.empty())
      {
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
            ostr << src.m_task[i].n_units;
         }
         ostr << "--------------------------" << endl;
      }
   }
}
