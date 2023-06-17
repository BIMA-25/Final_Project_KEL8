

void ledsetup(){
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
}
void ledloop(){
  if (CO > 80 || CO2 > 1000 || Toluen > 100 || NH4 > 80 || Aceton > 500 ){
    digitalWrite(red,HIGH);
    digitalWrite(green,LOW);
  }else{
    digitalWrite(green,HIGH);
    digitalWrite(red,LOW);
  }
  if ((WiFi.status() != WL_CONNECTED)){
       digitalWrite(blue, HIGH);   
       Serial.println("wifi tidak terhuubung");
  }else{
    
      digitalWrite(blue, LOW);
  }
}

