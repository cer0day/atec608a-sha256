#include <Arduino.h>
#include <cryptoauth.h>
AtEccX08 ecc = AtEccX08();

unsigned long tiempo1 = 0;
unsigned long tiempo2 = 0;
unsigned long diferenciaTiempo = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  ecc.enableDebug(&Serial);
}
String texto = "a";


void loop() {
  if (Serial.available() > 0){
      tiempo1 = millis();
      for(int i=0; i<10; i++){
        HashData();
      }
      tiempo2 = millis();
      diferenciaTiempo = tiempo2-tiempo1;
      //diferenciaTiempo=diferenciaTiempo/1000;
      Serial.print("Tiempo de ejecucion=");
      Serial.print(diferenciaTiempo);
      
      int i =5;
      while( i < 10){
        
      }
  }
 }

 uint8_t hash[32];
 uint8_t signature[64];
 uint8_t pubkey[64];
void HashData() {
    //  uint8_t hash[32];
      uint8_t toHash[64];
    
      int str_len = texto.length() + 1; 
      char responder[str_len];
      texto.toCharArray(responder, str_len);
           
      // Calculate the SHA256 hash of the data.
      uint8_t ret = ecc.calculateSHA256((uint8_t*)responder, strlen((char*)responder));
      memcpy (hash, ecc.rsp.getPointer(), sizeof(hash));
      //hexify("Hash: ", (const uint8_t *) hash, sizeof(hash));
      
}


void hexify(const char *str, const uint8_t *hex, unsigned int len) {
  int i;

  Serial.write(str);
  for (i = 0; i < len; i++)  {
    static char tmp[4] = {};
    sprintf(tmp, "%02X", hex[i]);
    Serial.write(tmp);
  }

//  Serial.write("\n");
  Serial.println();

}void consumeInput() {
  while ( Serial.available() ) {
    Serial.read();
  }
}
