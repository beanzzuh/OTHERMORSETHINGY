
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
  int timeunits = 1000;
  int bluePin = 10;
  int lettersP =0;
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
  
  lcd.begin(16,2);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
  pinMode(bluePin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //lcd.setCursor(0,0);
  displayDAD();
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
          getMilk();
        }
     }
     if(lowC == 7){
        lcd.clear(); 
        lettersP =0; 
        getMilk();
        
            }
     
      
    highC = 0;
    
  }
 if (buttonPushed == HIGH){


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
void getMilk(){
  for(int i =0; i<4;i++){
      DAD[i] = 0;
    }
    DADindex = 0;
}

void displayDAD(){
  lcd.setCursor(0,1);
  for(int i = 0;i <4; i++){
    lcd.print(DAD[i]);
  }
  
}
void printLetter(int num){
  switch (num) {
    case 0: lcd.print("a"); break;
    case 1: lcd.print("b"); break;
    case 2: lcd.print("c"); break;
    case 3: lcd.print("d"); break;
    case 4: lcd.print("e"); break;
    case 5: lcd.print("f"); break;
    case 6: lcd.print("g"); break;
    case 7: lcd.print("h"); break;
    case 8: lcd.print("i"); break;
    case 9: lcd.print("j"); break;
    case 10: lcd.print("k"); break;
    case 11: lcd.print("l"); break;
    case 12: lcd.print("m"); break;
    case 13: lcd.print("n"); break;
    case 14: lcd.print("o"); break;
    case 15: lcd.print("p"); break;
    case 16: lcd.print("q"); break;
    case 17: lcd.print("r"); break;
    case 18: lcd.print("s"); break;
    case 19: lcd.print("t"); break;
    case 20: lcd.print("u"); break;
    case 21: lcd.print("v"); break;
    case 22: lcd.print("w"); break;
    case 23: lcd.print("x"); break;
    case 24: lcd.print("y"); break;
    case 25: lcd.print("z"); break;
  }
  lettersP++;
}
void translator(){
  //go through dad and make letter
  int* allLetters[26] = {aarray,barray,carray,darray,earray,farray,garray,harray,iarray,jarray,karray,larray,marray,narray,oarray,parray,qarray,rarray,sarray,tarray,uarray,varray,warray,xarray,yarray,zarray};
  int match = 1;
  for(int i =0; i<26; i++){
    match = 1;
    for(int j = 0; j<4;j++){
      if(DAD[j] != allLetters[i][j]){
        match = 0;
        break;
      }
    }
    if(match == 1){
        printLetter(i);
       getMilk();
    return;

    }
  }
}
