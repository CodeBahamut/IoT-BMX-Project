# Wemos configuration

The wemos is now connected to the internet thanks to the following function:  

```cpp
void setup_wifi() {
  // Connect WiFi
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.hostname("Name");
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print("-");
    Serial.flush();
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Print the IP address
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

```

(the ssid and password are static variables)  

This is the POST Request function:  

```cpp
void httpPOSTRequest(const char* serverName, char[] httpRequestData){
  WiFiClient client;
  HTTPClient http;
  http.useHTTP10(true);
  http.begin(client, serverName);
    // Specify content-type header
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  // Data to send with HTTP POST
  http.addHeader("Content-Type", "application/json");
  int httpResponseCode = http.POST(httpRequestData);
  //int httpResponseCode = http.POST("{\"api_key\":\"tPmAT5Ab3j7F9\",\"sensor\":\"BME280\",\"value1\":\"24.25\",\"value2\":\"49.54\",\"value3\":\"1005.14\"}");
  
  Serial.print("HTTP Response code: ");
  Serial.println(httpResponseCode);
  http.end();
}
```

## How to edit the wifi connection

To use the device, a wifi connection is required. So, you need to manually change the wifi to make sure it works.

- Step 1: Download [Arduino IDE](https://www.arduino.cc/en/software).
- Step 2: Open the File delivered in the github in the IDE.
- Step 3: Go to Sketch -> Include library -> Manage libraries.
- Step 4: Download the following libraries:

1. NTPClient
2. DHT sensor library for ESPx
3. ArduinoJson
4. WiFi
5. Ethernet
6. DNS server

All text within the "<>" brackets after "#include" should now all be colored, if not, search for the text within the brackets in the library manager.

- Step 5: Go down in the folder until you find the following lines and edit them to your wifi ssid and password:

```cpp
const char* ssid = "AFBLIJVEN";
const char* password = "Kaas012!!";
```

- Step 6: plug your device into your computer.
- Step 7: Go to Tools -> Boards -> ESP8266 Boards (3.0.2) and select 'LOLIN(WEMOS) D1 mini Pro'.
- Step 8: Go to Tools -> Port and select the port you have your device plugged into. (If you try to upload your code to the wrong port it will simply fail, you can also try to guess the port and do trial and error.)
- Step 9: Click the Upload button, it should now start loading and sending the code to your device succesfully. To verify this, you can open the serial monitor in the topright of the IDE after the uploading is done (it will break if you open it while uploading). This should show data after some time, make sure the baudrate is set to 115200 (bottom left in the serial monitor).
