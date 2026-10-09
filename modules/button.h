#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>
#include "config.h"   // button_id_t, BUTTON_*_PIN


//Prüft ob ein bestimmter Knopf aktuell gedrückt ist (REQ-GAME-HIT)
bool button_pressed(button_id_t button_id);

//Gibt den ersten aktuell gedrückten Knopf zurück (REQ-IDLE, REQ-GAME-HIT).
button_id_t phase_any_pressed();

#endif // BUTTON_H