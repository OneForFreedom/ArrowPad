#include <Keypad.h>
#include <Keyboard.h>

// Matrix setup
const byte ROWS = 3;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'P','S','B','I'},  
  {'H','U','D','E'}, 
  {'G','U','L','N'} 
};


byte rowPins[ROWS] = {2, 3, 4};    
byte colPins[COLS] = {5, 6, 7, 8};  
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);


const int extraKeyPin = 9;

void setup() {
  pinMode(extraKeyPin, INPUT_PULLUP);
  Keyboard.begin();
}

void loop() {
  char key = keypad.getKey();
  if (key) sendKey(key);

  if (digitalRead(extraKeyPin) == LOW) {
    Keyboard.press(KEY_RIGHT_ARROW);
    delay(50);
    Keyboard.release(KEY_RIGHT_ARROW);
  }
}

void sendKey(char key) {
  switch(key) {
    case 'P': Keyboard.press(KEY_PRINT_SCREEN); Keyboard.release(KEY_PRINT_SCREEN); break;
    case 'S': Keyboard.press(KEY_SCROLL_LOCK); Keyboard.release(KEY_SCROLL_LOCK); break;
    case 'B': Keyboard.press(KEY_PAUSE); Keyboard.release(KEY_PAUSE); break;
    case 'I': Keyboard.press(KEY_INSERT); Keyboard.release(KEY_INSERT); break;
    case 'H': Keyboard.press(KEY_HOME); Keyboard.release(KEY_HOME); break;
    case 'U': Keyboard.press(KEY_PAGE_UP); Keyboard.release(KEY_PAGE_UP); break;
    case 'D': Keyboard.press(KEY_DELETE); Keyboard.release(KEY_DELETE); break;
    case 'E': Keyboard.press(KEY_END); Keyboard.release(KEY_END); break;
    case 'G': Keyboard.press(KEY_PAGE_DOWN); Keyboard.release(KEY_PAGE_DOWN); break;
    case 'L': Keyboard.press(KEY_LEFT_ARROW); Keyboard.release(KEY_LEFT_ARROW); break;
    case 'N': Keyboard.press(KEY_DOWN_ARROW); Keyboard.release(KEY_DOWN_ARROW); break;
    case 'U': Keyboard.press(KEY_UP_ARROW); Keyboard.release(KEY_UP_ARROW); break;
    default: break;
  }
}

