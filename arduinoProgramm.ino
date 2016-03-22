#include <aJSON.h>
aJsonStream serial_stream(&Serial);

const int EngineR=11;
const int EngineL=10;
const int SteeringR=9;
const int SteeringL=8;


void setup() {
   //pinMode(EngineR,OUTPUT);
  //pinMode(EngineL,OUTPUT);
  pinMode(SteeringR,OUTPUT);
  pinMode(SteeringL,OUTPUT);
  pinMode(13, OUTPUT);
 Serial.begin(115200);
}

void loop() {
  aJsonObject *msg = aJson.parse(&serial_stream);
  processMessage(msg);  //see api.ino
  aJson.deleteItem(msg);
}

void processMessage(aJsonObject *msg)
{
  
aJsonObject *directionRight = aJson.getObjectItem(msg, "directionRight");
  if (directionRight) {
    char* pwmvaluestring = directionRight->valuestring;
    float pwmvaluefloat = atof(pwmvaluestring);
    int pwmvalueint = pwmvaluefloat;
    if(pwmvaluefloat>0){//vor
      digitalWrite(SteeringR,HIGH);
      analogWrite(EngineR,pwmvalueint);
    
    }else if(pwmvaluefloat<0){//zurück
      digitalWrite(SteeringR,LOW);
      analogWrite(EngineR,abs(pwmvaluefloat));
    }
  }
  
  aJsonObject *directionLeft = aJson.getObjectItem(msg, "directionLeft");
  if (directionLeft) {
    char* pwmvaluestring = directionpwm->valuestring;
    float pwmvaluefloat = atof(pwmvaluestring);
    int pwmvalueint = pwmvaluefloat;
    if(pwmvaluefloat>0){//vor
      digitalWrite(SteeringL,HIGH);
      analogWrite(EngineL,pwmvalueint);
    
    }else if(pwmvaluefloat<0){//zurück
      digitalWrite(SteeringL,LOW);
      analogWrite(EngineL,abs(pwmvaluefloat));
    }
  }
   
}
