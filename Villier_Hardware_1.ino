//Author: Alex Villier
//Date:   3/20/2020
//YouTube Showcase: https://youtu.be/uoutn9wtW9A

const int ledPin = LED_BUILTIN;
const char message[] = "GEAUX TIGERS";
const int arrayLength = sizeof(message) / sizeof(message[0]);
const int morseSpeed = 250;
const int timeWithinLetter = morseSpeed;
const int timeForDot = morseSpeed;
const int timeForDash = 3 * morseSpeed;
const int timeBetweenLetters = 3 * morseSpeed;
const int timeBetweenWords = 7 * morseSpeed;

int ledState = LOW;
int letterPos = 0;
int interval = 0;
unsigned long prevMillis = 0;
unsigned long currMillis = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  currMillis = millis();

  if(currMillis - prevMillis >= interval){
    NextLetter();
    prevMillis = millis();
    if(letterPos >= arrayLength){
      letterPos = 0;
      interval = timeBetweenWords;
    }
    else if(message[letterPos] == ' '){
      interval = timeBetweenWords;
    }
    else{
      interval = timeBetweenLetters;
    }
  }
}

void NextLetter(){
  switch(message[letterPos]){
    case 'A': Dot();
              Dash();
            break;
    case 'B': Dash();
              Dot();
              Dot();
              Dot();
            break;
    case 'C': Dash();
              Dot();
              Dash();
              Dot();
            break;
    case 'D': Dash();
              Dot();
              Dot();
            break;
    case 'E': Dot();
            break;
    case 'F': Dot();
              Dot();
              Dash();
              Dot();
            break;
    case 'G': Dash();
              Dash();
              Dot();
            break;
    case 'H': Dot();
              Dot();
              Dot();
              Dot();
            break;
    case 'I': Dot();
              Dot();
            break;
    case 'J': Dot();
              Dash();
              Dash();
              Dash();
            break;
    case 'K': Dash();
              Dot();
              Dash();
            break;
    case 'L': Dot();
              Dash();
              Dot();
              Dot();
            break;
    case 'M': Dash();
              Dash();
            break;
    case 'N': Dash();
              Dash();
            break;
    case 'O': Dash();
              Dash();
              Dash();
            break;
    case 'P': Dot();
              Dash();
              Dash();
              Dot();
            break;
    case 'Q': Dash();
              Dash();
              Dot();
              Dash();
            break;
    case 'R': Dot();
              Dash();
              Dot();
            break;
    case 'S': Dot();
              Dot();
              Dot();
            break;
    case 'T': Dash();
            break;
    case 'U': Dot();
              Dot();
              Dash();
            break;
    case 'V': Dot();
              Dot();
              Dot();
              Dash();
            break;
    case 'W': Dot();
              Dash();
              Dash();
            break;
    case 'X': Dash();
              Dot();
              Dot();
              Dash();
            break;
    case 'Y': Dash();
              Dot();
              Dash();
              Dash();
            break;
    case 'Z': Dash();
              Dash();
              Dot();
              Dot();
            break;
  }
  letterPos++;
}

void Dot(){
  digitalWrite(ledPin, HIGH);
  delay(timeForDot);
  digitalWrite(ledPin, LOW);
  delay(timeWithinLetter);
}

void Dash(){
  digitalWrite(ledPin, HIGH);
  delay(timeForDash);
  digitalWrite(ledPin, LOW);
  delay(timeWithinLetter);
}
