unsigned long timet;
unsigned long previousTime;
unsigned long previousTime2;
boolean enterFunction = true;
boolean enterFunction2 = true;

boolean sensorPin = false;
boolean sensorWasLow = false;
boolean hasEnteredCounting = false;
unsigned long lapTime;
unsigned long initialLapTime;
int led = 1; 
//-----------------------

void setup() {
  // nothing happens in setup
  pinMode(led, OUTPUT);
}

void loop() {

   timet = micros();
  if (enterFunction == true){
    previousTime= timet;
    //Serial.println(previousTime); // for debugging

    // Write your first code below 
    //-----------------------

    sensorPin= digitalRead(0); // read the speed sensor
    
    if (sensorPin == true && sensorWasLow == true && hasEnteredCounting == false){ // if the sensor is HIGH/Activated, the last sensor state was LOW and has not entered the loop yet
      hasEnteredCounting = true; //makes the code enter here only once per 'lap'
      sensorWasLow = false; // says that the sensor was HIGH the last time 
      lapTime = millis()- initialLapTime;
      initialLapTime = millis();
      
    } else { // if the sensor is NOT ACTIVATED
      sensorWasLow = true; // keeps track of the edge detection (from LOW to HIGH)
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
    

    //digitalWrite(led, !digitalRead(led));



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

  if (timet - previousTime2 < 249998){ 
      enterFunction2= false;
  } 
  else {
    enterFunction2= true;
  }
    

  

}
