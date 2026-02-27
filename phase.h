#ifndef PHASE_H
#define PHASE_H

#include <Arduino.h>
#include "config.h"   // button_id_t, light

// ==================== FUNKTIONEN ====================

//Gibt eine zufällige Anzahl an Lampen zurück (REQ-PHASE-PROB):
uint8_t phase_draw_num_buttons_to_light();

//Schaltet alle Lampen aus und setzt deren Status zurück.
void phase_reset();

//Prüft ob ein Knopfdruck ein Treffer ist und schaltet die zugehörige Lampe aus (REQ-GAME-HIT).
bool phase_check_hit(button_id_t button_id);

//Gibt zurück ob alle Lampen der aktuellen Phase aus sind (REQ-PHASE).
bool phase_complete();

//Bestimmt zufällig welche Lampen für num_buttons Knöpfe aufgehen und schaltet sie ein (REQ-PHASE-PROB).
void phase_determine_buttons(uint8_t num_buttons);

//Startet eine neue Phase: zieht Lampenanzahl und schaltet sie ein.
void phase_start();

//Gibt den Button zurück, der als letztes gedrückt wurde (REQ-IDLE, REQ-GAME-HIT).
button_id_t phase_any_pressed();

#endif // PHASE_H