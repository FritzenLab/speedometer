// Variables used on this code

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
// Inicializa o display no endereco 0x27
LiquidCrystal_I2C lcd(0x3F,2,1,0,4,5,6,7,3, POSITIVE);
    
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

#define sensorReed 2
boolean estadoSensor= false;
boolean estadoAnterior = false;
int contagem = 0;
float tempoDecorrido;
float tempoAnterior;

float velocidadems;
float velocidadekmh;
boolean jaentrou = true;
float distanciaVida;

void setup() {
  // nothing happens in setup
  lcd.begin (16,2);
  pinMode(sensorReed, INPUT);
  Serial.begin(9600);
  pinMode(12, OUTPUT);
  lcd.setBacklight(HIGH);
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
        // perimetro da roda da bicicleta aro 26: Raio x 2 x Pi
        // Perimetro = 0,33 x 2 x 3,1415 = 2,073451
        velocidadems= 2.073451 / (tempoDecorrido/1000000);
        
        //prevencao de erros de leitura
        if (velocidadems >= 100){
          velocidadems = 0;
        }
        //calculo da velocidade em km/h
        velocidadekmh= velocidadems * 3.6;
        //calculo da distancia total percorrida com equipamento ligado
        distanciaVida = distanciaVida + 0.002073451;
        // so deixa limpar o display se ele ainda nao foi limpo
        jaentrou = false;
                
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
    
    // Calculo de bicicleta parada
    if ((micros() - tempoAnterior) > 3000000) {
          velocidadems = 0.0000;
          velocidadekmh = 0.0000;
          jaentrou = true;
        }
        
    Serial.print("pulsos= ");
    Serial.println(contagem);
    Serial.print("tempo decorrido");
    Serial.println(tempoDecorrido);
          
    lcd.setCursor(3,0);
    lcd.print("km/h= ");
    lcd.print(velocidadekmh,1);
    /*lcd.setCursor(10,0);
    lcd.print("-----");*/
    lcd.setCursor(0,1);
    lcd.print("Total(km)= ");
    lcd.print(distanciaVida,2);
    //contagem = 0;


    //-----------------------
    // End of your second code    
    }   


//------------------------
  // Your third code (different timing) starts here

  if (enterFunction3 == true){
    previousTime3= timet;
       
    // Write your third code below 
    //-----------------------
    
   

   


    
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

  if (timet - previousTime2 < 299990){ // 500,000 microsencods= 0.5 seconds delay
      enterFunction2= false;
  } 
  else {
    enterFunction2= true;
  }
  
    // The DELAY time is adjusted in the constant below >> 
  if (timet - previousTime3 < 3999990){ // 30,000 microsencods= 30 milisecond delay
      enterFunction3= false;
  } 
  else {
    enterFunction3= true;
  }

  

}
