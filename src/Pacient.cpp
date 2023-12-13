#include "Pacient.hpp"

bool Pacient::operator<(const Pacient &other) const {
  // Order by arrival hour, then priority, then duration
  if (arrivalHour != other.arrivalHour)
    return (arrivalHour > other.arrivalHour);

  if (priority != other.priority)
    return (priority < other.priority);

  return (duration > other.duration);
}
