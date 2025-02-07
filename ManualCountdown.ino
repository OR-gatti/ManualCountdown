int pattern[10][7]={{HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,LOW },
                    {LOW ,HIGH,HIGH,LOW ,LOW, LOW, LOW },
                    {HIGH,HIGH,LOW, HIGH,HIGH,LOW, HIGH},
                    {HIGH,HIGH,HIGH,HIGH,LOW, LOW, HIGH},
                    {LOW, HIGH,HIGH,LOW, LOW, HIGH,HIGH},
                    {HIGH,LOW, HIGH,HIGH,LOW, HIGH,HIGH},
                    {HIGH,LOW, HIGH,HIGH,HIGH,HIGH,HIGH},
                    {HIGH,HIGH,HIGH,LOW, LOW, LOW, LOW },
                    {HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH},
                    {HIGH,HIGH,HIGH,HIGH,LOW, HIGH,HIGH}
};

int pinNo[7] = {2,3,4,5,6,7,8};
void display(int n){
  for(int i=0;i<7;i++){
    digitalWrite(pinNo[i], pattern[n][i]);
  }
}

const int buttonPin = 12;
int num =9;
boolean isHit = false;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  for(int i=0;i<7;i++){
    pinMode(pinNo[i], OUTPUT);
  }
}

void loop() {
  display(num);
  int buttonState = digitalRead(buttonPin);
  boolean isPushed = false;
  if (buttonState == LOW) {
    if (!isHit) {
      isHit = true;
      isPushed = true;
    }
  } else {
    isHit = false;
  }
 
  if (isPushed) {
    num--;
    if(num==-1){
      num=9;
      }
  }

  delay(50);
}
