#include "light.h"
#include "config.h"
#include <Arduino.h>


/* Initialisierung der LED-Pins */
void light_init(void)
{
    pinMode(LED_TOP_LEFT_PIN, OUTPUT);
    pinMode(LED_TOP_RIGHT_PIN, OUTPUT);
    pinMode(LED_BOTTOM_LEFT_PIN, OUTPUT);
    pinMode(LED_BOTTOM_RIGHT_PIN, OUTPUT);

    /* Alle LEDs aus */
    digitalWrite(LED_TOP_LEFT_PIN, LOW);
    digitalWrite(LED_TOP_RIGHT_PIN, LOW);
    digitalWrite(LED_BOTTOM_LEFT_PIN, LOW);
    digitalWrite(LED_BOTTOM_RIGHT_PIN, LOW);
}

/* Top Left */
void light_top_left(void)
{
    digitalWrite(LED_TOP_LEFT_PIN, HIGH);
}

void light_off_top_left(void)
{
    digitalWrite(LED_TOP_LEFT_PIN, LOW);
}

/* Top Right */
void light_top_right(void)
{
    digitalWrite(LED_TOP_RIGHT_PIN, HIGH);
}

void light_off_top_right(void)
{
    digitalWrite(LED_TOP_RIGHT_PIN, LOW);
}

/* Bottom Left */
void light_bottom_left(void)
{
    digitalWrite(LED_BOTTOM_LEFT_PIN, HIGH);
}

void light_off_bottom_left(void)
{
    digitalWrite(LED_BOTTOM_LEFT_PIN, LOW);
}

/* Bottom Right */
void light_bottom_right(void)
{
    digitalWrite(LED_BOTTOM_RIGHT_PIN, HIGH);
}

void light_off_bottom_right(void)
{
    digitalWrite(LED_BOTTOM_RIGHT_PIN, LOW);
}
