#include "sdkconfig.h"

#include <string.h>

#include <freertos/FreeRTOS.h>
//include <esp_event.h>
//include <driver/adc.h>
//include <gde.h>
//include <gde-driver.h>

#include <badge_eink.h>
#include <badge_power.h>
#include <badge_sdcard.h>
#include <font.h>

#include "event_queue.h"

// re-use screen_buf from main.c
extern uint8_t screen_buf[296*16];

void
demoPower(void) {
	char text[32];

	bool bat_cs = false;
	bool sdcard_cd = false;
	int v_bat = -1;
	int v_usb = -1;

	while (1)
	{
		bool new_bat_cs = badge_battery_charge_status();
		bool new_sdcard_cd = false;
		int new_v_bat = badge_battery_volt_sense();
		int new_v_usb = badge_usb_volt_sense();

		if (bat_cs != new_bat_cs || sdcard_cd != new_sdcard_cd ||
			v_bat != new_v_bat || v_usb != new_v_usb)
		{
			bat_cs = new_bat_cs;
			sdcard_cd = new_sdcard_cd;
			v_bat = new_v_bat;
			v_usb = new_v_usb;

			memset(screen_buf, 0xff, sizeof(screen_buf));

			snprintf(text, sizeof(text), "Is charging: %s", bat_cs ? "true" : "false");
			draw_font(screen_buf, 16,  8, BADGE_EINK_WIDTH-32, text,
					FONT_MONOSPACE | FONT_INVERT);

			snprintf(text, sizeof(text), "Vusb       : %d.%03d V", v_usb / 1000, v_usb % 1000);
			draw_font(screen_buf, 16, 16, BADGE_EINK_WIDTH-32, text,
					FONT_MONOSPACE | FONT_INVERT);

			snprintf(text, sizeof(text), "Vbat       : %d.%03d V", v_bat / 1000, v_bat % 1000);
			draw_font(screen_buf, 16, 24, BADGE_EINK_WIDTH-32, text,
					FONT_MONOSPACE | FONT_INVERT);

			snprintf(text, sizeof(text), "Have SDcard: %s", sdcard_cd ? "true" : "false");
			draw_font(screen_buf, 16, 40, BADGE_EINK_WIDTH-32, text,
					FONT_MONOSPACE | FONT_INVERT);

			/* update display */
			badge_eink_display(screen_buf, (3 << DISPLAY_FLAG_LUT_BIT));
		}

		// wait 1 second
		uint32_t buttons_down = 0;
		if (xQueueReceive(evt_queue, &buttons_down, 1000 / portTICK_RATE_MS))
			if ((buttons_down & 0xffff) != 0)
				return;
	}
}
