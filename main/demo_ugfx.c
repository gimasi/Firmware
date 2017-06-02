#include "gfx.h"
#include "demo_ugfx.h"

font_t roboto;
font_t robotoBlackItalic;
font_t permanentMarker22;
font_t permanentMarker44;
font_t permanentMarker60;
font_t permanentMarker80;

const char* displayNames[] = {
    "kartoffel",
    "sebastius",
    "boekenwuurm",
    "attilla",
    "stitch",
    "tsd",
    "sprite_tm",
    "underhand",
    "markusbec",
    "roosted",
    "the_jinx",
    "realitygaps",
    "raboof"
};

#define numNames (sizeof(displayNames) / sizeof (const char*))

void showDemo(uint8_t number, color_t front, color_t back) {

  gdispClear(back);
  gdispDrawString(number, 0, "STILL", robotoBlackItalic, front);
  gdispDrawString((296-gdispGetStringWidth("sebastius", permanentMarker44))/2, 34, "sebastius", permanentMarker44, front);
  // underline:
  gdispDrawLine(10+(296-gdispGetStringWidth("sebastius", permanentMarker44))/2, 34 + 44,
                10+(296-gdispGetStringWidth("sebastius", permanentMarker44))/2 + gdispGetStringWidth("sebastius", permanentMarker44) + 14, 34 + 44,
                front);
  // cursor:
  if(number%2==0){
  gdispDrawLine((296-gdispGetStringWidth("sebastius", permanentMarker44))/2 + gdispGetStringWidth("sebastius", permanentMarker44) + 20, 50 + 2,
                (296-gdispGetStringWidth("sebastius", permanentMarker44))/2 + gdispGetStringWidth("sebastius", permanentMarker44) + 20, 50 + 22 - 2,
                front);
              } else {
  gdispDrawLine((296-gdispGetStringWidth("sebastius", permanentMarker44))/2 + gdispGetStringWidth("sebastius", permanentMarker44) + 20, 50 + 2,
                (296-gdispGetStringWidth("sebastius", permanentMarker44))/2 + gdispGetStringWidth("sebastius", permanentMarker44) + 20, 50 + 22 - 2,
                back);
              }

  gdispDrawString(293-gdispGetStringWidth("Anyway", robotoBlackItalic)-number, 103, "Anyway", robotoBlackItalic, front);
  gdispFlush();
}


void demoUgfx() {
  ets_printf("Initializing gfx\n");
  gfxInit();
  ets_printf("Initialized gfx\n");

  roboto = gdispOpenFont("Roboto_Regular12");
  robotoBlackItalic = gdispOpenFont("Roboto_BlackItalic24");
  permanentMarker22 = gdispOpenFont("PermanentMarker22");
  permanentMarker44 = gdispOpenFont("PermanentMarker44");
  permanentMarker60 = gdispOpenFont("PermanentMarker60");
  permanentMarker80 = gdispOpenFont("PermanentMarker80");
  gdispClear(White);
  gdispFlush();
  gdispClear(White);
  gdispFlush();
  gdispClear(White);
  gdispFlush();
  gdispClear(Black);
  gdispFlush();
  gdispClear(Black);
  gdispFlush();
  gdispClear(Black);
  gdispFlush();
  gdispClear(White);
  gdispFlush();
  gdispClear(Black);
  gdispFlush();
  gdispClear(White);
  gdispFlush();
  gdispClear(Black);
  gdispFlush();
  gdispClear(White);
  gdispFlush();
  gdispClear(Black);
  gdispFlush();
  gdispClear(White);
  gdispFlush();
  gdispClear(White);
  gdispFlush();
  gdispClear(White);
  gdispFlush();
  gdispClear(Black);
  gdispFlush();
  gdispClear(Black);
  gdispFlush();
  gdispClear(Black);
  gdispFlush();
  gdispClear(White);
  gdispFlush();
  gdispClear(White);
  gdispFlush();
  gdispClear(White);
  gdispFlush();

  while (1) {
    uint16_t i;
    for (i = 0; i < 296; i++) {

      showDemo(i, Black, White);
      //ets_delay_us(1000000);
    }
    for (i = 0; i < 296; i++) {

      showDemo(296-i, Black, White);
      //ets_delay_us(1000000);
    }
  }
}
