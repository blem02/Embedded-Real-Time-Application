// ==================== DISPLAY ====================
// Requirements: REQ-SCORE: Punktestand wird ausgegeben

void display_score(uint8_t score) {
    Serial.println("========================");
    Serial.print("Score: ");
    Serial.println(score);
}
