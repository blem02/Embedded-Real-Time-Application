
// ==================== CONFIG ====================
#define GAME_TIME_MS 30000U
#define GAME_FINISHED_WAIT_MS 5000U
#define GAME_HIT 1U
#define GAME_LOWEST_SCORE 0U

#define LED_TOP_LEFT_PIN     2
#define LED_TOP_RIGHT_PIN    3
#define LED_BOTTOM_LEFT_PIN  4
#define LED_BOTTOM_RIGHT_PIN 5

#define BUTTON_TOP_LEFT_PIN     A1
#define BUTTON_TOP_RIGHT_PIN    A2
#define BUTTON_BOTTOM_LEFT_PIN  A3
#define BUTTON_BOTTOM_RIGHT_PIN A4

// ==================== PHASE / BUTTONS ====================
typedef enum {
    BUTTON_NONE = 0,
    BUTTON_TOP_LEFT,
    BUTTON_TOP_RIGHT,
    BUTTON_BOTTOM_LEFT,
    BUTTON_BOTTOM_RIGHT
} button_id_t;

// Forward-Declarations
bool button_pressed(button_id_t button_id);
button_id_t phase_any_pressed();
void display_score(uint8_t score);
bool phase_check_hit(button_id_t button_id);
void phase_reset();
void phase_determine_buttons(uint8_t num_buttons);
void phase_start();
void game_init();
void game_finished();
void game_update();
void light_init();
void light_top_left(); void light_off_top_left();
void light_top_right(); void light_off_top_right();
void light_bottom_left(); void light_off_bottom_left();
void light_bottom_right(); void light_off_bottom_right();
uint8_t phase_draw_num_buttons_to_light();
bool phase_complete();

// ==================== GLOBALS ====================
// LEDs Status
static bool light_top_left_on = false;
static bool light_top_right_on = false;
static bool light_bottom_left_on = false;
static bool light_bottom_right_on = false;

// Timer
static uint32_t start_time = 0U;

// Game
typedef enum { GAME_STATE_IDLE, GAME_STATE_INIT, GAME_STATE_RUNNING, GAME_STATE_FINISHED } game_state_t;
static game_state_t game_state = GAME_STATE_IDLE;
static uint8_t game_score = 0;
static button_id_t update_button = BUTTON_NONE;

// ==================== TIMER ====================
void timer_start() {
    start_time = millis();
  	Serial.println("timer started");
}

bool timer_expired() {
    return (millis() - start_time) >= GAME_TIME_MS;
}

// ==================== LIGHT ====================
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

// ==================== BUTTONS ====================
bool button_pressed(button_id_t button_id) {
    switch(button_id) {
        case BUTTON_TOP_LEFT: 
            return digitalRead(BUTTON_TOP_LEFT_PIN) == LOW;
        case BUTTON_TOP_RIGHT: 
      		return digitalRead(BUTTON_TOP_RIGHT_PIN) == LOW;
        case BUTTON_BOTTOM_LEFT: 
            return digitalRead(BUTTON_BOTTOM_LEFT_PIN) == LOW;
        case BUTTON_BOTTOM_RIGHT: 
            return digitalRead(BUTTON_BOTTOM_RIGHT_PIN) == LOW;
        default: 
            return false;
    }
}

button_id_t phase_any_pressed() {
  	if (button_pressed(BUTTON_TOP_LEFT)) return BUTTON_TOP_LEFT;
  	if (button_pressed(BUTTON_TOP_RIGHT)) return BUTTON_TOP_RIGHT;
    if (button_pressed(BUTTON_BOTTOM_LEFT)) return BUTTON_BOTTOM_LEFT;
    if (button_pressed(BUTTON_BOTTOM_RIGHT)) return BUTTON_BOTTOM_RIGHT;
    return BUTTON_NONE;
}



// ==================== DISPLAY ====================
void display_score(uint8_t score) {
    Serial.println("========================");
    Serial.print("Score: ");
    Serial.println(score);
}

// ==================== PHASE LOGIC ====================
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

// ==================== GAME ====================


void game_init() {
    game_state = GAME_STATE_INIT;
    game_score = 0;
    timer_start();
    phase_start();
    game_state = GAME_STATE_RUNNING;
}

void game_finished() {
    display_score(game_score);
    uint32_t start = millis();
    while (millis() - start < GAME_FINISHED_WAIT_MS) { /* nur warten */ }
    phase_reset();
    game_score = 0;
    game_state = GAME_STATE_IDLE;
}

void game_update() {
    switch(game_state) {
        case GAME_STATE_IDLE:
      		if (phase_any_pressed() != BUTTON_NONE) {
       			game_init();
              	Serial.print("Button ");
              	Serial.print(phase_any_pressed());
              	Serial.println(" hat das Spiel initialisiert");
            }
            break;
        case GAME_STATE_RUNNING:
            if (timer_expired()) {
                game_state = GAME_STATE_FINISHED;
            }
            else if (phase_complete()) {
                game_score += GAME_HIT; 
                phase_start();
            }
            else {
                update_button = phase_any_pressed();
                if (update_button != BUTTON_NONE) 
                 	phase_check_hit(update_button);
            }
            break;
        case GAME_STATE_FINISHED:
            game_finished();
            break;
    }
}

// ==================== SETUP / LOOP ====================
void setup() {
    Serial.begin(9600);

    pinMode(BUTTON_TOP_LEFT_PIN, INPUT_PULLUP);
    pinMode(BUTTON_TOP_RIGHT_PIN, INPUT_PULLUP);
    pinMode(BUTTON_BOTTOM_LEFT_PIN, INPUT_PULLUP);
    pinMode(BUTTON_BOTTOM_RIGHT_PIN, INPUT_PULLUP);

    light_init();
    randomSeed(analogRead(A5)); // Zufall initialisieren
}

void loop() {
    game_update();
    
}
