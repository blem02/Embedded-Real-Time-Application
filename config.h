// Requirements: REQ-GAME-TIME, REQ-GAME-HIT, REQ-GAME-MISS, REQ-PHASE-PROB
// Diese Konfig bestimmt Konstanten zur Bestimmung der Spiellänge, des Score und der Wahrscheinlichkeiten von Lampenaufleuchten

#ifndef CONFIG_H
#define CONFIG_H

                                // xU für unsigned integer, (x) zur Klarheit kompilerlogik
#define GAME_TIME_MS (30000U)         //Millisekunden Spielzeit
#define GAME_FINISHED_WAIT_MS 5000U

#define GAME_HIT (1U)           //Punkt pro Hit

#define GAME_LOWEST_SCORE (0U)

#define PROB_LAMP_1 (0.7U)      //Prozent, dass x Lampen leuchten
#define PROB_LAMP_2 (0.2U)
#define PROB_LAMP_3 (0.07U)
#define PROB_LAMP_4 (0.03U)

#define BUTTON_TOP_LEFT     0U
#define BUTTON_TOP_RIGHT    1U
#define BUTTON_BOTTOM_LEFT  2U
#define BUTTON_BOTTOM_RIGHT 3U



#endif //CONFIG_H