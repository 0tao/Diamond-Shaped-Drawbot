#include <AFMotor.h>
#include <NewPing.h>
<<<<<<< HEAD
#define TRIGGER_PIN  A5  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     A4  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

///////////////////////////////////LED FADE SETUP///////////////////////////////
int brightness = 0;    // how bright the LED is
int fadeAmount = 1;    // how many points to fade the LED by
unsigned long currentTime;
unsigned long loopTime;

//////////////LED BLINK
// Variables will change:
int ledState = HIGH;             // ledState used to set the LED
long previousMillis = 0;        // will store last time LED was updated

// the follow variables is a long because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long interval = 500;           // interval at which to blink (milliseconds)
////////////////////////////////////////////////////


//////////////////////////////DECLARE THE MOTION SENSOR////////////////////
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.


/////////////////////////////////////////////////////////////////////////////DRAWING SPACE SETUP//////////////////////////////////////////////////////////
int drawingWidth = 90; // width of the drawing space in CM
int motorSpeed = 1;  //the speed of the motors  (6-7 is about the max speed with a weight  - 2-3 max without weight)
=======

#define TRIGGER_PIN  A4  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     A5  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 300 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

int ledPin = 14;  //define the pin that the LED is on
int motorSpeed = 20;  //the speed of the motors  (6-7 is about the max speed with a weight  - 2-3 max without weight)
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.



/////////////////////////////////////////////////////////////////////////////DRAWING SPACE SETUP//////////////////////////////////////////////////////////
int drawingWidth = 80; // width of the drawing space in CM
>>>>>>> master
/////// 1000 steps = 30cm wide diamond
/////// 1cm = 33.3 steps
/////// 
/////// 
/////// 

int upperLimit = 1;  //the top of the drawing space
int lowerLimit = drawingWidth*33; // the size of the sides of the diamond (roughly - adjust to suit on install)
int L = lowerLimit-1; // Left motor string length - at the bottom of the drawing space (-1 because we add 1 in the setup to engage motors)
int R = lowerLimit-1; // Right Motor string length - within the defined space above (-1 because we add 1 in the setup to engage motors)

///////////////////////////////// DRAWING STYLE VARIABLES - probably get these sorted out before the show ///////////////////////////
int stepSizeLimit = 30; //this is for the MediumStep function - currently not used
int lateralLineLimit; // this is the max length of the long lateral lines when going up or down
int lineGap; // max 'large gap' between dense lines
int randoChoice;
int lineGapChoice;
<<<<<<< HEAD
int randoChoiceLimit;

int lateralLineLargeLimit = 500;
int lateralLineSmallLimit = 40;
int percentChanceOfChoosingLargeLineLimit = 30;


int lineGaplargeLimit = 100; 
int lineGapSmallLimit = 3;
int percentChangeOfChoosingGapLargeLimit = 50;

//////////////////////VERTICAL LINES//////////////

int verticalSizeLineLimit = 400;

// Stepper 200 steps per revolution (or change to 400 for interleave)
AF_Stepper LM(400, 2),RM(400,1);

////////////////////////////////////////////////////////////////////////////////////
void setup() {
  Serial.begin(38400);
  randomSeed(analogRead(0));// set up Serial library at 9600 bps
  ///////////////////////////////////////////LED fading variables//////////////
   // declare pin 2 to be an output:
  pinMode(2, OUTPUT);
  currentTime = millis();
  loopTime = currentTime;
  delay(2000);
  ///////////////////////////////////////MOTOR SETUP///////////////////////
  LM.setSpeed(motorSpeed); //initiate left motor speed
  RM.setSpeed(motorSpeed); //initiate right motor speed
  delay(2000);
  ///////////////////////////////////////ENGAGE Motors//////////////////
  RM.step(1, BACKWARD, INTERLEAVE); //engage right motor
  LM.step(1, BACKWARD, INTERLEAVE); //engage left motor
  delay(4000);
=======
// Stepper 200 steps per revolution (or change to 400 for interleave)
AF_Stepper LM(400, 2),RM(400,1);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void setup() {
  Serial.begin(38400);
  randomSeed(analogRead(0));// set up Serial library at 9600 bps
  delay(2000);
  LM.setSpeed(motorSpeed); //initiate left motor speed
  RM.setSpeed(motorSpeed); //initiate right motor speed
  delay(2000);
  RM.step(1, BACKWARD, INTERLEAVE); //engage right motor
  LM.step(1, BACKWARD, INTERLEAVE); //engage left motor
  pinMode(ledPin, OUTPUT);  
  delay(2000);  //wait 4 seconds, then start the bot going
>>>>>>> master
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void loop() {
<<<<<<< HEAD


  ////////////////////////////////////////////SENSOR INPUT for HC-SR04//////////////////////////////////////////////////////////////////////////////////////
  delay(50);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  //Serial.print("Ping: ");
  //Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
 // Serial.println("cm");
  
  
  ///////////////////////Do these things when sensor is active or not//////////////////////////
  while(sonar.ping_cm() <10){  //while the sensor is reading 'not much' set the motor speed to 0 and the LED to fade
  fadeLED();
    LM.setSpeed(1); //initiate left motor speed
    RM.setSpeed(1); //initiate right motor speed
    DefaultSmallStep();

  }
  while(sonar.ping_cm() >=10){ //while the sensor is reading HIGH, set motors moving and turn on the LED
    LM.setSpeed(3); //initiate left motor speed
    RM.setSpeed(3); //initiate right motor speed
    int choice = int(random(4));
    if (choice == 0){
    LeftSideUpLineShapes();
    fadeLED();
    } else if (choice ==1){
    RightSideUpLineShapes();
    fadeLED();
    } else if (choice ==2){
    LeftSideDownLineShapes();
    fadeLED();
    } else {
    RightSideDownLineShapes();
    fadeLED();
    }
  }
  
  //fadeLED();

  ////////////////////////////////////////////////////////////MOVE THE BOT WHILE TESTING BOUNDARIES////////////////////////////////////////////////////////////////////////////////// 
  /*
   LeftSideUpLineShapes();
   RightSideUpLineShapes();
   LeftSideDownLineShapes();
   RightSideDownLineShapes();
   */
   
  // DefaultSmallStep();
  //verticalLinesDown(); 
  //testBoundaries();
  //testBox();
}

=======
  
  
  /*
  ////////////////////////////////////////////SENSOR INPUT//////////////////////////////////////////////////////////////////////////////////////
  delay(50);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  Serial.print("Ping: ");
  Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");
  while(sonar.ping_cm() <10){  //while the sensor is reading 'not much' set the motor speed to 0 and the LED to off.
    digitalWrite(ledPin, LOW); 
    LM.setSpeed(0);
    RM.setSpeed(0);

  }
  while(sonar.ping_cm() >10){ //while the sensor is reading HIGH, set motors moving and turn on the LED
    digitalWrite(ledPin, HIGH); 
    LM.setSpeed(4);
    RM.setSpeed(4);
  }

  */
  


/////////////////////////////////////////////////////CHOOSE DRAWING STYLE BASED ON LINE LENGTH AND LINE GAP VARIABLES //////////////////////////////////////////////////////////////////////////////////////////
  

  
  ////////////////////////////////////////////////////////////MOVE THE BOT WHILE TESTING BOUNDARIES////////////////////////////////////////////////////////////////////////////////// 
  LeftSideUpLineShapes();
  RightSideDownLineShapes();
  LeftSideDownLineShapes();
  RightSideUpLineShapes();
  
 
  //testBoundaries();
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}
>>>>>>> master




