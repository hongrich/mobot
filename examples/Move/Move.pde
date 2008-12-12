#include <Mobot.h>

/* E1, E2, I1, I2, I3, I4 */
Mobot mobot(13,8,11,12,9,10);

void setup() {

}

void loop() {
  mobot.forward(128);
  delay(1000);                  // waits for a second
  mobot.stop();
  delay(1000);                  // waits for a second
  mobot.turnLeft();
  delay(1000);                  // waits for a second
  mobot.stop();
  delay(1000);
}

