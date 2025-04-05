 #include <LiquidCrystal.h>

/*1H = dot
  3 H = Dash
  1 L = between dot/dash
  3 L = nExt letter
  7 L NExt Word
  9 l = EOM

  1. Dectcting h/l
  2 if high 
    -increment some constructive high counter
    -register space/end of dit-da/ end of letter on cons. low
      -reset low
    If low
      -inccerment some constructive low counter
      
      - register space/end of space
      -reset hihgh


      try to stor time? Also DAD is max dit and Dah in letter. fighure out hw to stare inputs from button until 7 time untis pass.  look into how to print milis
      there is a light to make memtromnome 
      fix THE PRINTT UHGH
  */
  const int dit = 1;
  const int dah = 2;
  static int DAD[4] = {0,0,0,0}; 
  float duration, distance;
  const int rs = 12, en = 11, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
  LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
  int highC = 0;
  int lowC = 0;
  const int buttonPin = 2;
  int buttonPushed = 0;
  int storedDAD = 0;
  int realese = 0;
  int pressed = 0; 
  int *dad = DAD;
  int DADindex = 0;
  int timeunits = 900;
  int bluePin = 10;
  // dad = DAD;
  static int aarray[4] = {1,2,0,0};
  static int barray[4] = {2,1,1,1};
  static int carray[4] = {2,1,2,1};
  static int darray[4] = {2,1,1,0};
  static int earray[4] = {1,0,0,0};
  static int farray[4] = {1,1,2,1};
  static int garray[4] = {2,2,1,0};
  static int harray[4] = {1,1,1,1};
  static int iarray[4] = {1,1,0,0};
  static int jarray[4] = {1,2,2,2};
  static int karray[4] = {2,1,2,0};
  static int larray[4] = {1,2,1,1};
  static int marray[4] = {2,2,0,0};
  static int narray[4] = {2,1,0,0};
  static int oarray[4] = {2,2,2,0};
  static int parray[4] = {1,2,2,1};
  static int qarray[4] = {2,2,1,2};
  static int rarray[4] = {1,2,1,0};
  static int sarray[4] = {1,1,1,0};
  static int tarray[4] = {2,0,0,0};
  static int uarray[4] = {1,1,2,0};
  static int varray[4] = {1,1,1,2};
  static int warray[4] = {1,2,2,0};
  static int xarray[4] = {2,1,1,2};
  static int yarray[4] = {2,1,2,2};
  static int zarray[4] = {2,2,1,1};


  
  /*int* startDad[4];
  startDad = dad;*/

void setup() {
  // put your setup code here, to run once:
  
  lcd.begin(16,1);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
  pinMode(bluePin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //lcd.setCursor(0,0);
  buttonPushed = digitalRead(buttonPin);
  if (buttonPushed == HIGH){
    highC++;
     if (lowC > 0) {
      if (lowC == 1){
        //time between same letter
      }
        if (lowC == 3){
          //betwen letters
          translator();

        }
          if (lowC == 5){
            //next word 
          }
            
           
     
    
    }
    lowC = 0;
  
    
  }
  else{
    
    lowC++;
    
     if( highC >0){
      //either dit or dah
      
      if(highC == 1){
        //this dit
        DAD[DADindex] = 1;
        DADindex++;
        //Serial.print("HAIIIIIIIII");

      }
        if(highC == 3){
          //this dah
          DAD[DADindex] = 2;
          DADindex++;
        }
        if(DADindex > 4){
          DADindex = 0;
          for(int i =0; i<4;i++){
      DAD[i] = 0;
    }
        }
     }
     if(lowC == 7){
        lcd.clear();
        for(int i =0; i<4;i++){
      DAD[i] = 0;
    }
    DADindex = 0;
            }
     
      
    highC = 0;
    
  }
 if (buttonPushed == HIGH){
    
    
    
     // Serial.print(DAD[DADindex]);
    
    //dad++;
    //lcd.print("HAI");

  }
  delay(timeunits-5);
  digitalWrite(bluePin,HIGH);
  delay(5);
  digitalWrite(bluePin,LOW);
  
 
  for(int i = 0;i <4; i++){
    Serial.print(DAD[i]);
    
  }
  Serial.println();

}
void translator(){
  //go through dad and make letter
  int match = 1;
  for(int i = 0; i<4; i++){
    if(DAD[i] != aarray[i]){
      match=0;
    }
  }
  if(match == 1){
    lcd.print("a");
    for(int i =0; i<4;i++){
      DAD[i] = 0;
    }
    DADindex = 0;
    return;
  }

  match = 1;
    for(int i = 0; i < 4; i++){
    if(DAD[i] != barray[i]){
      match = 0;
    }
  }
  if(match == 1){
    lcd.print("b");
    for(int i = 0; i < 4; i++){
      DAD[i] = 0;
    }
    DADindex = 0;
    return;
  }

  match = 1; // Reset match for next check
  for(int i = 0; i < 4; i++){
    if(DAD[i] != carray[i]){
      match = 0;
    }
  }
  if(match == 1){
    lcd.print("c");
    for(int i = 0; i < 4; i++){
      DAD[i] = 0;
    }
    DADindex = 0;
    return;
  }

  match = 1;
  for(int i = 0; i < 4; i++){
    if(DAD[i] != darray[i]){
      match = 0;
    }
  }
  if(match == 1){
    lcd.print("d");
    for(int i = 0; i < 4; i++){
      DAD[i] = 0;
    }
    DADindex = 0;
    return;
  }

  match = 1;
  for(int i = 0; i < 4; i++){
    if(DAD[i] != earray[i]){
      match = 0;
    }
  }
  if(match == 1){
    lcd.print("e");
    for(int i = 0; i < 4; i++){
      DAD[i] = 0;
    }
    DADindex = 0;
    return;
  }

  match = 1;
  for(int i = 0; i < 4; i++){
    if(DAD[i] != farray[i]){
      match = 0;
    }
  }
  if(match == 1){
    lcd.print("f");
    for(int i = 0; i < 4; i++){
      DAD[i] = 0;
    }
    DADindex = 0;
    return;
  }

  match = 1;
  for(int i = 0; i < 4; i++){
    if(DAD[i] != garray[i]){
      match = 0;
    }
  }
  if(match == 1){
    lcd.print("g");
    for(int i = 0; i < 4; i++){
      DAD[i] = 0;
    }
    DADindex = 0;
    return;
  }

  match = 1;
  for(int i = 0; i < 4; i++){
    if(DAD[i] != harray[i]){
      match = 0;
    }
  }
  if(match == 1){
    lcd.print("h");
    for(int i = 0; i < 4; i++){
      DAD[i] = 0;
    }
    DADindex = 0;
    return;
  }

  match = 1;
  for(int i = 0; i < 4; i++){
    if(DAD[i] != iarray[i]){
      match = 0;
    }
  }
  if(match == 1){
    lcd.print("i");
    for(int i = 0; i < 4; i++){
      DAD[i] = 0;
    }
    DADindex = 0;
    return;
  }

  match = 1;
  for(int i = 0; i < 4; i++){
    if(DAD[i] != jarray[i]){
      match = 0;
    }
  }
  if(match == 1){
    lcd.print("j");
    for(int i = 0; i < 4; i++){
      DAD[i] = 0;
    }
    DADindex = 0;
    return;
  }

  match = 1;
  for(int i = 0; i < 4; i++){
    if(DAD[i] != karray[i]){
      match = 0;
    }
  }
  if(match == 1){
    lcd.print("k");
    for(int i = 0; i < 4; i++){
      DAD[i] = 0;
    }
    DADindex = 0;
    return;
  }

  match = 1;
  for(int i = 0; i < 4; i++){
    if(DAD[i] != larray[i]){
      match = 0;
    }
  }
  if(match == 1){
    lcd.print("l");
    for(int i = 0; i < 4; i++){
      DAD[i] = 0;
    }
    DADindex = 0;
    return;
  }

  match = 1;
  for(int i = 0; i < 4; i++){
    if(DAD[i] != marray[i]){
      match = 0;
    }
  }
  if(match == 1){
    lcd.print("m");
    for(int i = 0; i < 4; i++){
      DAD[i] = 0;
    }
    DADindex = 0;
    return;
  }

  match = 1;
  for(int i = 0; i < 4; i++){
    if(DAD[i] != narray[i]){
      match = 0;
    }
  }
  if(match == 1){
    lcd.print("n");
    for(int i = 0; i < 4; i++){
      DAD[i] = 0;
    }
    DADindex = 0;
    return;
  }

  match = 1;
  for(int i = 0; i < 4; i++){
    if(DAD[i] != oarray[i]){
      match = 0;
    }
  }
  if(match == 1){
    lcd.print("o");
    for(int i = 0; i < 4; i++){
      DAD[i] = 0;
    }
    DADindex = 0;
    return;
  }

  match = 1;
  for(int i = 0; i < 4; i++){
    if(DAD[i] != parray[i]){
      match = 0;
    }
  }
  if(match == 1){
    lcd.print("p");
    for(int i = 0; i < 4; i++){
      DAD[i] = 0;
    }
    DADindex = 0;
    return;
  }

  match = 1;
  for(int i = 0; i < 4; i++){
    if(DAD[i] != qarray[i]){
      match = 0;
    }
  }
  if(match == 1){
    lcd.print("q");
    for(int i = 0; i < 4; i++){
      DAD[i] = 0;
    }
    DADindex = 0;
    return;
  }

  match = 1;
  for(int i = 0; i < 4; i++){
    if(DAD[i] != rarray[i]){
      match = 0;
    }
  }
  if(match == 1){
    lcd.print("r");
    for(int i = 0; i < 4; i++){
      DAD[i] = 0;
    }
    DADindex = 0;
    return;
  }
   match = 1;
  for(int i = 0; i < 4; i++){
    if(DAD[i] != sarray[i]){
      match = 0;
    }
  }
  if(match == 1){
    lcd.print("s");
    for(int i = 0; i < 4; i++){
      DAD[i] = 0;
    }
    DADindex = 0;
    return;
  }

  match = 1;
  for(int i = 0; i < 4; i++){
    if(DAD[i] != tarray[i]){
      match = 0;
    }
  }
  if(match == 1){
    lcd.print("t");
    for(int i = 0; i < 4; i++){
      DAD[i] = 0;
    }
    DADindex = 0;
    return;
  }

  match = 1;
  for(int i = 0; i < 4; i++){
    if(DAD[i] != uarray[i]){
      match = 0;
    }
  }
  if(match == 1){
    lcd.print("u");
    for(int i = 0; i < 4; i++){
      DAD[i] = 0;
    }
    DADindex = 0;
    return;
  }

  match = 1;
  for(int i = 0; i < 4; i++){
    if(DAD[i] != varray[i]){
      match = 0;
    }
  }
  if(match == 1){
    lcd.print("v");
    for(int i = 0; i < 4; i++){
      DAD[i] = 0;
    }
    DADindex = 0;
    return;
  }

  match = 1;
  for(int i = 0; i < 4; i++){
    if(DAD[i] != warray[i]){
      match = 0;
    }
  }
  if(match == 1){
    lcd.print("w");
    for(int i = 0; i < 4; i++){
      DAD[i] = 0;
    }
    DADindex = 0;
    return;
  }

  match = 1;
  for(int i = 0; i < 4; i++){
    if(DAD[i] != xarray[i]){
      match = 0;
    }
  }
  if(match == 1){
    lcd.print("x");
    for(int i = 0; i < 4; i++){
      DAD[i] = 0;
    }
    DADindex = 0;
    return;
  }

  match = 1;
  for(int i = 0; i < 4; i++){
    if(DAD[i] != yarray[i]){
      match = 0;
    }
  }
  if(match == 1){
    lcd.print("y");
    for(int i = 0; i < 4; i++){
      DAD[i] = 0;
    }
    DADindex = 0;
    return;
  }

  match = 1;
  for(int i = 0; i < 4; i++){
    if(DAD[i] != zarray[i]){
      match = 0;
    }
  }
  if(match == 1){
    lcd.print("z");
    for(int i = 0; i < 4; i++){
      DAD[i] = 0;
    }
    DADindex = 0;
    return;
  }

}
