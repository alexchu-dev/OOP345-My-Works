/******************************************************************************
//                    OOP345NDD - WS02 @ 24 Jan 2023
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include "ProteinDatabase.h"
using namespace std;
namespace sdds {
   ProteinDatabase::ProteinDatabase(const std::string filename)
   {
      std::ifstream fin(filename);
      std::string tempString{};
      while (getline(fin, tempString)) {
         if (tempString[0] == '>') {
            m_noOfStrings++;
         }
      }
      m_arr = new std::string[m_noOfStrings];
      // the ifstream obj must be clear, otherwise it would not work
      fin.clear();
      // seekg(0) is to rewind back to the position of 0, which default is the begining (ios::beg)
      fin.seekg(0);
      // index is to set as -1 os that when the first '>' received it becomes 0
      int index = -1;
      while (getline(fin, tempString)) {
         if (tempString[0] == '>') { index++; }
         else {
            m_arr[index] += tempString;
         }
      }
   }
   // Standard destructor.
   ProteinDatabase::~ProteinDatabase()
   {
      delete[] m_arr;
   }
   ProteinDatabase::ProteinDatabase(const ProteinDatabase& src)
   {
      *this = src;
   }
   // For this copy assignment operator, although it is using string that a string can be assigned(copied) to another string unlike char needs strcpy, however, this m_arr is an array of string, it must be created using dynamic memory allocation and all contents in the array must be deep copied. Tried to shallow copy like m_arr = src.m_arr and caused Exception Thrown.
   ProteinDatabase& ProteinDatabase::operator=(const ProteinDatabase& src)
   {
      if (this != &src) {
         delete[] m_arr;
         m_arr = nullptr;
         m_noOfStrings = src.m_noOfStrings;
         m_arr = new string[src.m_noOfStrings];
         for (int i = 0; i < m_noOfStrings; i++) {
            m_arr[i] = src.m_arr[i];
         }
      }
      return *this;
   }
   // noexcept is to place here for no exception thrown
   ProteinDatabase::ProteinDatabase(ProteinDatabase&& src)noexcept
   {
      *this = std::move(src);
   }
   // This move assignment deletes the previous dynamic memory allocation and assigning to another one. The source must be set to nullptr / empty state to achieve the "Move".
   ProteinDatabase& ProteinDatabase::operator=(ProteinDatabase&& src)noexcept
   {
      if (this != &src) {
         delete[] m_arr;
         m_arr = nullptr;
         m_noOfStrings = src.m_noOfStrings;
         m_arr = src.m_arr;
         src.m_noOfStrings = 0;
         src.m_arr = nullptr;
      }
      return *this;
   }
   size_t ProteinDatabase::size()const
   {
      return m_noOfStrings;
   }
   std::string ProteinDatabase::operator[](size_t index)const
   {
      std::string m_arrCopy;
      if (index < m_noOfStrings)
      {
         m_arrCopy = m_arr[index];
      }
      else {
         m_arrCopy = "";
      }
      return m_arrCopy;
   }
}
