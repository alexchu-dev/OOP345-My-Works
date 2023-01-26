/******************************************************************************
//                    OOP345NDD - WS02 @ 24 Jan 2023
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/
#ifndef SDDS_TIMEDTASK_H_
#define SDDS_TIMEDTASK_H_

namespace sdds {
   struct Task {
      std::string n_taskName{};
      std::string n_units{};
      std::chrono::steady_clock::duration n_duration{};
   };
   class TimedTask {
      long int m_noRecords{};
      Task m_task[10];
      std::chrono::steady_clock::time_point m_timeStart{};
      std::chrono::steady_clock::time_point m_timeEnd{};
   public:
      TimedTask() {};
      ~TimedTask() {};
      void startClock();
      void stopClock();
      void addTask(const char* src);
      friend std::ostream& operator<<(std::ostream& ostr, const TimedTask& src);
   };
}
#endif