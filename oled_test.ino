#include <U8g2lib.h>
#include <wire.h>
#include <arduino.h>

U8G2_SSD1306_128X64_NONAME_2_HW_I2C u8g2(U8G2_R0, SCL, SDA, /* cs=*/ 10, /*dc=*/ 9, RST);
void setup(void) {
  u8g2.begin();
}
void loop(void) {
  u8g2.firstPage();
  do {
    u8g2.setFont(u8g2_font_ncenB14_tr);
    u8g2.drawStr(0,15,"Hello World!");
  } while ( u8g2.nextPage() );
  delay(1000);
}

/*
  

void draw(void) {
  // graphic commands to redraw the complete screen should be placed here
  u8g.setFont(u8g_font_unifont);
  //u8g.setFont(u8g_font_osb21);
  //This Part Dsiplays Battery Indicator
  u8g.drawFrame(14, 5, 22, 10);                   //Frame for battery sign
  u8g.drawFrame(17, 1, 5, 5);                     //Terminal for battery
  u8g.drawFrame(28, 1, 5, 5);                     //Terminal for battery
  u8g.drawFrame(10, 16, 30, 46);                  //Frame for battery indicator
  u8g.drawLine(19, 7, 19, 11);                    //Vertical line for positive battery sign
  u8g.drawLine(17, 9, 21, 9);                     //Horizontal line for positive battery sign
  u8g.drawLine(27, 9, 31, 9);
  u8g.drawBox(14, 20, 22, 8);
  u8g.drawBox(14, 30, 22, 8);
  u8g.drawBox(14, 40, 22, 8);
  u8g.drawBox(14, 50, 22, 8);
  //This Part Displays Dispensing Level
  u8g.drawFrame(46, 16, 30, 46);
  //This Part Displays Chalk Storage Level
  u8g.drawFrame(82, 16, 30, 46);


}

void setup(void) {

  u8g.getMode() == U8G_MODE_BW;
  u8g.setColorIndex(1);         // pixel on
}
void loop(void) {
  // picture loop
  u8g.firstPage();
  do {
    draw();
  } while ( u8g.nextPage() );

  // rebuild the picture after some delay
  delay(50);
}

float iREF = 1.24; //internal reference cal factor

void setup() {
  // put your setup code here, to run once:
  analogReference(EXTERNAL);
  //burn some ADC readings after reference change
  for (int i = 0; i < 8; i++) analogRead(A0);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(3000);
  Serial.print("Measured battery voltage is: ");
  Serial.println(fReadVcc());
  Serial.println();
}

//This function uses the known internal reference value of the 328p (~1.1V) to calculate the VCC value which comes from a battery
//This was leveraged from a great tutorial found at https://code.google.com/p/tinkerit/wiki/SecretVoltmeter?pageId=110412607001051797704
float fReadVcc() {
  ADMUX = _BV(REFS0) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);
  delay(3); //delay for 3 milliseconds
  ADCSRA |= _BV(ADSC); // Start ADC conversion
  while (bit_is_set(ADCSRA, ADSC)); //wait until conversion is complete
  int result = ADCL; //get first half of result
  result |= ADCH << 8; //get rest of the result
  float batVolt = (iREF / result) * 1024; //Use the known iRef to calculate battery voltage
  return batVolt;
}

*/
