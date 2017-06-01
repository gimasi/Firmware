#include "gfx.h"
#include "sebastius.h"

font_t roboto;
font_t robotoBlackItalic;
font_t permanentMarker;




void sebastiusnametag(color_t front, color_t back) {
  gdispClear(back);
  gdispDrawString((296-gdispGetStringWidth("STILL", robotoBlackItalic))/2, 25, "STILL", robotoBlackItalic, front);
  gdispDrawString((296-gdispGetStringWidth("SEBASTIUS", permanentMarker))/2, 50, "SEBASTIUS", permanentMarker, front);
  // underline:
  gdispDrawLine((296-gdispGetStringWidth("SEBASTIUS", permanentMarker))/2, 50 + 22,
                (296-gdispGetStringWidth("SEBASTIUS", permanentMarker))/2 + gdispGetStringWidth("SEBASTIUS", permanentMarker) + 14, 50 + 22,
                front);
  // cursor:
  gdispDrawLine((296-gdispGetStringWidth("SEBASTIUS", permanentMarker))/2 + gdispGetStringWidth("SEBASTIUS", permanentMarker) + 10, 50 + 2,
                (296-gdispGetStringWidth("SEBASTIUS", permanentMarker))/2 + gdispGetStringWidth("SEBASTIUS", permanentMarker) + 10, 50 + 22 - 2,
                front);
  gdispDrawString((296-gdispGetStringWidth("Anyway", robotoBlackItalic))/2, 75, "Anyway", robotoBlackItalic, front);

  gdispFlush();
}

void sebastius() {
  ets_printf("Initializing gfx\n");
  gfxInit();
  ets_printf("Initialized gfx\n");

  roboto = gdispOpenFont("Roboto_Regular12");
  robotoBlackItalic = gdispOpenFont("Roboto_BlackItalic24");
  permanentMarker = gdispOpenFont("PermanentMarker22");

  gdispClear(Black);
  gdispFlush();
  sebastiusnametag(Black, White);

  while (1) {
ets_delay_us(5000000);
}
}
