

const int EngineR=11;
const int EngineL=10;
const int SteeringR=9;
const int SteeringL=8;


void setup() {
 
  pinMode(EngineR,OUTPUT);
  pinMode(EngineL,OUTPUT);
  pinMode(SteeringR,OUTPUT);
  pinMode(SteeringL,OUTPUT);
  Serial.begin(115200);
}

void loop(){
  int currentAction = Serial.read();
  if(currentAction==1){
    moveForward();
    delay(10);
  }else if(currentAction==2){
    delay(10);
    moveBackward(); 
   
  }
   

}




void moveForward(){
  digitalWrite(EngineL,HIGH);
  digitalWrite(EngineR,HIGH);
  digitalWrite(SteeringL,HIGH);
  digitalWrite(SteeringR,HIGH);
}

void moveBackward(){
  digitalWrite(EngineL,HIGH);
  digitalWrite(EngineR,HIGH);
  digitalWrite(SteeringL,LOW);
  digitalWrite(SteeringR,LOW);


}



