#include "button.h"
#include "config.h"
#include <Arduino.h>

bool button_pressed(button_id_t button_id)
{
    bool pressed = false;

    switch (button_id)
    {
        case BUTTON_TOP_LEFT:
            pressed = (digitalRead(BUTTON_TOP_LEFT_PIN) == LOW);
            break;

        case BUTTON_TOP_RIGHT:
            pressed = (digitalRead(BUTTON_TOP_RIGHT_PIN) == LOW);
            break;

        case BUTTON_BOTTOM_LEFT:
            pressed = (digitalRead(BUTTON_BOTTOM_LEFT_PIN) == LOW);
            break;

        case BUTTON_BOTTOM_RIGHT:
            pressed = (digitalRead(BUTTON_BOTTOM_RIGHT_PIN) == LOW);
            break;

        default:
            //ungültige ID → nicht gedrückt
            pressed = false;
            break;
    }

    return pressed;
}
