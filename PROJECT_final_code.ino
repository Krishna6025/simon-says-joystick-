#define joyX A0
#define joyY A1
#define buttonPin 2 // Pin for the button

// Declarations
int xValue;
int yValue;
int top = 8;
int right = 4;
int left = 11;
int bottom = 3;
int n, i;
int simon[20];
int says[10];
bool userInputCorrect = true;

void setup() {
  Serial.begin(9600);
  pinMode(bottom, OUTPUT);
  pinMode(left, OUTPUT);
  pinMode(top, OUTPUT);
  pinMode(right, OUTPUT);
  digitalWrite(top, LOW);
  digitalWrite(right, LOW);
  digitalWrite(bottom, LOW);
  digitalWrite(left, LOW);
  pinMode(7, OUTPUT);
  pinMode(2, INPUT_PULLUP); 
  // Random number generator
  randomSeed(analogRead(5));
}

void loop() {
 //press to start a new game
  while (digitalRead(buttonPin) == HIGH) {
    delay(10); // debounce delay
  }
  delay(500); 

  // No of lights to show
  n =1;
  Serial.println(n);
  Serial.println("====");

  // What lights to turn on
  for (i = 0; i < n; i++) {
    simon[i] = random(4);
    Serial.println(simon[i]);
    delay(50);
  }

  // Turning on the lights
  for (i = 0; i < n; i++) {
    if (simon[i] == 0) {
      digitalWrite(top, HIGH);
      delay(300);
      digitalWrite(top, LOW);
    } else if (simon[i] == 1) {
      digitalWrite(right, HIGH);
      delay(300);
      digitalWrite(right, LOW);
    } else if (simon[i] == 2) {
      digitalWrite(bottom, HIGH);
      delay(300);
      digitalWrite(bottom, LOW);
    } else if (simon[i] == 3) {
      digitalWrite(left, HIGH);
      delay(300);
      digitalWrite(left, LOW);
    } else {
      digitalWrite(left, LOW);
    }
  }

  delay(800);

  // Joystick values and user input
  for (i = 0; i < n; i++) {
    xValue = analogRead(joyX);
    yValue = analogRead(joyY);
    Serial.print(xValue);
    Serial.print("\t");
    Serial.println(yValue);


    if (xValue >= 750 && yValue >= 300) {
      digitalWrite(bottom, HIGH);
      says[i] = 2; 
    } else if (xValue >= 350 && yValue >= 750) {
      digitalWrite(left, HIGH);
      says[i] = 3; 
    } else if (xValue <= 0 && yValue >= 300) {
      digitalWrite(top, HIGH);
      says[i] = 0; 
    } else if (xValue >= 300 && yValue < 350) {
      digitalWrite(right, HIGH);
      says[i] = 1; 
    } else {
      userInputCorrect = false;
    }

    // Compare the arrays
    if (simon[i] != says[i]) {
      userInputCorrect = false;
      break;
    }

    // Reset 
    says[i] = 0;
    digitalWrite(left, LOW);
    digitalWrite(bottom, LOW);
    digitalWrite(right, LOW);
    digitalWrite(top, LOW);


  }


  if (userInputCorrect) {

    Serial.println("Correct!");
   digitalWrite(7,HIGH);
    delay(50);
    digitalWrite(7,LOW);
  } else {

    Serial.println("Incorrect!");
    digitalWrite(10,HIGH);
    delay(50);
    digitalWrite(10,LOW);
  }


  while (digitalRead(2) == HIGH) {
    delay(10); 
  }
  delay(500); 
}