#include <iostream>
#include "Pair.h"

//std::ostream& sdds::Pair::display(std::ostream& os) const
//{
//   os << "----------------------\n| Collection Content |\n----------------------\n" << std::endl;
//   for (int i = 0; i < m_size; i++) {
//      os.setf(std::ios::right);
//      os.width(20);
//      os << m_collection[i] << std::endl;
//   }
//   os << "----------------------" << std::endl;
//   return os;
//}

std::ostream& sdds::operator<<(std::ostream& os, const Pair& src)
{
   os.setf(std::ios::right);
   os.width(20);
   os << src.getKey() << ": " << src.getValue();
   return os;
}
