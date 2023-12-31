#include "Timer.hpp"

Timer::Timer(TimerFunctionPtr timer_function)
{
  this->timer = 0;
  this->time_f_ptr = timer_function;
}

void Timer::updateTimer()
{
  this->timer = this->time_f_ptr();
}

const uint64_t& Timer::getTimer() const
{
  return this->timer;
}

bool Timer::operator()(const uint64_t& interval, const bool& auto_update_timer)
{
  bool result = this->time_f_ptr() - this->timer >= interval;
  if (result && auto_update_timer) this->resetTimer();
  return result;
}
