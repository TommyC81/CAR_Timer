/////////////////////////////////////////////////////////////////
/*
    CAR_Timer.h - Arduino Library to simplify working with millis.	
    Created by Tommy Carlsson.
	
	Initial code derived from https://github.com/pfeerick/elapsedMillis
*/
/////////////////////////////////////////////////////////////////

#pragma once

#include <Arduino.h>

/////////////////////////////////////////////////////////////////

class CAR_Timer {
  private:
    unsigned long ms;
  public:
    CAR_Timer() : ms(millis()) {}
    CAR_Timer(unsigned long val) : ms(millis() - val) {}
    CAR_Timer(const CAR_Timer &orig) : ms(orig.ms) {}

    operator unsigned long() const { return millis() - ms; }

    CAR_Timer& operator=(const CAR_Timer &rhs) { 
        if (this != &rhs) ms = rhs.ms; 
        return *this; 
    }

    CAR_Timer& operator=(unsigned long val) { 
        ms = millis() - val; 
        return *this; 
    }

    CAR_Timer& operator-=(unsigned long val) { 
        ms += val; 
        return *this; 
    }

    CAR_Timer& operator+=(unsigned long val) { 
        ms -= val; 
        return *this; 
    }

    template<typename T>
    CAR_Timer operator-(T val) const {
        CAR_Timer r(*this); 
        r.ms += val; 
        return r; 
    }

    template<typename T>
    CAR_Timer operator+(T val) const {
        CAR_Timer r(*this); 
        r.ms -= val; 
        return r; 
    }
};
