//Noch zu erledigen
//für timer: timer_start() und timer_expired
//phase_complete(), phase_check_hit(button_id), phase_start()
//display_score(game_score);

#include "game.h"
#include "config.h"
#include "timer.h"
#include "phase.h"
#include "display.h"
#include <Arduino.h>

static game_state_t game_state = GAME_STATE_IDLE;
static uint8_t game_score = GAME_LOWEST_SCORE;


void game_init(void) {
    game_state = GAME_STATE_INIT;
    //low priority: init_lightshow();
    game_score = GAME_LOWEST_SCORE;
    timer_start();
    phase_start();
    game_state = GAME_STATE_RUNNING;
}

void game_start(void) {
    if (game_state == GAME_STATE_IDLE){
        game_init();
    }
    else {
        report_error(ERROR_GAME_START_INVALID_STATE);
    }
}

void game_update(void) {

    if (game_state == GAME_STATE_RUNNING) {
        if (timer_expired()) {
            game_state = GAME_STATE_FINISHED;
        }
        else if (phase_complete()){
             phase_start();
        }
        else {
                //Lasse phase zuende laufen, keine Aktion nötig
        }
    }
    else {
        report_error(ERROR_GAME_UPDATE_INVALID_STATE); 

    }   
}

void game_finished(void) {
    // Score anzeigen 
    display_score(game_score);

    // 5 Sekunden anzeigen
    uint32_t start_time = millis();
    while ((millis() - start_time) < GAME_FINISHED_WAIT_MS)
    {
        //low priority, lightshow ähnlich zu init ergänzen, sonst keine Aktion nötig
    }

    //LED ausschalten
    phase_reset();
    // Spiel zurücksetzen 

    game_score = GAME_LOWEST_SCORE;
    game_state = GAME_STATE_IDLE;

}

void game_button_pressed(uint8_t button_id) {
    if (game_state != GAME_STATE_RUNNING) {
        report_error(ERROR_GAME_BUTTON_PRESSED_INVALID_STATE);
        return;
    }

    if (phase_check_hit(button_id)) {
        game_score += GAME_HIT;
    }
    else {
        if (game_score > GAME_LOWEST_SCORE) {
            game_score -= GAME_HIT;
        }
        else {
            //belasse punktstand, keine aktion nötig
        }
    }
}

void report_error(error_t code) {
    switch(code) {
        case ERROR_GAME_START_INVALID_STATE:
            Serial.println("ERROR: Game start invalid state");
            break;
        case ERROR_GAME_UPDATE_INVALID_STATE:
            Serial.println("ERROR: Game update invalid state");
            break;
        case ERROR_GAME_BUTTON_PRESSED_INVALID_STATE:
            Serial.println("ERROR: Game button pressed invalid state");
            break;
        default: 
            Serial.println("UNKNOWN ERROR");
            break;

    }
}

game_state_t game_get_state(void) {
    return game_state;
}
uint8_t game_get_score(void) {
    return game_score;
}
