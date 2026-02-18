#pragma once

typedef enum {
	GREEN,
	RED,
	ORANGE
} led_color;

void light_up(led_color led);
void light_down(led_color led);
