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
      Collection(const std::string& name) : m_name{ name } {};
      Collection(const Collection&) = delete;
      Collection& operator=(const Collection&) = delete;
      ~Collection() { delete[] m_array; };
      const std::string& name() const { return m_name; }
      size_t size() const { return m_size; }
      void setObserver(void (*observer)(const Collection<T>&, const T&)) {
         m_observer = observer;
      }
      Collection<T>& operator+=(const T& item) {
         bool found = false;
         for (auto i = 0; i < m_size; i++) {
            if (m_array[i].title() == item.title()) {
               found = true;
            }
         }
         if (found == false) {
            T* temp_array = new T[++m_size];
            for (auto i = 0; i < m_size - 1; i++) {
               temp_array[i] = m_array[i];
            }
            temp_array[m_size - 1] = item;
            delete[] m_array;
            m_array = temp_array; //Passing address only.
            if (m_observer) {
               m_observer(*this, m_array[m_size - 1]);
            }
         }
         return *this;
      }
      T& operator[](size_t idx) const {
         if (idx >= m_size || idx < 0) {
            std::string e = "Bad index [";
            e = e + std::to_string(idx) + "]. Collection has [" + std::to_string(m_size) + "] items.";
            throw std::out_of_range(e);
         }
         return m_array[idx];
      }
      T* operator[](const std::string& title) const {
         T* index = nullptr;
         for (auto i = 0; i < m_size; i++) {
            if (m_array[i].title() == title) {
               index = &m_array[i];
            }
         }
         return index;
      }
   };
   template<typename T>
   std::ostream& operator<<(std::ostream& os, const Collection<T>& src) {
      for (auto i = 0; i < src.size(); i++) {
         os << src[i];
      }
      return os;
   }
}
#endif