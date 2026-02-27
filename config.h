
// ==================== CONFIG ====================

// Definitionen für game.c
#define GAME_TIME_MS 30000U
#define GAME_FINISHED_WAIT_MS 5000U
#define GAME_HIT 1U
#define GAME_LOWEST_SCORE 0U

// Definitionen für light.c
#define LED_TOP_LEFT_PIN     2
#define LED_TOP_RIGHT_PIN    3
#define LED_BOTTOM_LEFT_PIN  4
#define LED_BOTTOM_RIGHT_PIN 5

// Definitionen für Button.c
#define BUTTON_TOP_LEFT_PIN     A1
#define BUTTON_TOP_RIGHT_PIN    A2
#define BUTTON_BOTTOM_LEFT_PIN  A3
#define BUTTON_BOTTOM_RIGHT_PIN A4

// für Buttons, Game, Phase
typedef enum {
    BUTTON_NONE = 0,
    BUTTON_TOP_LEFT,
    BUTTON_TOP_RIGHT,
    BUTTON_BOTTOM_LEFT,
    BUTTON_BOTTOM_RIGHT
} button_id_t;

