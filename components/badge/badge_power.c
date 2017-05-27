#include <stdbool.h>
#include <stdint.h>

#include <stdio.h>
#include <string.h>

#include "sdkconfig.h"

#include "badge_pins.h"
#include "badge_portexp.h"
#include "badge_mpr121.h"
#include "badge_power.h"

int
badge_battery_volt_sense(void)
{
	// FIXME
	return -1;
}

int
badge_usb_volt_sense(void)
{
	// FIXME
	return -1;
}

#if defined(PORTEXP_PIN_NUM_CHRGSTAT) || defined(MPR121_PIN_NUM_CHRGSTAT)
bool
badge_battery_charge_status(void)
{
#ifdef PORTEXP_PIN_NUM_CHRGSTAT
	return (badge_portexp_get_input() >> PORTEXP_PIN_NUM_CHRGSTAT) & 1;
#elif defined(MPR121_PIN_NUM_CHRGSTAT)
	return badge_mpr121_get_gpio_level(MPR121_PIN_NUM_CHRGSTAT);
#endif
}
#endif // defined(PORTEXP_PIN_NUM_CHRGSTAT) || defined(MPR121_PIN_NUM_CHRGSTAT)

void
badge_power_init(void)
{
	// configure vbat-sense
	// FIXME

	// configure vusb-sense
	// FIXME

	// configure charge-stat pin
#ifdef PORTEXP_PIN_NUM_CHRGSTAT
	badge_portexp_set_io_direction(PORTEXP_PIN_NUM_CHRGSTAT, 0);
	badge_portexp_set_input_default_state(PORTEXP_PIN_NUM_CHRGSTAT, 0);
	badge_portexp_set_pull_enable(PORTEXP_PIN_NUM_CHRGSTAT, 0);
	badge_portexp_set_interrupt_enable(PORTEXP_PIN_NUM_CHRGSTAT, 0);
#elif defined(MPR121_PIN_NUM_CHRGSTAT)
	badge_mpr121_configure_gpio(MPR121_PIN_NUM_CHRGSTAT, MPR121_INPUT);
#endif
}
