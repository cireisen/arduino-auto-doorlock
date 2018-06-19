#include <Keypad.h>  
const byte rows = 4;
const byte cols = 4;
char keys[rows][cols] = {
  {'1','2','3','4'},
  {'5','6','7','8'},
  {'9','a','b','c'},
  {'d','e','f','g'}
};

byte password[4];
byte passwordline=0;
byte nowpassword[4];
byte nowpasswordline=0;
byte rowPins[rows] = {2,3,4,5};
byte colPins[cols] = {6,7,8,9};
Keypad keypad = Keypad(makeKeymap(keys),rowPins,colPins,rows,cols);
byte ledPin = 13;
boolean blink = false;
boolean ledPin_state;
boolean isPassword=false;
boolean therepassword=false;
boolean Passwordright=true;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
  digitalWrite(ledPin,HIGH);
  ledPin_state = digitalRead(ledPin);
  keypad.addEventListener(keypadEvent);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  char key = keypad.getKey();
  if(key)
  {
    if(passwordline==4)
    {
       for(int i =0 ;i<4;i++)
        Serial.println(password[i]);
       passwordline=0;
       isPassword=false;
       therepassword=true;
    }
    if(nowpasswordline==4)
    {
      for(int i = 0 ;i<4;i++)
      {
        if(nowpassword[i]!=password[i])
          Passwordright=false;
      }
      if(Passwordright)
        Serial.println("비밀번호가 맞습니다.");
      else
        Serial.println("비밀번호가 다릅니다.");
        Passwordright=true;
        nowpasswordline=0;
    }
  }
  if(blink)
  {
    digitalWrite(ledPin,!digitalRead(ledPin));
    delay(100);
  }
  
}
void keypadEvent(KeypadEvent key){
    switch (keypad.getState()){
    case PRESSED:
        if (key == 'd') 
        {
                    // Remember LED state, lit or unlit.
            Passwordsetting(1);
        }
        else if (key == 'e') 
        {
                    // Remember LED state, lit or unlit.
            Passwordsetting(2);
        }
        else if (key == 'f') 
        {
                    // Remember LED state, lit or unlit.
            Passwordsetting(3);
        }
        else if (key == 'g') 
        {
                    // Remember LED state, lit or unlit.
            Passwordsetting(4);
        }
        else if (key == '9') 
        {
                    // Remember LED state, lit or unlit.
            Passwordsetting(5);
        }
        else if (key == 'a') 
        {
                    // Remember LED state, lit or unlit.
            Passwordsetting(6);
        }
        else if (key == 'b') 
        {
                    // Remember LED state, lit or unlit.
            Passwordsetting(7);
        }
        else if (key == 'c') 
        {
                    // Remember LED state, lit or unlit.
            Passwordsetting(8);
        }
        else if (key == '5') 
        {
                    // Remember LED state, lit or unlit.
            Passwordsetting(9);
        }
        else if (key =='4')
        {
          isPassword = true;
        }
        else if(key == '3')
        {
          for(int i = 0 ;i<4; i++)
            Serial.prinln(password[i]);
        }
        break;

    case RELEASED:
        if (key == '2') {
            digitalWrite(ledPin,ledPin_state);    // Restore LED state from before it started blinking.
            blink = false;
        }
        break;

    case HOLD:
        if (key == '2') {
            blink = true;    // Blink the LED when holding the * key.
        }
        break;
    }
}
void Passwordsetting(byte pass)
{
                    // Remember LED state, lit or unlit.
            if(isPassword)
            {
              password[passwordline]=pass;
              passwordline++;
            }
            else 
            {
              if(!therepassword)
                Serial.println("비밀번호를 초기화해주세요");
              else 
               {
                 nowpassword[nowpasswordline]=pass;
                 nowpasswordline++;
               }
            }
 }


