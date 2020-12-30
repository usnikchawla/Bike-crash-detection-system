void formulatedata(String data)
    {
    switch(data[0])
    {
    case 'd':
    defaultvalues(data);
    break;
    case 'l':
    id_password(data);
    break;
    case 'c':
    vehicle=change(data);
    Serial.println(vehicle);
    break;
    case 'n':
    owner_name = data;
    owner_name=change(owner_name);
    Serial.println(owner_name);
    break;
    case 'v':
    vehicle_name= change(data);
    break;
    case 'p':
    owner_no = change(data);
    break;
    case 'o':
    other_no= change(data);
    break;
    case 'e':
    email = change(data);
    break;
    default:
    break;
    }
    Serial.println(default_id);
    //Serial.print("   ");
    Serial.println(default_password);
    //Serial.println("   ");
    Serial.println(user_id);
    //Serial.print("   ");
    Serial.println(password);
    //Serial.println("");
    Serial.println(vehicle);
    }
void defaultvalues(String info)
    {
      int i=1,j=0;

      while(info[i]!=',')
      {
        default_id[j]=info[i];
        i=i+1;
        j=j+1;
      }
      for(;j<15;j++)
      {
        default_id[j]='\0';
        }
      i=i+1;
      j=0;
      while(info[i]!='\0')
      {
        default_password[j]=info[i];
        i=i+1;
        j+=1;
      }
      for(;j<15;j++)
      {
        default_password[j]='\0';
        }
     }
void id_password(String info)
    {
      //user_id="shivam";
    //  password="mittal";
      int i=1,j=0;

      while(info[i]!=',')
      {
        user_id[j]=info[i];
        i=i+1;
        j=j+1;
      }
      for(;j<15;j++)
      {
        user_id[j]='\0';
        }
      i=i+1;
      j=0;
      while(info[i]!='\0')
      {
        password[j]=info[i];
        i+=1;
        j+=1;
      }
      for(;j<15;j++)
      {
        password[j]='\0';
        }
     }
String change(String info)
    {
//      int i=1;
//      while(info[i]!='\0')
//      {
//        info[i-1]=info[i];
//        i=i+1;
//       
//      }
//     info[i-1]='\0';

     char letter[25];
i=1;
j=0;
while(info[i]!='\0')
      {
        letter[j]=info[i];
        i+=1;
        j+=1;
      }
      for(;j<15;j++)
      {
        letter[j]='\0';
        }
     String info1(letter);   
     return info1; 
    }

