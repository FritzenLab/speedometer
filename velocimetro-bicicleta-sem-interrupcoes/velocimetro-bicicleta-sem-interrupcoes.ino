// Variables used on this code

unsigned long timet;
unsigned long tempoativo1inicio;
unsigned long tempoativo2inicio;
unsigned long tempoativo3inicio;
unsigned long tempoativo1final;
unsigned long tempoativo2final;
unsigned long tempoativo3final;
unsigned long tempototal1;
unsigned long tempototal2;
unsigned long tempototal3;

unsigned long previousTime;
unsigned long previousTime2;
unsigned long previousTime3;
boolean enterFunction = true;
boolean enterFunction2 = true;
boolean enterFunction3 = true;
//-----------------------

#define sensorReed 7
boolean estadoSensor= false;
boolean estadoAnterior = false;
int contagem = 0;
unsigned long tempoDecorrido;
unsigned long tempoAnterior;

void setup() {
  // nothing happens in setup
  pinMode(sensorReed, INPUT);
  Serial.begin(9600);
  pinMode(12, OUTPUT);
}

void loop() {

   timet = micros();
  if (enterFunction == true){
    previousTime= timet;
    //Serial.println(previousTime); // for debugging

    // Write your first code below 
    //-----------------------

    
    
    estadoSensor = digitalRead(sensorReed);
        
    if (estadoSensor == HIGH){
      if(estadoAnterior == false){
        tempoAnterior = micros();
        estadoAnterior = true;
      } else{
        
      }
    } else{
      if (estadoAnterior == true){
        tempoDecorrido = micros() - tempoAnterior;
        estadoAnterior = false;
        contagem = contagem + 1;
      } else{
        
      }      
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
    
    Serial.print("pulsos em 1 segundo= ");
    Serial.println(contagem);
    contagem = 0;
    



    //-----------------------
    // End of your second code    
    }   


//------------------------
  // Your third code (different timing) starts here

  if (enterFunction3 == true){
    previousTime3= timet;
       
    // Write your third code below 
    //-----------------------


    PORTB ^= _BV(PB3);


    
    //-----------------------
   // End of your third code
   } 
  
  
  // The DELAY time is adjusted in the constant below >> 
  if (timet - previousTime < 5000){ // 1 million microsencods= 1 second delay
    /* I have actually used 0.999990 seconds, in a trial to compensate the time that
       this IF function takes to be executed. this is really a point that
       need improvement in my code */   
    enterFunction= false;
  } 
  else {
    enterFunction= true;
  }

  if (timet - previousTime2 < 999990){ // 500,000 microsencods= 0.5 seconds delay
      enterFunction2= false;
  } 
  else {
    enterFunction2= true;
  }
  
    // The DELAY time is adjusted in the constant below >> 
  if (timet - previousTime3 < 50000){ // 30,000 microsencods= 30 milisecond delay
      enterFunction3= false;
  } 
  else {
    enterFunction3= true;
  }

  

}
