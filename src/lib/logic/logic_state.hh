/**
 * @file logic_state.hh
 * @brief Header file for the LogicState class, the base class for the logic
 * module of all states.
 * @author Joshua Gwinn (jdgbolt@gmail.com)
 * @version 
 * @date 2012-01-29
 */

#ifndef _LOGIC_STATE_HH_
#define _LOGIC_STATE_HH_

#include "impact.hh"

class
LogicState
{
 public:
    virtual ErrorReturn
       init() = 0;
    virtual ErrorReturn
       cleanup() = 0;
    virtual
       ~LogicState() {};
};

#endif
