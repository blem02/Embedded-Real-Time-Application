#include <Arduino.h>

#include "button.h"
#include "config.h"
#include "display.h"
#include "game.h"
#include "light.h"
#include "phase.h"
#include "timer.h"

void setup(void) {
    Serial.begin(9600);

    pinMode(BUTTON_TOP_LEFT_PIN,     INPUT_PULLUP);
    pinMode(BUTTON_TOP_RIGHT_PIN,    INPUT_PULLUP);
    pinMode(BUTTON_BOTTOM_LEFT_PIN,  INPUT_PULLUP);
    pinMode(BUTTON_BOTTOM_RIGHT_PIN, INPUT_PULLUP);

    light_init(); // LEDs aus
}

void loop(void) {
    game_update();
    delay(5);
}