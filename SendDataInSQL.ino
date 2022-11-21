#include <WiFi.h>

//setup const for WiFi connection (blurred)
const char* ssid = "**********";
const char* password = "*********";
const char* host = "localhost";

//////////////////////////////////////
//fill SQL database with simple data//
//could be used for logging sensor////
//data or something/////////////////// 
//////////////////////////////////////

void setup() {
//setup serial connection for debugging
Serial.begin(9600);

//print some information to give feedback of the connection process
Serial.println();
Serial.println();
Serial.print("Connecting to ");
Serial.println(ssid);

//connect to WiFi 
WiFi.begin(ssid,password);

//try again if connection failed
while (WiFi.status() != WL_CONNECTED){
  delay(500);
  Serial.println(".");
}

//give feedback that the connection succeeded
Serial.println("");
Serial.println("WiFi Connected");
Serial.println(WiFi.localIP());
}

void loop() {
//create an counter variable "id_" and the String "Besucher" which gets the id_ appended later on
 int id_ = 2;
 String name_ = "Besucher";

 //keep counting "id_" up and make http request to save the data in SQL (name=Besucher_id_, id=id_)
  while(1==1){
  Serial.print("conencting to ");
  Serial.println(host);
  WiFiClient client;
  const int httpPort = 80;

  //connect to localhost (myIP [blurred] and port 80)
  if(!client.connect("myIP",80)){
    Serial.println("connection failed");
    delay(500);
    return;
  }
  

 //when connection succeeded -> send GET request with id and name to server
  client.print(String("GET http://localhost/connect.php?") +
    ("&id_=") + id_ + 
    ("&name_=") + (name_+id_) +
    "/HTTP/1.1\r\n" +
    "Host :" + host + "\r\n" +
    "Connection: close\r\n\r\n");

//increase id_
    id_++;
    
    delay(500);
}
}
