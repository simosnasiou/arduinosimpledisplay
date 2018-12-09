

/*-----( Import needed libraries )-----*/
#include <Wire.h>  // Comes with Arduino IDE 
// https://bitbucket.org/fmalpartida/new-liquidcrystal/downloads
// See Library "Docs" folder for possible commands etc.
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address


void setup()   /*----( SETUP: RUNS ONCE )----*/
{
  Serial.begin(9600);  // Used to type in characters

  lcd.begin(20,4);         // initialize the lcd for 20 chars 4 lines, turn on backlight

// ------- Quick 2 blinks of backlight  -------------
  for(int i = 0; i< 2; i++)
  {
    lcd.backlight();
    delay(250);
    lcd.noBacklight();
    delay(250);
  }
  lcd.backlight(); // finish with backlight on  

//-------- Write characters on the display ------------------
  // NOTE: Cursor Position: Lines and Characters start at 0  
  lcd.setCursor(0,0);
  lcd.print("Geia sas oi kaboi");
  delay(1000);
  lcd.setCursor(0,1);
  lcd.print("Ki oi xanthoi gialoi");
  delay(1000);  
  lcd.setCursor(0,2);
  lcd.print("Geia sas oi orkoi");
  lcd.setCursor(0,3);
  delay(1000);   
  lcd.print("Oi pantotinoi");
  delay(8000);
  // Wait and then tell user they can start the Serial Monitor and type in characters to
  // Display. (Set Serial Monitor option to "No Line Ending")
  lcd.clear();
  lcd.setCursor(0,0); //Start at character 0 on line 0
  lcd.print("Start Serial Monitor");
  lcd.setCursor(0,1);
  lcd.print("Type chars 2 display");  


}/*--(end setup )---*/


void loop()   /*----( LOOP: RUNS CONSTANTLY )----*/
{
  {
    // when characters arrive over the serial port...
    if (Serial.available()) {
      // wait a bit for the entire message to arrive
      delay(100);
      // clear the screen
      lcd.clear();
      // read all the available characters
      while (Serial.available() > 0) {
        // display each character to the LCD
        lcd.write(Serial.read());
      }
    }
  }

}/* --(end main loop )-- */


/* ( THE END ) */

