#include "usb_mouse.h"
#include "usbd_hid.h"
#include "usbd_desc.h"
#include "usbd_conf.h"

extern USBD_HandleTypeDef hUsbDeviceFS;

static uint8_t mouse_report[4] = {0, 0, 0, 0};

void mouse_send_report(int8_t dx, int8_t dy, uint8_t buttons) {
    mouse_report[0] = buttons;
    mouse_report[1] = dx;
    mouse_report[2] = dy;
    mouse_report[3] = 0; // wheel (not used)
    USBD_HID_SendReport(&hUsbDeviceFS, mouse_report, sizeof(mouse_report));
}

void mouse_move(int8_t dx, int8_t dy) {
    mouse_send_report(dx, dy, mouse_report[0]);
}

void mouse_press(uint8_t buttons) {
    mouse_send_report(0, 0, mouse_report[0] | buttons);
}

void mouse_release(uint8_t buttons) {
    mouse_send_report(0, 0, mouse_report[0] & ~buttons);
}
