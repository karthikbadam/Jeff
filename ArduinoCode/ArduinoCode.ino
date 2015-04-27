  
  // Modified by Karthik Badam for CMSC838f MP4
  
  /* Based on Sweep
   by BARRAGAN <http://barraganstudio.com> 
   This example code is in the public domain.
  
   modified 8 Nov 2013
   by Scott Fitzgerald
   http://arduino.cc/en/Tutorial/Sweep
  */ 
  
  #include <Servo.h> 
   
  Servo myservo;  // create servo object to control a servo 
                  // twelve servo objects can be created on most boards
  
  Servo myservo2;  // create servo object to control a servo 
                  // twelve servo objects can be created on most boards
  
   
  int pos = 0;    // variable to store the servo position 
  
  int servo1 = 10; 
  
  int servo2 = 9; 
   
  void transition (Servo myservo, int startAngle, int endAngle) {
    
    myservo.write(startAngle); 
    
    int movement = endAngle - startAngle; 
    
    if (movement > 0) {
      for(pos = startAngle; pos <= endAngle; pos += 1) {                                   
        myservo.write(pos);               
        delay(3);  
      }      
    } else {
      for(pos = startAngle; pos>=endAngle; pos-= 1) {                                
        myservo.write(pos);              
        delay(3);    
      }      
    }
  }  
  
  void transitionBoth (Servo myservo, Servo myservo2, int startAngle, int endAngle) {
    
    myservo.write(startAngle); 
    myservo2.write(startAngle);
    
    int movement = endAngle - startAngle; 
    
    if (movement > 0) {
      for(pos = startAngle; pos <= endAngle; pos += 1) {                                   
        myservo.write(pos);
        myservo2.write(180-pos);        
        delay(3);  
      }      
    } else {
      for(pos = startAngle; pos>=endAngle; pos-= 1) {                                
        myservo.write(pos);              
        myservo2.write(180-pos);        
        delay(3);    
      }      
    }
  }  
  
  
  // for right hand
  void state1 (Servo myservo) {
    
    int startAngle = 30; 
    int endAngle = 150;
    
    transition (myservo, startAngle, endAngle);
    
    delay (1000); 
    
    startAngle = 150; 
    endAngle = 30;
    
    transition (myservo, startAngle, endAngle);
   
  }
  
  // left hand
  void state2 (Servo myservo) {
     
    int startAngle = 30; 
    int endAngle = 160;
    
    transition (myservo, startAngle, endAngle);
    
    startAngle = 160; 
    endAngle = 100;
    
    transition (myservo, startAngle, endAngle);
    
    delay (50); 
    
    startAngle = 100; 
    endAngle = 160;
    
    transition (myservo, startAngle, endAngle);
    
    delay (50); 
    
    startAngle = 160; 
    endAngle = 100;
    
    transition (myservo, startAngle, endAngle);
    
    delay (50); 
    
    startAngle = 100; 
    endAngle = 160;
    
    delay (50); 
    
    transition (myservo, startAngle, endAngle);
    
    startAngle = 160; 
    endAngle = 30;
    
    transition (myservo, startAngle, endAngle);
   
  }
  
  // both hands
  void state3 (Servo myservo, Servo myservo2) {
    
    int startAngle = 30; 
    int endAngle = 130;
    
    transitionBoth (myservo, myservo2, startAngle, endAngle);
    
    startAngle = 130; 
    endAngle = 30;
    
    transitionBoth (myservo, myservo2, startAngle, endAngle);
    
  }
  
  // both hands
  void state4 (Servo myservo, Servo myservo2) {
    
    int startAngle = 30; 
    int endAngle = 170;
    
    transitionBoth (myservo, myservo2, startAngle, endAngle);
    
    delay (500);
    
    startAngle = 170; 
    endAngle = 30;
    
    transitionBoth (myservo, myservo2, startAngle, endAngle);
    
  }
  
  void ByteToChar(byte* bytes, char* chars, unsigned int count){
    for(unsigned int i = 0; i < count; i++)
    	 chars[i] = (char)bytes[i];
  
  }
   
  void setup() 
  { 
    myservo.attach(servo1);  // attaches the servo on pin 10 to the servo object 
    myservo2.attach(servo2);  // attaches the servo on pin 9 to the servo object 
  
    Serial.begin(9600);  
  } 
   
  void loop() 
  { 
   
    if (Serial.available() > 0)
    {
      byte inChar = Serial.read();
      int inVal = (int)inChar;
      
      if (inVal == 1) {
        state1 (myservo); 
      }
      
      if (inVal == 2) {
        state2 (myservo); 
      }
      
      if (inVal == 3) {
        state3 (myservo, myservo2); 
      }
      
      if (inVal == 4) {
      
        state4 (myservo, myservo2); 
      }
      
    }

  } 

