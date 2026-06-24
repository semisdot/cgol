#ifndef INPUT_H
#define INPUT_H


#define MAX_KEYBOARD_KEYS 232
#define MAX_MOUSE_BUTTONS 4

/* ---------------------------------------------------------------------------------------------------- */

struct keyboard
{
	int keys[MAX_KEYBOARD_KEYS];
};

struct mouse
{
	int x;
	int y;

	int buttons[MAX_MOUSE_BUTTONS];
};

struct events
{
	struct keyboard keyboard;
	struct mouse mouse;
};

/* ---------------------------------------------------------------------------------------------------- */

void input(struct events *events);


#endif // INPUT_H
