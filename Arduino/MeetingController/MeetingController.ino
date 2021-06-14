/*
  MeetingController - No Toggle
  created 25 Feb 2021
  by Hugh Elliott (hugh@thinkingbox.com)
  Original example code is in the public domain.
  http://www.arduino.cc/en/Tutorial/KeyboardMessage
  Thanks Hugh - Ben
  I updated the camera but to switch btw desktops
*/

#include "Keyboard.h"

const int windowPin = 7;
const int mutePin = 6;
const int cameraPin = 5; 

int windowState = 0; 
int muteState = 0;
int cameraState = 0; 
int prevWinState = 1;
int prevMuteState = 1;
int prevCamState = 1;
int desktopState = 0;
int prevDesktopState = 1;
boolean windowToggle = false;
boolean muteToggle = false;
boolean cameraToggle = false;

void setup() {
  // make the pushButton pin an input:
  pinMode(windowPin, INPUT);
  pinMode(mutePin, INPUT);
  pinMode(cameraPin, INPUT);
  // initialize control over the keyboard:
  digitalWrite(windowPin,LOW);
  digitalWrite(mutePin,LOW);
  digitalWrite(cameraPin,LOW);
  Keyboard.begin();
  //Serial.begin(9600);
}
void loop() {
  windowState = digitalRead(windowPin);
  muteState = digitalRead(mutePin);
  cameraState = digitalRead(cameraPin);
  if(windowState == HIGH){
    windowToggle = true;
  }else{
    if(windowToggle == true){
      Keyboard.press(KEY_LEFT_GUI);
      delay(20);
      Keyboard.press('d');
      delay(20);
      Keyboard.releaseAll(); 
      windowToggle = false;
    }
  }
  if(muteState == HIGH){
    muteToggle = true;
  }else{
    if(muteToggle == true){
      Keyboard.press(KEY_LEFT_GUI);
      delay(100);
      Keyboard.press('w');
      Keyboard.releaseAll();
      muteToggle = false;
    }
  }
  if(cameraState == HIGH){
    cameraToggle = true;
  }else{
    if(cameraToggle == true){
      if(desktopState == 0)
      {
      Keyboard.press(KEY_RIGHT_CTRL);
      delay(20);
      Keyboard.press(KEY_RIGHT_ARROW);
      Keyboard.releaseAll();
      desktopState = 1;
      cameraToggle = false;
      }
      else
      {
      Keyboard.press(KEY_RIGHT_CTRL);
      delay(20);
      Keyboard.press(KEY_LEFT_ARROW);
      Keyboard.releaseAll();
      desktopState = 0;
      cameraToggle = false; 
      }
      }
    }
  }
