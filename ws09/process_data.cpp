/******************************************************************************
//                    OOP345NDD - WS09 @ 30 Mar 2023
//Module:      ProcessData CPP
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assdignments.
******************************************************************************/
// Workshop 9 - Multi-Threading, Thread Class
// process_data.cpp
// 2021/1/5 - Jeevan Pant


#include "process_data.h"

namespace sdds_ws9 {

   void computeAvgFactor(const int* arr, int size, int divisor, double& avg) {
      avg = 0;
      for (int i = 0; i < size; i++) {
         avg += arr[i];
      }
      avg /= divisor;
   }

   void computeVarFactor(const int* arr, int size, int divisor, double avg, double& var) {
      var = 0;
      for (int i = 0; i < size; i++) {
         var += (arr[i] - avg) * (arr[i] - avg);
      }
      var /= divisor;
   }
   ProcessData::operator bool() const {
      return total_items > 0 && data && num_threads > 0 && averages && variances && p_indices;
   }

   ProcessData::ProcessData(std::string filename, int n_threads) {
      // TODO: Open the file whose name was received as parameter and read the content
      //         into variables "total_items" and "data". Don't forget to allocate
      //         memory for "data".
      //       The file is binary and has the format described in the specs.
      std::ifstream file(filename, std::ios::binary);
      if (file.is_open()) {
         file.read((char*)&total_items, sizeof(int));
         data = new int[total_items];
         file.read((char*)data, sizeof(int) * total_items);
         file.close();
         std::cout << "Item's count in file '" << filename << "': " << total_items << std::endl;
         std::cout << "  [" << data[0] << ", " << data[1] << ", " << data[2] << ", ... , "
            << data[total_items - 3] << ", " << data[total_items - 2] << ", "
            << data[total_items - 1] << "]\n";
      }

      // Following statements initialize the variables added for multi-threaded 
      //   computation
      num_threads = n_threads;
      averages = new double[num_threads] {};
      variances = new double[num_threads] {};
      p_indices = new int[num_threads + 1] {};
      for (int i = 0; i < num_threads + 1; i++)
         p_indices[i] = i * (total_items / num_threads);
   }
   ProcessData::~ProcessData() {
      delete[] data;
      delete[] averages;
      delete[] variances;
      delete[] p_indices;
   }

   // TODO Improve operator() function from part-1 for multi-threaded operation. Enhance the  
   //   function logic for the computation of average and variance by running the 
   //   function computeAvgFactor and computeVarFactor in multile threads. 
   // The function divides the data into a number of parts, where the number of parts is 
   //   equal to the number of threads. Use multi-threading to compute average-factor for 
   //   each part of the data by calling the function computeAvgFactor. Add the obtained 
   //   average-factors to compute total average. Use the resulting total average as the 
   //   average value argument for the function computeVarFactor, to compute variance-factors 
   //   for each part of the data. Use multi-threading to compute variance-factor for each 
   //   part of the data. Add computed variance-factors to obtain total variance.
   // Save the data into a file with filename held by the argument fname_target. 
   // Also, read the workshop instruction.
   int ProcessData::operator()(std::string target_filename, double& avg, double& var) {
      std::vector<std::thread> t, t2;
      int chunk = total_items / num_threads;
      using namespace std::placeholders;
      auto f1 = std::bind(computeAvgFactor, _1, _2, total_items, _3);
      for (auto i = 0; i < num_threads; ++i) {
         t.push_back(std::thread(f1, &data[p_indices[i]], chunk, std::ref(averages[i])));
         //std::this_thread::sleep_for(std::chrono::nanoseconds(1000));
      }
      for (auto& x : t) {
         x.join();
      }
      for (auto i = 0; i < num_threads; ++i) {
         avg += averages[i];
      }
      // Using "avg" here, it is already a computed threaded average
      auto f2 = std::bind(computeVarFactor, _1, _2, total_items, avg, _3);
      for (auto i = 0; i < num_threads; ++i) {
         t2.push_back(std::thread(f2, &data[p_indices[i]], chunk, std::ref(variances[i])));
         //std::this_thread::sleep_for(std::chrono::nanoseconds(1000));
      }
      for (auto& x : t2) {
         x.join();
      }
      for (auto i = 0; i < num_threads; ++i) {
         var += variances[i];
      }
      std::ofstream target_file(target_filename, std::ios::binary);
      if (target_file.is_open()) {
         target_file.write((const char*)&total_items, sizeof(int));
         target_file.write((const char*)data, sizeof(int) * total_items);
         target_file.close();
      }
      return (!target_file);
   }



}