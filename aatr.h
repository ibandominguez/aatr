/**
 * AATR
 *
 * @author    Ibán Domínguez <ibandominguez@hotmail.com>
 * @copyright 2015 Ibán Domínguez (http://www.ibandominguez.com)
 * @license   http://www.opensource.org/licenses/mit-license.php MIT
 * @link      https://github.com/ibandominguez/aatr
 */
 
#ifndef AATR_H
#define AATR_H

class AATR {
  public:
    /**
     * AATR Constructor
     * Sets the pin for analog reading
     * @param int
     * @return void
     */
    AATR(int pin = A0);

    /**
     * ATTR::read
     * Reads the value from the pin and sets it to the pin private property
     * @return ATTR *
     */
    AATR *read();

    /**
     * ATTR::getTmp
     * Retrieves a temperature in a given format [c|C, k|K, f|F]
     * @param char
     * @return float
     */
    double getTmp(char format = 'C');

  private:
    int pin;
    int readValue;

    /**
     * ATTR::toKelvin
     * Converts a integer given from the analog read to kelvin
     * @param int
     * @return double
     */
    double toKelvin(int value);

    /**
     * ATTR::toCelcius
     * Converts a integer given from the analog read to Celcius
     * @param int
     * @return double
     */
    double toCelcius(int value);

    /**
     * ATTR::toFahrenheit
     * Converts a integer given from the analog read to Fahrenheit
     * @param int
     * @return double
     */
    double toFahrenheit(int value);
};

#endif
