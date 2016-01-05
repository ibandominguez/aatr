/**
 * AATR
 *
 * @author    Ibán Domínguez <ibandominguez@hotmail.com>
 * @copyright 2015 Ibán Domínguez (http://www.ibandominguez.com)
 * @license   http://www.opensource.org/licenses/mit-license.php MIT
 * @link      https://github.com/ibandominguez/aatr
 */

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
