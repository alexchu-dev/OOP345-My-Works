/******************************************************************************
//                    OOP345NDD - WS05 @ 13 Feb 2023
//Module:      Collection Module Header
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/
#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <iostream>
#include <string>
namespace sdds {
   template<typename T>
   class Collection {
      std::string m_name{};
      T* m_array{};
      size_t m_size{};
      void (*m_observer)(const Collection<T>&, const T&) {};
   public:
      Collection(const std::string& name) : m_name{ name } {};  //1 arg constructor with default value name. Other values already initialised above when declared.
      Collection(const Collection&) = delete; //delete to prevent copying
      Collection& operator=(const Collection&) = delete; //delete to prevent copying
      ~Collection() { delete[] m_array; }; //basic destructor to delete the dynamic array member.
      const std::string& name() const { return m_name; } //basic function to return the name (private member)
      size_t size() const { return m_size; } //basic function to return the size (private member)
      void setObserver(void (*observer)(const Collection<T>&, const T&)) { //basic function to set the pointer of function observer (private member)
         m_observer = observer;
      }
      //The following is a += operator overload function. It receives a reference to a constant T object and process it. if it is found in the record do nothing. If it is new to the array then add it to the array and resize it.
      Collection<T>& operator+=(const T& item) {
         bool found = false;
         for (size_t i = 0; i < m_size; i++) {
            if (m_array[i].title() == item.title()) {
               found = true;
            }
         }
         if (found == false) {
            T* temp_array = new T[++m_size];
            for (size_t i = 0; i < m_size - 1; i++) {
               temp_array[i] = m_array[i];
            }
            temp_array[m_size - 1] = item;
            delete[] m_array;
            m_array = temp_array; //Passing address only. No need to worry about mem leak.
            if (m_observer) {
               m_observer(*this, m_array[m_size - 1]);
            }
         }
         return *this;
      }
      //This is to overload the [] operator. It receives an index and returns the item at that specific index as a reference to a constant T object.
      Collection <T>& operator[](size_t idx) const {
         if (idx >= m_size || idx < 0) {
            std::string e = "Bad index [";
            e = e + std::to_string(idx) + "]. Collection has [" + std::to_string(m_size) + "] items.";
            throw std::out_of_range(e);
         }
         return m_array[idx];
      }
      //This is to overload the [] operator as well. It receives a reference of a const string and find it in the function. If it matches the record, it returns a pointer of T.
      T* operator[](const std::string& title) const {
         T* index = nullptr;
         for (size_t i = 0; i < m_size; i++) {
            if (m_array[i].title() == title) {
               index = &m_array[i];
            }
         }
         return index;
      }
   };
   //Helper function overloading the << operator.
   template<typename T>
   std::ostream& operator<<(std::ostream& os, const Collection<T>& src) {
      for (size_t i = 0; i < src.size(); i++) {
         os << src[i];
      }
      return os;
   }
}
#endif