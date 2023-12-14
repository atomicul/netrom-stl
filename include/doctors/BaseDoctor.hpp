#ifndef DOCTORS_BASEDOCTOR_HPP
#define DOCTORS_BASEDOCTOR_HPP

#include "doctors/IDoctor.hpp"
#include "emergencies/IEmergency.hpp"

#include <set>
#include <string>

namespace doctors {
class BaseDoctor : public doctors::IDoctor {
protected:
  std::string _id;
  std::set<std::string> _specialities;

public:
  virtual std::string id() const override;
  virtual std::set<std::string> const &specialities() const override;

  virtual IDoctor &setId(std::string_view id) override;
  virtual IDoctor &addSpeciality(std::string speciality) override;
  virtual IDoctor &removeSpeciality(std::string_view speciality) override;
};
}; // namespace doctors

#endif
