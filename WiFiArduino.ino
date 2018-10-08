#include <WiFiEspServer.h>
#include <WiFiEspUdp.h>
#include <WiFiEspClient.h>
#include <WiFiEsp.h>

#include <SoftwareSerial.h>



// Create WiFi module on GPIO pin 6 (RX) and 7 (TX)
SoftwareSerial Serial1(6, 7);

// Declare and initialise global arrays for WiFi settings
char ssid[] = "shiwan";
char pass[] = "shiwan11";

// Declare and intialise variable for radio status
int status = WL_IDLE_STATUS;

void setup() {
  pinMode(13, OUTPUT);

  // Initialize serial for debugging
  Serial.begin (115200);

  // Intialize serial for ESP module
  Serial1.begin(9600);

  // Initialize ESP module
  WiFi.init(&Serial1);

  //Check for the presences of the shield
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");

                   // Don't continue
                   while (true);
                 }

                   // Attempt to connect to WiFi netwok
                   while (status != WL_CONNECTED) {
                   Serial.print("Attempting to connect to SSID: ");
                   Serial.println(ssid);

                   //Connect to WPA/WPA2 network
                   status = WiFi.begin(ssid, pass);
                 }

                   Serial.println("You're connected to the network");
                   printWifiStatus();
}

void loop() {
  
}

void printWifiStatus() {
// Print the SSID of the network
Serial.print("SSID: ");
Serial.println(WiFi.SSID());

// Print the IP address
IPAddress ip = WiFi.localIP();
Serial.print("IP Address: ");
Serial.println(ip);
}
