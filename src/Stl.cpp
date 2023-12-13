#include "Stl.hpp"
#include "Doctor.hpp"
#include "Pacient.hpp"

#include <iostream>
#include <map>
#include <queue>
#include <vector>

constexpr int k_hospitalOpenTime = 9;
constexpr int k_hospitalCloseTime = 17;

int Stl::task(std::istream &in, std::ostream &out) {
  int numProblems;
  in >> numProblems;

  std::priority_queue<Pacient> problemsQueue;
  for (int problemIdx = 0; problemIdx < numProblems; problemIdx++) {
    Pacient problem;
    in >> problem.name >> problem.speciality >> problem.arrivalHour >>
        problem.duration >> problem.priority;
    problemsQueue.push(problem);
  }

  int numDoctors;
  in >> numDoctors;

  std::map<std::string, Doctor> doctorsById;
  std::map<std::string, std::set<std::string>> doctorIdsBySpeciality;
  for (int doctorIdx = 0; doctorIdx < numDoctors; doctorIdx++) {
    Doctor doctor;
    in >> doctor.id;

    int numSpecialities;
    in >> numSpecialities;

    for (int idx = 0; idx < numSpecialities; idx++) {
      std::string speciality;
      in >> speciality;
      doctor.specialities.insert(speciality);

      doctorIdsBySpeciality[speciality].insert(doctor.id);
    }

    doctor.availableFromHour = k_hospitalOpenTime;

    doctorsById[doctor.id] = doctor;
  }

  // Solve
  while (!problemsQueue.empty()) {
    Pacient currentProblem = problemsQueue.top();
    problemsQueue.pop();

    // Find available doctor
    const auto &doctorsIt =
        doctorIdsBySpeciality.find(currentProblem.speciality);
    if (doctorsIt == doctorIdsBySpeciality.end())
      continue; // No doctor for this speciality

    const std::set<std::string> &doctorIdsSet = doctorsIt->second;
    for (const std::string &doctorId : doctorIdsSet) {
      Doctor &doctor = doctorsById[doctorId];

      if (doctor.availableFromHour <= currentProblem.arrivalHour &&
          currentProblem.arrivalHour + currentProblem.duration <=
              k_hospitalCloseTime) {
        // Assign problem to doctor
        doctor.availableFromHour =
            currentProblem.arrivalHour + currentProblem.duration;
        doctor.solvedProblems.push_back(currentProblem);
        break;
      }
    }
  }

  // Print output
  for (auto &doctorEntry : doctorsById) {
    Doctor &doctor = doctorEntry.second;
    if (doctor.solvedProblems.size() > 0) {
      std::cout << doctor.id << " " << doctor.solvedProblems.size() << " ";
      for (const Pacient &problem : doctor.solvedProblems)
        std::cout << problem.name << " " << problem.arrivalHour << " ";

      std::cout << std::endl;
    }
  }

  std::getchar();
  return 0;
}
