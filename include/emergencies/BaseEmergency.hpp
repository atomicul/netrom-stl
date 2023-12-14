#ifndef EMERGENCIES_BASEEMERGENCY_HPP
#define EMERGENCIES_BASEEMERGENCY_HPP

#include "emergencies/IEmergency.hpp"

class BaseEmergency : public emergencies::IEmergency {
protected:
  std::string _id;
  int _arrivalHour;
  int _leaveHour;
  std::string _specialty;
  int _priority;

public:
  BaseEmergency() = default;
  BaseEmergency(std::string_view id, int arrivalHour, int leaveHour,
                std::string_view specialty, int priority);
  std::string const &id() const override;
  int arrivalHour() const override;
  int leaveHour() const override;
  int duration() const override;
  std::string const &specialty() const override;
  int priority() const override;

  BaseEmergency &setId(std::string_view id) override;
  BaseEmergency &setArrivalHour(int arrivalHour) override;
  BaseEmergency &setDuration(int duratior) override;
  BaseEmergency &setSpecialty(std::string_view specialty) override;
  BaseEmergency &setPriority(int priority) override;

  bool operator<(emergencies::IEmergency const &other) const override;
  virtual ~BaseEmergency() = default;
};

#endif
