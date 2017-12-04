// this example will play a track and then 
// every five seconds play another track
//
// it expects the sd card to contain these three mp3 files
// but doesn't care whats in them
//
// sd:/mp3/0001.mp3
// sd:/mp3/0002.mp3
// sd:/mp3/0003.mp3

#include <SoftwareSerial.h>
#include <DFMiniMp3.h>
#include <U8g2lib.h>
#include <Wire.h>

void SetupSSD1306();
void UpdateSSD1306();
void SetupMP3();
void UpdateMP3();
void waitMilliseconds(uint16_t msWait);

String LCD_Line_1 = " BUTON_1 OFF ";
String LCD_Line_2 = " Volume ";
String LCD_Line_3 = " Track ";
String LCD_Line_4 = " NOT SET ";
String LCD_Line_5 = " NOT SET ";

  /*U8glib Example Overview:
    Frame Buffer Examples: clearBuffer/sendBuffer. Fast, but may not work with all Arduino boards because of RAM consumption
    Page Buffer Examples: firstPage/nextPage. Less RAM usage, should work with all Arduino boards.
    U8x8 Text Only Example: No RAM usage, direct communication with display controller. No graphics, 8x8 Text only.
    
  This is a page buffer example.    
*/

// Please UNCOMMENT one of the contructor lines below
// U8g2 Contructor List (Picture Loop Page Buffer)
// The complete list is available here: https://github.com/olikraus/u8g2/wiki/u8g2setupcpp
// Please update the pin numbers according to your setup. Use U8X8_PIN_NONE if the reset pin is not connected

U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);   // All Boards without Reset of the Display

// implement a notification class,
// its member methods will get called 
//
class Mp3Notify
{
public:
  static void OnError(uint16_t errorCode)
  {
    // see DfMp3_Error for code meaning
    Serial.println();
    Serial.print("Com Error ");
    Serial.println(errorCode);
  }

  static void OnPlayFinished(uint16_t globalTrack)
  {
    Serial.println();
    Serial.print("Play finished for #");
    Serial.println(globalTrack);   
  }

  static void OnCardOnline(uint16_t code)
  {
    Serial.println();
    Serial.print("Card online ");
    Serial.println(code);     
  }

  static void OnCardInserted(uint16_t code)
  {
    Serial.println();
    Serial.print("Card inserted ");
    Serial.println(code); 
  }

  static void OnCardRemoved(uint16_t code)
  {
    Serial.println();
    Serial.print("Card removed ");
    Serial.println(code);  
  }
};

// instance a DFMiniMp3 object, 
// defined with the above notification class and the hardware serial class
//
//DFMiniMp3<HardwareSerial, Mp3Notify> mp3(Serial1);

// Some arduino boards only have one hardware serial port, so a software serial port is needed instead.
// comment out the above definition and uncomment these lines
SoftwareSerial secondarySerial(10, 11); // RX, TX
DFMiniMp3<SoftwareSerial, Mp3Notify> mp3(secondarySerial);

void setup() 
{
   Serial.begin(115200);
   Serial.println("initializing..."); 
   
  SetupSSD1306();
  SetupMP3();
  
  Serial.println("initializing...");  

  Serial.println("starting...");
      delay(1000);
}

void loop() 
{
  UpdateSSD1306();
  UpdateMP3();
  
}
