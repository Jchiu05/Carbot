//Motor 1
int EN1 = 6;  //Enable
int DIR1 = 7; //Direction

//Motor 2
int EN2 = 5;
int DIR2 = 4;

int sensL = 12;
int sensR = 13;
int stateL = 0; //Used to save the state of Left sensor
int stateR = 0; //Used to save the state of Right sensor

void setup()
{
  //setup pins as inputs and outputs  
  pinMode (EN1, OUTPUT); 
  pinMode (DIR1, OUTPUT);
  pinMode (EN2, OUTPUT);
  pinMode (DIR2, OUTPUT); 

  pinMode (sensL, INPUT);
  pinMode (sensR, INPUT);
}

void loop()
{ 
  //Read the sensor pins and store them in a variable
  stateL= digitalRead(sensL);
  stateR= digitalRead(sensR);

  if(stateL == HIGH && stateR == HIGH) //If both sensors on, L&R on
  {
    digitalWrite(EN1, HIGH);
    digitalWrite(DIR1, HIGH);
    digitalWrite(EN2, HIGH);
    digitalWrite(DIR2, HIGH);
  }

  else if(stateL == HIGH && stateR == LOW) //If Left on, turn left
  {
    digitalWrite(EN1, HIGH);
    digitalWrite(DIR1, LOW);
    digitalWrite(EN2, HIGH);
    digitalWrite(DIR2, HIGH);
    
  }

  else if(stateL == LOW && stateR == HIGH) //If Right on, turn right
  {
    digitalWrite(EN1, HIGH);
    digitalWrite(DIR1, HIGH);
    digitalWrite(EN2, HIGH);
    digitalWrite(DIR2, LOW);
    
  }

  else if(stateL == LOW && stateR == LOW) //If both off, turn off
  {
    digitalWrite(EN1, LOW);
    digitalWrite(DIR1, HIGH);
    digitalWrite(EN2, LOW);
    digitalWrite(DIR2, HIGH);
  }
}

