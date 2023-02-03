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
#include "Pair.h"
//Extraction operator overload so that it can output the values of the attributes to ostream.
std::ostream& sdds::operator<<(std::ostream& os, const Pair& src)
{
   os.setf(std::ios::right);
   os.width(20);
   os << src.getKey() << ": " << src.getValue();
   return os;
}
//This operator overload is mainly for part 2 of this workshop, as a specialisation to compare the Pair class.
bool sdds::Pair::operator==(const Pair& rhs)
{
   return m_key == rhs.m_key;
}
