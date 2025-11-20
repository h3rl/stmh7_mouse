#ifndef USB_MOUSE_H
#define USB_MOUSE_H

#include <stdint.h>

#define MOUSE_BTN_LEFT   0x01
#define MOUSE_BTN_RIGHT  0x02
#define MOUSE_BTN_MIDDLE 0x04

void mouse_move(int8_t dx, int8_t dy);
void mouse_press(uint8_t buttons);
void mouse_release(uint8_t buttons);
void mouse_send_report(int8_t dx, int8_t dy, uint8_t buttons);

#endif // USB_MOUSE_H
