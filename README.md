# AATR

A very basic library to read temperature from an analog sensor, the development is done
on top of a [KEYES temperature sensor](https://tkkrlab.nl/wiki/Arduino_KY-013_Temperature_sensor_module)

# Using

```cpp
#include "aatr.h"

AATR *sensor = new AATR(A0);

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("Celcius:\t");
  Serial.print(sensor->read()->getTmp('C'));
  Serial.print("\n");

  delay(500);
}
```

# License

The MIT License

Copyright (c) 2015 Ibán Domínguez, http://ibandominguez.com

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
