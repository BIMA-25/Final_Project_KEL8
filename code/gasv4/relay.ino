void relaysetup(){
  pinMode(27, OUTPUT);
}
void relayloop(){
  if (CO > 80 || CO2 > 1000 || Toluen > 100 || NH4 > 80 || Aceton > 500 ){
    digitalWrite(27,LOW);
  }else{
    digitalWrite(27,HIGH);
  }
}

