
# CAR_Timer Library Documentation

## Overview

The `CAR_Timer` library simplifies working with the `millis()` function on Arduino. It provides a convenient way to measure elapsed time and manage timers.

## Installation

To use the `CAR_Timer` library, include it in your project by copying the `CAR_Timer.h` file into your project's directory and include the header file in your sketch.

```cpp
#include "CAR_Timer.h"
```

## Class: `CAR_Timer`

### Constructors

#### `CAR_Timer()`

Initializes the timer with the current time from `millis()`.

```cpp
CAR_Timer timer;
```

#### `CAR_Timer(unsigned long val)`

Initializes the timer with the current time from `millis()` minus the specified value.

```cpp
CAR_Timer timer(1000); // Timer initialized 1000 ms ago
```

#### `CAR_Timer(const CAR_Timer &orig)`

Copy constructor that initializes the timer with the value from another `CAR_Timer` object.

```cpp
CAR_Timer timer1;
CAR_Timer timer2(timer1); // Copy constructor
```

### Operators

#### `operator unsigned long() const`

Returns the elapsed time in milliseconds since the timer was initialized.

```cpp
unsigned long elapsed = timer;
```

#### `CAR_Timer& operator=(const CAR_Timer &rhs)`

Assigns the value from another `CAR_Timer` object to this timer.

```cpp
CAR_Timer timer1;
CAR_Timer timer2;
timer2 = timer1;
```

#### `CAR_Timer& operator=(unsigned long val)`

Sets the timer to the current time minus the specified value.

```cpp
timer = 500; // Timer set to 500 ms ago
```

#### `CAR_Timer& operator-=(unsigned long val)`

Subtracts the specified value from the timer.

```cpp
timer -= 100; // Timer subtracted by 100 ms
```

#### `CAR_Timer& operator+=(unsigned long val)`

Adds the specified value to the timer.

```cpp
timer += 100; // Timer added by 100 ms
```

#### `template<typename T> CAR_Timer operator-(T val) const`

Returns a new `CAR_Timer` object with the specified value subtracted.

```cpp
CAR_Timer newTimer = timer - 100;
```

#### `template<typename T> CAR_Timer operator+(T val) const`

Returns a new `CAR_Timer` object with the specified value added.

```cpp
CAR_Timer newTimer = timer + 100;
```

## Usage Examples

### Example 1: Basic Timer Usage

This example demonstrates how to use the `CAR_Timer` class to measure elapsed time and perform an action every second.

```cpp
#include <CAR_Timer.h>

CAR_Timer timer;

void setup() {
    Serial.begin(9600);
}

void loop() {
    if (timer >= 1000) { // Check if 1000 ms (1 second) has passed
        Serial.println("One second has passed");
        timer = 0; // Reset the timer
    }
}
```

### Example 2: Timer with Initial Value

This example initializes the timer with an initial value of 1000 ms and checks the elapsed time.

```cpp
#include <CAR_Timer.h>

CAR_Timer timer(1000); // Timer initialized 1000 ms ago

void setup() {
    Serial.begin(9600);
}

void loop() {
    if (timer >= 2000) { // Check if 2000 ms (2 seconds) has passed since initialization
        Serial.println("Two seconds have passed since initialization");
        timer = 0; // Reset the timer
    }
}
```

### Example 3: Using Copy Constructor

This example demonstrates the use of the copy constructor to create a new `CAR_Timer` object from an existing one.

```cpp
#include <CAR_Timer.h>

CAR_Timer timer1;

void setup() {
    Serial.begin(9600);
    timer1 = 500; // Initialize timer1 with 500 ms
    CAR_Timer timer2(timer1); // Copy constructor
}

void loop() {
    if (timer1 >= 1000) {
        Serial.println("Timer1: One second has passed");
        timer1 = 0;
    }

    if (timer2 >= 1000) {
        Serial.println("Timer2: One second has passed");
        timer2 = 0;
    }
}
```

### Example 4: Assignment Operator

This example demonstrates the use of the assignment operator to set the value of one `CAR_Timer` object to another.

```cpp
#include <CAR_Timer.h>

CAR_Timer timer1;
CAR_Timer timer2;

void setup() {
    Serial.begin(9600);
    timer1 = 500; // Initialize timer1 with 500 ms
    timer2 = timer1; // Assignment operator
}

void loop() {
    if (timer1 >= 1000) {
        Serial.println("Timer1: One second has passed");
        timer1 = 0;
    }

    if (timer2 >= 1000) {
        Serial.println("Timer2: One second has passed");
        timer2 = 0;
    }
}
```

### Example 5: Timer Arithmetic

This example demonstrates how to use the arithmetic operators to create a new timer object with an adjusted value.

```cpp
#include <CAR_Timer.h>

CAR_Timer timer;

void setup() {
    Serial.begin(9600);
    timer = 500; // Initialize timer with 500 ms
}

void loop() {
    CAR_Timer newTimer = timer + 500; // New timer 500 ms ahead
    if (newTimer >= 1000) {
        Serial.println("NewTimer: One second has passed");
        newTimer = 0;
    }

    if (timer >= 1000) {
        Serial.println("Timer: One second has passed");
        timer = 0;
    }
}
```

