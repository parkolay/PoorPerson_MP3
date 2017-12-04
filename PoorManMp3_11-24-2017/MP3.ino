void SetupMP3()
{
  mp3.begin();

  uint16_t volume = mp3.getVolume();
  LCD_Line_2 = volume;
  UpdateSSD1306();
  Serial.print("volume ");
  Serial.println(LCD_Line_3);
  
  mp3.setVolume(15);  //set on power up & use I/O 1&2 for volume adjustment
 
  uint16_t count = mp3.getTotalTrackCount();
  Serial.print("files ");
  Serial.println(count);
  
  uint16_t mode = mp3.getPlaybackMode();
//0 Repeat/1 folder repeat/2 single repeat/3 random
  Serial.print("playback mode ");
  Serial.println(mode);

  uint16_t EQ_mode = mp3.getEq();
  Serial.print("Eq Setting ");
  Serial.println(EQ_mode);
//    DfMp3_Eq_Normal,
//    DfMp3_Eq_Pop,
//    DfMp3_Eq_Rock,
//    DfMp3_Eq_Jazz,
//    DfMp3_Eq_Classic,
//    DfMp3_Eq_Bass
    
}

void waitMilliseconds(uint16_t msWait)
{
  uint32_t start = millis();
  
  while ((millis() - start) < msWait)
  {
    // calling mp3.loop() periodically allows for notifications 
    // to be handled without interrupts
    mp3.loop(); 
    delay(100);
  }
}

void UpdateMP3()
{
  LCD_Line_3 = ("track 1");
  Serial.println(LCD_Line_3); 
  mp3.playMp3FolderTrack(1);  // sd:/mp3/0001.mp3
  UpdateSSD1306();
  waitMilliseconds(5000);
  
  
  LCD_Line_3 = ("track 2");
  Serial.println(LCD_Line_3); 
  mp3.playMp3FolderTrack(2); // sd:/mp3/0002.mp3
  UpdateSSD1306();
  waitMilliseconds(5000);
  
  LCD_Line_3 = ("track 3");
  Serial.println(LCD_Line_3); 
  mp3.playMp3FolderTrack(3); // sd:/mp3/0003.mp3
  UpdateSSD1306();
  waitMilliseconds(5000); 
  
  LCD_Line_3 = ("track 4");
  Serial.println(LCD_Line_3); 
  mp3.playMp3FolderTrack(4);  // sd:/mp3/0004.mp3
  UpdateSSD1306();
  waitMilliseconds(5000);
  
  LCD_Line_3 = ("track 5");
  Serial.println(LCD_Line_3); 
  mp3.playMp3FolderTrack(5); // sd:/mp3/0005.mp3
  UpdateSSD1306();
  waitMilliseconds(5000);
  
  LCD_Line_3 = ("track 6");
  Serial.println(LCD_Line_3); 
  mp3.playMp3FolderTrack(6); // sd:/mp3/0006.mp3
  UpdateSSD1306();
  waitMilliseconds(5000); 

  LCD_Line_3 = ("track 7");
  Serial.println(LCD_Line_3); 
  mp3.playMp3FolderTrack(7); // sd:/mp3/0007.mp3
  UpdateSSD1306();
  waitMilliseconds(5000);
}
