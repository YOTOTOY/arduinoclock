#include <EEPROM.h>
#include <TouchScreen.h>
#include <LCDWIKI_KBV.h>
#include <LCDWIKI_GUI.h>

#define BLACK 0x0000
#define WHITE 0xFFFF
#define GREEN 0x07E0
#define RED 0xF800
#define BLUE 0x001F
#define YELLOW 0xFFE0
#define PINK 0xF80F
#define PURPLE 0x781F
#define ORANGE 0xFD20
#define CYAN 0x07FF
#define GRAY 0xC618

#define YP A2
#define XM A3
#define YM 8
#define XP 9

#define MINPRESSURE 10
#define MAXPRESSURE 1000

int a = 1;
int b = GREEN;
int c = GREEN;

LCDWIKI_KBV mylcd(ILI9341,A3,A2,A1,A0,A4);
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

void setup() {
  Serial.begin(115200); 
  mylcd.Set_Rotation(1);
  EEPROM.get(c,b);
  mylcd.Init_LCD();
  mylcd.Fill_Screen(BLACK);
  mylcd.Set_Text_Size(5);
  mylcd.Set_Text_colour(WHITE);
  mylcd.Set_Text_Back_colour(BLACK);
  mylcd.Print_String("Arduino",60,100);
  delay(1000);
  mylcd.Fill_Screen(BLACK);
}

void loop() {
  TSPoint p = ts.getPoint();
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);   
  if (Serial.available()) {
    String Time = Serial.readString(); 
    mylcd.Set_Text_Size(9);
    mylcd.Set_Text_colour(b);
    mylcd.Set_Text_Back_colour(BLACK);
    mylcd.Print_String(Time.substring(11,16),30,80);
    mylcd.Set_Text_Size(2);
    mylcd.Set_Text_colour(b);
    mylcd.Set_Text_Back_colour(BLACK);
    mylcd.Print_String(Time.substring(5,10),257,220);
    mylcd.Print_String("Set",275,2);
  }    
  if (p.z > MINPRESSURE && p.z < MAXPRESSURE) {    
    if (a == 1) {
      if ((p.x > 140 && p.x < 284) && (p.y > 90 && p.y < 200)) {
        Serial.end();
        a = 2;
        mylcd.Fill_Screen(BLACK);
        mylcd.Set_Text_Size(3);
        mylcd.Set_Text_colour(b);
        mylcd.Set_Text_Back_colour(BLACK);
        mylcd.Print_String("Setting",CENTER,2);
        mylcd.Print_String("Colour",2,110);
        mylcd.Set_Text_Size(2);
        mylcd.Print_String("Back",2,2);
      }
    }  
    if (a == 2) {
       if ((p.x > 816 && p.x < 960) && (p.y > 90 && p.y < 200)) {
         a = 1;
         Serial.begin(115200);
         mylcd.Fill_Screen(BLACK);      
       }
       if ((p.x > 676 && p.x < 960) && (p.y > 435 && p.y < 585)) {
         mylcd.Fill_Screen(BLACK);
         mylcd.Set_Text_Size(3);
         mylcd.Set_Text_colour(b);
         mylcd.Set_Text_Back_colour(BLACK);
         mylcd.Print_String("Colour",CENTER,2);
         mylcd.Print_String("green",2,65);
         mylcd.Print_String("red",120,65);
         mylcd.Print_String("purple",200,65);
         mylcd.Print_String("yellow",2,110);
         mylcd.Print_String("pink",140,110);
         mylcd.Print_String("blue",240,110);
         mylcd.Print_String("orange",2,155);
         mylcd.Print_String("cyan",140,155);
         mylcd.Print_String("gray",240,155);
         mylcd.Print_String("white",2,200);
         mylcd.Set_Text_Size(2);
         mylcd.Print_String("Back",2,2);
         a = 4;
       }
   }  
    if (a == 3 || a == 4) {
      if ((p.x > 816 && p.x < 960) && (p.y > 90 && p.y < 200)) {    
        a = 2;
        mylcd.Fill_Screen(BLACK);
        mylcd.Set_Text_Size(3);
        mylcd.Set_Text_colour(b);
        mylcd.Set_Text_Back_colour(BLACK);
        mylcd.Print_String("Setting",CENTER,2);
        mylcd.Print_String("Colour",2,110);
        mylcd.Set_Text_Size(2);
        mylcd.Print_String("Back",2,2);
      }
    }
    if (a == 4) {
      if ((p.x > 728 && p.x < 960) && (p.y > 285 && p.y < 435)) {
        b = GREEN;
        mylcd.Set_Text_Size(3);
        mylcd.Set_Text_colour(b);
        mylcd.Set_Text_Back_colour(BLACK);
        mylcd.Print_String("Colour",CENTER,2);
        mylcd.Print_String("green",2,65);
        mylcd.Print_String("red",120,65);
        mylcd.Print_String("purple",200,65);
        mylcd.Print_String("yellow",2,110);
        mylcd.Print_String("pink",140,110);
        mylcd.Print_String("blue",240,110);
        mylcd.Print_String("orange",2,155);
        mylcd.Print_String("cyan",140,155);
        mylcd.Print_String("gray",240,155);
        mylcd.Print_String("white",2,200);
        mylcd.Set_Text_Size(2);
        mylcd.Print_String("Back",2,2);
        EEPROM.put(c,b);
      }
      if ((p.x > 520 && p.x < 670) && (p.y > 285 && p.y < 435)) {
        b = RED;
        mylcd.Set_Text_Size(3);
        mylcd.Set_Text_colour(b);
        mylcd.Set_Text_Back_colour(BLACK);
        mylcd.Print_String("Colour",CENTER,2);
        mylcd.Print_String("green",2,65);
        mylcd.Print_String("red",120,65);
        mylcd.Print_String("purple",200,65);
        mylcd.Print_String("yellow",2,110);
        mylcd.Print_String("pink",140,110);
        mylcd.Print_String("blue",240,110);
        mylcd.Print_String("orange",2,155);
        mylcd.Print_String("cyan",140,155);
        mylcd.Print_String("gray",240,155);
        mylcd.Print_String("white",2,200);
        mylcd.Set_Text_Size(2);
        mylcd.Print_String("Back",2,2);
        EEPROM.put(c,b);
      }
      if ((p.x > 164 && p.x < 456) && (p.y > 285 && p.y < 435)) {
        b = PURPLE;
        mylcd.Set_Text_Size(3);
        mylcd.Set_Text_colour(b);
        mylcd.Set_Text_Back_colour(BLACK);
        mylcd.Print_String("Colour",CENTER,2);
        mylcd.Print_String("green",2,65);
        mylcd.Print_String("red",120,65);
        mylcd.Print_String("purple",200,65);
        mylcd.Print_String("yellow",2,110);
        mylcd.Print_String("pink",140,110);
        mylcd.Print_String("blue",240,110);
        mylcd.Print_String("orange",2,155);
        mylcd.Print_String("cyan",140,155);
        mylcd.Print_String("gray",240,155);
        mylcd.Print_String("white",2,200);
        mylcd.Set_Text_Size(2);
        mylcd.Print_String("Back",2,2);
        EEPROM.put(c,b);
      }
      if ((p.x > 690 && p.x < 960) && (p.y > 435 && p.y < 585)) {
        b = YELLOW;
        mylcd.Set_Text_Size(3);
        mylcd.Set_Text_colour(b);
        mylcd.Set_Text_Back_colour(BLACK);
        mylcd.Print_String("Colour",CENTER,2);
        mylcd.Print_String("green",2,65);
        mylcd.Print_String("red",120,65);
        mylcd.Print_String("purple",200,65);
        mylcd.Print_String("yellow",2,110);
        mylcd.Print_String("pink",140,110);
        mylcd.Print_String("blue",240,110);
        mylcd.Print_String("orange",2,155);
        mylcd.Print_String("cyan",140,155);
        mylcd.Print_String("gray",240,155);
        mylcd.Print_String("white",2,200);
        mylcd.Set_Text_Size(2);
        mylcd.Print_String("Back",2,2);
        EEPROM.put(c,b);
      }
      if ((p.x > 428 && p.x < 616) && (p.y > 435 && p.y < 585)) {
        b = PINK;
        mylcd.Set_Text_Size(3);
        mylcd.Set_Text_colour(b);
        mylcd.Set_Text_Back_colour(BLACK);
        mylcd.Print_String("Colour",CENTER,2);
        mylcd.Print_String("green",2,65);
        mylcd.Print_String("red",120,65);
        mylcd.Print_String("purple",200,65);
        mylcd.Print_String("yellow",2,110);
        mylcd.Print_String("pink",140,110);
        mylcd.Print_String("blue",240,110);
        mylcd.Print_String("orange",2,155);
        mylcd.Print_String("cyan",140,155);
        mylcd.Print_String("gray",240,155);
        mylcd.Print_String("white",2,200);
        mylcd.Set_Text_Size(2);
        mylcd.Print_String("Back",2,2);
        EEPROM.put(c,b);
      }
      if ((p.x > 154 && p.x < 344) && (p.y > 435 && p.y < 585)) {
        b = BLUE;
        mylcd.Set_Text_Size(3);
        mylcd.Set_Text_colour(b);
        mylcd.Set_Text_Back_colour(BLACK);
        mylcd.Print_String("Colour",CENTER,2);
        mylcd.Print_String("green",2,65);
        mylcd.Print_String("red",120,65);
        mylcd.Print_String("purple",200,65);
        mylcd.Print_String("yellow",2,110);
        mylcd.Print_String("pink",140,110);
        mylcd.Print_String("blue",240,110);
        mylcd.Print_String("orange",2,155);
        mylcd.Print_String("cyan",140,155);
        mylcd.Print_String("gray",240,155);
        mylcd.Print_String("white",2,200);
        mylcd.Set_Text_Size(2);
        mylcd.Print_String("Back",2,2);
        EEPROM.put(c,b);
      }
      if ((p.x > 690 && p.x < 960) && (p.y > 585 && p.y < 735)) {
        b = ORANGE;
        mylcd.Set_Text_Size(3);
        mylcd.Set_Text_colour(b);
        mylcd.Set_Text_Back_colour(BLACK);
        mylcd.Print_String("Colour",CENTER,2);
        mylcd.Print_String("green",2,65);
        mylcd.Print_String("red",120,65);
        mylcd.Print_String("purple",200,65);
        mylcd.Print_String("yellow",2,110);
        mylcd.Print_String("pink",140,110);
        mylcd.Print_String("blue",240,110);
        mylcd.Print_String("orange",2,155);
        mylcd.Print_String("cyan",140,155);
        mylcd.Print_String("gray",240,155);
        mylcd.Print_String("white",2,200);
        mylcd.Set_Text_Size(2);
        mylcd.Print_String("Back",2,2);
        EEPROM.put(c,b);
      }
      if ((p.x > 428 && p.x < 616) && (p.y > 585 && p.y < 735)) {
        b = CYAN;
        mylcd.Set_Text_Size(3);
        mylcd.Set_Text_colour(b);
        mylcd.Set_Text_Back_colour(BLACK);
        mylcd.Print_String("Colour",CENTER,2);
        mylcd.Print_String("green",2,65);
        mylcd.Print_String("red",120,65);
        mylcd.Print_String("purple",200,65);
        mylcd.Print_String("yellow",2,110);
        mylcd.Print_String("pink",140,110);
        mylcd.Print_String("blue",240,110);
        mylcd.Print_String("orange",2,155);
        mylcd.Print_String("cyan",140,155);
        mylcd.Print_String("gray",240,155);
        mylcd.Print_String("white",2,200);
        mylcd.Set_Text_Size(2);
        mylcd.Print_String("Back",2,2);
        EEPROM.put(c,b);
      }
      if ((p.x > 154 && p.x < 344) && (p.y > 585 && p.y < 735)) {
        b = GRAY;
        mylcd.Set_Text_Size(3);
        mylcd.Set_Text_colour(b);
        mylcd.Set_Text_Back_colour(BLACK);
        mylcd.Print_String("Colour",CENTER,2);
        mylcd.Print_String("green",2,65);
        mylcd.Print_String("red",120,65);
        mylcd.Print_String("purple",200,65);
        mylcd.Print_String("yellow",2,110);
        mylcd.Print_String("pink",140,110);
        mylcd.Print_String("blue",240,110);
        mylcd.Print_String("orange",2,155);
        mylcd.Print_String("cyan",140,155);
        mylcd.Print_String("gray",240,155);
        mylcd.Print_String("white",2,200);
        mylcd.Set_Text_Size(2);
        mylcd.Print_String("Back",2,2);
        EEPROM.put(c,b);
      }
      if ((p.x > 728 && p.x < 960) && (p.y > 735 && p.y < 885)) {
        b = WHITE;
        mylcd.Set_Text_Size(3);
        mylcd.Set_Text_colour(b);
        mylcd.Set_Text_Back_colour(BLACK);
        mylcd.Print_String("Colour",CENTER,2);
        mylcd.Print_String("green",2,65);
        mylcd.Print_String("red",120,65);
        mylcd.Print_String("purple",200,65);
        mylcd.Print_String("yellow",2,110);
        mylcd.Print_String("pink",140,110);
        mylcd.Print_String("blue",240,110);
        mylcd.Print_String("orange",2,155);
        mylcd.Print_String("cyan",140,155);
        mylcd.Print_String("gray",240,155);
        mylcd.Print_String("white",2,200);
        mylcd.Set_Text_Size(2);
        mylcd.Print_String("Back",2,2); 
        EEPROM.put(c,b);
      }
   }
 }
}
