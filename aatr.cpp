/**
 * AATR
 *
 * @author    Ibán Domínguez <ibandominguez@hotmail.com>
 * @copyright 2015 Ibán Domínguez (http://www.ibandominguez.com)
 * @license   http://www.opensource.org/licenses/mit-license.php MIT
 * @link      https://github.com/ibandominguez/aatr
 */

#include <math.h>
#include "Arduino.h"
#include "aatr.h"

/**
 * AATR Constructor
 * Sets the pin for analog reading
 * @param int
 * @return void
 */
AATR::AATR(int pin) {
  this->pin = pin;
}

/**
 * ATTR::read
 * Reads the value from the pin and sets it to the pin private property
 * @return ATTR *
 */
AATR *AATR::read() {
  this->readValue = analogRead(this->pin);

  return this;
}

/**
 * ATTR::getTmp
 * Retrieves a temperature in a given format [c|C, k|K, f|F]
 * @param char
 * @return float
 */
double AATR::getTmp(char format) {
  if (format == 'K' || format == 'k') return this->toKelvin(this->readValue);
  else if (format == 'F' || format == 'f') return this->toFahrenheit(this->readValue);
  else return this->toCelcius(this->readValue);
}

/**
 * ATTR::toKelvin
 * Converts a integer given from the analog read to kelvin
 * @param int
 * @return double
 */
double AATR::toKelvin(int value) {
  double temp;
  temp = log(10000.0 * ((1024.0 / value - 1)));
  temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * temp * temp )) * temp);

  return temp;
}

/**
 * ATTR::toCelcius
 * Converts a integer given from the analog read to Celcius
 * @param int
 * @return double
 */
double AATR::toCelcius(int value) {
  double temp;
  temp = this->toKelvin(value);
  temp = temp - 273.15;

  return temp;
}

/**
 * ATTR::toFahrenheit
 * Converts a integer given from the analog read to Fahrenheit
 * @param int
 * @return double
 */
double AATR::toFahrenheit(int value) {
  double temp;
  temp = this->toCelcius(value);
  temp = (temp * 9.0)/ 5.0 + 32.0;

  return temp;
}
