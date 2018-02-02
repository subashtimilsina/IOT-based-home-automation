
#define DEBUG true

int pin1 =A0;
int pin2 =A1;
int pin3 =A2;
int pin4 =A3;
int pin5 =A4;
int pin6 =A5;
int pin7 =12;
int pin8 =13;

String ssid = "Subash's Wifi";
String password = "bastain123";

void setup() 
{
  Serial.begin(115200);   
  pinMode(pin1,OUTPUT);   
  digitalWrite(pin1,LOW); 
  pinMode(pin2,OUTPUT);   
  digitalWrite(pin2,LOW); 
  pinMode(pin3,OUTPUT);   
  digitalWrite(pin3,LOW); 
  pinMode(pin4,OUTPUT);   
  digitalWrite(pin4,LOW);
  pinMode(pin5,OUTPUT);   
  digitalWrite(pin5,LOW);
  pinMode(pin6,OUTPUT);   
  digitalWrite(pin6,LOW);
  pinMode(pin7,OUTPUT);   
  digitalWrite(pin7,LOW);
  pinMode(pin8,OUTPUT);   
  digitalWrite(pin8,LOW);
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
        
     if (pinNumber == 14)
       pinNumber = A0;
      else if (pinNumber == 15)
        pinNumber = A1;
       else if (pinNumber == 16)
       pinNumber = A2;
       else if (pinNumber == 17)
       pinNumber = A3;
        else if (pinNumber == 18)
       pinNumber = A4;
        else if (pinNumber == 19)
       pinNumber = A5;
             
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
