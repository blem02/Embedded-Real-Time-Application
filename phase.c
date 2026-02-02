phase_complete(), phase_check_hit(button_id), phase_start(), phase_any_pressed()

#include "phase.h"
#include <Arduino.h>   // nur für millis() / random(), kann später HAL sein
#include "config.h"

//MAX_BUTTONS


uint8_t phase_draw_num_buttons_to_light() {
        uint8_t r1 = random(0, 100);
        if (r1 < 70U)               // 0–69 → 70%
            num_buttons = 1U;
        else if (r1 < 90U)          // 70–89 → 20%
            num_buttons = 2U;
        else if (r1 < 97U)          // 90–96 → 7%
            num_buttons = 3U;
        else                       // 97–99 → 3%
            num_buttons = 4U;
    }

void phase_determine_buttons(uint8_t num_buttons_to_light) {
 //mach das nach mustern
    
}