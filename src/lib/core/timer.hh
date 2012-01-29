/**
 * @file timer.hh
 * @brief Header file for the Timer class, which provides basic timekeeping
 * functionality, such as as start time and paused time.
 * @author Joshua Gwinn (jdgbolt@gmail.com)
 * @version 
 * @date 2012-01-29
 */

#ifndef _TIMER_HH_
#define _TIMER_HH_

class
Timer
{
 public:
    void 
       time_start();
    void 
       time_stop();
    void
       time_pause();
    void
       time_unpause();
    int
       time_ticks();
    bool
       time_started();
    bool
       time_paused();
 private:
    bool paused;
    bool started;
    int pausedTicks;
    int startTicks;
};

#endif
