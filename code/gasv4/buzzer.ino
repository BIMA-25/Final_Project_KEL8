void buzzersetup(){
  pinMode(26, OUTPUT);
  digitalWrite(26, HIGH);
}
void buzzerloop(){
  if (CO > 80 || CO2 > 1000 || Toluen > 100 || NH4 > 80 || Aceton > 500 ){
    digitalWrite(26,LOW);
  }else{
    digitalWrite(26,HIGH);
  }
}
