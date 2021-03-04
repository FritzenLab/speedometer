#include <TM1637TinyDisplay.h>
#include <avr/pgmspace.h>

// Define Digital Pins
#define CLK 4
#define DIO 5

// Initialize TM1637TinyDisplay
TM1637TinyDisplay display(CLK, DIO);

unsigned long timet;
unsigned long previousTime;
unsigned long previousTime2;
boolean enterFunction = true;
boolean enterFunction2 = true;

int sensorPin = 0;
boolean sensorWasLow = false;
boolean hasEnteredCounting = false;
float lapTime;
float initialLapTime;
float speedMs;
float tyreCircumference= 2298;
float speedKmh;
#define led 1
//-----------------------

void setup() {
  // nothing happens in setup
  pinMode(led, OUTPUT);
  pinMode(3, INPUT);
  display.setBrightness(BRIGHT_7);
    
}

void loop() {

   timet = micros();
  if (enterFunction == true){
    previousTime= timet;
    //Serial.println(previousTime); // for debugging

    // Write your first code below 
    //-----------------------

    sensorPin= digitalRead(3); // read the speed sensor
    
    if (sensorPin == HIGH && sensorWasLow == true && hasEnteredCounting == false){ // if the sensor is HIGH/Activated, the last sensor state was LOW and has not entered the loop yet
      hasEnteredCounting = true; //makes the code enter here only once per 'lap'
      sensorWasLow = false; // says that the sensor was HIGH the last time 
      lapTime = millis()- initialLapTime;
      speedMs= tyreCircumference / lapTime; // Calculate the SPEED here
      speedKmh= speedMs * 3.6;
      initialLapTime = millis();
      
    } else if (sensorPin == HIGH && hasEnteredCounting == true){ // Enter here if the sensor is still HIGH (from second passage on)
      // Does nothing while the sensor is still HIGH
      
    } else if(sensorPin == LOW && hasEnteredCounting == true){ // Enter here if the sensor was HIGH and now is LOW
      hasEnteredCounting = false;
      
    } else{ 
      // Does nothing while the sensor is still LOW
      sensorWasLow = true;
    }
  



    //-----------------------
    // End of your first code
  }  
   

  //------------------------
  // Your second code (different timing) starts here

  if (enterFunction2 == true){
    previousTime2= timet;
    //Serial.println(previousTime2); // for debugging

    // Write your second code below 
    //-----------------------
    

    digitalWrite(led, !digitalRead(led));
    display.clear();
    display.showNumber(speedKmh, false, 4, 0);
    
    //-----------------------
    // End of your second code    
    }   
  // The DELAY time is adjusted in the constant below >> 
  if (timet - previousTime < 9999){ // 1 million microsencods= 1 second delay
    /* I have actually used 0.999990 seconds, in a trial to compensate the time that
       this IF function takes to be executed. this is really a point that
       need improvement in my code */   
    enterFunction= false;
  } 
  else {
    enterFunction= true;
  }

  if (timet - previousTime2 < 999999){ 
      enterFunction2= false;
  } 
  else {
    enterFunction2= true;
  }
    

  

}
