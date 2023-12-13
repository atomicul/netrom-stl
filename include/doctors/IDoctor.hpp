#ifndef DOCTORS_IDOCTOR_HPP
#define DOCTORS_IDOCTOR_HPP

#include "emergencies/IEmergency.hpp"

#include <concepts>
#include <memory>
#include <set>
#include <span>
#include <string>
#include <string_view>
#include <vector>

namespace doctors {
class IDoctor {
public:
  virtual std::string id() const = 0;
  virtual std::set<std::string> specialities() const = 0;
  virtual const std::vector<emergencies::IEmergency> &
  solvedProblems() const = 0;

  virtual IDoctor &setId(std::string_view id) = 0;
  virtual IDoctor &
  setSpecialities(std::span<const emergencies::IEmergency> specialities) = 0;
  virtual IDoctor &addSpeciality(std::string_view speciality) = 0;
  virtual IDoctor &removeSpeciality(std::string_view speciality) = 0;

  virtual bool canSolve(const emergencies::IEmergency &emergency) const = 0;
  virtual bool solve(const emergencies::IEmergency &emergency) = 0;

  virtual ~IDoctor() = default;
};
}; // namespace doctors

#endif
