#include <iostream>
#include <string>
enum class StateType
{
   boolean,
   character,
   number
};
typedef struct
{
   char name[20];
   StateType sType;
   union
   {
      bool stateAsBool;
      char stateAsChar;
      int stateAsNum;
   } sState;
} Switch;
class HomeStereo {
   Switch* m_switch{};
   size_t m_numOfValues{};
public:
   HomeStereo() {};
   HomeStereo(Switch* switchArg, size_t num) {
      m_switch = new Switch[num];
      for (auto i = 0u; i < num; i++) {
         m_switch[i] = switchArg[i];
      }
      m_numOfValues = num;
   };
   ~HomeStereo() {
      delete[] m_switch;
   };
   HomeStereo(const HomeStereo& src) { *this = src; }
   HomeStereo& operator=(const HomeStereo& src) {
      if (this != &src) {
         delete[] m_switch;
         m_switch = nullptr;
         m_numOfValues = src.m_numOfValues;
         if (src.m_switch) {
            m_switch = new Switch[src.m_numOfValues];
            for (size_t i = 0; i < m_numOfValues; i++) {
               m_switch[i] = src.m_switch[i];
            }
         }
      }
      return *this;
   }
   HomeStereo(HomeStereo&& src)noexcept { *this = std::move(src); }
   HomeStereo& operator=(HomeStereo&& src)noexcept {
      if (this != &src) {
         delete[] m_switch;
         m_switch = nullptr;
         m_numOfValues = src.m_numOfValues;
         m_switch = src.m_switch;
         src.m_switch = nullptr;
         src.m_numOfValues = 0;
      }
      return *this;
   }
   std::ostream& displayOutputState(std::ostream& os = std::cout) const {
      if (m_switch != nullptr)
         for (auto i = 0u; i < m_numOfValues; i++) {
            os << "Channel Name: " << m_switch[i].name << " - State [";
            switch (m_switch[i].sType) {
            case StateType::boolean:
               os << (m_switch[i].sState.stateAsBool == true) ? "On" : "Off";
               //asd
               break;
            case StateType::character:
               os << (m_switch[i].sState.stateAsChar == 'O') ? "On" : "Off";
               break;
            case StateType::number:
               os << (m_switch[i].sState.stateAsNum == 1) ? "On" : "Off";
               break;
            }
            os << "]" << std::endl;
         }
      return os;
   }
};
std::string abc() {
   std::string abc = "xuz";
   std::cin >> abc;
   std::cout << 999 << std::endl;
   return abc;
}
int main() {
   std::cout << abc();
   double x[]{ 1.1,2.2,3.3,4.4 };

   int j = 2;

   std::cout << *(j + x);
   std::cout << x[j];
   return 0;
}