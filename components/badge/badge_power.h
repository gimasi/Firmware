#ifndef BADGE_POWER_H
#define BADGE_POWER_H

extern void badge_power_init(void);
extern bool badge_battery_charge_status(void);
extern int badge_battery_volt_sense(void);
extern int badge_usb_volt_sense(void);

#endif // BADGE_POWER_H
