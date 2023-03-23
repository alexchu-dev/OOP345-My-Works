/******************************************************************************
//                    OOP345NDD - WS08 @ 22 Mar 2023
//Module:      Bakery Header
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/
#ifndef SDDS_BAKERY_H
#define SDDS_BAKERY_H
#include <iostream>
#include <memory>
namespace sdds {
enum class Err_Status
{
   Err_Success,
   Err_NotFound,
   Err_OutOfMemory,
};
class Database
{ 
   static std::shared_ptr<Database> db;
public:
   static Database getInstance(const std::string& filename);
};
}
#endif