#ifndef PHASE_H
#define PHASE_H

typedef enum
{
    BUTTON_NONE = 0,
    BUTTON_TOP_LEFT,
    BUTTON_TOP_RIGHT,
    BUTTON_BOTTOM_LEFT,
    BUTTON_BOTTOM_RIGHT
} button_id_t;

void phase_start(void);
uint8_t phase_draw_num_buttons_to_light(void);
void phase_determine_buttons(uint8_t num_buttons_to_light);
void phase_reset(void);
bool phase_check_hit(uint8_t button_id);
bool phase_complete(void);
button_id_t phase_any_pressed(void);


#endif