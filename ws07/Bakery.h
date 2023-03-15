/******************************************************************************
//                    OOP345NDD - WS06 @ 15 Mar 2023
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
#include <vector>
#include <map>
namespace sdds {
   enum class BakedType {
      BREAD, PASTERY
   };
   struct BakedGood {
      BakedType m_type = BakedType::BREAD;
      std::string m_desc{};
      size_t m_shelfLife{};
      size_t m_stock{};
      double m_price{ 0.0 };
   };
   class Bakery
   {
      std::vector<BakedGood> m_collection;
   public:
      Bakery(const std::string filename);
      void showGoods(std::ostream& os) const;
   };
   std::ostream& operator<<(std::ostream& os, const BakedGood& bg);
   std::string& trim(std::string& s);
}
#endif


