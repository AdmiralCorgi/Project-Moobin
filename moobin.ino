#define BLYNK_TEMPLATE_ID "TMPL6M4QOKkqI"
#define BLYNK_TEMPLATE_NAME "Moobin Template"
#define BLYNK_AUTH_TOKEN "llAggoUFQrvpn1j2bURB1E4sOXq34ygm"

#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>
#include <BlynkSimpleEsp32.h>

// WiFi credentials
char ssid[] = "OAK_2.4G";         // Replace with your WiFi SSID
char pass[] = "oaksoelay2018";     // Replace with your WiFi password

// LCD setup (Set the correct I2C address, typically 0x27 or 0x3F)
LiquidCrystal_PCF8574 lcd(0x27);

// Define relay pins
#define RELAY_1 33 // Milk Motor
#define RELAY_2 26 // Banana Milk Motor
#define RELAY_3 27 // Coffee Motor

void setup() {
  // Initialize I2C for LCD
  Wire.begin(4, 5);

  // Initialize LCD
  lcd.begin(16, 2); // 16 columns, 2 rows
  lcd.setBacklight(255); // Turn on backlight
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("System Starting...");

  // Initialize Serial
  Serial.begin(115200);
  Serial.println("System Starting...");

  // Set relay pins as outputs
  pinMode(RELAY_1, OUTPUT);
  pinMode(RELAY_2, OUTPUT);
  pinMode(RELAY_3, OUTPUT);

  // Ensure all relays are OFF initially
  digitalWrite(RELAY_1, LOW); // Relay OFF
  digitalWrite(RELAY_2, LOW); // Relay OFF
  digitalWrite(RELAY_3, LOW); // Relay OFF

  // Initialize Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  // Display system ready message
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("System Ready");
  Serial.println("System Ready");
  delay(1000);
}

void loop() {
  Blynk.run();
}

// Function to make Latte (Milk + Coffee)
void makeLatte() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Making Latte");
  Serial.println("Making Latte...");

  // Run Coffee Motor first
  lcd.setCursor(0, 1);
  lcd.print("Coffee (1s)");
  digitalWrite(RELAY_3, HIGH); // Coffee Motor ON
  delay(2000);
  digitalWrite(RELAY_3, LOW);  // Coffee Motor OFF

  // Run Milk Motor
  lcd.setCursor(0, 1);
  lcd.print("Milk (3s)");
  digitalWrite(RELAY_1, HIGH); // Milk Motor ON
  delay(3000);
  digitalWrite(RELAY_1, LOW);  // Milk Motor OFF

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Latte Done!");
  Serial.println("Latte is ready!");
  delay(2000);
}

// Function to make Banana Latte (Banana Milk + Coffee)
void makeBananaLatte() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Making BanaLatte");
  Serial.println("Making Banana Latte...");

  // Run Coffee Motor first
  lcd.setCursor(0, 1);
  lcd.print("Coffee (1s)");
  digitalWrite(RELAY_3, HIGH); // Coffee Motor ON
  delay(1000);
  digitalWrite(RELAY_3, LOW);  // Coffee Motor OFF

  // Run Banana Milk Motor
  lcd.setCursor(0, 1);
  lcd.print("Banana Milk (3s)");
  digitalWrite(RELAY_2, HIGH); // Banana Milk Motor ON
  delay(3000);
  digitalWrite(RELAY_2, LOW);  // Banana Milk Motor OFF

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("BanaLatte Done!");
  Serial.println("Banana Latte is ready!");
  delay(2000);
}

// Function to make Milk
void makeMilk() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Making Milk");
  Serial.println("Making Milk...");

  // Run Milk Motor
  lcd.setCursor(0, 1);
  lcd.print("Milk (3s)");
  digitalWrite(RELAY_1, HIGH); // Milk Motor ON
  delay(3000);
  digitalWrite(RELAY_1, LOW);  // Milk Motor OFF

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Milk Done!");
  Serial.println("Milk is ready!");
  delay(2000);
}

// Function to make Banana Milk
void makeBananaMilk() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Making Bana Milk");
  Serial.println("Making Banana Milk...");

  // Run Banana Milk Motor
  lcd.setCursor(0, 1);
  lcd.print("Banana Milk (3s)");
  digitalWrite(RELAY_2, HIGH); // Banana Milk Motor ON
  delay(3000);
  digitalWrite(RELAY_2, LOW);  // Banana Milk Motor OFF

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Bana Milk Done!");
  Serial.println("Banana Milk is ready!");
  delay(2000);
}

// Function to make Espresso
void makeEspresso() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Making Espresso");
  Serial.println("Making Espresso...");

  // Run Coffee Motor
  lcd.setCursor(0, 1);
  lcd.print("Coffee (3s)");
  digitalWrite(RELAY_3, HIGH); // Coffee Motor ON
  delay(3000);
  digitalWrite(RELAY_3, LOW);  // Coffee Motor OFF

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Espresso Done!");
  Serial.println("Espresso is ready!");
  delay(2000);
}

// Blynk Virtual Pin Handlers
BLYNK_WRITE(V0) { int value = param.asInt(); if (value == 1) makeLatte(); }
BLYNK_WRITE(V2) { int value = param.asInt(); if (value == 1) makeBananaLatte(); }
BLYNK_WRITE(V1) { int value = param.asInt(); if (value == 1) makeMilk(); }
BLYNK_WRITE(V4) { int value = param.asInt(); if (value == 1) makeBananaMilk(); }
BLYNK_WRITE(V5) { int value = param.asInt(); if (value == 1) makeEspresso(); }