/******************************************************************************
//                    OOP345NDD - MS3 @ 26 Mar 2023
//Module:      Workstation Header
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments.
******************************************************************************/
#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H
#include "Utilities.h"
#include "CustomerOrder.h"
#include <deque>
namespace sdds
{
   extern std::deque<CustomerOrder> g_pending, g_completed, g_incomplete{};
   class Workstation : public Station
   {
      std::deque<CustomerOrder> m_orders{};
      Workstation* m_pNextStation{};
   public:
      Workstation(const std::string& str) :Station(str) {};
      ~Workstation();
      Workstation(const Workstation& src) = delete;
      Workstation& operator=(const Workstation& src) = delete;
      Workstation(Workstation&& src) = delete;
      Workstation& operator=(Workstation&& src) = delete;
      void fill(std::ostream& os);
      bool attemptToMoveOrder();
      void setNextStation(Workstation* station);
      Workstation* getNextStation() const;
      void display(std::ostream& os) const;
      Workstation& operator+=(CustomerOrder&& newOrder);
   };
}
#endif
