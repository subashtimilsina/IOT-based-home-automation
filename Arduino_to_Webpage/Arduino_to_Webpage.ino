
#define DEBUG true


String ssid = "Subash's Wifi";
String password = "bastain123";

void setup() 
{
  Serial.begin(115200);   
  pinMode(4,OUTPUT);   
  digitalWrite(4,LOW); 
  pinMode(5,OUTPUT);   
  digitalWrite(5,LOW); 
  sendData("AT+RST\r\n",2000,DEBUG);
  String cmd = "AT+CWJAP=\"" +ssid+"\",\"" + password + "\"\r\n";
   sendData(cmd,7000,DEBUG);
  sendData("AT+CWMODE=3\r\n",2000,DEBUG);       
  sendData("AT+CIFSR\r\n",2000,DEBUG);          
  sendData("AT+CIPMUX=1\r\n",2000,DEBUG);       
  sendData("AT+CIPSERVER=1,80\r\n",2000,DEBUG); 
}
void loop() 
{
  if(Serial.available()) 
  { 
    if(Serial.find("+IPD,"))
    { 
      delay(1000);       
      int connectionId = Serial.read()-48;   
      Serial.find("pin=");                   
      int pinNumber = (Serial.read()-48)*10; 
      pinNumber += (Serial.read()-48);
      if (pinNumber == 13)
        pinNumber = 5;
      else if (pinNumber == 12)
        pinNumber = 4;       
      digitalWrite(pinNumber, !digitalRead(pinNumber)); 
      
      String closeCommand = "AT+CIPCLOSE="; 
      closeCommand+=connectionId; 
      closeCommand+="\r\n";
      sendData(closeCommand,1000,DEBUG);     
    } 
  } 
}
String sendData(String command, const int timeout, boolean debug) 
{
  String response = ""; 
  Serial.print(command);           
  long int time = millis();
  while( (time+timeout) > millis()) 
  {
    while(Serial.available())     
    {
      char c = Serial.read();      
      response+=c;                 
    }
  }
  if(debug)
  { 
    //Serial.print(response);         //to check whether the esp is sending data or not 
  }
  return response;
} 
