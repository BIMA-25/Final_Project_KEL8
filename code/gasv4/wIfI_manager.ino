

void Wifisetup(){
     pinMode(15,INPUT); //for resetting WiFi creds
    //WiFiManager, Local intialization. Once its business is done, there is no need to keep it around

    bool res;
    // res = wm.autoConnect(); // auto generated AP name from chipid
    // res = wm.autoConnect("AutoConnectAP"); // anonymous ap
    res = wm.autoConnect("AutoConnectAP","password"); // password protected ap

    if(!res) {
        Serial.println("Failed to connect");
         ESP.restart();
    } 
    else {
        //if you get here you have connected to the WiFi    
        Serial.println("connected...yeey :)");
    } 
}

void Wifiloop(){   
 // put your main code here, to run repeatedly:   
   if(digitalRead(15) == HIGH){
    Serial.println("Wiping WiFi credentials from memory...");
    wm.resetSettings();
    g=2;
    digitalWrite(red,LOW);
    digitalWrite(green,LOW);
    ESP.restart();
   }
}

