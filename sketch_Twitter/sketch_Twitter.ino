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

  Simple tweet example

  App project setup:
    Twitter widget (connect it to your Twitter account!)

  Connect a button to pin 2 and GND...
  Pressing this button will also tweet a message! ;)
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <SoftwareSerial.h>
SoftwareSerial SwSerial(0, 1); // RX, TX
    
#include <BlynkSimpleSerialBLE.h>
#include <SoftwareSerial.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "1f146b5f7f9e4d5599bc22c4cdf5df40";

SoftwareSerial SerialBLE(0, 1); // RX, TX

BlynkTimer timer;

void tweetUptime()
{
  long uptime = millis() / 60000L;
  Serial.println("Tweetando a cada 10 minutos ;)");

  // Actually send the message.
  // Note:
  //   We allow 1 tweet per 15 seconds for now.
  //   Twitter doesn't allow identical subsequent messages.
  Blynk.tweet(String("Running for ") + uptime + " minutes.");
}

void setup()
{
  // Debug console
  Serial.begin(9600);

  SerialBLE.begin(9600);
  Blynk.begin(SerialBLE, auth);

  Serial.println("Esperando por conexões...");

  // Tweet immediately on startup
  Blynk.tweet("Meu projeto do Arduino está twittando usando @blynk_app e é incrível!\n #arduino #IoT #blynk");

  // Setup a function to be called every 10 minutes
  timer.setInterval(10L * 60000L, tweetUptime);

}

void loop()
{
  Blynk.run();
  timer.run();
}
