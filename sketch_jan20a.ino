#include <Servo.h>
Servo myobject;
int pos;

void setup() {
  myobject.attach(9);
  Serial.begin(9600);
  
}

void loop() {
  for(pos=0;pos<=180;pos++){
    myobject.write(pos);
    Serial.println(pos);
    delay(15);
  }
  for(pos=180;pos>=0;pos--){
    myobject.write(pos);
    Serial.println(pos);
    delay(15);
  }
 
}
