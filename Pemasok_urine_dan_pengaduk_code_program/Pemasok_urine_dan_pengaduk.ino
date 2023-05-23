#include <DS3231.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// inisialisasi variabel rtc
  DS3231 rtc (SDA, SCL);
  
// inisialisasi pin LCD I2C
  LiquidCrystal_I2C lcd (0x27, 16, 4);
  
// inisialisasi pin 
  int relayPin = A3;
  bool on = LOW;
  bool off = HIGH;
  String hari;
  String waktu;
  String tanggal;
  int proximityPin = A2;
  int flowsensorPin = A3;
  int valvePin = A2;

// inisialisasi waktu
  unsigned long previousMillis = 0; // waktu mulai menyala relay
  unsigned long interval = 120000; // waktu motor aktif selama 20 menit
  
// jumlah volume urine
  const float volumeMax = 125; // Volume maksimum tampungan urine dalam liter

void setup() {
  rtc.begin();
  Serial.begin(9600);

// set input dan output
  pinMode(proximityPin, INPUT);
  pinMode(relayPin, OUTPUT);
  pinMode(flowsensorPin, OUTPUT);
  pinMode(valvePin, OUTPUT);

// kondisi awal relay
  digitalWrite(relayPin, LOW);

// inisialisasi LCD
  Wire.begin();
  lcd.begin();
  lcd.backlight();

// set hari, waktu dan tanggal pada RTC
  rtc.setDOW(MONDAY);
  rtc.setTime(15, 10, 0);
  rtc.setDate(22, 5, 2023);

}

void loop() {
//  mulai RTC
  hari = rtc.getDOWStr();
  waktu = rtc.getTimeStr();
  tanggal = rtc.getDateStr();

// baca nilai promity
  int proximityValue = digitalRead(proximityPin);
// konversi ke liter
   proximityValue = proximityValue * 0.0049;
// hitung jumlah urine dalam tampungan
   int urineLevel = map(proximityValue, 0, 1023, 0, 40);

// baca flow sensor
  int flow (digitalRead, flowsensorPin);

// kondisi awal saat relay aktif 
  
  

}
