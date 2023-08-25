# Arduino Timer v1.0.0

The library is used to simple **non blocking** control the instruction execution **time interval** in a program written in the **Arduino framework**.

## Instalation

To get this library you can clone it from repo:
``` 
git clone "https://github.com/Programistanamiare/Timer.git"
```
with included **examples** or take only header file with interface from <a href="https://github.com/Programistanamiare/Timer.git">here</a>.

## How to use
```
#include "Timer.hpp"

Timer t; // constructor
int x = 0;
t.updateTimer(); // update time
usnigned long time = t.getTimer(); // get last update time
if ( t(100) )
{
  x++;
  t.updateTimer();
}

```


## Example

```
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

```

## Documentation
* ```Timer::Timer(unsigned long(*fun_ptr)(void) timer_function_reference = millis)``` constructor get reference to time function like **millis** or **micros**.
* ```void Timer::updateTimer() ``` component function to update internal timer propertie according to time function given in the class constructor.
* ```const uint64_t Timer::getTimer() const ``` constant component function to get time value from last **updateTimer()** function call.
* ```bool Timer::operator() (const uint64_t& interval, const bool& auto_update_timer) ``` operator overload to get, when **current time - last update time >= interval**. Additional argument setted on <i>true</i> update timer after overload interval.
