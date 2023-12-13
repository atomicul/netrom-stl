#ifndef EMERGENCIES_IEMERGENCY_HPP
#define EMERGENCIES_IEMERGENCY_HPP

#include <string>

namespace emergencies {
class IEmergency {
public:
  virtual std::string id() const = 0;
  virtual int arrivalHour() const = 0;
  virtual int leaveHour() const = 0;
  virtual int duration() const = 0;
  virtual int specialty() const = 0;
  virtual int priority() const = 0;

  virtual IEmergency &setId(std::string_view id) = 0;
  virtual IEmergency &setArrivalHour(int arrivalHour) = 0;
  virtual IEmergency &setLeaveHour(int leaveHour) = 0;
  virtual IEmergency &setSpecialty(int specialty) = 0;
  virtual IEmergency &setPriority(int priority) = 0;

  virtual bool operator<(const IEmergency &other) const = 0;

  virtual ~IEmergency() = default;
};
}; // namespace emergencies

#endif
