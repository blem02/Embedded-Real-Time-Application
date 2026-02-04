


#include "phase.h"
#include <Arduino.h>   // nur für millis() / random(), kann später HAL sein
#include "config.h"
#include "light.h"
#include "game.h"

static bool light_top_left_on = false;
static bool light_top_right_on = false;
static bool light_bottom_left_on = false;
static bool light_bottom_right_on = false;

static bool any_button_pressed = false;

void phase_start(void) {
    phase_reset();
    uint8_t num_buttons_to_light = phase_draw_buttons_to_light();
    phase_determine_buttons(num_buttons_to_light);
}

uint8_t phase_draw_num_buttons_to_light(void) {
        uint8_t r1 = random(0, 100);
        if (r1 < 70U)               // 0–69 → 70%
            return 1U;
        else if (r1 < 90U)          // 70–89 → 20%
            return 2U;
        else if (r1 < 97U)          // 90–96 → 7%
            return 3U;
        else                       // 97–99 → 3%
            return 4U;
    }

void phase_determine_buttons(uint8_t num_buttons_to_light) {
 //mach das nach mustern
    uint8_t r2 = random(0, 4);
    switch(num_buttons_to_light) {
        case 1:
            if (r2 == 0) {
                light_top_left();
                light_top_left_on = true;
            }
            else if (r2 == 1) {
                light_top_right();
                light_top_right_on = true;
            }
            else if (r2 == 2) {
                light_bottom_left();
                light_bottom_left_on = true;
            }
            else if (r2 == 3) {
                light_bottom_right();
                light_bottom_right_on = true;
            }
            else {
                report_error(ERROR_PHASE_DETERMINE_BUTTONS);
            }
            break;
        case 2:
            if (r2 == 0)
                //light_two_left
                light_top_left();
                light_bottom_left();
                light_top_left_on = true;
                light_bottom_left_on = true;
            else if (r2 == 1)
                //light_two_right
                light_top_right();
                light_bottom_right();
                light_top_right_on = true;
                light_bottom_right_on = true;
            else if (r2 == 2)
                //light_two_top
                light_top_left();
                light_top_right();
                light_top_left_on = true;
                light_top_right_on = true;
            else if (r2 == 3)
                //light_two_bottom
                light_bottom_left();
                light_bottom_right();
                light_bottom_left_on = true;
                light_bottom_right_on = true;
            else {
                report_error(ERROR_PHASE_DETERMINE_BUTTONS);
            }
            break;
        case 3:
            if (r2 == 0)
                //light_all_except_top_left
                light_top_right();
                light_bottom_left();
                light_bottom_right();

                light_top_right_on = true;
                light_bottom_left_on = true;
                light_bottom_right_on = true;
            else if (r2 == 1)
                //light_all_except_top_right
                light_top_left();
                light_bottom_left();
                light_bottom_right();

                light_top_left_on = true;
                light_bottom_left_on = true;
                light_bottom_right_on = true;
            else if (r2 == 2)
                //light_all_except_bottom_left
                light_top_left();
                light_top_right();
                light_bottom_right();

                light_top_left_on = true;
                light_top_right_on = true;
                light_bottom_right_on = true;
            else if (r2 == 3)
                //light_all_except_bottom_right
                light_top_left();
                light_top_right();
                light_bottom_left();

                light_top_left_on = true;
                light_top_right_on = true;
                light_bottom_left_on = true;
            else {
                report_error(ERROR_PHASE_DETERMINE_BUTTONS);
            }
            break;
        case 4:
            light_top_left();
            light_top_right();
            light_bottom_left();
            light_bottom_right();

            light_top_left_on = true;
            light_top_right_on = true;
            light_bottom_left_on = true;
            light_bottom_right_on = true;
            break;
        default:
            report_error(ERROR_PHASE_DETERMINE_BUTTONS);
            break;
    }
}

//turns all lights off
void phase_reset(void) {
    light_off_top_left();
    light_off_top_right();
    light_off_bottom_left();
    light_off_bottom_right();

    light_top_left_on = false;
    light_top_right_on = false;
    light_bottom_left_on = false;
    light_bottom_right_on = false;
}

//wird von game_button_pressed aufgerufen, um zu prüfen ob hit war
bool phase_check_hit(button_id_t button_id) {
    bool hit = false;

    switch (button_id) {
        case BUTTON_TOP_LEFT:
            if (light_top_left_on == true) {
                light_top_left_on = false;
                light_off_top_left();
                hit = true;
            }
            break;

        case BUTTON_TOP_RIGHT:
            if (light_top_right_on == true) {
                light_top_right_on = false;
                light_off_top_right();
                hit = true;
            }
            break;

        case BUTTON_BOTTOM_LEFT:
            if (light_bottom_left_on == true) {
                light_bottom_left_on = false;
                light_off_bottom_left();
                hit = true;
            }
            break;

        case BUTTON_BOTTOM_RIGHT:
            if (light_bottom_right_on == true) {
                light_bottom_right_on = false;
                light_off_bottom_right();
                hit = true;
            }
            break;

        default:
            report_error(ERROR_PHASE_INVALID_BUTTON); 
            break;
    }

    return hit;
}


bool phase_complete(void) {
    if ((light_top_left_on == true) ||
        (light_top_right_on == true) ||
        (light_bottom_left_on == true) ||
        (light_bottom_right_on == true))
    {
        return false;   /* Mindestens eine Lampe ist noch an */
    }
    else
    {
        return true;    /* Alle Lampen sind aus → Phase beendet */
    }
}

button_id_t phase_any_pressed(void)
{
    if (button_pressed(BUTTON_TOP_LEFT) == true)
    {
        return BUTTON_TOP_LEFT;
    }
    if (button_pressed(BUTTON_TOP_RIGHT) == true)
    {
        return BUTTON_TOP_RIGHT;
    }
    if (button_pressed(BUTTON_BOTTOM_LEFT) == true)
    {
        return BUTTON_BOTTOM_LEFT;
    }
    if (button_pressed(BUTTON_BOTTOM_RIGHT) == true)
    {
        return BUTTON_BOTTOM_RIGHT;
    }

    return BUTTON_NONE;
}
