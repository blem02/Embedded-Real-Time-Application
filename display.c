#include "display.h"
#include <Arduino.h>

void display_score(uint8_t score)
{
    Serial.print("Score: ");
    Serial.println(score);
}
