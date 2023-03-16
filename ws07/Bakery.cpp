/******************************************************************************
//                    OOP345NDD - WS06 @ 15 Mar 2023
//Module:      Bakery CPP
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/
#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <iomanip>
#include "Bakery.h"
using namespace std;
namespace sdds {
   /* Using map to map the enum to string for i/o */
   std::map<BakedType, std::string> bakedTypeNames{
    {BakedType::BREAD, "Bread"},
    {BakedType::PASTERY, "Pastry"}
   };

   Bakery::Bakery(const std::string& filename)
   {
      ifstream file(filename);
      string line;
      string token;
      if (!file) {
         throw ("Filename incorrect!");
      }
      while (getline(file, line))
      {
         try {
            BakedGood bg;
            // Retrieve token, trim, assign enum
            bg.m_type = (trim(token = line.substr(0, 8)) == "Bread" ? BakedType::BREAD : BakedType::PASTERY);
            bg.m_desc = trim(token = line.erase(0, 8).substr(0, 20));
            bg.m_shelfLife = stoi(line.erase(0, 20).substr(0, 14));
            bg.m_stock = stoi(line.erase(0, 14).substr(0, 8));
            bg.m_price = stod(line.erase(0, 8).substr(0, 6));
            m_collection.push_back(bg);
         }
         catch (const std::string msg) {
            cout << "ERROR: " << msg << endl;
         }
         catch (std::invalid_argument const& msg) {
            cout << "ERROR: " << msg.what() << endl;
         }
         catch (...) {
            cout << "Error(s) found in Bakery(const string) constructor ." << endl;
         }
      }
   }
   void Bakery::showGoods(std::ostream& os) const
   {
      //Using "for_each" from algorithm instead of for+iterator.
      for_each(m_collection.begin(), m_collection.end(), [&os](const BakedGood& src) {os << src << endl; });
      //Using "accumulate".
      cout << "Total Stock: " << accumulate(m_collection.begin(), m_collection.end(), 0, [](const int& result, const BakedGood& src) { return result + src.m_stock; }) << endl;
      cout << "Total Price: " << accumulate(m_collection.begin(), m_collection.end(), 0.0, [](const double& result, const BakedGood& src) { return result + src.m_price; }) << endl;
   }
   void Bakery::sortBakery(const std::string& field)
   {
      if (field == "Description") {
         sort(m_collection.begin(), m_collection.end(), [](const BakedGood& lhs, const BakedGood& rhs) {return lhs.m_desc < rhs.m_desc; });
      }
      else if (field == "Shelf") {
         sort(m_collection.begin(), m_collection.end(), [](const BakedGood& lhs, const BakedGood& rhs) {return lhs.m_shelfLife < rhs.m_shelfLife; });
      }
      else if (field == "Stock") {
         sort(m_collection.begin(), m_collection.end(), [](const BakedGood& lhs, const BakedGood& rhs) {return lhs.m_stock < rhs.m_stock; });
      }
      else if (field == "Price") {
         sort(m_collection.begin(), m_collection.end(), [](const BakedGood& lhs, const BakedGood& rhs) {return lhs.m_price < rhs.m_price; });
      };
   }
   std::vector<BakedGood> Bakery::combine(Bakery& rhs)
   {
      vector<BakedGood> combined;
      rhs.sortBakery("Price");
      this->sortBakery("Price");
      merge(m_collection.begin(), m_collection.end(), rhs.m_collection.begin(), rhs.m_collection.end(), std::back_inserter(combined), [](const BakedGood& lhs, const BakedGood& rhs) {return lhs.m_price < rhs.m_price; });
      return combined;
   }
   bool Bakery::inStock(const std::string& desc, const BakedType& type) const
   {
      return (any_of(m_collection.begin(), m_collection.end(), [&](const BakedGood& bg) {return bg.m_type == type && bg.m_desc == desc && bg.m_stock > 0; }));
   }
   std::list<BakedGood> Bakery::outOfStock(const BakedType& type) const
   {
      std::list<BakedGood> noStock;
      copy_if(m_collection.begin(), m_collection.end(), std::back_inserter(noStock), [&](const BakedGood& bg) {return bg.m_type == type && bg.m_stock == 0; });
      return noStock;
   }
   std::ostream& operator<<(std::ostream& os, const BakedGood& bg)
   {
      os << "* ";
      os << left << setw(10) << bakedTypeNames[bg.m_type] << " * ";
      os << setw(20) << bg.m_desc << " * ";
      os << setw(5) << bg.m_shelfLife << " * ";
      os << setw(5) << bg.m_stock << " * ";
      os << right << fixed << setprecision(2) << setw(8) << bg.m_price << " * ";
      return os;
   }
   std::string& trim(std::string& s)
   {
      s.erase(0, s.find_first_not_of(" "));  // Erase leading spaces
      s.erase(s.find_last_not_of(" ") + 1);  // Erase trailing spaces
      return s;
   }
}