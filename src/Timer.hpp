#pragma once

#include <Arduino.h>
#include "time_utility.hpp"

class Timer
{
public:
  
  /**
   * Konstruktor klasy Timer. Obiekt służy do reagowania w programie co określony czas.
   * @param time_function wskaźnik do funkcji, która będzie wykorzystywana do odmierzania czasu. Domyślnie "millis".
  */
  Timer(TimerFunctionPtr timer_function = millis);

  /**
   * Funkcja składowa resetująca parametr czasu.
  */
  void resetTimer();

  /**
   * Funkcja składowa zwracająca aktualną wartość parametru czasu.
  */
  const uint64_t& getTimer() const;

  /**
   * Przeciążenia operatora wywołania, co zadany interwał czasu zwraca wartość true.
   * @param interval interwał czasowy
   * @param auto_reset_timer ustawienie go na wartość true powoduje automatyczne zresetowanie licznika.
   * @return zwraca true gdy upłynął czas podany jako argument od ostatniego resetu licznika.
  */
  bool operator()(const uint64_t& interval, const bool& auto_reset_timer = false);

private:
  uint64_t timer;
  TimerFunctionPtr time_f_ptr;
};

