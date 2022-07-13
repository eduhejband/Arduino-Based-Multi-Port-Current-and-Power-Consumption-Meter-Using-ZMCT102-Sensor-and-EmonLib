#include "EmonLib.h"                   // Include Emon Library
EnergyMonitor ZMCT102;                   // Create an instance
int Digital [] = {2,3,4,5,6};
int app [5];
int Sensor1 = A0;
int Sensor2 = A1;
int Sensor3 = A2;
int Sensor4 = A3;
int Sensor5 = A4;
int porta [5];


int tensao = 220;
float KWH = 0;
float KWH1;
float Isaida = 0.006;
float Pot = 0;
float x =0;
float y;
int t = 1;
int cont;
int i;
float Irms1;
float Irms2;
void setup()
{  
  Serial.begin(9600);
  //Pino, calibracao - Cur Const= Ratio/BurdenR. 2000/33 = 60
  ZMCT102.current(Sensor1, 6.78);
  ZMCT102.current(Sensor2, 6.78);
  ZMCT102.current(Sensor3, 6.78);
  ZMCT102.current(Sensor4, 6.78);
  ZMCT102.current(Sensor5, 6.78);
  //emon1.current(1, 39.1);             // Current: input pin, calibration.

  for (i=0;i<=4;i++){
    pinMode (app [i], INPUT);
    pinMode(Digital [i], OUTPUT);
    
    }
}

void loop()
{
  double Irms = ZMCT102.calcIrms(1480);  // Calculate Irms only
  Irms1 = Irms - (Irms * 0.3);
  Irms2 = Irms - (Irms * 0.5);
  cont =t++;
  for (i=0;i<=4;i++){
     porta [i] = digitalRead (app[i]);
     
    }

     if (porta [0] == 1){
     Serial.println ("\n\n\n______________");
     Serial.print ("\n Porta 1 aberta");
     analogRead (Sensor1);
     digitalWrite (Digital [0], HIGH);
   
       if(Irms >= 0.4 && Irms1 >= 0.4 && Irms2 >= 0.4 ){
       Serial.println ("\n\n Porta 1 carregando ");
       delay (100);
          if (Irms >=3 ){
          Pot = Irms * tensao;
          KWH = (Pot/1000)*cont;
          KWH1 +=KWH;
          delay(1000); //Espera 1 segundo
          //x=(((Pot)/1000)*Isaida); //calcula e guarda em x o valor do consumo em reais
         //y=y+x; //após 1 segundo, soma e guarda em y o valor de x
     
         Serial.print("\n Porta 1 - Corrente: ");
         Serial.print(Irms);
         Serial.println (" A");
         Serial.print("\n Porta 1 - Potência: ");
         Serial.print (Pot);
         Serial.println (" W");
         Serial.print("\n Porta 1 - Consumo: ");
         Serial.print (KWH1);
         Serial.println (" kW/h");
          
         }else if(Irms <3 && Irms >= 1){
         Pot = Irms1* tensao;
         KWH = (Pot/1000)*cont;
         KWH1 +=KWH;
         delay(1000); //Espera 1 segundo
         //x=(((Pot)/1000)*Isaida); //calcula e guarda em x o valor do consumo em reais
         //y=y+x; //após 1 segundo, soma e guarda em y o valor de x
   
         Serial.print("\n Porta 1 - Corrente: ");
         Serial.print(Irms1);
         Serial.println (" A");
         Serial.print("\n Porta 1 - Potência: ");
         Serial.print (Pot);
         Serial.println (" W");
         Serial.print("\n Porta 1 - Consumo: ");
         Serial.print (KWH1);
         Serial.println (" kW/h");
  
         }else if (Irms1 < 1){
         Pot = Irms2 * tensao;
         KWH1 +=KWH;
         KWH = (Pot/1000)*cont;
         delay(1000); //Espera 1 segundo
        //x=(((Pot)/1000)*Isaida); //calcula e guarda em x o valor do consumo em reais
        //y=y+x; //após 1 segundo, soma e guarda em y o valor de x
      
         Serial.print("\n Porta 1 - Corrente: ");
         Serial.print(Irms2);
         Serial.println (" A");
         Serial.print("\n Porta 1 - Potência: ");
         Serial.print (Pot);
         Serial.println (" W");
         Serial.print("\n Porta 1 - Consumo: ");
         Serial.print (KWH1);
         Serial.println (" kW/h");
  }
           
         }else{
         Serial.println ("\n Porta 1 não está carregando\n");
         delay (1000);  
     }
}else{
     Serial.println ("\n\n\n______________");
     Serial.print ("\n Porta 1 fechada");
     digitalWrite (Digital [0], LOW);
}

     if (porta [1] == 1){
     Serial.println ("\n\n\n______________");
     Serial.println ("\n Porta 2 aberta");
     digitalWrite (Digital [1], HIGH);
     analogRead (Sensor2);
       if(Irms >= 0.4 && Irms1 >= 0.4 && Irms2 >= 0.4 ){
       Serial.println ("\n\n Porta 2 carregando");
       delay (100);
          if (Irms >=3 ){
          Pot = Irms * tensao;
          KWH = (Pot/1000)*cont;
          KWH1 +=KWH;
          delay(1000); //Espera 1 segundo
          //x=(((Pot)/1000)*Isaida); //calcula e guarda em x o valor do consumo em reais
         //y=y+x; //após 1 segundo, soma e guarda em y o valor de x
     
         Serial.print("\n\n\n Porta 2 - Corrente: ");
         Serial.print(Irms);
         Serial.println (" A");
         Serial.print("\n Porta 2 - Potência: ");
         Serial.print (Pot);
         Serial.println (" W");
         Serial.print("\n Porta 2 - Consumo: ");
         Serial.print (KWH1);
         Serial.println (" kW/h");
          
         }else if(Irms <3 && Irms >= 1){
         Pot = Irms1* tensao;
         KWH = (Pot/1000)*cont;
         KWH1 +=KWH;
         delay(1000); //Espera 1 segundo
         //x=(((Pot)/1000)*Isaida); //calcula e guarda em x o valor do consumo em reais
         //y=y+x; //após 1 segundo, soma e guarda em y o valor de x
   
         Serial.print("\n\n\n Porta 2 - Corrente: ");
         Serial.print(Irms1);
         Serial.println (" A");
         Serial.print("\n Porta 2 - Potência: ");
         Serial.print (Pot);
         Serial.println (" W");
         Serial.print("\n Porta 2 - Consumo: ");
         Serial.print (KWH1);
         Serial.println (" kW/h");
  
         }else if (Irms1 < 1){
         Pot = Irms2 * tensao;
         KWH1 +=KWH;
         KWH = (Pot/1000)*cont;
         delay(1000); //Espera 1 segundo
        //x=(((Pot)/1000)*Isaida); //calcula e guarda em x o valor do consumo em reais
        //y=y+x; //após 1 segundo, soma e guarda em y o valor de x
      
         Serial.print("\n\n\n Porta 2 - Corrente: ");
         Serial.print(Irms2);
         Serial.println (" A");
         Serial.print("\n Porta 2 - Potência: ");
         Serial.print (Pot);
         Serial.println (" W");
         Serial.print("\n Porta 2 - Consumo: ");
         Serial.print (KWH1);
         Serial.println (" kW/h");
  }
           
         }else{
         Serial.println ("\n Porta 2 não está carregando");
         delay (1000);  
     }
}else{
     Serial.println ("\n\n\n______________");
     Serial.println ("\n Porta 2 fechada");
     digitalWrite (Digital [1], LOW);
}       
     if (porta [2] == 1){
     Serial.println ("\n\n\n______________"); 
     Serial.println ("\n Porta 3 aberta");
     digitalWrite (Digital [2], HIGH);
     analogRead (Sensor3);
       if(Irms >= 0.4 && Irms1 >= 0.4 && Irms2 >= 0.4 ){
       Serial.println ("\n\n Porta 3 carregando");
       delay (100);
          if (Irms >=3 ){
          Pot = Irms * tensao;
          KWH = (Pot/1000)*cont;
          KWH1 +=KWH;
          delay(1000); //Espera 1 segundo
          //x=(((Pot)/1000)*Isaida); //calcula e guarda em x o valor do consumo em reais
         //y=y+x; //após 1 segundo, soma e guarda em y o valor de x
     
         Serial.print("\n\n\n Porta 3 - Corrente: ");
         Serial.print(Irms);
         Serial.println (" A");
         Serial.print("\n Porta 3 - Potência: ");
         Serial.print (Pot);
         Serial.println (" W");
         Serial.print("\n Porta 3 - Consumo: ");
         Serial.print (KWH1);
         Serial.println (" kW/h");
          
         }else if(Irms <3 && Irms >= 1){
         Pot = Irms1* tensao;
         KWH = (Pot/1000)*cont;
         KWH1 +=KWH;
         delay(1000); //Espera 1 segundo
         //x=(((Pot)/1000)*Isaida); //calcula e guarda em x o valor do consumo em reais
         //y=y+x; //após 1 segundo, soma e guarda em y o valor de x
   
         Serial.print("\n\n\n Porta 3 - Corrente: ");
         Serial.print(Irms1);
         Serial.println (" A");
         Serial.print("\n Porta 3 - Potência: ");
         Serial.print (Pot);
         Serial.println (" W");
         Serial.print("\n Porta 3 - Consumo: ");
         Serial.print (KWH1);
         Serial.println (" kW/h");
  
         }else if (Irms1 < 1){
         Pot = Irms2 * tensao;
         KWH1 +=KWH;
         KWH = (Pot/1000)*cont;
         delay(1000); //Espera 1 segundo
        //x=(((Pot)/1000)*Isaida); //calcula e guarda em x o valor do consumo em reais
        //y=y+x; //após 1 segundo, soma e guarda em y o valor de x
      
         Serial.print("\n\n\n Porta 3 - Corrente: ");
         Serial.print(Irms2);
         Serial.println (" A");
         Serial.print("\n Porta 3 - Potência: ");
         Serial.print (Pot);
         Serial.println (" W");
         Serial.print("\n Porta 3 - Consumo: ");
         Serial.print (KWH1);
         Serial.println (" kW/h");
  }
           
         }else{
         Serial.println ("\n Porta 3 não está carregando");
         delay (1000);  
     }
}else{
     Serial.println ("\n\n\n______________");
     Serial.println ("\n Porta 3 fechada");
     digitalWrite (Digital [2], LOW);
}
     if (porta [3] == 1){
     Serial.println ("\n\n\n______________"); 
     Serial.println ("\n Porta 4 aberta");
     digitalWrite (Digital [3], HIGH);
     analogRead (Sensor4);
       if(Irms >= 0.4 && Irms1 >= 0.4 && Irms2 >= 0.4 ){
       Serial.println ("\n\n Porta 4 carregando");
       delay (100);
          if (Irms >=3 ){
          Pot = Irms * tensao;
          KWH = (Pot/1000)*cont;
          KWH1 +=KWH;
          delay(1000); //Espera 1 segundo
          //x=(((Pot)/1000)*Isaida); //calcula e guarda em x o valor do consumo em reais
         //y=y+x; //após 1 segundo, soma e guarda em y o valor de x
     
         Serial.print("\n\n\n Porta 4 - Corrente: ");
         Serial.print(Irms);
         Serial.println (" A");
         Serial.print("\n Porta 4 - Potência: ");
         Serial.print (Pot);
         Serial.println (" W");
         Serial.print("\n Porta 4 - Consumo: ");
         Serial.print (KWH1);
         Serial.println (" kW/h");
          
         }else if(Irms <3 && Irms >= 1){
         Pot = Irms1* tensao;
         KWH = (Pot/1000)*cont;
         KWH1 +=KWH;
         delay(1000); //Espera 1 segundo
         //x=(((Pot)/1000)*Isaida); //calcula e guarda em x o valor do consumo em reais
         //y=y+x; //após 1 segundo, soma e guarda em y o valor de x
   
         Serial.print("\n\n\n Porta 4 - Corrente: ");
         Serial.print(Irms1);
         Serial.println (" A");
         Serial.print("\n Porta 4 - Potência: ");
         Serial.print (Pot);
         Serial.println (" W");
         Serial.print("\n Porta 4 - Consumo: ");
         Serial.print (KWH1);
         Serial.println (" kW/h");
  
         }else if (Irms1 < 1){
         Pot = Irms2 * tensao;
         KWH1 +=KWH;
         KWH = (Pot/1000)*cont;
         delay(1000); //Espera 1 segundo
        //x=(((Pot)/1000)*Isaida); //calcula e guarda em x o valor do consumo em reais
        //y=y+x; //após 1 segundo, soma e guarda em y o valor de x
      
         Serial.print("\n\n\n Porta 4 - Corrente: ");
         Serial.print(Irms2);
         Serial.println (" A");
         Serial.print("\n Porta 4 - Potência: ");
         Serial.print (Pot);
         Serial.println (" W");
         Serial.print("\n Porta 4 - Consumo: ");
         Serial.print (KWH1);
         Serial.println (" kW/h");
  }
           
         }else{
         Serial.println ("\n Porta 4 não está carregando");
         delay (1000);  
     } 
}else{
     Serial.println ("\n\n\n______________");
     Serial.println ("\n Porta 4 fechada");
     digitalWrite (Digital [3], LOW);
}
     if (porta [4] == 1){
     Serial.println ("\n\n\n______________");
     Serial.println ("\n Porta 5 aberta");
     digitalWrite (Digital [4], HIGH);
     analogRead (Sensor5);
       
       if(Irms >= 0.4 && Irms1 >= 0.4 && Irms2 >= 0.4 ){
       Serial.println ("\n\n Porta 5 carregando");
       delay (100);
          if (Irms >=3 ){
          Pot = Irms * tensao;
          KWH = (Pot/1000)*cont;
          KWH1 +=KWH;
          delay(1000); //Espera 1 segundo
          //x=(((Pot)/1000)*Isaida); //calcula e guarda em x o valor do consumo em reais
         //y=y+x; //após 1 segundo, soma e guarda em y o valor de x
     
          Serial.print("\n\n\n Porta 5 - Corrente: ");
          Serial.print(Irms);
          Serial.println (" A");
          Serial.print("\n Porta 5 - Potência: ");
          Serial.print (Pot);
          Serial.println (" W");
          Serial.print("\n Porta 5 - Consumo: ");
          Serial.print (KWH1);
          Serial.println (" kW/h");
          
          }else if(Irms <3 && Irms >= 1){
          Pot = Irms1* tensao;
          KWH = (Pot/1000)*cont;
          KWH1 +=KWH;
          delay(1000); //Espera 1 segundo
         //x=(((Pot)/1000)*Isaida); //calcula e guarda em x o valor do consumo em reais
         //y=y+x; //após 1 segundo, soma e guarda em y o valor de x
   
          Serial.print("\n\n\n Porta 5 - Corrente: ");
          Serial.print(Irms1);
          Serial.println (" A");
          Serial.print("\n Porta 5 - Potência: ");
          Serial.print (Pot);
          Serial.println (" W");
          Serial.print("\n Porta 5 - Consumo: ");
          Serial.print (KWH1);
          Serial.println (" kW/h");
  
          }else if (Irms1 < 1){
          Pot = Irms2 * tensao;
          KWH1 +=KWH;
          KWH = (Pot/1000)*cont;
          delay(1000); //Espera 1 segundo
        //x=(((Pot)/1000)*Isaida); //calcula e guarda em x o valor do consumo em reais
        //y=y+x; //após 1 segundo, soma e guarda em y o valor de x
      
          Serial.print("\n\n\n Porta 5 - Corrente: ");
          Serial.print(Irms2);
          Serial.println (" A");
          Serial.print("\n Porta 5 - Potência: ");
          Serial.print (Pot);
          Serial.println (" W");
          Serial.print("\n Porta 5 - Consumo: ");
          Serial.print (KWH1);
          Serial.println (" kW/h");
  }
           
       }else{
       Serial.println ("\n Porta 5 não está carregando");
       delay (1000);  
     }
}else{
     Serial.println ("\n\n\n______________");
     Serial.println ("\n Porta 5 fechada");
     digitalWrite (Digital [4], LOW);
}
}
