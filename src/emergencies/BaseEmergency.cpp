#include "emergencies/BaseEmergency.hpp"
#include "emergencies/IEmergency.hpp"

using namespace emergencies;

BaseEmergency::BaseEmergency(std::string_view id, int arrivalHour,
                             int leaveHour, std::string_view specialty,
                             int priority)
    : _id(id), _arrivalHour(arrivalHour), _leaveHour(leaveHour),
      _specialty(specialty), _priority(priority) {}

std::string const &BaseEmergency::id() const { return _id; }
int BaseEmergency::arrivalHour() const { return _arrivalHour; }
int BaseEmergency::leaveHour() const { return _leaveHour; }
int BaseEmergency::duration() const { return _leaveHour - _arrivalHour; }
std::string const &BaseEmergency::specialty() const { return _specialty; }
int BaseEmergency::priority() const { return _priority; }

BaseEmergency &BaseEmergency::setId(std::string_view id) {
  _id = id;
  return *this;
}
BaseEmergency &BaseEmergency::setArrivalHour(int arrivalHour) {
  _leaveHour += arrivalHour - _arrivalHour;
  _arrivalHour = arrivalHour;
  return *this;
}
BaseEmergency &BaseEmergency::setDuration(int duration) {
  _leaveHour = _arrivalHour + duration;
  return *this;
}
BaseEmergency &BaseEmergency::setSpecialty(std::string_view specialty) {
  _specialty = specialty;
  return *this;
}
BaseEmergency &BaseEmergency::setPriority(int priority) {
  _priority = priority;
  return *this;
}

bool BaseEmergency::operator<(IEmergency const &other) const {
  if (this->arrivalHour() != other.arrivalHour())
    return this->arrivalHour() < other.arrivalHour();
  return this->priority() < other.priority();
}
