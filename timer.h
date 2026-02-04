#ifndef TIMER_H
#define TIMER_H

#include <stdint.h>
#include <stdbool.h>

void timer_start(void);
bool timer_expired(void);

#endif /* TIMER_H */
