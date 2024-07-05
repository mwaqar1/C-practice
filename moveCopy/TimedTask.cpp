#include "TimedTask.h"
#include <iomanip>

namespace sdds {

TimedTask::TimedTask()
    : m_numRecords{}, m_startTime{}, m_endTime{}, m_arrayTask(){};

void TimedTask::startClock() { m_startTime = std::chrono::system_clock::now(); }

void TimedTask::stopClock() { m_endTime = std::chrono::system_clock::now(); }

void TimedTask::addTask(const char *passed_name) {

  if (passed_name) {

    // check to make sure passed_name array has a null terminator at the end of
    // the string and if number of records is less than the max size of 10

    if (m_numRecords < 10) {
      m_arrayTask[m_numRecords].m_taskName = passed_name;
      m_arrayTask[m_numRecords].m_unitTime = "nanoseconds";
      m_arrayTask[m_numRecords].m_durationTask =
          std::chrono::duration_cast<std::chrono::nanoseconds>(m_endTime -
                                                               m_startTime);

      m_numRecords++; // increment num of records after populating array
    }
  }
}

std::ostream &operator<<(std::ostream &os, const TimedTask &passedTask) {
  os << "--------------------------" << std::endl;
  os << "Execution Times:" << std::endl;
  os << "--------------------------" << std::endl;

  for (int i = 0; i < passedTask.m_numRecords; i++) {
    os << std::left << std::setw(22) << passedTask.m_arrayTask[i].m_taskName;
    os << std::right << std::setw(13)
       << passedTask.m_arrayTask[i].m_durationTask.count();
    os << " " << passedTask.m_arrayTask[i].m_unitTime << std::endl;
  }

  os << "--------------------------" << std::endl;
  return os;
}
} // namespace sdds
