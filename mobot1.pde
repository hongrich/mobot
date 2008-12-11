
void goForward(int s);
void enableMotors(void);
void coastMotors(void);
void leftMotor(int dir, int mSpeed);
void leftMotorBrake(void);
void rightMotor(int dir, int mSpeed);
void rightMotorBrake(void);
void stop(void);
void turnLeft(void);

int E1 = 13;                //enable 1, pin 13
int E2 = 8;                 //enable 2, pin 8
int I1 = 11;                
int I2 = 12;                //for PWM
int I3 = 9;
int I4 = 10;                //for PWM

void setup()                    // run once, when the sketch starts
{
  pinMode(E1, OUTPUT);      // sets the digital pin as output
  pinMode(E2, OUTPUT);
  pinMode(I1, OUTPUT);
  pinMode(I2, OUTPUT);
  pinMode(I3, OUTPUT);
  pinMode(I4, OUTPUT);
}

void loop()                     // run over and over again
{
  goForward(128);
  
  delay(1000);                  // waits for a second
  stop();
  delay(1000);                  // waits for a second
  turnLeft();
  delay(1000);                  // waits for a second
  stop();
  delay(1000);
}

//goForward runs the mobot forward
//full speed, 0 to 255
void goForward(int s = 255)
{
  enableMotors();
  leftMotor(0, s);
  rightMotor(0, s);
  
}

void enableMotors()
{
  digitalWrite(E1, HIGH);
  digitalWrite(E2, HIGH);
}

void coastMotors()
{
 digitalWrite(E1, LOW);
 digitalWrite(E2, LOW); 
}

void leftMotor(int dir, int mSpeed)
{
  if(mSpeed == 0)
 {
    //brake the motor
    leftMotorBrake();
 }
 else
 {
   
   
   if(dir == 0)
   {
     mSpeed = (mSpeed - 255) * (-1);
     digitalWrite(I4, HIGH);
     analogWrite(I3, mSpeed);
   }
   else
   {
     digitalWrite(I4, LOW);
     analogWrite(I3, mSpeed);
   }
 }
}

void leftMotorBrake()
{
 digitalWrite(I4, LOW);
 digitalWrite(I3, LOW); 
}

void rightMotor(int dir, int mSpeed)
{
  if(mSpeed == 0)
 {
    //brake the motor
    rightMotorBrake();
 }
 else
 {
   //go forward
   if(dir == 0)
   {
     digitalWrite(I2, LOW);
     analogWrite(I1, mSpeed);
   }
   else  //go backward
   {
     digitalWrite(I2, HIGH);
     analogWrite(I1, (mSpeed - 255) * (-1));
   }
 }
}

void rightMotorBrake()
{
 digitalWrite(I1, LOW);
 digitalWrite(I2, LOW); 
}

void stop()
{
 leftMotorBrake();
 rightMotorBrake(); 
}

void turnLeft()
{
  rightMotor(0, 255);
  digitalWrite(E2, LOW);
}
