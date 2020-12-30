void mpusensordata()
{
  float Ax, Ay, Az, T, Gx, Gy, Gz, Acc_angle_x,Acc_angle_y;
  if(vehicle=="car")
{
  Serial.println("car function");
  Read_RawValue(MPU6050SlaveAddress, MPU6050_REGISTER_ACCEL_XOUT_H);
Ax = (float)AccelX/AccelScaleFactor;
Ay = (float)AccelY/AccelScaleFactor;
Az = (float)AccelZ/AccelScaleFactor;
Acc_angle_x = (atan((Ay)/sqrt(pow((Ax),2) + pow((Az),2)))*rad_to_deg);
Acc_angle_y = (atan(-1*(Ax)/sqrt(pow((Ay),2) + pow((Az),2)))*rad_to_deg);
if (abs(Acc_angle_y) >= 70||abs(Acc_angle_x) >= 70){
Serial.print(" Gx: "); 
Serial.print(Acc_angle_x);
Serial.print(" Gy: "); 
Serial.print(Acc_angle_y);
 Receive_GPS_Data();              
   Serial.print("Latitude  : ");
   Serial.println(lati);
   Serial.print("Longitude : ");
   Serial.println(lg);
   finish = 0;
   pos_cnt = 0;
   send_data2();  
   while(true)
   {
    }
   
}
  }
  else
  {
    delay(500);
    Serial.println("bike function");
Read_RawValue(MPU6050SlaveAddress, MPU6050_REGISTER_ACCEL_XOUT_H);
Ax = (float)AccelX/AccelScaleFactor;
Ay = (float)AccelY/AccelScaleFactor;
Az = (float)AccelZ/AccelScaleFactor;
if(abs(Ax) >= 1.4 || abs(Ay) >= 1.4){
Serial.print("Ax: ");
Serial.print(Ax);
Serial.print(" Ay: "); 
Serial.print(Ay);
Serial.print(" Az: "); 
Serial.print(Az);
delay(1000);

for(int i = 0;i <= 3;i++){
delay(1000);
Read_RawValue(MPU6050SlaveAddress, MPU6050_REGISTER_ACCEL_XOUT_H);
Ax = (float)AccelX/AccelScaleFactor;
Ay = (float)AccelY/AccelScaleFactor;
Az = (float)AccelZ/AccelScaleFactor;
Acc_angle_x = (atan((Ay)/sqrt(pow((Ax),2) + pow((Az),2)))*rad_to_deg);
Acc_angle_y = (atan(-1*(Ax)/sqrt(pow((Ay),2) + pow((Az),2)))*rad_to_deg);
if (abs(Acc_angle_y) >= 70){
Serial.print(" Gx: "); 
Serial.print(Acc_angle_x);
Serial.print(" Gy: "); 
Serial.print(Acc_angle_y);
 Receive_GPS_Data();              
   Serial.print("Latitude  : ");
   Serial.println(lati);
   Serial.print("Longitude : ");
   Serial.println(lg);
   finish = 0;
   pos_cnt = 0;
   send_data2(); 
   //send_email();
   while(true)
   {
   }
   }
}
}
}
Acc_angle_x = (atan((Ay)/sqrt(pow((Ax),2) + pow((Az),2)))*rad_to_deg);
Acc_angle_y = (atan(-1*(Ax)/sqrt(pow((Ay),2) + pow((Az),2)))*rad_to_deg);
Serial.print("Ax: ");
Serial.print(Ax);
Serial.print(" Ay: "); 
Serial.print(Ay);
Serial.print(" Az: "); 
Serial.print(Az);
Serial.print(" Gx: "); 
Serial.print(Acc_angle_x);
Serial.print(" Gy: "); 
Serial.print(Acc_angle_y);
Serial.println(" "); 
}


void I2C_Write(uint8_t deviceAddress, uint8_t regAddress, uint8_t data){
Wire.beginTransmission(deviceAddress);
Wire.write(regAddress);
Wire.write(data);
Wire.endTransmission();
}
void Read_RawValue(uint8_t deviceAddress, uint8_t regAddress){
Wire.beginTransmission(deviceAddress);
Wire.write(regAddress);
Wire.endTransmission();
Wire.requestFrom(deviceAddress, (uint8_t)14);
AccelX = (((int16_t)Wire.read()<<8) | Wire.read());
AccelY = (((int16_t)Wire.read()<<8) | Wire.read());
AccelZ = (((int16_t)Wire.read()<<8) | Wire.read());
}
void MPU6050_Init(){
delayloop(150);
I2C_Write(MPU6050SlaveAddress, MPU6050_REGISTER_SMPLRT_DIV, 0x07);
I2C_Write(MPU6050SlaveAddress, MPU6050_REGISTER_PWR_MGMT_1, 0x01);
I2C_Write(MPU6050SlaveAddress, MPU6050_REGISTER_PWR_MGMT_2, 0x00);
I2C_Write(MPU6050SlaveAddress, MPU6050_REGISTER_CONFIG, 0x00);
I2C_Write(MPU6050SlaveAddress, MPU6050_REGISTER_GYRO_CONFIG, 0x00);//set +/-250 degree/second full scale
I2C_Write(MPU6050SlaveAddress, MPU6050_REGISTER_ACCEL_CONFIG, 0x01);// set +/- 2g full scale
I2C_Write(MPU6050SlaveAddress, MPU6050_REGISTER_FIFO_EN, 0x00);
I2C_Write(MPU6050SlaveAddress, MPU6050_REGISTER_INT_ENABLE, 0x01);
I2C_Write(MPU6050SlaveAddress, MPU6050_REGISTER_SIGNAL_PATH_RESET, 0x00);
I2C_Write(MPU6050SlaveAddress, MPU6050_REGISTER_USER_CTRL, 0x00);
}
