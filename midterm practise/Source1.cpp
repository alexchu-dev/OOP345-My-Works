#include <iostream>
#include <cstring>
using namespace std;
template <typename T>
T* insertAtEnd(const T* arr, const size_t size, const T& elem) {
   T* temp = new T[size + 1];
   for (auto i = 0u; i < size; ++i)
      temp[i] = arr[i];
   temp[size] = elem;
   delete[] arr;
   return temp;
}
template <>
char* insertAtEnd(const char* arr, const size_t size, const char& elem) {
   char* temp = new char[size + 2];
   for (auto i = 0u; i < size; ++i)
      temp[i] = arr[i];
   temp[size] = elem;
   temp[size + 1] = '\0';
   delete[] arr;
   return temp;
}
class A {
public:
   double m_val;
};
int main()
{
   {
      int* arrI = nullptr;
      arrI = insertAtEnd(arrI, 0, 1); // 1
      arrI = insertAtEnd(arrI, 1, 5); // 1, 5
      arrI = insertAtEnd(arrI, 2, -3);// 1, 5, -3
      for (auto i = 0u; i < 3; i++)
         cout << arrI[i] << endl;
      delete[] arrI;
   }
   {
      double* arrD = nullptr;
      arrD = insertAtEnd(arrD, 0, 1.2);// 1.2
      arrD = insertAtEnd(arrD, 1, 2.3);// 1.2, 2.3
      arrD = insertAtEnd(arrD, 2, 3.4);// 1.2, 2.3, 3.4
      for (auto i = 0u; i < 3; i++)
         cout << arrD[i] << endl;
      delete[] arrD;
   }
   {
      char* arrC = nullptr;
      arrC = insertAtEnd(arrC, 0, 'a');// a\0
      arrC = insertAtEnd(arrC, 1, 'b');// ab\0
      arrC = insertAtEnd(arrC, 2, 'c');// abc\0
      cout << arrC;
      delete[] arrC;
   }
}