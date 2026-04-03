//Variable Declaration
const int output = 9;
const int toggle = 13;

//Initializing table to compute sin values.
const int tableSize = 100;
uint8_t sinTable[tableSize];

bool lastButtonState = HIGH;

int waveType = 0;

void setup() {
  pinMode(output, OUTPUT);
  //Sets input pin's state w/o pressing button to HIGH.
  pinMode(toggle, INPUT_PULLUP);

  //Initializes baud rate to 115200 bits per second.
  Serial.begin(115200);

  //Fills sinTable with once cycle of sin wave.
  //Value is calculated from converting i / tableSize into radians, converting to sin value, and then scaling to 0 - 255 range for PWM.
  for (int i = 0; i < tableSize; i++) {
    sinTable[i] = 127 + 127  * sin(2 * PI * i / tableSize);
  }
}

void loop() {

  bool currentState = digitalRead(toggle);

    //If button is pressed increase waveType by 1, cycling around 0, 1, and 2.
     if (lastButtonState == HIGH && currentState == LOW) {
    waveType = (waveType + 1) % 3;

    if (waveType == 0) Serial.println("Sin Wave");
    if (waveType == 1) Serial.println("Square Wave");
    if (waveType == 2) Serial.println("Triangle Wave");

    delay(200);
  }

  lastButtonState = currentState;

  for (int i = 0; i < tableSize; i++) {
    int value;
    int delayTime;

    switch(waveType) {
      //If waveType == 0, use value from sinTable.
      case 0:
        value = sinTable[i];
        delayTime = 2500;
        break;

      //If waveType == 1, generate square wave.
      case 1:
        value = (i < tableSize / 2) ? 255 : 0;
        delayTime = 50;
        break;
      
      //If waveType == 2, generate triangle wave.
      case 2:
        if (i < tableSize / 2) {
        value = (i * 255) / (tableSize / 2);
    } else {
        value = 255 - ((i - tableSize / 2) * 255) / (tableSize / 2);
    }
    delayTime = 2500;
    break;
        
    }

    analogWrite(output, value);
    delayMicroseconds(delayTime);
  }
}
  
  
  