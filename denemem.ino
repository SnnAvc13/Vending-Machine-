#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>            

#define jetonSensor 7 // sensor için input
#define buton1 2      // buton1 için input                    
#define buton2 3      // buton2 için input 
LiquidCrystal_I2C lcd(0x27,16,2);  // lcd tanımlama
Servo servo1, servo2;
int jtn = 0; // atilan jetonu tutan değişken
int butonBasma; //butona basıldıgında aksiyon alan değişken



void setup() {    //objelerin input oldugunu girip setupı hazırladıgımız kısım
  pinMode(buton1, INPUT);
    pinMode(buton2, INPUT); 
      servo1.attach(9);  
        servo2.attach(10); 
              

   
             
}
void loop() { //artık kullanıcıya görünen işlemlerin lcd output vs vs girildigi kısım buradaki kodlar yani loop kısmı devamlı olarak calısacak
                                  servo2.write(90);
                                     servo1.write(90);  
                                        


  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("3 jeton atiniz");
  lcd.setCursor(0, 1);
        lcd.print("atilan jeton :");

  while (true) {
    if (digitalRead(jetonSensor) == LOW) { // ır sensorun onunden geçen jetonların okundugu kısım
      if (jtn == 1) {
        jtn = 0;
        break;
      }
      else {
        lcd.setCursor(0, 1);
        lcd.print("atilan jeton :1");
        jtn = 1;

        delay(500);
      }
    }
  }
  while (true) {
    if (digitalRead(jetonSensor) == LOW) {
      if (jtn == 1) {
        jtn = 0;
        break;
      }
      else {
        lcd.setCursor(0, 1);
        lcd.print("atilan jeton :2");
        jtn = 1;

        delay(500);
      }
    }
  }
  delay(10);            // 3 adet jeton yani para atıldıgında ekrana verilen kısım burada ürünleri seçiyoruz
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Lutfen urun sec!");
  lcd.setCursor(4, 1);
  lcd.print("1      2");
  
  // burada ise 4 butondan birine basıp istedigimiz ürünü seçiyoruz
  while (true) {
    if (digitalRead(buton1) == HIGH) {  //hangi tusa basılır ise o tuşa atanmış olan servo dönüp kullanıcıya ürünü veriyor
      butonBasma = 1;
      

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("1.Urunu sectiniz");
      delay(1000);
            lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Teslim Ediliyor");
  lcd.setCursor(0, 1);
  lcd.print("Lutfen Bekleyin");
  delay(3000);
    lcd.clear();
        servo1.writeMicroseconds(700); 
      delay(1290);
      servo1.writeMicroseconds(1500);  
      delay(300);
      break;
    }
 
 

    if (digitalRead(buton2) == HIGH) {
      butonBasma = 1;   

    lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("2.Urunu sectiniz");
            delay(1000);

            lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Teslim Ediliyor");
  lcd.setCursor(0, 1);
  lcd.print("Lutfen Bekleyin");
  delay(3000);
    lcd.clear();

      servo2.writeMicroseconds(700); 
      delay(1290);
      servo2.writeMicroseconds(1500); 
      delay(300);
      break;
    }
  

   
   
     servo2.write(90);
                                     servo1.write(90);
  }
servo2.write(90);
                                     servo1.write(90);
  
  

    
  lcd.setCursor(0, 0);
  lcd.print("Teslim Edildi...");
  delay(3000);
 lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("baska islem icin");
      lcd.setCursor(0, 1);
      lcd.print("bir butona basin");
      
while (true) {
    if (digitalRead(buton1) == HIGH) {

      butonBasma = 1;
       lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Lutfen Bekleyin...");
      lcd.setCursor(0, 1);
      lcd.print("Yonlendiriliyor");
      delay(5000);
     break;
     servo2.write(90);
                                     servo1.write(90);
    }if (digitalRead(buton2) == HIGH) {
      butonBasma = 1;
       lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Lutfen Bekleyin...");
      lcd.setCursor(0, 1);
      lcd.print("Yonlendiriliyor");
      delay(5000);
     break;
     servo2.write(90);
                                     servo1.write(90);
    
    }
    
                 servo2.write(90);
                                     servo1.write(90);

 
  }
    }
 
  
    
    