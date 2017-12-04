void SetupSSD1306()
{
    u8g2.begin(); 
}

/*
//    -----------LiquidCrystal compatible functions------------- 
//    void home(void) { tx = 0; ty = 0;  u8x8_utf8_init(u8g2_GetU8x8(&u8g2)); }
//    void clear(void) { home(); clearDisplay(); clearBuffer();  }
//    void noDisplay(void) { u8g2_SetPowerSave(&u8g2, 1); }
//    void display(void) { u8g2_SetPowerSave(&u8g2, 0); }
//    void setCursor(u8g2_uint_t x, u8g2_uint_t y) { tx = x; ty = y; }
*/


void UpdateSSD1306()
{
  u8g2.firstPage();
  do 
  {
    u8g2.setFont(u8g2_font_ncenB10_tr);
    //Line 1
    u8g2.setCursor(0,11);           //Less than this using u8g2_font_ncenB10_tr will cut the TOP off 
    u8g2.print(LCD_Line_1);
    u8g2.setCursor(0,24);
    u8g2.print(" Volume ");
    u8g2.print(LCD_Line_2);
    u8g2.setCursor(0,37);
    //u8g2.print("0123456789012345"); //This shows the display to be 16x5 display using u8g2_font_ncenB10_tr 
    u8g2.print(LCD_Line_3);
    u8g2.setCursor(0,50);
    u8g2.print(LCD_Line_4);
    u8g2.setCursor(0,64);           //Greater than this using u8g2_font_ncenB10_tr will cut the BOTTOM off 
    u8g2.print(LCD_Line_5);
    
  } while ( u8g2.nextPage() );
  //delay(1000);
}
