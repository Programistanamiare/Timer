#include "Timer.hpp"


#define T1_INTERVAL 100
#define T2_INTERVAL 500

// for using MILLIS as time controller
Timer t1(millis);

// for using MICROS as time controller
Timer t2(micros);

void setup()
{
  Serial.begin(9600);
  t1.resetTimer();
  t2.resetTimer();
  Serial.println("Timers begin").
}

void loop()
{
  if ( t1(T1_INTERVAL) )
  {
    Serial.println("Timer 1 has counted.");
    t1.resetTimer();
  }

  if ( t2(T2_INTERVAL, true) )
  {
    Serial.println("Timer 2 has counted, and auto reset timer.");
  }
  
}