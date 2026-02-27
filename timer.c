// ==================== TIMER ====================
// Requirements: REQ-GAME-TIME: Das Spiel soll nach x Sekunden enden
static uint32_t start_time = 0U;


void timer_start() {
    start_time = millis();
  	Serial.println("timer started");
}

bool timer_expired() {
    return (millis() - start_time) >= GAME_TIME_MS;
}
