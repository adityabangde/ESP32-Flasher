#include "esp32_flasher.h"

ESP32Flasher espflasher;

void setup() {
  Serial.begin(115200);         // Start communication With IDE to see whats going on
  delay(5000);                  // wait 5 seconds before Starting
  if (SPIFFS.begin(true))       //Must begin SD CARD before trying to flash Wifi module, will fail if not connected
  {
    Serial.println("spiffs begin");

    espflasher.espFlasherInit();//sets up Serial communication to another esp32

    int connect_status = espflasher.espConnect();

    if (connect_status != SUCCESS) {
      Serial.print("Cannot connect to target");
    }
    Serial.print("Connected to target\n");

    espflasher.espFlashBinFile("/firmware.bin");
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
