#ifndef PACIENT_HPP
#define PACIENT_HPP

#include <string>

class Pacient {
public:
  std::string name;
  std::string speciality;
  int arrivalHour;
  int duration;
  int priority;

  bool operator<(const Pacient &other) const;
};

#endif
