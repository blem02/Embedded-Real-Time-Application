// ==================== SETUP / LOOP ====================

#include <Arduino.h>
#include "config.h" //für button_ver_hor_pin
#include "game.h"   //für game_update
#include "light.h"  //für light_init

void setup() {
    Serial.begin(9600);

    pinMode(BUTTON_TOP_LEFT_PIN, INPUT_PULLUP);
    pinMode(BUTTON_TOP_RIGHT_PIN, INPUT_PULLUP);
    pinMode(BUTTON_BOTTOM_LEFT_PIN, INPUT_PULLUP);
    pinMode(BUTTON_BOTTOM_RIGHT_PIN, INPUT_PULLUP);

    light_init();
    randomSeed(analogRead(A0)); // Zufall initialisieren
}

void loop() {
    game_update();
    
}

