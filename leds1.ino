  #include <ESP8266WiFi.h>
    const char* ssid = "internetclaro";
const char* password = "774539fr";
//const char* ssid = "LABO";
//const char* password = "murialdo";
//const char* ssid = "SopTec";
//const char* password = "Aucaavr3055";
//const char* ssid = "PROYECTOS2022";
//const char* password = "";
#define Ledr  D0
#define Ledb  D1
#define Ledg  D2
int modo = 6;
int Red = 0, Green = 0, Blue = 0;
int brillo=0, sbrillo=0, bbrillo=0, modoo, x, p=0;
int random1, random2, random3;
WiFiServer server(8080);
void setup() {
  Serial.begin(500000);
  delay(10);
  // put your setup code here, to run once:
  pinMode(Ledr, OUTPUT);
  pinMode(Ledg, OUTPUT);
  pinMode(Ledb, OUTPUT);

  //mediante una pag web se extraen los valores los cuales indicaran la intensidad con la que se encenderan los leds generando así un color en conjunto
  //Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print('Intentando conectar con ');
  Serial.println(ssid);

  WiFi.begin(ssid, password);

brillo=0;
sbrillo=0;
bbrillo=0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print('.');



  }
  Serial.println("");
  Serial.println('Wifi conectado');

  // Start the server
  server.begin();
  Serial.println('El servidor está listo');

  // Print the IP address
  Serial.print('Esta es la dirección IP a la que te tenés que conectar: ');
  Serial.print('http://');
  Serial.print(WiFi.localIP());
  Serial.println('/');


}




void loop() {
  
  if (brillo >= 0 || brillo <= 0) {
    brillo = brillo + sbrillo;
    brillo = brillo + bbrillo;
  }

  // Read the first line of the request



//Serial.println((modo));
  if (modo == 6) { //todo apagado
    analogWrite (Ledr,  0);
    analogWrite (Ledg, 0);
    analogWrite (Ledb, 0);
  }

if (modoo==2){
  for (x=0; x<=1;x++){
    analogWrite (Ledr, 255);
    analogWrite (Ledg, 0);
    analogWrite (Ledb, 0);
    delay(1000);
      analogWrite (Ledr, 0);
    analogWrite (Ledg, 255);
    analogWrite (Ledb, 0);
    delay(1000);
      analogWrite (Ledr, 0);
    analogWrite (Ledg, 0);
    analogWrite (Ledb, 255);
    delay(800);
    break;
}

}
if (modoo==3){
  for (x=0; x<=1;x++){
    analogWrite (Ledr, 255);
    analogWrite (Ledg, 0);
    analogWrite (Ledb, 0);
    delay(500);
      analogWrite (Ledr, 0);
    analogWrite (Ledg, 255);
    analogWrite (Ledb, 0);
    delay(500);
      analogWrite (Ledr, 0);
    analogWrite (Ledg, 0);
    analogWrite (Ledb, 255);
    delay(200);
     break;
}
}
if (modoo==4){
  for (x=0; x<=1;x++){
    if(p==0){
    analogWrite (Ledr,  255);
    analogWrite (Ledg, 0);
    analogWrite (Ledb, 0);
    delay(1000);
      analogWrite (Ledr,  255);
    analogWrite (Ledg, 63);
    analogWrite (Ledb, 0);
     delay(1000);
      analogWrite (Ledr,  255);
    analogWrite (Ledg, 127);
    analogWrite (Ledb, 0);
     delay(1000);
      analogWrite (Ledr,  0);
    analogWrite (Ledg, 191);
    analogWrite (Ledb, 0);
     delay(1000);
      analogWrite (Ledr,  255);
    analogWrite (Ledg, 255);
    analogWrite (Ledb, 0);
    delay(1000);
    }
     if(p==1){
    analogWrite (Ledr,  0);
    analogWrite (Ledg, 255);
    analogWrite (Ledb, 0);
    delay(1000);
      analogWrite (Ledr,  0);
    analogWrite (Ledg, 255);
    analogWrite (Ledb, 63);
     delay(1000);
      analogWrite (Ledr,  0);
    analogWrite (Ledg, 255);
    analogWrite (Ledb, 127);
     delay(1000);
      analogWrite (Ledr,  0);
    analogWrite (Ledg, 255);
    analogWrite (Ledb, 191);
     delay(1000);
      analogWrite (Ledr,  0);
    analogWrite (Ledg, 255);
    analogWrite (Ledb, 255);
    delay(1000);
    }
    if(p==2){
    analogWrite (Ledr,  0);
    analogWrite (Ledg, 0);
    analogWrite (Ledb, 255);
    delay(1000);
      analogWrite (Ledr,  63);
    analogWrite (Ledg, 0);
    analogWrite (Ledb, 255);
     delay(1000);
      analogWrite (Ledr,  127);
    analogWrite (Ledg, 0);
    analogWrite (Ledb, 255);
     delay(1000);
      analogWrite (Ledr,  191);
    analogWrite (Ledg, 0);
    analogWrite (Ledb, 255);
     delay(1000);
      analogWrite (Ledr,  255);
    analogWrite (Ledg, 0);
    analogWrite (Ledb, 255);
    delay(1000);
    }

    p++;
    if(p==3){
      p=0;
    }
     break;
}
}

if (modoo==5){
  for (x=0; x<=1;x++){
    random1 = rand() % 255;
    random2 = rand() % 255;
    random3 = rand() % 255;
    Red = 255 - random1;
    Green = 255 - random2;
    Blue = 255 - random3;
    analogWrite (Ledr,  Red);
    analogWrite (Ledg, Green);
    analogWrite (Ledb, Blue);
    delay (1000);
     break;
}
}

  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  // Wait until the client sends some data

  while (!client.available()) {
    delay(1);
  }

  // Read the first line of the request
  String request = client.readStringUntil('\r');
  
  if (request.indexOf('/TR') != -1 && request.indexOf('/TR') != 7)  {
    analogWrite (Ledr,  0);
    analogWrite (Ledg, 0);
    analogWrite (Ledb, 0);
    modoo=1;
    modo=6;
     Serial.println("11: " + String(request.indexOf('/TR')));
  }
  if (request.indexOf('/A4') != -1)  {
    analogWrite (Ledr,  255 );
    analogWrite (Ledg, 255 );
    analogWrite (Ledb, 255 );
    modo = 0;
    modoo=1;
      Serial.println("A4: " + String(request.indexOf('/A4')));
  }
//
  if (modo==0)  {
//     if (request.indexOf('/33') != -1)  {
//    sbrillo=51;
//  if (brillo > 51 || brillo <= 0) {
//    brillo = brillo + sbrillo;
//  }
//   Serial.println("brs: " + String(request.indexOf('/brs')));
//   }
//   if (request.indexOf('/34') != -1)  {
//    bbrillo=-51;
//  if (brillo > 51 || brillo <= 0) {
//    brillo = brillo + bbrillo;
//  }
//   Serial.println("brb: " + String(request.indexOf('/brb')));
//   }
  if (request.indexOf('/A5') != -1) {

    analogWrite (Ledr,  255);
    analogWrite (Ledg, 0);
    analogWrite (Ledb, 0);
    modoo=1;
    Serial.println("A5: " + String(request.indexOf('/A5')));
  }

  if (request.indexOf('/A6') != -1)  {
    Red = 0;
    Green = 255;
    Blue = 0;
    analogWrite (Ledr,  Red);
    analogWrite (Ledg, Green);
    analogWrite (Ledb, Blue);
     modoo=1;
  }
  if (request.indexOf('/A7') != -1)  {
    Red = 0;
    Green = 0;
    Blue = 255;
    analogWrite (Ledr,  Red);
    analogWrite (Ledg, Green);
    analogWrite (Ledb, Blue);
     modoo=1;
  }
  if (request.indexOf('/A8') != -1)  {
    analogWrite (Ledr,  255);
    analogWrite (Ledg, 255);
    analogWrite (Ledb, 255);
     modoo=1;
  }
  if (request.indexOf('/A9') != -1)  {
    Red = 255;
    Green = 63;
    Blue = 0;
    analogWrite (Ledr,  Red);
    analogWrite (Ledg, Green);
    analogWrite (Ledb, Blue);
     modoo=1;
  }
  if (request.indexOf ('/A10') != -1 && request.indexOf('/A10') ==7)  {
    Red = 255;
    Green = 127;
    Blue = 0;
    analogWrite (Ledr,  Red);
    analogWrite (Ledg, Green);
    analogWrite (Ledb, Blue);
     Serial.println("A10: " + String(request.indexOf('/A10')));
     modoo=1;
 }
  if (request.indexOf('/AY') != -1)  {
    Red = 255;
    Green = 191;
    Blue = 0;
    analogWrite (Ledr,  Red);
    analogWrite (Ledg, Green);
    analogWrite (Ledb, Blue);
    Serial.println("AY: " + String(request.indexOf('/AY')));
       delay(500);
        modoo=1;
  }

  if (request.indexOf('/A12') !=-1 && request.indexOf('/A12') ==7)  {
    Red = 255;
    Green = 255;
    Blue = 0;
    analogWrite (Ledr,  Red);
    analogWrite (Ledg, Green);
    analogWrite (Ledb, Blue);
    Serial.println("A12: " + String(request.indexOf('/A12')));
       delay(500);
        modoo=1;
  }

  if (request.indexOf('/A13') != -1 && request.indexOf('/A13')==7)  {
    Red = 0;
    Green = 255;
    Blue = 63;
    analogWrite (Ledr, Red);
    analogWrite (Ledg, Green);
    analogWrite (Ledb, Blue);
       Serial.println("A13: " + String(request.indexOf('/A13')));
       delay(500);
 modoo=1;
  }
  
//
  if (request.indexOf('/A14') != 6 && request.indexOf('/A14') != -1)  {
    Red = 0;
    Green = 255;
    Blue = 127;
    analogWrite (Ledr,  Red);
    analogWrite (Ledg, Green);
    analogWrite (Ledb, Blue);
    Serial.println("A14: " + String(request.indexOf('/A14')));
     modoo=1;
  }
//
  if (request.indexOf('/A15') != 6 && request.indexOf('/A15') != -1)  {
    Red = 0;
    Green = 255;
    Blue = 191;
    analogWrite (Ledr,  Red);
    analogWrite (Ledg, Green);
    analogWrite (Ledb, Blue);
    Serial.println("A15: " + String(request.indexOf('/A15')));
     modoo=1;
  }
  if (request.indexOf('/A16') != 6 && request.indexOf('/A16') != -1)  {
    Red = 0;
    Green = 255;
    Blue = 255;
    analogWrite (Ledr,  Red);
    analogWrite (Ledg, Green);
    analogWrite (Ledb, Blue);
     Serial.println("A16: " + String(request.indexOf('/A16')));
       delay(500);
        modoo=1;
  }
  if (request.indexOf('/A17') != 6 && request.indexOf('/A17') != -1)  {
    Red = 63;
    Green = 0;
    Blue = 255;
    analogWrite (Ledr,  Red);
    analogWrite (Ledg, Green);
    analogWrite (Ledb, Blue);
    Serial.println("A17: " + String(request.indexOf('/A17')));
       delay(500);
  }
////
  if (request.indexOf('/A18') != 6 && request.indexOf('/A18') != -1)  {
    Red = 127;
    Green = 0;
    Blue = 255;
    analogWrite (Ledr,  Red);
    analogWrite (Ledg, Green);
    analogWrite (Ledb, Blue);
    Serial.println("A18: " + String(request.indexOf('/A18')));
//       delay(500);
  }
  if (request.indexOf('/A19') != 6 && request.indexOf('/A19') != -1)  {
    Red = 191;
    Green = 0;
    Blue = 255;
    analogWrite (Ledr,  Red);
    analogWrite (Ledg, Green);
    analogWrite (Ledb, Blue);
  }

  if (request.indexOf('/z') != -1)  {
    Red = 255;
    Green = 0;
    Blue = 255;
    analogWrite (Ledr,  Red);
    analogWrite (Ledg, Green);
    analogWrite (Ledb, Blue);
    Serial.println("z: " + String(request.indexOf('/z')));
       delay(500);
   
  }


  if (request.indexOf('/i') ==5)  {
  modoo=2;
    Serial.println("i: " + String(request.indexOf('/i')));
       delay(500);
    
  }
  if (request.indexOf('/w')!=-1)  {
      modoo=3;
       Serial.println("w: " + String(request.indexOf('/w')));
       delay(500);
  }
  if (request.indexOf('/u') != 6 && request.indexOf('/u') != -1)  {
    modoo=4;
    Serial.println("u: " + String(request.indexOf('/u')));
       
  }
  if (request.indexOf('/q') != 6 && request.indexOf('/q') != -1)  {
   modoo=5;
    Serial.println("q: " + String(request.indexOf('/q')));
  }
}
  client.flush();
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.print("<html lang='es'> <head> <link rel='stylesheet' href='estilos.css'> </head> <body> <br><br><br><br><br><br><table class='Control' style='border-color: black; border-radius: 15px; background-color: darkgray; width: 500px; height: 750;' align='center' > ");

//  client.print(" <p><a href=\'/\'\'> <tr> <td align='center' > <div style='background-color: grey; width: 100px; height: 100px ; border-radius: 50px;'> <input type='image' src='subir brillo.png' width='70px' align='center' style='padding-top: 15px;'> </div></td></a></p> ");
//  client.print(" <p><a href=\'/\'\'><td align='center' > <div style='background-color: grey; width: 100px; height: 100px ; border-radius: 50px;'> <input type='image' src='bajar brillo.png' width='70px' align='center' style='padding-top: 15px;'> </div></td></a></p>");
  
  client.print(" <tr align='center'><td align='center' ><p><a href=\'/TR\'\'><div style='background-color: black; width: 100px; height: 100px ; border-radius: 50px;'> <input type='image' src='OFF.png' width='70px' align='center' style='padding-top: 15px;'> </div></a></p></td> ");
  client.print(" <td align='center' ><p><a href=\'/A4\'\'><div  style='background-color: white; width: 100px; height: 100px ; border-radius: 50px;'> <input type='image' src='https://drive.google.com/file/d/13pwBk_4iO5ugzt0VPA6b83s8eo70gl_v/view?usp=share_link' width='70px' align='center' style='padding-top: 15px;'> </div></a></p></td></tr>");
  client.print(" <tr><td align='center' ><p><a href=\'/A5\'\'> <div style='background-color: red; width: 100px; height: 100px ; border-radius: 50px; border-color: transparent;'> <input type='image' src='r.png' width='75px' align='center' style='padding-top: 12px;'> </div></a></p></td> ");
  client.print(" <td align='center' ><p><a href=\'/A6\'\'> <div style='background-color: green; width: 100px; height: 100px ; border-radius: 50px; border-color: transparent;'> <input type='image' src='g.png' width='75px' align='center' style='padding-top: 12px;'> </div></a></p></td> ");
  client.print(" <td align='center' ><p><a href=\'/A7\'\'><div style='background-color: blue; width: 100px; height: 100px ; border-radius: 50px; border-color: transparent;'> <input type='image' src='b.png' width='75px' align='center' style='padding-top: 12px;'> </div></a></td></p> ");
  client.print(" <td align='center' ><p><a href=\'/A8\'\'><div style='background-color: white; width: 100px; height: 100px ; border-radius: 50px;'> <input type='image' src='W.png' width='70px' align='center' style='padding-top: 15px;'> </div></a></p></td></tr> ");
  client.print(" <tr><td align='center' ><p><a href=\'/A9\'\'><div> <input type='image' src='c1.jpg' width='70px' align='center' style='background-color: ee5c2b; width: 100px; height: 100px ; border-radius: 50px;'> </div></a></p></td> ");
  client.print(" <td align='center' ><p><a href=\'/A13\'\'><div> <input type='image' src='c2.jpg' width='70px' align='center' style='background-color: 72bd7d; width: 100px; height: 100px ; border-radius: 50px;'> </div></a></p></td> ");
  client.print(" <td align='center' ><p><a href=\'/A17\'\'><div> <input type='image' src='c3.jpg' width='70px' align='center' style='background-color: 1a8bc4; width: 100px; height: 100px ; border-radius: 50px;'> </div></a></p></td>");
  client.print(" <td align='center' ><p><a href=\'/i\'\'><div style='background-color: white; width: 100px; height: 100px ; border-radius: 50px;'> <input type='image' src='Flash.png' width='70px' align='center' style='padding-top: 15px;'> </div></a></p></td></tr>");
  client.print(" <tr><td align='center' ><p><a href=\'/A10\'\'><div> <input type='image' src='d1.jpg' width='70px' align='center' style='background-color: ee8d4e; width: 100px; height: 100px ; border-radius: 50px;'> </div> </a></p></td>");
  client.print(" <td align='center' ><p><a href=\'/A14\'\'><div> <input type='image' src='d2.jpg' width='70px' align='center' style='background-color: 64cacf; width: 100px; height: 100px ; border-radius: 50px;'> </div></a></p></td>");
  client.print(" <td align='center' ><p><a href=\'/A18\'\'><div> <input type='image' src='d3.jpg' width='70px' align='center' style='background-color: 633655; width: 100px; height: 100px ; border-radius: 50px;'> </div> </a></p></td>");
  client.print("<td align='center' > <p><a href=\'/w\'\'><div style='background-color: white; width: 100px; height: 100px ; border-radius: 50px;'> <input type='image' src='STROBE.png' width='70px' align='center' style='padding-top: 15px;'> </div></a></p></td></tr> ");
  client.print("<tr><td align='center' ><p><a href=\'/AY\'\'><div> <input type='image' src='e1.jpg' width='70px' align='center' style='background-color: f0bc6c; width: 100px; height: 100px ; border-radius: 50px;'> </div></a></p></td> ");
  client.print(" <td align='center' ><p><a href=\'/A15\'\'><div> <input type='image' src='e2.jpg' width='70px' align='center' style='background-color: 1bb8ca; width: 100px; height: 100px ; border-radius: 50px;'> </div></a></p></td></td> ");
  client.print(" <td align='center' ><p><a href=\'/A19\'\'><div> <input type='image' src='e3.jpg' width='70px' align='center' style='background-color: 854874; width: 100px; height: 100px ; border-radius: 50px;'> </div> </a></p></td>");
  client.print(" <td align='center' ><p><a href=\'/u\'\'><div style='background-color: white; width: 100px; height: 100px ; border-radius: 50px;'> <input type='image' src='FADE.png' width='70px' align='center' style='padding-top: 15px;'> </div> </a></p></td></tr>");
  client.print(" <tr><td align='center' ><p><a href=\'/A12\'\'><div> <input type='image' src='f1.jpg' width='70px' align='center' style='background-color: f5e352; width: 100px; height: 100px ; border-radius: 50px;'> </div></a></p></td>");
  client.print(" <td align='center' ><p><a href=\'/A16\'\'><div> <input type='image' src='f2.jpg' width='70px' align='center' style='background-color: 15a5b4; width: 100px; height: 100px ; border-radius: 50px;'> </div> </a></p></td>");
  client.print(" <td align='center' ><p><a href=\'/z\'\'><div> <input type='image' src='f3.jpg' width='70px' align='center' style='background-color: d66695; width: 100px; height: 100px ; border-radius: 50px;'> </div> </a></p></td>");
  client.print(" <td align='center' ><p><a href=\'/q\'\'><div style='background-color: white; width: 100px; height: 100px ; border-radius: 50px;'> <input type='image' src='SMOOTH.png' width='90px' align='center' style='padding-top: 7px;'> </div></td></table></body></html> ");

}
