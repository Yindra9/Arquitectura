#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
#include <BlynkSimpleStream.h>

volatile int flujo_frecuencia; // Mide pulsos del sensor de flujo
float vol = 0.0, l_minute;
unsigned int sensor_flujo = 2; // Entrada del sensor
unsigned long currentTime;
unsigned long cloopTime;

LiquidCrystal lcd(12, 11, 5, 4, 3, 9);
SoftwareSerial SwSerial(10, 11); // RX, TX

#define BLYNK_TEMPLATE_ID           "TMPL6X3cOCu5r"
#define BLYNK_TEMPLATE_NAME         "medidor de flujo"
#define BLYNK_AUTH_TOKEN            "07XnWIabtDqed2bJLoQWE9vLiQvwX9px"

BlynkTimer timer;
int uptimeCounter;
String someStaticData = "SomeStaticData";

void flow() // Función de interrupción
{
  flujo_frecuencia++;
}

void sendSensorData()
{
  currentTime = millis();

  if (currentTime >= (cloopTime + 1000))
  {
    cloopTime = currentTime;

    if (flujo_frecuencia != 0)
    {
      l_minute = (flujo_frecuencia / 7.5);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Velocidad:");
      lcd.print(l_minute);
      lcd.print("L / M");
      l_minute = l_minute / 60;
      lcd.setCursor(0, 1);
      vol = vol + l_minute;
      lcd.print("Vol:");
      lcd.print(vol);
      lcd.print("L");
      flujo_frecuencia = 0;
      Serial.print(l_minute, DEC);
      Serial.println("L / Sec");
    }
    else
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Velocidad:");
      lcd.print(flujo_frecuencia);
      lcd.print("L / M");
      lcd.setCursor(0, 1);
      lcd.print("Vol:");
      lcd.print(vol);
      lcd.print("L");
    }
  }
}

void increment() {
  uptimeCounter++;

  //storing int and string in V0 pin on server
  Blynk.virtualWrite(V0, uptimeCounter, someStaticData);

  //updating value display with uptimeCounter
  Blynk.virtualWrite(V1, uptimeCounter);
}

void setup()
{
  pinMode(sensor_flujo, INPUT);
  digitalWrite(sensor_flujo, HIGH);
  Serial.begin(9600);
  lcd.begin(16, 2);
  attachInterrupt(digitalPinToInterrupt(sensor_flujo), flow, RISING); // Configuración de interrupción
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Medidor de flujo de agua");
  lcd.setCursor(0, 1);
  lcd.print("Resumen del circuito");
  currentTime = millis();
  cloopTime = currentTime;

  SwSerial.begin(115200);
  Blynk.begin(SwSerial, BLYNK_AUTH_TOKEN);
  
  Blynk.virtualWrite(V2, vol); // Inicializar el valor de volumen en la pantalla virtual V2

  timer.setInterval(1000L, increment); // Llama a la función increment cada segundo
}

void loop()
{
  Blynk.run();
  timer.run();
  sendSensorData();
}
