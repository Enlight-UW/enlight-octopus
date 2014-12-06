#define LED1b 13
#define LED2b 12
#define LED3b 11
#define LED4b 10
#define LED1r 9
#define LED2r 8
#define LED3r 7
#define LED4r 6
#define LED1g 5
#define LED2g 4
#define LED3g 3
#define LED4g 2
#define LED5b 42
#define LED6b 52
#define LED5r 44
#define LED6r 50
#define LED5g 46
#define LED6g 48


int led = 3;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(LED1r, OUTPUT);
  pinMode(LED1g, OUTPUT);
  pinMode(LED1b, OUTPUT);
  pinMode(LED2r, OUTPUT);
  pinMode(LED2g, OUTPUT);
  pinMode(LED2b, OUTPUT);
  pinMode(LED3r, OUTPUT);
  pinMode(LED3g, OUTPUT);
  pinMode(LED3b, OUTPUT);
  pinMode(LED4r, OUTPUT);
  pinMode(LED4g, OUTPUT);
  pinMode(LED4b, OUTPUT);
  pinMode(LED5r, OUTPUT);
  pinMode(LED5g, OUTPUT);
  pinMode(LED5b, OUTPUT);
  pinMode(LED6r, OUTPUT);
  pinMode(LED6g, OUTPUT);
  pinMode(LED6b, OUTPUT);
  
  
}

void loop(){

  setColor(5, 0, 0, 0);
  setColor(6, 0, 0, 0);
//   for (int i = 1; i < 7; i++){
//    setColor(i, 255, 255, 255);
//  }
//  
//  delay(1000);
//  
//  for (int w = 0; w < 255; w++){
//    for (int i = 1; i < 7; i++){
//      setColor(i, w, w, w);
//      delay(2);
//    }
//  }
//  
//  delay(1000);
//  
//  for (int w = 0; w < 255; w++){
//    for (int i = 1; i < 7; i++){
//      setColor(i, 255, 255, w);
//      delay(2);
//    }
//  }
//  
//  delay(1000);
//  
//  for (int w = 0; w < 255; w++){
//    for (int i = 1; i < 7; i++){
//      setColor(i, 255, w, 255);
//      delay(2);
//    }
//  }
//  
//  delay(1000);
//  
//  for (int w = 0; w < 255; w++){
//    for (int i = 1; i < 7; i++){
//      setColor(i, w, 255, 255);
//      delay(2);
//    }
//  }
//  
//  delay (1000);
//  
  setColor(1, 0, 0, 255);
  setColor(3, 0, 0, 255);
  setColor(2, 255, 0, 0);
  setColor(4, 222, 0, 0);
  
  delay(100);
  
  setColor(2, 0, 0, 255);
  setColor(4, 0, 0, 255);
  setColor(1, 255, 0, 0);
  setColor(3, 225, 0, 0);
  
  delay(100);
  
  setColor(2, 255, 255, 255);
  setColor(4, 255, 255, 255);
  setColor(1, 255, 255, 255);
  setColor(3, 222, 255, 255);
  
  delay(100);
}


//void cycle() {
// setColor(i, 255, 255, 255); 
//  
//}


void setColor(int n, int r, int g, int b) {
  switch (n) {
    case 1:
        analogWrite(LED1r,r);
        analogWrite(LED1g,g);
        analogWrite(LED1b,b);
        break;
    case 2:
        analogWrite(LED2r,r);
        analogWrite(LED2g,g);
        analogWrite(LED2b,b);
        break;
    case 3:
        analogWrite(LED3r,r);
        analogWrite(LED3g,g);
        analogWrite(LED3b,b);
        break;
    case 4:
        analogWrite(LED4r,r);
        analogWrite(LED4g,g);
        analogWrite(LED4b,b);
        break;
    case 5:
        digitalWrite(LED5r,r > 127?HIGH:LOW);
        digitalWrite(LED5g,g > 127?HIGH:LOW);
        digitalWrite(LED5b,b > 127?HIGH:LOW);
        break;
    case 6:
        digitalWrite(LED6r,r > 127?HIGH:LOW);
        digitalWrite(LED6g,g > 127?HIGH:LOW);
        digitalWrite(LED6b,b > 127?HIGH:LOW);
        break;
  }
  
}

