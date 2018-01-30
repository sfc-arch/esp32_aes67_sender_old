/*
 *  This sketch sends random data over UDP on a ESP32 device
 *
 */
#include <Arduino.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include "AES67_L16_48kHz.hpp"
#include "ex_string.cpp"
#include "Rtp.hpp"

// WiFi network name and password:
const char *networkName = "ESP32_wifi"; // "WX03_Todoroki"; // "TP-LINK_62CF";
const char *networkPswd = "esp32pass"; // "TodorokiWX03"; // "0484767648";

//IP address to send UDP data to:
// either use the ip address of the server or
// a network broadcast address
const char *udpAddress = "192.168.4.1";
const int udpPort = 5004;

//Are we currently connected?
boolean connected = false;

//The udp library class
WiFiUDP udp;

unsigned short loopCount = 0;
AES67_L16_48kHz aes67(33773, 126, 2863311530);

TaskHandle_t th[2];

//wifi event handler
void WiFiEvent(WiFiEvent_t event)
{
   switch (event)
   {
   case SYSTEM_EVENT_STA_GOT_IP:
      //When connected set
      Serial.print("WiFi connected! IP address: ");
      Serial.println(WiFi.localIP());
      //initializes the UDP state
      //This initializes the transfer buffer
      udp.begin(WiFi.localIP(), udpPort);
      connected = true;
      break;
   case SYSTEM_EVENT_STA_DISCONNECTED:
      Serial.println("WiFi lost connection");
      connected = false;
      break;
   default:
      break;
   }
}

void printWifiStatus()
{
   // print the SSID of the network you're attached to:
   Serial.print("SSID: ");
   Serial.println(WiFi.SSID());

   // print your WiFi shield's IP address:
   IPAddress ip = WiFi.localIP();
   Serial.print("IP Address: ");
   Serial.println(ip);

   // print the received signal strength:
   long rssi = WiFi.RSSI();
   Serial.print("signal strength (RSSI):");
   Serial.print(rssi);
   Serial.println(" dBm");
}

void connectToWiFi(const char *ssid, const char *pwd)
{
   Serial.println("Connecting to WiFi network: " + String(ssid));

   // delete old config
   WiFi.disconnect(true);
   //register event handler
   WiFi.onEvent(WiFiEvent);

   //Initiate connection
   WiFi.begin(ssid, pwd);

   Serial.print("Waiting for WIFI connection ");

   while (WiFi.status() != WL_CONNECTED)
   {
      delay(500);
      Serial.print(". ");
   }

   Serial.println("");
   Serial.println("WiFi connected.");
   printWifiStatus();
}

void connectToSerial(unsigned int baudRate)
{
   // Initilize hardware serial:
   Serial.begin(baudRate);

   while (!Serial)
   {
      ; // wait for serial port to connect. Needed for native USB port only
   }
}

int getAdcIn()
{
   int adc_key_in = analogRead(32);
   Serial.println(adc_key_in);
   return (adc_key_in);
}


void exStringTest()
{
   ExString str = "1011";

   Serial.println(str.binaryToInt());

   // Serial.println(str.pad(ExString::PadDirection::LEADING, 16, '0'));
};


void setup()
{
   connectToSerial(115200);
   connectToWiFi(networkName, networkPswd);
   
   Serial.println(" ");

   // exStringTest();

   // AES67_L16_48kHz aes;

   // aes.addSampleSample(7);
   // Serial.println(aes.info());
   // String r = aes.createUdpPayload();
   // Serial.println("RTP to string: ");
   // Serial.println(r);
}

void sendPacket(void *pvParameters)
{
   aes67.addSampleSample(loopCount);
   // if (loopCount % 100 == 0)
   // {
      Serial.printf(" * Loop No.%u\n", loopCount);
   // };

   // //Send a packet
   udp.beginPacket(udpAddress, udpPort);
   udp.print(aes67.createUdpPayload());
   udp.endPacket();
   udp.flush();

   aes67 = AES67_L16_48kHz(aes67, aes67.timestamp() + 250);

   // end task
   vTaskDelete(NULL);
}

void loop()
{
   //only send data when connected
   if (connected && loopCount < 1000)
   {
      loopCount++;
      
      /*
      aes67.addSampleSample(loopCount);
      if (loopCount % 100 == 0) {
         Serial.printf(" * Loop No.%u\n", loopCount);
      };
      // Serial.println(aes67.info());
      // String r = aes67.createUdpPayload();
      // Serial.println("RTP to string: ");
      // Serial.println(r);

      // //Send a packet
      udp.beginPacket(udpAddress, udpPort);
      // udp.print("AudioPacket 12bits : ");
      // udp.printf("%u", getAdcIn());
      udp.print(aes67.createUdpPayload());
      udp.endPacket();

      aes67 = AES67_L16_48kHz(aes67, aes67.timestamp() + 250);
      */

      xTaskCreatePinnedToCore(
          sendPacket,
          "Sample one-time task",
          8172,
          NULL,
          4,
          &th[0],
          0);
   }
   //Wait for 250us
   delayMicroseconds(250);
   // delay(1000);
}
