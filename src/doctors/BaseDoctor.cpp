#include "doctors/BaseDoctor.hpp"

using namespace doctors;

std::string BaseDoctor::id() const { return _id; }
std::set<std::string> const &BaseDoctor::specialities() const {
  return _specialities;
}

IDoctor &BaseDoctor::setId(std::string_view id) {
  _id = id;
  return *this;
}
IDoctor &BaseDoctor::addSpeciality(std::string speciality) {
  _specialities.insert(std::move(speciality));
  return *this;
};
IDoctor &BaseDoctor::removeSpeciality(std::string_view speciality) {
  _specialities.erase((const std::string &)speciality);
  return *this;
}
