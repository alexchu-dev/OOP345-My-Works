/******************************************************************************
//                    OOP345NDD - MS3 @ 27 Mar 2023
//Module:      LineManager CPP
//Full Name  : Alex Chu
//Student ID#: 153954219
//Email      : kchu30@myseneca.ca
//
//I have done all the coding by myself and only copied the code
//that my professor provided to complete my workshops and assignments.
******************************************************************************/
#include "LineManager.h"
#include "Utilities.h"
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
namespace sdds {
   LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations)
   {
      ifstream fin(file);
      string line, firstStation, secondStation;
      Utilities util;
      Utilities::setDelimiter('|');
      bool more = true;
      size_t next_pos = 0u;
      if (!fin) {
         throw string("Unable to open [") + file + "] file";
      }
      while (getline(fin, line)) {
         firstStation = util.extractToken(line, next_pos, more);
         secondStation = util.extractToken(line, next_pos, more);
         auto firstIterator = find_if(stations.begin(), stations.end(), [&](const Workstation* workstation) {return workstation->getItemName() == firstStation; });
      }
   }
}