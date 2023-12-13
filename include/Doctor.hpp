#ifndef DOCTOR_HPP
#define DOCTOR_HPP

#include "Pacient.hpp"

#include <set>
#include <string>
#include <vector>

class Doctor {
public:
  std::string id;
  std::set<std::string> specialities;

  int availableFromHour;
  std::vector<Pacient> solvedProblems;
};

#endif
