// ==================== GAME ====================
// Requirements: 
    // REQ-GAME-TIME: Spiel beendet nach x Sekunden
    // REQ-GAME-HIT, REQ-PHASE: Lampe geht aus bei hit, wenn alle aus => Phase complete
    // REQ-INIT: Noch nicht erledigt, aber leicht nachreichbar
    // REQ-IDLE: Bei Knopfdruck initialisieren


typedef enum {  GAME_STATE_IDLE, 
                GAME_STATE_INIT, 
                GAME_STATE_RUNNING, 
                GAME_STATE_FINISHED 
                } game_state_t;
                
static game_state_t game_state = GAME_STATE_IDLE;
static uint8_t game_score = 0;
static button_id_t update_button = BUTTON_NONE;


void game_init() {
    game_state = GAME_STATE_INIT;
    game_score = 0;
    timer_start();
    phase_start();
    game_state = GAME_STATE_RUNNING;
}

void game_finished() {
    display_score(game_score);
    uint32_t start = millis();
    while (millis() - start < GAME_FINISHED_WAIT_MS) { /* nur warten */ }
    phase_reset();
    game_score = 0;
    game_state = GAME_STATE_IDLE;
}

void game_update() {
    switch(game_state) {
        case GAME_STATE_IDLE:
      		if (phase_any_pressed() != BUTTON_NONE) {
       			game_init();
              	Serial.print("Button ");
              	Serial.print(phase_any_pressed());
              	Serial.println(" hat das Spiel initialisiert");
            }
            break;
        case GAME_STATE_RUNNING:
            if (timer_expired()) {
                game_state = GAME_STATE_FINISHED;
            }
            else if (phase_complete()) {
                game_score += GAME_HIT; 
                phase_start();
            }
            else {
                update_button = phase_any_pressed();
                if (update_button != BUTTON_NONE) 
                 	phase_check_hit(update_button);
            }
            break;
        case GAME_STATE_FINISHED:
            game_finished();
            break;
    }
}
