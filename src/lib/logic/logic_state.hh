/* Copyright (C) 
 * 2012 - Joshua Gwinn (jdgbolt@gmail.com)
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 * 
 */

#ifndef _LOGIC_STATE_HH_
#define _LOGIC_STATE_HH_

/**
 * @file logic_state.hh
 * @brief Header file for the LogicState class, the base class for the logic
 * module of all states.
 * @author Joshua Gwinn (jdgbolt@gmail.com)
 * @version 
 * @date 2012-01-29
 */

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
