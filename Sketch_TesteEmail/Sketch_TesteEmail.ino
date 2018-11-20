/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  Note: This only works on Android!
        iOS does not support Bluetooth 2.0 Serial Port Profile
        You may need to pair the module with your smartphone
        via Bluetooth settings. Default pairing password is 1234

  Feel free to apply it to any other example. It's simple!

  NOTE: Bluetooth support is in beta!

  Simple e-mail example

  App project setup:
    E-mail Widget

  Connect a button to digital pin 2 and GND
  Pressing this button will send an e-mail

  WARNING: You are limited to send ONLY ONE E-MAIL PER 15 SECONDS!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial
/* Set this to a bigger number, to enable sending longer messages */
//#define BLYNK_MAX_SENDBYTES 128

#include <SoftwareSerial.h>
SoftwareSerial SwSerial(0,1); // RX, TX
    
#include <BlynkSimpleSerialBLE.h>
#include <SoftwareSerial.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "1f146b5f7f9e4d5599bc22c4cdf5df40";

SoftwareSerial SerialBLE(0, 1); // RX, TX

void emailOnButtonPress()
{
  // *** WARNING: You are limited to send ONLY ONE E-MAIL PER 15 SECONDS! ***

  // Let's send an e-mail when you press the button
  // connected to digital pin 2 on your Arduino

  int isButtonPressed = !digitalRead(13); // Invert state, since button is "Active LOW"

  if (isButtonPressed) // You can write any condition to trigger e-mail sending
  {
    Serial.println("Botão é pressionado."); // This can be seen in the Serial Monitor
    Blynk.email("jefferson........@hotmail.com", "Botão precionado", "Botão de Led do Arduino foi precionado");

    // Or, if you want to use the email specified in the App (like for App Export):
    //Blynk.email("Subject: Button Logger", "You just pushed the button...");
  }
}

void setup()
{
  // Debug console
  Serial.begin(9600);

  SerialBLE.begin(9600);
  Blynk.begin(SerialBLE, auth);

  Serial.println("Esperando por conexões...");

  // Send e-mail when your hardware gets connected to Blynk Server
  // Just put the recepient's "e-mail address", "Subject" and the "message body"
  Blynk.email("jefferson........@hotmail.com", "OB_INTELIGENTES", "Meu Projeto de Objetos inteligentes Conectados está online.");

  // Setting the button
  pinMode(13, INPUT_PULLUP);
  // Attach pin 13 interrupt to our handler
  attachInterrupt(digitalPinToInterrupt(13), emailOnButtonPress, CHANGE);
}

void loop()
{
  Blynk.run();
}
