// include the library code:
#include <LiquidCrystal.h>
#include "DHT.h"

// set the DHT Pin
#define DHTPIN 8

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  dht.begin();
  
  // print a message to the LCD.
  lcd.print("Temp:  Wilgotn:");
  
  // start serial monitor
  Serial.begin(9600);
  Serial.println("--- Start Serial Monitor ---");
}

void loop() {
  // turn off the display:
  // lcd.noDisplay();
  // delay(1000);
  
  // turn on the display:
  // lcd.display();
  delay(1000);
  
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  
  // read humidity
  float h = dht.readHumidity();
  
  //read temperature in Fahrenheit
  float f = dht.readTemperature(true);

  //read temperature in Celsius
  float c = dht.readTemperature();

  // show error if any
  if (isnan(h) || isnan(f)) {
    lcd.print("ERROR");
    return;
  }

  // print c and h on monitor
  lcd.print(c);
  lcd.setCursor(7,1);
  lcd.print(h);  
  
  // print f, c and h on serial
  Serial.print("temp F: ");
  Serial.print(f);
  Serial.print(", temp C: ");
  Serial.print(c);
  Serial.print(", wilgotn: ");
  Serial.print(h);
  Serial.println("");
}