// ==================== PHASE LOGIC ====================
// Requirements:
    // REQ-PHASE: Phasenlogik, Licht aus bei Knopfdruck, neue Phase bei allen Lichtern aus
    // REQ-PHASE-PROB: Wahrscheinlichkeiten für Lampenanzahl und Zuordnung  
#include "config.h" // für button_id_t

// LEDs Status
static bool light_top_left_on = false;
static bool light_top_right_on = false;
static bool light_bottom_left_on = false;
static bool light_bottom_right_on = false;


uint8_t phase_draw_num_buttons_to_light() {
    uint8_t r = random(0, 100);
    if (r < 70U) 
        return 1;
    else if (r < 90U) 
        return 2;
    else if (r < 97U) 
        return 3;
    else
        return 4;
}

void phase_reset() {
    light_off_top_left(); 
    light_off_top_right();
    light_off_bottom_left(); 
    light_off_bottom_right();
    light_top_left_on = light_top_right_on = light_bottom_left_on = light_bottom_right_on = false;
}

bool phase_check_hit(button_id_t button_id) {
    bool hit = false;
    switch(button_id) {
        case BUTTON_TOP_LEFT: 
            if (light_top_left_on) { 
                light_top_left_on=false; light_off_top_left(); hit=true; 
            } 
            break;
        case BUTTON_TOP_RIGHT: 
            if (light_top_right_on) { 
                light_top_right_on=false; light_off_top_right(); hit=true; 
            } 
            break;
        case BUTTON_BOTTOM_LEFT: 
            if (light_bottom_left_on) { 
                light_bottom_left_on=false; light_off_bottom_left(); hit=true; 
            } 
            break;
        case BUTTON_BOTTOM_RIGHT: 
            if (light_bottom_right_on) { 
                light_bottom_right_on=false; light_off_bottom_right(); hit=true; 
            } 
            break;
        default:
            Serial.println("phase_check_hit error: button not found");
    }
  	if (hit){
      	Serial.print("Button ");
      	Serial.print(button_id);
      	Serial.println(" was a hit!");
  	}
  	else {
    	Serial.print("Button ");
      	Serial.print(button_id);
      	Serial.println(" was a miss");
  	}
      	
    return hit;
}

bool phase_complete() {
  	bool complete = !(light_top_left_on || light_top_right_on || light_bottom_left_on || light_bottom_right_on);
    if (complete)
  		Serial.println("Phase abgeschlossen");
    return complete;
}

void phase_determine_buttons(uint8_t num_buttons) {
    uint8_t r = random(0,4);
    phase_reset();

    if (num_buttons == 1) {
        if (r==0) { light_top_left(); light_top_left_on=true; }
        else if (r==1) { light_top_right(); light_top_right_on=true; }
        else if (r==2) { light_bottom_left(); light_bottom_left_on=true; }
        else { light_bottom_right(); light_bottom_right_on=true; }
    } else if (num_buttons == 2) {
        if (r==0) { light_top_left(); light_bottom_left(); light_top_left_on=true; light_bottom_left_on=true; }
        else if (r==1) { light_top_right(); light_bottom_right(); light_top_right_on=true; light_bottom_right_on=true; }
        else if (r==2) { light_top_left(); light_top_right(); light_top_left_on=true; light_top_right_on=true; }
        else { light_bottom_left(); light_bottom_right(); light_bottom_left_on=true; light_bottom_right_on=true; }
    } else if (num_buttons == 3) {
        if (r==0) { light_top_right(); light_bottom_left(); light_bottom_right(); light_top_right_on=true; light_bottom_left_on=true; light_bottom_right_on=true; }
        else if (r==1) { light_top_left(); light_bottom_left(); light_bottom_right(); light_top_left_on=true; light_bottom_left_on=true; light_bottom_right_on=true; }
        else if (r==2) { light_top_left(); light_top_right(); light_bottom_right(); light_top_left_on=true; light_top_right_on=true; light_bottom_right_on=true; }
        else { light_top_left(); light_top_right(); light_bottom_left(); light_top_left_on=true; light_top_right_on=true; light_bottom_left_on=true; }
    } else { // 4
        light_top_left(); light_top_right(); light_bottom_left(); light_bottom_right();
        light_top_left_on = light_top_right_on = light_bottom_left_on = light_bottom_right_on = true;
    }
}

void phase_start() {
    uint8_t num = phase_draw_num_buttons_to_light();
  	Serial.print(num);
  	Serial.println(" Lampen sollen in dieser Phase aufleuchten");
    phase_determine_buttons(num);
}
