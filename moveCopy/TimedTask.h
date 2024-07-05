#ifndef Timed_task_h
#define Timed_task_h

#include <chrono>
#include <cstring>
#include <iostream>
#include <istream>

namespace sdds {

struct Task {
  std::string m_taskName{};
  std::string m_unitTime{};
  std::chrono::steady_clock::duration m_durationTask{};
};

class TimedTask {

public:
  TimedTask();
  TimedTask(const TimedTask &) = default;
  TimedTask &operator=(const TimedTask &) = default;
  ~TimedTask() = default;
  void startClock();
  void stopClock();
  void addTask(const char *);
  friend std::ostream &operator<<(std::ostream &, const TimedTask &);

private:
  int m_numRecords{};
  std::chrono::system_clock::time_point m_startTime{};
  std::chrono::system_clock::time_point m_endTime{};
  Task m_arrayTask[10]{};
};

} // namespace sdds
#endif // !Timed_task_h
