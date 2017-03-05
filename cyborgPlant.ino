#include <TimeLib.h>


time_t lastPressed;

// constants won't change. They're used here to 
// set pin numbers:
const int buttonPin = 13;     // the number of the pushbutton pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton statu

int pinA0;
int pinB0;
int pinC0;
int pinD0;
int pinA1;
int pinB1;
int pinC1;
int pinD1;

void setup() {
  // initialize the LED pin as an output:
  Serial.begin(9600);  
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);   

  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  //Initialize lastPressed to the current time
  lastPressed = now();
}

void loop(){
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  Serial.println(buttonState);
  if(buttonState){
    lastPressed = now();
    Serial.println("hey");
  }
  time_t t = now();
  
  int days = daysSincePressed(t); 
  
  displayNumber(days%10, 4);
  displayNumber(days/10, 8);
}

//displa offset - pass in 4 for displa 0 and 8 for display 1
void displayNumber(int n, int displayOffset){
  int binNumOutput;
  int currentHL; 
  binNumOutput = decToBinaryDigit(n);
  
  //Check rightmost bit (D)     
  currentHL = binNumOutput%10;
  if (currentHL == 1){
    digitalWrite(0+displayOffset,  HIGH);
  }else{
    digitalWrite(0+displayOffset,  LOW);
  }
  binNumOutput = binNumOutput / 10;
  
  //Check second to right bit (C)
  currentHL = binNumOutput%10; 
  if (currentHL == 1){
    digitalWrite(1+displayOffset,  HIGH);
  }else{
    digitalWrite(1+displayOffset,  LOW);
  }
  binNumOutput = binNumOutput / 10;
  
  //Check 2nd to left bit (B)
  currentHL = binNumOutput%10; 
  if (currentHL == 1){
    digitalWrite(2+displayOffset,  HIGH);
  }else{
    digitalWrite(2+displayOffset,  LOW);
  }  
  binNumOutput = binNumOutput / 10;
  
  //Check left bit (A)
  currentHL = binNumOutput%10;
  if (currentHL == 1){
    digitalWrite(3+displayOffset,  LOW);
  }else{
    digitalWrite(3+displayOffset,  LOW);
  }
}

int daysSincePressed(time_t t){
  //Testing Code
  //int days = (t - lastPressed)/3;
  //USE THIS LINE FOR ACTUAL RUNNING
  int days = (t - lastPressed)/60/60/24
  return days;
}

int decToBinaryDigit(int num){
    int result;

    switch (num) {
      case 0:
        result = 0;
        break;
      case 1:
        result = 1;
        break;
      case 2:
        result = 10;
        break;
      case 3:
        result = 11;
        break;
      case 4:
        result = 100;
        break;
      case 5:
        result = 101;
        break;
      case 6:
        result = 110;
        break;
      case 7:
        result = 111;
        break;
      case 8:
        result = 1000;
        break;
      case 9:
        result = 1001;
        break;
    }
    return result;
}
