/* 
 * --------------------------------------------------------------------------------------------
 * Example: ESP32 Diagnostic and Memory Test. 
 * --------------------------------------------------------------------------------------------
 * Date: 30-12-2024 (30th of Dec, 2024)
 * --------------------------------------------------------------------------------------------
 * Ömer Kolsuz
 * --------------------------------------------------------------------------------------------
*/


#include <Arduino.h>

// testning av ram
void testRAM() {
  Serial.println("Testar RAM...");
  const size_t testSize = 1024; 
  byte *testArray = (byte *)malloc(testSize);

  if (testArray != nullptr) {
    for (size_t i = 0; i < testSize; i++) {
      testArray[i] = (byte)i; // skriver till ram
    }

    // kontrollerar ram
    for (size_t i = 0; i < testSize; i++) {
      if (testArray[i] != (byte)i) {
        Serial.println("RAM-test misslyckades!");
        free(testArray);
        return;
      }
    }

    Serial.println("RAM-test lyckades!");
    free(testArray);
  } else {
    Serial.println("Kan inte allokera RAM, för lite minne.");
  }
}

void setup() {
  Serial.begin(115200);
  delay(2000); 
  Serial.println("Startar ESP32-test...");

  // visar all systeminformation
  Serial.print("Chip: ");
  Serial.println(ESP.getChipModel());
  Serial.print("Revision: ");
  Serial.println(ESP.getChipRevision());
  Serial.print("CPU-frekvens: ");
  Serial.println(ESP.getCpuFreqMHz());
  Serial.print("Flash-storlek: ");
  Serial.println(ESP.getFlashChipSize());
  Serial.print("Fri RAM: ");
  Serial.println(ESP.getFreeHeap());


  testRAM();

  Serial.println("Test klart!");
}

void loop() {
}
