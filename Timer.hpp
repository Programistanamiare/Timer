#pragma once

#include <Arduino.h>
#include "time_utility.hpp"

class Timer
{
public:
  
  /**
    * Timer class constructor. The object is used to react in the program at a certain time.
    * @param time_function pointer to the function that will be used to measure the time. By default, "millis".
   */
  Timer(TimerFunctionPtr timer_function = millis);

  /**
    * Component function update the time parameter.
   */
  void updateTimer();

  /**
    * A component function that returns the current value of the time parameter.
   */
  const uint64_t& getTimer() const;

  /**
    * Call operator overloads, every given time interval returns true.
    * @param interval time interval
    * @param auto_reset_timer setting it to true resets the timer automatically.
    * @return returns true when the time specified as the argument has elapsed since the last reset of the counter.
   */
  bool operator()(const uint64_t& interval, const bool& auto_update_timer = false);

private:
  uint64_t timer;
  TimerFunctionPtr time_f_ptr;
};

