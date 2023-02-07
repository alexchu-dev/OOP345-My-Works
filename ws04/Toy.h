#ifndef SDDS_TOY_H
#define SDDS_TOY_H
#include <iostream>
#include <string>
namespace sdds {
   class Toy {
      int m_orderid{};
      std::string m_name{};
      int m_amount{};
      double m_price{};
      double m_hst{ 0.13 };
   public:
      Toy() {};
      Toy(const std::string& toy);
      void update(const int);
      friend std::ostream& operator << (std::ostream& os, const Toy& src);
   };
}
#endif