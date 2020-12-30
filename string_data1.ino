#include<SoftwareSerial.h>
#include <Wire.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <HTTPSRedirect.h>
ESP8266WiFiMulti wifiMulti;
String data;
int i,j,k;
char default_id[15], default_password[15],user_id[15],password[15];
String vehicle,owner_name,vehicle_name,owner_no,other_no,email;

int RXPin = D7;
int TXPin = D8;
SoftwareSerial ss(RXPin,TXPin);


SoftwareSerial bt(D3,D0);
void formulatedata(String data);
void defaultvalues(String info);
void id_password(String info);
char* id;
char* pas;


const uint8_t MPU6050SlaveAddress = 0x68;
float rad_to_deg = 180/3.141592654; 
const uint8_t scl = D1;
const uint8_t sda = D2;   
const char* host = "script.google.com";
const int httpsPort = 443;

void MPU6050_Init();
void Read_RawValue(uint8_t deviceAddress, uint8_t regAddress);
void I2C_Write(uint8_t deviceAddress, uint8_t regAddress, uint8_t data);
void mpusensordata();
void send_data2();
void send_email();
//WiFiClientSecure client;
//const char* fingerprint = "46 B2 C3 44 9C 59 09 8B 01 B6 F8 BD 4C FB 00 74 91 2F EF F6";
//String GAS_ID = "AKfycbxldea6Xve_Ea9fiXNVEVl716F62-zbcd0tSemo83cN90JMw3aI"; 
//String Email_ID="AKfycbzLq1jEeChwDzu-3vgj43Sg7QXkwNAG-mqa8jD5d6UNz3itzvwQ";
String url = "https://script.google.com/macros/s/AKfycbxldea6Xve_Ea9fiXNVEVl716F62-zbcd0tSemo83cN90JMw3aI/exec?";
String url2 = "https://script.google.com/macros/s/AKfycbzLq1jEeChwDzu-3vgj43Sg7QXkwNAG-mqa8jD5d6UNz3itzvwQ/exec?";
const uint16_t AccelScaleFactor = 16384;
const uint16_t GyroScaleFactor = 131;
const uint8_t MPU6050_REGISTER_SMPLRT_DIV   =  0x19;
const uint8_t MPU6050_REGISTER_USER_CTRL    =  0x6A;
const uint8_t MPU6050_REGISTER_PWR_MGMT_1   =  0x6B;
const uint8_t MPU6050_REGISTER_PWR_MGMT_2   =  0x6C;
const uint8_t MPU6050_REGISTER_CONFIG       =  0x1A;
const uint8_t MPU6050_REGISTER_GYRO_CONFIG  =  0x1B;
const uint8_t MPU6050_REGISTER_ACCEL_CONFIG =  0x1C;
const uint8_t MPU6050_REGISTER_FIFO_EN      =  0x23;
const uint8_t MPU6050_REGISTER_INT_ENABLE   =  0x38;
const uint8_t MPU6050_REGISTER_ACCEL_XOUT_H =  0x3B;
const uint8_t MPU6050_REGISTER_SIGNAL_PATH_RESET  = 0x68;


int Gpsdata;             
unsigned int finish =0;  
unsigned int pos_cnt=0;  
unsigned int lat_cnt=0;  
unsigned int log_cnt=0;  
unsigned int flg    =0;  
unsigned int com_cnt=0;  
char lati[30];           
char lg[30]; 
String Phone_no="";            
void Receive_GPS_Data();
String send_data();
int16_t AccelX, AccelY, AccelZ;
String payload = "";

HTTPSRedirect* client = nullptr;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  ss.begin(9600); 
  bt.begin(9600);
  //bt.begin(9600);
  Wire.begin(sda,scl);
  MPU6050_Init();
  WiFi.mode(WIFI_STA);
  Serial.println("Connecting Wifi...");
  pinMode(D4,OUTPUT);
  

  
  
}

void loop() {
 
  id="home";
 pas="123456789";
  wifiMulti.addAP(default_id, default_password);
  wifiMulti.addAP(user_id, password);
  wifiMulti.addAP(id, pas);
//ss.end();
// take bluetooth data
bt.begin(9600);
  if(bt.available()>0)
 {
  data=bt.readString();
  formulatedata(data);
  Serial.println(owner_name);
 }

  
  if (wifiMulti.run() != WL_CONNECTED) {
    Serial.println("WiFi not connected!");
    delay(1000);
    digitalWrite(D4,LOW);
    
  }
  if (wifiMulti.run() == WL_CONNECTED) {
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    digitalWrite(D4,HIGH);
    //delay(1000);
}

mpusensordata();
//send_data2();
//delay(2000);
// Receive_GPS_Data();              
//   Serial.print("Latitude  : ");
//   Serial.println(lati);
//   Serial.print("Longitude : ");
//   Serial.println(lg);
//   finish = 0;
//   pos_cnt = 0;
//   send_data2();
}

     // put your main code here, to run repeatedly:

