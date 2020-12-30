  void Receive_GPS_Data()
  {
    ss.flush();
    while(finish==0){
      while(ss.available()>0){       
        Gpsdata = ss.read();
        flg = 1;
       if( Gpsdata=='$' && pos_cnt == 0) 
         pos_cnt=1;
       if( Gpsdata=='G' && pos_cnt == 1)
         pos_cnt=2;
       if( Gpsdata=='P' && pos_cnt == 2)
         pos_cnt=3;
       if( Gpsdata=='R' && pos_cnt == 3)
         pos_cnt=4;
       if( Gpsdata=='M' && pos_cnt == 4)
         pos_cnt=5;
       if( Gpsdata=='C' && pos_cnt==5 )
         pos_cnt=6;
       if(pos_cnt==6 &&  Gpsdata ==','){   
         com_cnt++;
         flg=0;
       }
 
       if(com_cnt==3 && flg==1){
        lati[lat_cnt++] =  Gpsdata;        
        flg=0;
       }
       
       if(com_cnt==4 && flg==1){
        lati[lat_cnt++] =  Gpsdata;        
        flg=0;
       }
 
       if(com_cnt==5 && flg==1){
         lg[log_cnt++] =  Gpsdata;         
         flg=0;
       }
       
       if(com_cnt==6 && flg==1){
        lg[log_cnt++] =  Gpsdata;        
        flg=0;
       }
 
       if( Gpsdata == '*' && com_cnt >= 6){
         com_cnt = 0;                     
         lat_cnt = 0;
         log_cnt = 0;
         flg     = 0;
         finish  = 1;
 
      }
    }
}

}
