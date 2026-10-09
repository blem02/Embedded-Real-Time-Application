#ifndef GAME_H
#define GAME_H

#include <Arduino.h>
#include "timer.h"
#include "phase.h"
#include "display.h"
#include "button.h"

// ==================== KONFIGURATION ====================

#define GAME_HIT              10       // Punkte pro abgeschlossener Phase
#define GAME_FINISHED_WAIT_MS 3000     // Anzeigedauer des Scores nach Spielende (ms)

// ==================== TYPEN ====================

typedef enum {
    GAME_STATE_IDLE,
    GAME_STATE_INIT,
    GAME_STATE_RUNNING,
    GAME_STATE_FINISHED
} game_state_t;


//Initialisiert das Spiel, setzt Score zurück, startet Timer und erste Phase. (REQ-INIT)
void game_init();

//Zeigt Score an, wartet, setzt alles zurück => IDLE. (REQ-GAME-TIME)
void game_finished();


//IDLE: Warten auf Knopfdruck => Init (REQ-IDLE)
//RUNNING: Timer prüfen (REQ-GAME-TIME), Phase prüfen (REQ-PHASE), Trefferauswertung (REQ-GAME-HIT)
//FINISHED: Abschlusssequenz
void game_update();

#endif // GAME_H