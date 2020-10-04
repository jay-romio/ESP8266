/*
 Project Auther : JAYANAND SIDAR
 Date           : 3 OCT 2020
 Email Id       : jayanandsidar27@gmail.com
 Mobile No.     : 9340449355

*/

// Include library file
#include<ESP8266WiFi.h>

// Add credentiaals of your wifi access point
const char* ssid = "xxxx";
const char* password = "xxxx";

// Set wifi port no. (80)
WiFiServer server(80);

String header;

// Declear which pins to use of ESP8266
int Device0 = D0;
int Device1 = D1;
int Device2 = D2;
int Device3 = D3;
int Device4 = D4;
int Device5 = D5;
int Device6 = D6;
int Device7 = D7;
int Device8 = D8;

// STATE OF DEVICE WHEN DEVICE WILL BE TURNED ON
String Device0state = "off";
String Device1state = "off";
String Device2state = "off";
String Device3state = "off";
String Device4state = "off";
String Device5state = "off";
String Device6state = "off";
String Device7state = "off";
String Device8state = "off";

void setup() {
Serial.begin(115200);

pinMode(Device0, OUTPUT);
pinMode(Device1, OUTPUT);
pinMode(Device2, OUTPUT);
pinMode(Device3, OUTPUT);
pinMode(Device4, OUTPUT);
pinMode(Device5, OUTPUT);
pinMode(Device6, OUTPUT);
pinMode(Device7, OUTPUT);
pinMode(Device8, OUTPUT);


digitalWrite(Device0, LOW);
digitalWrite(Device1, LOW);
digitalWrite(Device2, LOW);
digitalWrite(Device3, LOW);
digitalWrite(Device4, LOW);
digitalWrite(Device5, LOW);
digitalWrite(Device6, LOW);
digitalWrite(Device7, LOW);
digitalWrite(Device8, LOW);



 //connect to access point
  WiFi.begin(ssid, password);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());// this will display the Ip address of the Pi which should be entered into your browser
  server.begin();
}

void loop(){
  WiFiClient client = server.available();   // Listen for incoming clients

  if (client) {                             // If a new client connects,
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            
            // turns the GPIOs on and off
            if (header.indexOf("GET /Device0/on") >= 0)
            {
              Serial.println("Device 0 is on");
              Device0state = "on";
              digitalWrite(Device0, HIGH);
            }
            else if (header.indexOf("GET /Device0/off") >= 0)
            {
              Serial.println("Device 0 is off");
              Device0state = "off";
              digitalWrite(Device0, LOW);
            } 
            else if (header.indexOf("GET /Device1/on") >= 0)
            {
              Serial.println("Device 1 on");
              Device1state = "on";
              digitalWrite(Device1, HIGH);
            }
            else if (header.indexOf("GET /Device1/off") >= 0)
            {
              Serial.println("Device 1 off");
              Device1state = "off";
              digitalWrite(Device1, LOW);
            }

            // JJJJJJJJJJJJAAAAAAAAAAAAAAYYYYYYYYYYYYYY

            else if (header.indexOf("GET /Device2/on") >= 0)
            {
              Serial.println("Device 2 is on");
              Device2state = "on";
              digitalWrite(Device2, HIGH);
            }
            else if (header.indexOf("GET /Device2/off") >= 0)
            {
              Serial.println("Device 2 off");
              Device2state = "off";
              digitalWrite(Device2, LOW);
            }
             else if (header.indexOf("GET /Device3/on") >= 0)
            {
              Serial.println("Device 3 is on");
              Device3state = "on";
              digitalWrite(Device3, HIGH);
            }
            else if (header.indexOf("GET /Device3/off") >= 0)
            {
              Serial.println("Device 3 is off");
              Device3state = "off";
              digitalWrite(Device3, LOW);
            }
             else if (header.indexOf("GET /Device4/on") >= 0)
            {
              Serial.println("Device 4 is on");
              Device4state = "on";
              digitalWrite(Device4, HIGH);
            }
            else if (header.indexOf("GET /Device4/off") >= 0)
            {
              Serial.println("Device 4 off");
              Device4state = "off";
              digitalWrite(Device4, LOW);
            }
             else if (header.indexOf("GET /Device5/on") >= 0)
            {
              Serial.println("Device 5 is on");
              Device5state = "on";
              digitalWrite(Device5, HIGH);
            }
            else if (header.indexOf("GET /Device5/off") >= 0)
            {
              Serial.println("Device 5 is off");
              Device5state = "off";
              digitalWrite(Device5, LOW);
            }
      else if (header.indexOf("GET /Device6/on") >= 0)
            {
              Serial.println("Device 6 is on");
              Device6state = "on";
              digitalWrite(Device6, HIGH);
            }
            else if (header.indexOf("GET /Device6/off") >= 0)
            {
              Serial.println("Device 6 is off");
              Device6state = "off";
              digitalWrite(Device6, LOW);
            }
      else if (header.indexOf("GET /Device7/on") >= 0)
            {
              Serial.println("Device 7 is on");
              Device7state = "on";
              digitalWrite(Device7, HIGH);
            }
            else if (header.indexOf("GET /Device7/off") >= 0)
            {
              Serial.println("Device 7 is off");
              Device7state = "off";
              digitalWrite(Device7, LOW);
            }
      else if (header.indexOf("GET /Device8/on") >= 0)
            {
              Serial.println("Device 8 is on");
              Device8state = "on";
              digitalWrite(Device8, HIGH);
            }
            else if (header.indexOf("GET /Device8/off") >= 0)
            {
              Serial.println("Device 8 is off");
              Device8state = "off";
              digitalWrite(Device8, LOW);
            }


          // Display the HTML web page
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            // CSS to style the on/off buttons 
            // Feel free to change the background-color and font-size attributes to fit your preferences
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: #195B6A; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: #77878A;}</style></head>");
            
            // Web Page Heading
            client.println("<body><h1>Jay - ESP8266 Web Server</h1>");
            client.println("<hr>");
            
            // Display current state, and ON/OFF buttons for GPIO 0  
            client.println("<p>Device0 - State " + Device0state + "</p>");
            // If Device 1 is off, it displays the ON button       
            if (Device0state == "off") {
              client.println("<p><a href=\"/Device0/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/Device0/off\"><button class=\"button button2\">OFF</button></a></p>");
            } 
               
            // Display current state, and ON/OFF buttons for GPIO 1  
            client.println("<p>Device1 - State " + Device1state + "</p>");
            // If Device 1 is off, it displays the ON button       
            if (Device1state == "off") {
              client.println("<p><a href=\"/Device1/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/Device1/off\"><button class=\"button button2\">OFF</button></a></p>");
            }

             // Display current state, and ON/OFF buttons for GPIO 3  
            client.println("<p>Device2 - State " + Device2state + "</p>");
            // If Device 2 is off, it displays the ON button       
            if (Device2state == "off") {
              client.println("<p><a href=\"/Device2/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/Device2/off\"><button class=\"button button2\">OFF</button></a></p>");
            }

             // Display current state, and ON/OFF buttons for GPIO 4  
            client.println("<p>Device3 - State " + Device3state + "</p>");
            // If Device 3 is off, it displays the ON button       
            if (Device3state == "off") {
              client.println("<p><a href=\"/Device3/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/Device3/off\"><button class=\"button button2\">OFF</button></a></p>");
            }

             // Display current state, and ON/OFF buttons for GPIO 5  
            client.println("<p>Device4 - State " + Device4state + "</p>");
            // If Device 4 is off, it displays the ON button       
            if (Device4state == "off") {
              client.println("<p><a href=\"/Device4/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/Device4/off\"><button class=\"button button2\">OFF</button></a></p>");
            }
     
      // Display current state, and ON/OFF buttons for GPIO 6  
            client.println("<p>Device5 - State " + Device5state + "</p>");
            // If Device 5 is off, it displays the ON button       
            if (Device5state == "off") {
              client.println("<p><a href=\"/Device5/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/Device5/off\"><button class=\"button button2\">OFF</button></a></p>");
            }
      
      // Display current state, and ON/OFF buttons for GPIO 7  
            client.println("<p>Device6 - State " + Device6state + "</p>");
            // If Device 7 is off, it displays the ON button       
            if (Device6state == "off") {
              client.println("<p><a href=\"/Device6/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/Device6/off\"><button class=\"button button2\">OFF</button></a></p>");
            }
      
      // Display current state, and ON/OFF buttons for GPIO 8  
            client.println("<p>Device7 - State " + Device7state + "</p>");
            // If Device 8 is off, it displays the ON button       
            if (Device7state == "off") {
              client.println("<p><a href=\"/Device7/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/Device7/off\"><button class=\"button button2\">OFF</button></a></p>");
            }
      
      // Display current state, and ON/OFF buttons for GPIO 9  
            client.println("<p>Device8 - State " + Device8state + "</p>");
            // If Device 9 is off, it displays the ON button       
            if (Device8state == "off") {
              client.println("<p><a href=\"/Device8/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/Device8/off\"><button class=\"button button2\">OFF</button></a></p>");
            }

            
            
            client.println("</body></html>");
            
            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}























 
