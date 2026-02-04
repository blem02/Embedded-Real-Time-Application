// Requirements: REQ-IDLE, REQ-INIT, REQ-GAME-HIT, REQ-GAME-MISS, REQ-PHASE
// Schnittstelle für game.c. Hier werden GAME_STATEs definiert und die dazugehörenden funktionen angebunden

#ifndef GAME_H
#define GAME_H

#include <stdint.h>

typedef enum
{
    GAME_STATE_IDLE,
    GAME_STATE_INIT,
    GAME_STATE_RUNNING,
    GAME_STATE_FINISHED
} game_state_t;

typedef enum
{
    ERROR_GAME_START_INVALID_STATE = 1,
    ERROR_GAME_UPDATE_INVALID_STATE = 2,
    ERROR_GAME_BUTTON_PRESSED_INVALID_STATE = 3
    //expand in future
} error_t;

void report_error(error_t code);

// Interface
void game_init(void);
void game_update(void);
void game_finished(void);
void game_button_pressed(button_id_t button_id);

game_state_t game_get_state(void);
uint8_t game_get_score(void);

#endif