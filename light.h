#ifndef LIGHT_H
#define LIGHT_H

#include <Arduino.h>
#include "config.h"   // LED_*_PIN


// Lampen leuchten auf (REQ-PHASE)
// ==================== FUNKTIONEN ====================

//Setzt alle LED-Pins als OUTPUT und schaltet sie aus. 
void light_init();

//brief Schaltet die obere linke  Lampe EIN. 
void light_top_left();
//Schaltet die obere linke  Lampe AUS. 
void light_off_top_left();

//Schaltet die obere rechte Lampe EIN.
void light_top_right();
//Schaltet die obere rechte Lampe AUS. 
void light_off_top_right();

//Schaltet die untere linke  Lampe EIN. 
void light_bottom_left();
//Schaltet die untere linke  Lampe AUS. 
void light_off_bottom_left();

//brief Schaltet die untere rechte Lampe EIN.
void light_bottom_right();
//Schaltet die untere rechte Lampe AUS. 
void light_off_bottom_right();

#endif // LIGHT_H