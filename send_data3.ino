void send_email()
{


  client = new HTTPSRedirect(httpsPort);
  client->setInsecure();
  client->setPrintResponseBody(true);
  client->setContentTypeHeader("application/json");
  
  Serial.print("Connecting to ");
  Serial.println(host);

  // Try to connect for a maximum of 5 times
  bool flag = false;
  for (int i=0; i<5; i++)
  while(!flag){
    int retval = client->connect(host, httpsPort);
    if (retval == 1) {
       flag = true;
       break;
    }
    else
      Serial.println("Connection failed. Retrying...");
  delayloop(1000);
  }

  if (!flag){
    Serial.print("Could not connect to server: ");
    Serial.println(host);
    Serial.println("Exiting...");
   // return;
  }
 if(flag)
 {
  Serial.println("host connected");
  delayloop(2000);
  } 
  String latitude(lati);
  String longitude(lg);
  String FinalStringToSend;
  FinalStringToSend = url2 +  "&ownerno=" + owner_no +"&email=" + email + "&latitude=" + latitude + "&longitude=" + longitude ;
//  payload = "name=aaaa&vehicleno=122";
//  Serial.println("post");
//  client->POST(FinalStringToSend, host, payload, false);
//  Serial.println("get");
//  client->GET(FinalStringToSend, host);
//  Serial.println("out"); 

   static int connect_count = 0;
  flag = false;
  

  
  if (client != nullptr){
    if (!client->connected()){
      client->connect(host, httpsPort);
      payload= "";
       Serial.println("POST Data to Sheet");
//      FinalStringToSend = url + myString;
  Serial.println("POST url :" + FinalStringToSend);
  client->POST(FinalStringToSend, host, payload,true);
    }
  }
  else{
  Serial.println(" >> Failed to POST data");
  }
  Serial.println("GET url :"+FinalStringToSend);
  client->GET(FinalStringToSend, host);

  delayloop(1000);
}

