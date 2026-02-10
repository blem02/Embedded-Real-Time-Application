// ==================== BUTTONS ====================
// Requirements: 
    //REQ-IDLE: Knopfdruck registrieren zum Initialisieren des Spiels 
    //REQ-GAME-HIT, REQ-GAME-MISS: Knopfdruck registrieren, um game score anzupassen

#inlcude "config.h" //für button_id_t und button_ver_hor_pin

bool button_pressed(button_id_t button_id) {
    switch(button_id) {
        case BUTTON_TOP_LEFT: 
            return digitalRead(BUTTON_TOP_LEFT_PIN) == LOW;
        case BUTTON_TOP_RIGHT: 
      		return digitalRead(BUTTON_TOP_RIGHT_PIN) == LOW;
        case BUTTON_BOTTOM_LEFT: 
            return digitalRead(BUTTON_BOTTOM_LEFT_PIN) == LOW;
        case BUTTON_BOTTOM_RIGHT: 
            return digitalRead(BUTTON_BOTTOM_RIGHT_PIN) == LOW;
        default: 
            return false;
    }
}

button_id_t phase_any_pressed() {
  	if (button_pressed(BUTTON_TOP_LEFT)) return BUTTON_TOP_LEFT;
  	if (button_pressed(BUTTON_TOP_RIGHT)) return BUTTON_TOP_RIGHT;
    if (button_pressed(BUTTON_BOTTOM_LEFT)) return BUTTON_BOTTOM_LEFT;
    if (button_pressed(BUTTON_BOTTOM_RIGHT)) return BUTTON_BOTTOM_RIGHT;
    return BUTTON_NONE;
}

