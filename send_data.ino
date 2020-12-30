//String send_data(){
//Serial.println("connecting to ");
//Serial.println(host);
//if (!client.connect(host, httpsPort)) {
//Serial.println("connection failed");
//return "connection failed";
//}
//if (client.verify(fingerprint, host)) {
//Serial.println("certificate matches");
//}
//else {
//Serial.println("certificate doesn't match");
//}
//String latitude(lati);
//String longitude(lg);
//String url = "/macros/s/" + GAS_ID + "/exec?name=" + owner_name + "&vehicle=" + vehicle_name + "&ownerno=" + owner_no +"&otherno=" + other_no + "&latitude=" + latitude + "&longitude=" + longitude;
//String url1 = "/macros/s/" + Email_ID + "/exec?number=" + owner_no+"&email=" +email+ "&latitude=" + latitude + "&longitude=" + longitude;
//Serial.println("requesting URL: ");
//Serial.print(url);
//client.print(String("GET ") + url + " HTTP/1.1\r\n" +
//"Host: " + host + "\r\n" +
//    "User-Agent: BuildFailureDetectorESP8266\r\n" +
//    "Connection: close\r\n\r\n");
//Serial.println("request sent");
//while (client.connected()) {
//String line = client.readStringUntil('\n');
//if (line == "\r") {
//Serial.println("headers received");
//client.print(String("GET ") + url1 + " HTTP/1.1\r\n" +
//"Host: " + host + "\r\n" +
//    "User-Agent: BuildFailureDetectorESP8266\r\n" +
//    "Connection: close\r\n\r\n");
//break;
//}
//}
//String line = client.readStringUntil('\n');
//if (line.startsWith("{\"state\":\"success\"")) {
//Serial.println("esp8266/Arduino CI successfull!");
//return "suc";
//} 
//else {
//Serial.println("esp8266/Arduino CI has failed");
//}
//Serial.println("reply was:");
//Serial.println("==========");
//Serial.println(line);
//Serial.println("==========");
//Serial.println("closing connection");
//}  
//
//

