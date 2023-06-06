// put your setup code here, to run once:
volatile int flujo_frecuencia; // Mide pulsos del sensor de flujo
// Calculo de litros / hora
float vol = 0.0, l_minute;
unsigned int sensor_flujo = 2; // Entrada del sensor
unsigned long currentTime;
unsigned long cloopTime;
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 9);

void flow() // Función de interrupción
{
  flujo_frecuencia++;
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
}

// put your main code here, to run repeatedly:
void loop()
{
  currentTime = millis();
  // Cada segundo, calcula e imprime litros / hora
  if (currentTime >= (cloopTime + 1000))
  {
    cloopTime = currentTime; // Actualiza cloopTime
    if (flujo_frecuencia != 0)
    {
      // Frecuencia de pulso (Hz) = 7.5Q, Q es la velocidad de flujo en L / min.
      l_minute = (flujo_frecuencia / 7.5); // (Frecuencia de pulso x 60 min) / 7.5Q = caudal en L / hora
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
      flujo_frecuencia = 0; // Restablecer contador
      Serial.print(l_minute, DEC); // Imprimir litros / hora
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
