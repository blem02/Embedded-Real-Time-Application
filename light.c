// ==================== LIGHT ====================
// Requirement: REQ-PHASE: Lampen leuchten auf
void light_init() {
    pinMode(LED_TOP_LEFT_PIN, OUTPUT);
    pinMode(LED_TOP_RIGHT_PIN, OUTPUT);
    pinMode(LED_BOTTOM_LEFT_PIN, OUTPUT);
    pinMode(LED_BOTTOM_RIGHT_PIN, OUTPUT);

    digitalWrite(LED_TOP_LEFT_PIN, LOW);
    digitalWrite(LED_TOP_RIGHT_PIN, LOW);
    digitalWrite(LED_BOTTOM_LEFT_PIN, LOW);
    digitalWrite(LED_BOTTOM_RIGHT_PIN, LOW);
}

void light_top_left() { 
    digitalWrite(LED_TOP_LEFT_PIN, HIGH); 
}
void light_off_top_left() {
    digitalWrite(LED_TOP_LEFT_PIN, LOW); 
}
void light_top_right() { 
    digitalWrite(LED_TOP_RIGHT_PIN, HIGH); 
}
void light_off_top_right() { 
    digitalWrite(LED_TOP_RIGHT_PIN, LOW); 
}
void light_bottom_left() { 
    digitalWrite(LED_BOTTOM_LEFT_PIN, HIGH); 
}
void light_off_bottom_left() { 
    digitalWrite(LED_BOTTOM_LEFT_PIN, LOW); 
}
void light_bottom_right() { 
    digitalWrite(LED_BOTTOM_RIGHT_PIN, HIGH); 
}
void light_off_bottom_right() { 
    digitalWrite(LED_BOTTOM_RIGHT_PIN, LOW); 
}

