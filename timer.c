#include "timer.h"
#include "config.h"
#include <Arduino.h>  // für millis()

static uint32_t start_time = 0U;

void timer_start(void)
{
    start_time = millis();
}

bool timer_expired(void)
{
    /* millis() ist uint32_t, Subtraktion funktioniert auch bei Overflow */
    if ((millis() - start_time) >= GAME_TIME_MS)
    {
        return true;
    }
    else
    {
        return false;
    }
}
