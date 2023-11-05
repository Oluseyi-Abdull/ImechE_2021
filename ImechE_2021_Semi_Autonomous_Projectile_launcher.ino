#include <Servo.h>
Servo myservo;// initializing sevo 1 (Rotating base Servo)
Servo myservo2; // intializing servo 2 (String Servo)
const int ma = 5; // Motor mechanism
const int mb = 6; // Motor spooling
const int buzzPin = 7; // Buzzer pin
const int Red = 11; // Red Led
const int Amber = 12;// Amber Led
const int Green = 13; // Green Led
volatile int count = 0;//used for interrupts
int counter = 0; // counter int
int lastcount = 0;
int startpos = 0; // servo motor start position
int pos; // pos start reading
int pos2; // pos2 for servo2
int x = 10;//insert angle1 num here ;
int y = 20;//insert angle2 num here ;
int z = 30;//insert angle3 num here ;
// constant variable for Notes
const int e5 = 659;
const int d5 = 587; 
const int fs4 = 370;
const int gs4 = 415;
const int cs5 = 554;
const int b4 = 494;
const int d4 = 294;
const int e4 = 330;
const int a4 = 440;
const int cs4 = 277; 



void setup() { // setup loop and initialize inputs
  pinMode(Red, OUTPUT); //Red LED pin
  pinMode(Amber, OUTPUT); //Amber LED Pin
  pinMode(Green, OUTPUT); //Green LED Pin
  pinMode(ma, OUTPUT); //Mech. Motor Pin
  pinMode(mb, OUTPUT); //String Motor Pin
  pinMode(buzzPin, OUTPUT); //Ding dong
  Serial.begin(9600); // Serial monitor intialization
  attachInterrupt(0, i, RISING); // Interrupts set to when the input increases, when the button is pressed .
  myservo.attach(9); // Select pin for servo (Rotating Base)
  myservo2.attach(10); //  select pin for servo2 (String Servo)
  myservo.write(0); // put servo to one of the limits to calibrate
  //should be at 0 degree position
  myservo2.write(0);// Calibrate servo2
  //make sure to put them in the correct order and to include the delays
}

void loop() {
  digitalWrite(Red, HIGH);
  if (count == 1 && count != lastcount)
  {
    lastcount = count;
    Serial.print("One");
    Serial.print(lastcount);
    for (pos2 = 0; pos2 <= 90; pos2 += 1) // increases in incriments of +1
    {
      myservo2.write(pos2); //new position on the second servo
      delay(20); // delay by 20ms so the servo reads the correct position
      //before moving onto the next
      digitalWrite(Red, LOW); // set red led to high
      digitalWrite(Amber, HIGH); // set amber led to high
      Serial.println(myservo2.read());
    }

    for (pos = 0; pos <= x; pos += 1) // increases in incriments of +1
    {
      myservo.write(pos);// new positon
      delay(20); // delay by 20ms so the servo reads the correct position
      //before moving onto the next
      digitalWrite(Red, LOW); // set red led to high
      digitalWrite(Amber, HIGH); // set amber led to high
      Serial.println(myservo.read());

      if (myservo.read() == x)
      {
        digitalWrite(Amber, LOW); // amber led to low
        digitalWrite(Green, HIGH); // green led high
        delay(1000);//delay 1/s
        digitalWrite(ma, HIGH); // set motor to high
        delay(4000);//delay for one rotation
        digitalWrite(ma, LOW); // set motor to low
        digitalWrite(Green, LOW);
        delay(1000);//delay 1/s
        Melody();
        delay(500);
      }
    }
    for (pos > x; pos >= 0; pos -= 1) // decrements by 1 to calibration position
    {
      //Serial.println("GO");
      myservo.write(pos); //new position on the second servo
      delay(20);  // small delay for accuracy
      digitalWrite(Red, LOW); // set red led to high
      digitalWrite(Amber, HIGH); // set amber led to high
      Serial.println("NEW");
      Serial.println(myservo.read());
    }
    for (pos2 > 90; pos2 >= 0; pos2 -= 1) // decrements measures of 1
    {
      myservo2.write(pos2); //new position on the second servo
      delay(20); // delay by 20ms so the servo reads the correct position
      //before moving onto the next
      digitalWrite(Red, LOW); // set red led to high
      digitalWrite(Amber, HIGH); // set amber led to high
      //Serial.println("POS2");
      //Serial.print(pos2);


      if (pos2 == 0) {
        delay(1500);
        digitalWrite(Amber, LOW); // amber led to low
        digitalWrite(Green, HIGH); // green led high
        digitalWrite(mb, HIGH); // set motor to high
        delay(6015);//delay for one rotation
        digitalWrite(mb, LOW); // set motor to low
        digitalWrite(Green, LOW);
      }
    }
  }
  if (count == 2 && count != lastcount)
  {
    lastcount = count;
    Serial.print("two");
    Serial.print(lastcount);
    for (pos2 = 0; pos2 <= 90; pos2 += 1) // increases in incriments of +1
    {
      myservo2.write(pos2); //new position on the second servo
      delay(20); // delay by 20ms so the servo reads the correct position
      //before moving onto the next
      digitalWrite(Red, LOW); // set red led to high
      digitalWrite(Amber, HIGH); // set amber led to high
      Serial.println(myservo2.read());
    }

    for (pos = 0; pos <= y; pos += 1) // increases in incriments of +1
    {
      myservo.write(pos);// new positon
      delay(20); // delay by 20ms so the servo reads the correct position
      //before moving onto the next
      digitalWrite(Red, LOW); // set red led to high
      digitalWrite(Amber, HIGH); // set amber led to high
      Serial.println(myservo.read());

      if (myservo.read() == y)
      {
        digitalWrite(Amber, LOW); // amber led to low
        digitalWrite(Green, HIGH); // green led high
        delay(1000);//delay 1/s
        digitalWrite(ma, HIGH); // set motor to high
        delay(4000);//delay for one rotation
        digitalWrite(ma, LOW); // set motor to low
        digitalWrite(Green, LOW);
        delay(1000);//delay 1/s
      }
    }
    for (pos > y; pos >= 0; pos -= 1) // decrements by 1 to calibration position
    {
      //Serial.println("GO");
      myservo.write(pos); //new position on the second servo
      delay(20);  // small delay for accuracy
      digitalWrite(Red, LOW); // set red led to high
      digitalWrite(Amber, HIGH); // set amber led to high
      Serial.println("NEW");
      Serial.println(myservo.read());
    }

    for (pos2 > 90; pos2 >= 0; pos2 -= 1) // decrements measures of 1
    {
      myservo2.write(pos2); //new position on the second servo
      delay(20); // delay by 20ms so the servo reads the correct position
      //before moving onto the next
      digitalWrite(Red, LOW); // set red led to high
      digitalWrite(Amber, HIGH); // set amber led to high
      //Serial.println("POS2");
      //Serial.print(pos2);

      if (pos2 == 0) {
        delay(1500);
        digitalWrite(Amber, LOW); // amber led to low
        digitalWrite(Green, HIGH); // green led high
        digitalWrite(mb, HIGH); // set motor to high
        delay(6015);//delay for one rotation
        digitalWrite(mb, LOW); // set motor to low
        digitalWrite(Green, LOW);
      }
    }
  }
  if (count == 3 && count != lastcount)
  {
    lastcount = count;
    Serial.print("three");
    Serial.print(lastcount);
    for (pos2 = 0; pos2 <= 90; pos2 += 1) // increases in incriments of +1
    {
      myservo2.write(pos2); //new position on the second servo
      delay(20); // delay by 20ms so the servo reads the correct position
      //before moving onto the next
      digitalWrite(Red, LOW); // set red led to high
      digitalWrite(Amber, HIGH); // set amber led to high
      Serial.println(myservo2.read());
    }

    for (pos = 0; pos <= z; pos += 1) // increases in incriments of +1
    {
      myservo.write(pos);// new positon
      delay(20); // delay by 20ms so the servo reads the correct position
      //before moving onto the next
      digitalWrite(Red, LOW); // set red led to high
      digitalWrite(Amber, HIGH); // set amber led to high
      Serial.println(myservo.read());

      if (myservo.read() == z)
      {
        digitalWrite(Amber, LOW); // amber led to low
        digitalWrite(Green, HIGH); // green led high
        delay(1000);//delay 1/s
        digitalWrite(ma, HIGH); // set motor to high
        delay(4000);//delay for one rotation
        digitalWrite(ma, LOW); // set motor to low
        digitalWrite(Green, LOW);
        delay(1000);//delay 1/s
      }
    }

    for (pos > z; pos >= 0; pos -= 1) // decrements by 1 to calibration position
    {
      //Serial.println("GO");
      myservo.write(pos); //new position on the second servo
      delay(20);  // small delay for accuracy
      digitalWrite(Red, LOW); // set red led to high
      digitalWrite(Amber, HIGH); // set amber led to high
      Serial.println("NEW");
      Serial.println(myservo.read());
    }

    for (pos2 > 90; pos2 >= 0; pos2 -= 1) // decrements measures of 1
    {
      myservo2.write(pos2); //new position on the second servo
      delay(20); // delay by 20ms so the servo reads the correct position
      //before moving onto the next
      digitalWrite(Red, LOW); // set red led to high
      digitalWrite(Amber, HIGH); // set amber led to high
      //Serial.println("POS2");
      //Serial.print(pos2);

      if (pos2 == 0) {
        delay(1500);
        digitalWrite(Amber, LOW); // amber led to low
        digitalWrite(Green, HIGH); // green led high
        digitalWrite(mb, HIGH); // set motor to high
        delay(6015);//delay for one rotation
        digitalWrite(mb, LOW); // set motor to low
        digitalWrite(Green, LOW);
      }
    }
  }
  digitalWrite(Red, HIGH);
}
void i() { // interrupt  initialization
  //count increment
  count ++;
  if (count > 3)
  { // if count is greater than 3 then it reurns back to zero
    count = 0; // count starts at zero
  }
  Serial.println(count); // checking the interrupt button for the number of times pressed,
}

void play(int note, int duration){
  tone(buzzPin, note, duration);
  delay(duration);
  noTone(buzzPin);
  delay(50);
}

void Melody(){
  play(e5, 150);
  play(d5, 150);
  play(fs4, 300);
  play(gs4, 300);
  play(cs5, 150);
  play(b4, 150);
  play(d4, 300);
  play(e4, 300);
  play(b4, 150);
  play(a4, 150);
  play(cs4, 300);
  play(e4, 300);
  play(a4, 500);

  delay(500);
}
