#include <iostream>
#include <numeric>
#include <vector>
#include <chrono>
#include <execution>
#include <algorithm>
using namespace std;
void task() {
   cout << "Hello!" << endl;
}
int main()
{
   std::vector<double> x(10000000, 0.5);
   std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
   //double s = std::accumulate(x.begin(), x.end(), 0.0);
   double s = std::reduce(std::execution::par, x.begin(), x.end(), 0.0);
   std::cout << "sum = " << s << std::endl;
   std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
   auto dur = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
   std::cout << dur.count() << "milliseconds" << endl;
   std::thread t = std::thread(task);
   cout << std::this_thread::get_id() << std::endl;
   cout << std::thread::hardware_concurrency();
   t.join();
   return 0;
}