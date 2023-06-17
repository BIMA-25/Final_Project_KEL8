
#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL6-4nIyEFq"
#define BLYNK_TEMPLATE_NAME "GasDashboard"
#define BLYNK_AUTH_TOKEN "Eh2F7jJGocwFyQlTJHgixZeCPmht7w1g"



BlynkTimer timer;

 void myTimerEvent(){
   Blynk.virtualWrite(V0, CO );
   Blynk.virtualWrite(V1, CO2 + 400);
   Blynk.virtualWrite(V2, Toluen);
   Blynk.virtualWrite(V3, NH4);
   Blynk.virtualWrite(V4, Aceton);
 }

 
 void blynkSetup(){
   Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
   timer.setInterval(1000L, myTimerEvent);
 }

 void blynkloop(){
   Blynk.run();
   timer.run(); // Initiates BlynkTimer
 }
