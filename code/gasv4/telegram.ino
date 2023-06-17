#define BOTtoken "6160614665:AAGcNpljKROAO0tzeGqb-LT0luGzePMKb6U"
#define CHAT_ID "6097007259"

//milis send masage 
unsigned long previousTelMillis = 0;
unsigned long intervalTel = 60000;

int state =0;

WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);

// Checks for new messages every 1 second.
int botRequestDelay = 1000;
unsigned long lastTimeBotRan;

  // Handle what happens when you receive new messages
  void handleNewMessages(int numNewMessages){
    Serial.println("handleNewMessages");
    Serial.println(String(numNewMessages));
  
      for (int i=0; i<numNewMessages; i++) {
        // Chat id of the requester
        String chat_id = String(bot.messages[i].chat_id);
        Serial.println(chat_id);
        
          if (chat_id != CHAT_ID){
            bot.sendMessage(chat_id, "Unauthorized user", "");
            continue;
          }
      
       // Print the received message
       String text = "o";
       text = bot.messages[i].text;
       Serial.println(text);
    
       String from_name = bot.messages[i].from_name;
        //kirim comand control
        if (text == "/start") {
          String welcome = "Welcome, " + from_name + ".\n";
          welcome += "Use the following commands to control your outputs.\n\n";
          welcome += "/CO untuk melihat kadar CO di udara saat ini\n";
          welcome += "/CO2 untuk melihat kadar CO2 di udara saat ini\n";
          welcome += "/Tolueno untuk melihat kadar Tolueno di udara saat ini\n";
          welcome += "/NH4 untuk melihat kadar NH4 di udara saat ini\n";
          welcome += "/Aceton untuk melihat kadar Aceton di udara saat ini\n";
          welcome += "/All untuk melihat semua\n";
          welcome += "/cek untuk melihat kondisi udara saat ini\n";
          welcome += "/ganti_koneksi_wifi untuk mengganti ssid dan password\n";
          bot.sendMessage(chat_id, welcome, "");
          g=1;
        }
        //kirim kadar ppm gas CO
        if (text == "/CO"){
         float coo = CO;
         String kadar = "kadar CO di udara : ";
         kadar += float (coo);
         kadar += " ppm\n";
          bot.sendMessage(CHAT_ID, kadar, "");
        }
        //kirim kadar ppm gas CO2
        if (text == "/CO2"){
         float co22 = CO2 + 400;
         String kadar = "kadar CO2 di udara : ";
         kadar += float (co22);
         kadar += " ppm\n";
          bot.sendMessage(CHAT_ID, kadar, "");
        }
        //kirim kadar ppm gas Tolueno
        if (text == "/Tolueno"){
         float toluenoo = Toluen;
         String kadar = "kadar Tolueno di udara : ";
         kadar += float (toluenoo);
         kadar += " ppm\n";
          bot.sendMessage(CHAT_ID, kadar, "");
        }
        //kirim kadar ppm gas NH4
        if (text == "/NH4"){
         float nh44 = NH4;
         String kadar = "kadar NH4 di udara : ";
         kadar += float (nh44);
         kadar += " ppm\n";
          bot.sendMessage(CHAT_ID, kadar, "");
        }
        //kirim kadar ppm gas aceton
        if (text == "/Aceton"){
         float acetonn = Aceton;
         String kadar = "kadar Aceton di udara : ";
         kadar += float (acetonn);
         kadar += " ppm\n";
          bot.sendMessage(CHAT_ID, kadar, "");
        }
        //kirim informasi detail jumlah kadar ppm gas di udara
         if (text == "/All"){
         float acetonn = Aceton;
         float nh44 = NH4;
         float toluenoo = Toluen;
         float co22 = CO2 + 400;
         float coo = CO;
         String kadar = "kadar : \n";
         kadar += "CO ";
         kadar += float (coo);
         kadar += " ppm\n";
         kadar += "CO2 ";
         kadar += float (co22);
         kadar += " ppm\n";
         kadar += "Touleno ";
         kadar += float (toluenoo);
         kadar += " ppm\n";
         kadar += "NH4 ";
         kadar += float (nh44);
         kadar += " ppm\n";
         kadar += "Aceton ";
         kadar += float (acetonn);
         kadar += " ppm\n";
          bot.sendMessage(CHAT_ID, kadar, "");
        }
        // kirim peringatan gas apa saja yang di ambang batas bahaya
         if (text == "/cek"){
            if (CO > 80 )  {
              bot.sendMessage(CHAT_ID, "PERINGATAN! GAS CO SUDAH DI AMBANG BATAS BAHAYA!", "");  
             }
            if (CO2 > 1000 ) {
              bot.sendMessage(CHAT_ID, "PERINGATAN! GAS CO2 SUDAH DI AMBANG BATAS BAHAYA!", ""); 
             }
            if (Toluen > 100 ) {
              bot.sendMessage(CHAT_ID, "PERINGATAN! GAS TOLUENO SUDAH DI AMBANG BATAS BAHAYA!", ""); 
             }
            if (NH4 > 60 ) {
              bot.sendMessage(CHAT_ID, "PERINGATAN! GAS NH4 SUDAH DI AMBANG BATAS BAHAYA!", ""); 
             }
            if (Aceton > 500 ) {
              bot.sendMessage(CHAT_ID, "PERINGATAN! GAS ACETON SUDAH DI AMBANG BATAS BAHAYA!", ""); 
             }  
            if (CO < 80 && CO2 < 1000 && Toluen < 100 && NH4 < 80 && Aceton < 500 ){
              bot.sendMessage(CHAT_ID, "KONDISI UDARA AMAN", ""); 
             }}
         if (text == "/ganti_koneksi_wifi" && g == 1){
         bot.sendMessage(CHAT_ID, "Wiping WiFi credentials from memory...", "");
         bot.sendMessage(CHAT_ID, "mohon koneksi ke hotspot alat dan akses ip 192.168.4.1 pada web browser", "");
         Serial.println("Wiping WiFi credentials from memory...");
         digitalWrite(red,LOW);
         digitalWrite(green,LOW);
         g=2;
         wm.resetSettings();
         ESP.restart();
         }
      } }
  
  void teleSetup(){
      client.setCACert(TELEGRAM_CERTIFICATE_ROOT); // Add root certificate for api.telegram.org
     bot.sendMessage(CHAT_ID, "hallo selamat datang di gas bot tulis /start untuk melihat comands control ", "");
     g =2;
  } 
   void teleloop(){
      if (millis() > lastTimeBotRan + botRequestDelay)  {
        int numNewMessages = bot.getUpdates(bot.last_message_received + 1);
  
          while(numNewMessages) {
            Serial.println("got response");
            handleNewMessages(numNewMessages);
            numNewMessages = bot.getUpdates(bot.last_message_received + 1);
          }
  //kirim peringatan adanya gas berbahaya        
        lastTimeBotRan = millis();
     }
     unsigned long currentTelMillis = millis();
      if (CO > 80 || CO2 > 1000 || Toluen > 100 || NH4 > 80 || Aceton > 500 && state != 1 ){
        state = 1;
        bot.sendMessage(CHAT_ID, "PERINGATAN! ADA GAS DI AMBANG BATAS BAHAYA! SEND /cek UNTUK LIHAT DETAIL", ""); 
      }else if(currentTelMillis - previousTelMillis >= intervalTel) {
        state = 2;
        previousTelMillis = currentTelMillis;
      }
  }

