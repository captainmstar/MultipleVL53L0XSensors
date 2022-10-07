/* This example shows how to use continuous mode to take
range measurements with the VL53L0X. It is based on
vl53l0x_ContinuousRanging_Example.c from the VL53L0X API.

The range readings are in units of mm. */

#include <Wire.h>
#include <VL53L0X.h>
#include <FastLED.h>

#define XSHUT_pin1 7
#define XSHUT_pin2 6
#define XSHUT_pin3 5
#define XSHUT_pin4 4

VL53L0X Sensor1;
VL53L0X Sensor2;
VL53L0X Sensor3;
VL53L0X Sensor4;

void setup()
{
  Serial.begin(9600);
  // wait until serial port opens for native USB devices
  while (! Serial) { delay(1); }
  
  Serial.println(F("setup..."));
    
  /*WARNING*/
  //Shutdown pins of VL53L0X ACTIVE-LOW-ONLY NO TOLERANT TO 5V will fry them
  pinMode(XSHUT_pin1, OUTPUT);
  pinMode(XSHUT_pin2, OUTPUT);
  pinMode(XSHUT_pin3, OUTPUT);
  pinMode(XSHUT_pin4, OUTPUT);
  Serial.println(F("Shutdown pins inited..."));

  digitalWrite(XSHUT_pin1, LOW);
  digitalWrite(XSHUT_pin2, LOW);
  digitalWrite(XSHUT_pin3, LOW);
  digitalWrite(XSHUT_pin4, LOW);
  Serial.println(F("XSHUT pins in reset mode...(pins are low)"));
  
  delay(500);
  
  Wire.begin();
  Serial.println(F("Wire.begin()"));
  
  //Power up sensor1
//  digitalWrite(XSHUT_pin1, HIGH);
  pinMode(XSHUT_pin1, INPUT);
  delay(150);
  Serial.println(F("XSHUT_pin1 set to HIGH"));
  
  if(!Sensor1.init(true)) {
    Serial.println(F("Error starting Sensor1"));
  } else {
    Serial.println(F("Succes starting Sensor1"));
  }
  delay(100);
  
  Sensor1.setAddress((uint8_t)22);
  delay(10);

  //Power up sensor2
//  digitalWrite(XSHUT_pin2, HIGH);
  pinMode(XSHUT_pin2, INPUT);
  delay(150);
  Serial.println(F("XSHUT_pin2 HIGH"));
  
  if(!Sensor2.init(true)) {
    Serial.println(F("Error starting Sensor2"));
  } else {
    Serial.println(F("Succes starting Sensor2"));
  }
  delay(100);
  
  Sensor2.setAddress((uint8_t)25);
  delay(10);

  //Power up sensor3
//  digitalWrite(XSHUT_pin3, HIGH);
  pinMode(XSHUT_pin3, INPUT);
  delay(150);
  Serial.println(F("XSHUT_pin3 set to HIGH"));
  
  if(!Sensor3.init(true)) {
    Serial.println(F("Error starting Sensor3"));
  } else {
    Serial.println(F("Succes starting Sensor3"));
  }
  delay(100);
  
  Sensor3.setAddress((uint8_t)28);
  delay(10);

  //Power up sensor4
  pinMode(XSHUT_pin4, INPUT);
  delay(150);
  Serial.println(F("XSHUT_pin4 set to HIGH"));
  
  if(!Sensor4.init(true)) {
    Serial.println(F("Error starting Sensor4"));
  } else {
    Serial.println(F("Succes starting Sensor4"));
  }
  delay(100);
  
  Sensor4.setAddress((uint8_t)31);
  delay(10);
  
  Sensor1.setTimeout(100);
  Sensor2.setTimeout(100);
  Sensor3.setTimeout(100);
  Sensor4.setTimeout(100);
  Serial.println("Sensor1.setTimeout(500)");

  // Start continuous back-to-back mode (take readings as
  // fast as possible).  To use continuous timed mode
  // instead, provide a desired inter-measurement period in
  // ms (e.g. sensor.startContinuous(100)).
  Sensor1.startContinuous(100);
  Sensor2.startContinuous(100);
  Sensor3.startContinuous(100);
  Sensor4.startContinuous(100);
  delay(10);
  Serial.println("Sensor1.startContinuous()");
}

void loop()
{
  Serial.print(Sensor1.readRangeContinuousMillimeters());
  Serial.print(F(","));
  Serial.print(Sensor2.readRangeContinuousMillimeters());
  Serial.print(F(","));
  Serial.print(Sensor3.readRangeContinuousMillimeters());
  Serial.print(',');
  Serial.print(Sensor4.readRangeContinuousMillimeters());
  Serial.println();
//  Serial.println ("I2C scanner. Scanning ...");
//  byte count = 0;
//
//
//  for (byte i = 1; i < 240; i++)
//  {
//
//    Wire.beginTransmission (i);
//    if (Wire.endTransmission () == 0)
//    {
//      Serial.print ("Found address: ");
//      Serial.print (i, DEC);
//      Serial.print (" (0x");
//      Serial.print (i, HEX);
//      Serial.println (")");
//      count++;
//      delay (1);  // maybe unneeded?
//    } // end of good response
//  } // end of for loop
//  Serial.println ("Done.");
//  Serial.print ("Found ");
//  Serial.print (count, DEC);
//  Serial.println (" device(s).");
//
//  delay(3000);
}
