/******************************************************************************
//                    OOP345NDD - WS03 @ 2 Feb 2023
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/
#include <iostream>
#include <iomanip>
#include <string>
#include "Toy.h"

sdds::Toy::Toy(const std::string& toy)
{
   std::string temp = toy;
   m_orderid = stoi(temp);
   temp.erase(0, temp.find(":") + 1);
   temp.erase(0, temp.find_first_not_of(" "));
   m_name = temp.substr(0, temp.find(":"));
   m_name.erase(m_name.find_last_not_of(" ") + 1);
   temp.erase(0, temp.find(":") + 1);
   m_amount = stoi(temp);
   temp.erase(0, temp.find(":") + 1);
   m_price = stod(temp);
   //std::cout << "OrderID: " << std::endl << m_orderid << std::endl;
   //std::cout << "M_name: " << std::endl << m_name << std::endl;
   //std::cout << "M_name length: " << m_name.length() << std::endl;
   //std::cout << "Amount:" << std::endl << m_amount << std::endl;
   //std::cout << "Price:" << std::endl << m_price << std::endl;
   //std::cout << "Rest Temp String:" << std::endl << temp << std::endl;
   //std::cout << std::to_string(m_orderid).length() << std::endl;
}

void sdds::Toy::update(const int numItems)
{
   m_amount = numItems;
}

std::ostream& sdds::operator<<(std::ostream& os, const Toy& src)
{
   os << "Toy";
   os.setf(std::ios::right);
   os.width(8);
   os << src.m_orderid << ":";
   os.width(18);
   os << src.m_name;
   os.width(3);
   os << src.m_amount << " items";
   os.width(8);
   os << src.m_price << "/item  subtotal:";
   os.width(7);
   os << std::setprecision(2) << std::fixed << src.m_price * src.m_amount << " tax:";
   os.width(6);
   os << std::setprecision(2) << std::fixed << src.m_price * src.m_amount * src.m_hst << " total:";
   os.width(7);
   os << std::setprecision(2) << std::fixed << src.m_price * src.m_amount * (1 + src.m_hst) << std::endl;
   os.unsetf(std::ios::right);
   return os;
}
