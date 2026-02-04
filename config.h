// Requirements: REQ-GAME-TIME, REQ-GAME-HIT, REQ-GAME-MISS, REQ-PHASE-PROB
// Diese Konfig bestimmt Konstanten zur Bestimmung der Spiellänge, des Score und der Wahrscheinlichkeiten von Lampenaufleuchten

#ifndef CONFIG_H
#define CONFIG_H

                                // xU für unsigned integer, (x) zur Klarheit kompilerlogik
#define GAME_TIME_MS (30000U)         //Millisekunden Spielzeit
#define GAME_FINISHED_WAIT_MS 5000U

#define GAME_HIT (1U)           //Punkt pro Hit

#define GAME_LOWEST_SCORE (0U)






#endif //CONFIG_H