

bool functionState = false;
String incomingByte;
int buzzer = 12;
int redLight = 10;
int greenLight = 11;
void setup() {


pinMode(buzzer, OUTPUT);
pinMode(redLight, OUTPUT);
pinMode(greenLight, OUTPUT);
Serial.begin(9600);

}

void loop() {

// send data only when you receive data:
 if (Serial.available() > 0) {
                // read the incoming byte:
                incomingByte = Serial.readString();
                if(incomingByte == "on"){
                  functionState = true;
                }else if (incomingByte == "off"){
                  functionState = false;
                }else{
                   // say what you got:
                Serial.print("Unknown Command");
               // Serial.println(incomingByte, DEC);
                }
}
  if(functionState){

 for(int i=0; i<80; i++){
  digitalWrite(buzzer, HIGH);
  digitalWrite(redLight, HIGH);
  delay(1);
  digitalWrite(buzzer, LOW);
  digitalWrite(redLight, LOW);
  delay(1);
  }
  for(int i=0; i<100; i++){
    digitalWrite(buzzer, HIGH);
    digitalWrite(greenLight, HIGH);
    delay(2);
    digitalWrite(buzzer, LOW);
    digitalWrite(greenLight, LOW);
    delay(1);
  }
//  while(1);
  
 
  }else{
  
  }


}



