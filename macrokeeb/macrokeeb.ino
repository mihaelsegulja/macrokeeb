#include <Wire.h>
#include <HID-Project.h>
#include <Keypad.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Encoder.h>

const byte ROWS = 2;
const byte COLS = 5;
char keys[ROWS][COLS] = {
  {'1','2','3','4','5'},
  {'6','7','8','9','0'} 
};
byte rowPins[ROWS] = {10, 9};
byte colPins[COLS] = {4, 5, 6, 7, 8};
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS);

#define CLK 19    // A1
#define DT 18     // A0
#define SW 16
Encoder enc(DT, CLK);

long oldPosition  = -999;
byte counterSW = 1;
int lastButtonPress = 0;

Adafruit_SSD1306 display(128, 64, &Wire, -1);

void setup() {
  Serial.begin(9600);
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(SW, INPUT_PULLUP);
  
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)){
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  // splash screen
  display.display();
  display.clearDisplay();
  display.setCursor(0,0);
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.println();
  display.println("HELLO");
  display.println("THERE!");
  display.display();
  display.startscrollright(0x00, 0x0F);
  delay(5000);
  display.stopscroll();

  Consumer.begin();
  Keyboard.begin();
}

void loop() {
  // LED lights
  digitalWrite(14, HIGH);
  digitalWrite(15, HIGH);

  long newPosition = enc.read();
  
  // volume control with rotary encoder
  if(newPosition != oldPosition){
    if(newPosition - oldPosition > 0){
      Consumer.write(MEDIA_VOLUME_UP);
    }
    else{
      Consumer.write(MEDIA_VOLUME_DOWN);
    }
      oldPosition = newPosition;
      delay(5);
  }

  int btnState = digitalRead(SW);

  if(btnState == LOW){
    if(millis() - lastButtonPress > 50){
      counterSW++;
      delay(300);
    }
    lastButtonPress = millis();
  }

  if(counterSW > 5){
    counterSW = 1;
  }

  oledOutput(counterSW);

  char key = kpd.getKey();

  // layer switcher
  if(key){
    switch(counterSW){
      case 1: layer1(key); break;
      case 2: layer2(key); break;
      case 3: layer3(key); break;
      case 4: layer4(key); break;
      case 5: layer5(key); break;
    }
  }

  delay(10);
  
  Consumer.releaseAll();
  Keyboard.releaseAll();
}

// functions layer1() - layer5()
// for every physical button pressed, one or more keys are activated (macro command)
// for example, if we press key 1, key CTRL and key C will be pressed
void layer1(char key){
  switch(key){
    case '1': 
      Keyboard.press(KEY_LEFT_CTRL); 
      Keyboard.press(KEY_C); 
      break;
    case '2': 
      Keyboard.press(KEY_LEFT_CTRL); 
      Keyboard.press(KEY_X); 
      break;
    case '3': 
      Keyboard.press(KEY_LEFT_CTRL); 
      Keyboard.press(KEY_V); 
      break;
    case '4': 
      Keyboard.press(KEY_LEFT_CTRL); 
      Keyboard.press(KEY_Z); 
      break;
    case '5': 
      Keyboard.press(KEY_LEFT_CTRL); 
      Keyboard.press(KEY_Y); 
      break;
    case '6': 
      Keyboard.press(KEY_LEFT_CTRL); 
      Keyboard.press(KEY_S); 
      break;
    case '7': 
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_F); 
      break;
    case '8': 
      Keyboard.press(KEY_LEFT_CTRL); 
      Keyboard.press(KEY_A); 
      break;
    case '9': 
      Keyboard.press(KEY_LEFT_ALT); 
      Keyboard.press(KEY_F4); 
      break;
    case '0': 
      Keyboard.press(KEY_LEFT_WINDOWS); 
      Keyboard.press(KEY_TAB); 
      break;
  }
}

void layer2(char key){      
  switch(key){
    case '1': 
      Keyboard.press(KEY_LEFT_WINDOWS); 
      Keyboard.press(KEY_V); 
      break;
    case '2': 
      Keyboard.press(KEY_LEFT_WINDOWS); 
      Keyboard.press(KEY_L); 
      break;
    case '3': 
      Keyboard.press(KEY_LEFT_WINDOWS); 
      Keyboard.press(KEY_E); 
      break;
    case '4': 
      Keyboard.press(KEY_LEFT_WINDOWS); 
      Keyboard.press(KEY_LEFT_SHIFT); 
      Keyboard.press(KEY_S); 
      break;
    case '5': 
      Keyboard.press(KEY_LEFT_WINDOWS); 
      Keyboard.press(KEY_SPACE); 
      break;
    case '6': 
      Keyboard.press(KEY_LEFT_WINDOWS); 
      Keyboard.press(KEY_S); 
      break;
    case '7': 
      Keyboard.press(KEY_LEFT_WINDOWS); 
      Keyboard.press(KEY_LEFT_ARROW); 
      break;
    case '8': 
      Keyboard.press(KEY_LEFT_WINDOWS); 
      Keyboard.press(KEY_RIGHT_ARROW); 
      break;
    case '9': 
      Keyboard.press(KEY_LEFT_WINDOWS); 
      Keyboard.press(KEY_UP_ARROW); 
      break;
    case '0': 
      Keyboard.press(KEY_LEFT_WINDOWS); 
      Keyboard.press(KEY_DOWN_ARROW); 
      break;
  }
}

void layer3(char key){      
  switch(key){
    case '1': 
      Keyboard.press(KEY_LEFT_ALT); 
      Keyboard.press(KEY_F2); 
      break;
    case '2': 
      Keyboard.press(KEY_LEFT_CTRL); 
      Keyboard.press(KEY_LEFT_ALT); 
      Keyboard.press(KEY_L); 
      break;
    case '3': 
      Keyboard.press(KEY_LEFT_CTRL); 
      Keyboard.press(KEY_LEFT_ALT); 
      Keyboard.press(KEY_F1); 
      break;
    case '4': 
      Keyboard.press(KEY_LEFT_CTRL); 
      Keyboard.press(KEY_LEFT_ALT); 
      Keyboard.press(KEY_F7); 
      break;
    case '5': 
      Keyboard.press(KEY_LEFT_CTRL); 
      Keyboard.press(KEY_L); 
      break;
    case '6': 
      Keyboard.press(KEY_LEFT_CTRL); 
      Keyboard.press(KEY_U); 
      break;
    case '7': 
      Keyboard.press(KEY_LEFT_CTRL); 
      Keyboard.press(KEY_A); 
      break;
    case '8': 
      Keyboard.press(KEY_LEFT_CTRL); 
      Keyboard.press(KEY_E); 
      break;
    case '9': 
      Keyboard.press(KEY_LEFT_CTRL); 
      Keyboard.press(KEY_LEFT_SHIFT); 
      Keyboard.press(KEY_C); 
      break;
    case '0': 
      Keyboard.press(KEY_LEFT_CTRL); 
      Keyboard.press(KEY_LEFT_SHIFT); 
      Keyboard.press(KEY_V); 
      break;
  }
}

void layer4(char key){      
  switch(key){
    case '1': 
      Keyboard.press(KEY_F1); 
      break;
    case '2': 
      Keyboard.press(KEY_LEFT_SHIFT); 
      Keyboard.press(KEY_F6); 
      break;
    case '3': 
      Keyboard.press(KEY_LEFT_ALT); 
      Keyboard.press(KEY_DOWN_ARROW); 
      break;
    case '4': 
      Keyboard.press(KEY_LEFT_ALT); 
      Keyboard.press(KEY_UP_ARROW); 
      break;
    case '5': 
      Keyboard.press(KEY_LEFT_CTRL); 
      Keyboard.press(KEY_O); 
      break;
    case '6': 
      Keyboard.press(KEY_LEFT_CTRL); 
      Keyboard.press(KEY_LEFT_SHIFT); 
      Keyboard.press(KEY_K); 
      break;
    case '7': 
      Keyboard.press(KEY_LEFT_ALT); 
      Keyboard.press(KEY_L); 
      Keyboard.press(KEY_O); 
      break;
    case '8': 
      Keyboard.press(KEY_LEFT_ALT); 
      Keyboard.press(KEY_L); 
      Keyboard.press(KEY_C); 
      break;
    case '9': 
      Keyboard.press(KEY_LEFT_CTRL); 
      Keyboard.press(KEY_LEFT_ALT); 
      Keyboard.press(KEY_N); 
      break;
    case '0': 
      Keyboard.press(KEY_LEFT_CTRL); 
      Keyboard.press(KEY_K); 
      Keyboard.press(KEY_O); 
      break;
  }
}

void layer5(char key){      
  switch(key){
    case '1': 
      Consumer.write(MEDIA_VOLUME_MUTE); 
      break;
    case '2': 
      Consumer.write(MEDIA_PLAY_PAUSE); 
      break;
    case '3': 
      Consumer.write(MEDIA_NEXT); 
      break;
    case '4': 
      Consumer.write(MEDIA_PREVIOUS); 
      break;
    case '5': 
      Consumer.write(CONSUMER_SCREENSAVER); 
      break;
    case '6': 
      Consumer.write(CONSUMER_CALCULATOR); 
      break;
    case '7': 
      Consumer.write(CONSUMER_BROWSER_BACK); 
      break;
    case '8': 
      Consumer.write(CONSUMER_BROWSER_FORWARD); 
      break;
    case '9': 
      Consumer.write(CONSUMER_BROWSER_REFRESH); 
      break;
    case '0': 
      Consumer.write(CONSUMER_BROWSER_HOME); 
      break;
  }
}

// function for output on OLED display
// outputs current layer and short name of macro
void oledOutput(byte counterSW){
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(BLACK, WHITE);
  display.setCursor(0,0);
  switch(counterSW){
    case 1: 
      display.println("  LAYER1 - GENERAL   ");
      display.setTextColor(WHITE);
      display.println();
      display.println("1.COPY       2.CUT");
      display.println("3.PASTE      4.UNDO");
      display.println("5.REDO       6.SAVE");
      display.println("7.FIND       8.SELALL");
      display.println("9.CLOSE     10.SWITCH");
      display.display();
      break;
    case 2:
      display.println("  LAYER2 - WINDOWS   ");
      display.setTextColor(WHITE);
      display.println();
      display.println("1.CLPBRD    2.LOCK");
      display.println("3.FILEEXP   4.SNIP");
      display.println("5.LANG      6.SEARCH");
      display.println("7.SNAPLFT   8.SNAPRGT");
      display.println("9.BIGGER   10.SMOLR");
      display.display();
      break;
    case 3: 
      display.println("  LAYER3 - LINUX     ");
      display.setTextColor(WHITE);
      display.println();
      display.println("1.CMDLNCHR  2.LOCK");
      display.println("3.VTY1      4.GUI");
      display.println("5.CLEAR     6.ERASELN");
      display.println("7.BEGINLN   8.ENDLN");
      display.println("9.COPY      10.PASTE");
      display.display();
      break;
    case 4:
      display.println("  LAYER4 - VSCODE    ");
      display.setTextColor(WHITE);
      display.println();
      display.println("1.CMDPLT   2.OPNINBRW");
      display.println("3.MVLNDWN  4.MVLNUP");
      display.println("5.OPENFILE 6.DELLN");
      display.println("7.LIVESVR  8.CLIVESVR");
      display.println("9.RUNCODE  10.OPNFLDR");
      display.display();
      break;
    case 5:
      display.println("  LAYER5 - OTHER     ");
      display.setTextColor(WHITE);
      display.println();
      display.println("1.MUTE   2.PLAY/PAUSE");
      display.println("3.NEXT   4.PREV");
      display.println("5.SCRNSV 6.CALC");
      display.println("7.BACK   8.FRWRD");
      display.println("9.RFRSH  10.HOME");
      display.display();
      break;      
  }
}