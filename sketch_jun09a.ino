volatile int pulsos; // Cantidad de pulsos del sensor. Como se usa dentro de una interrupcion debe ser volatile
#include <LiquidCrystal.h>

unsigned int litrosPorHora; // Calculated litres/hour

unsigned char sensorDeFlujo = 2; // Pin al que esta conectado el sensor

unsigned long tiempoAnterior; // Para calcular el tiempo

unsigned long pulsosAcumulados; // Pulsos acumulados

float litros; // Litros acumulados
float precio;//precio por flujo de agua
void flujo () // Funcion de interrupcion

{
  pulsos++; // Simplemente sumar el numero de pulsos
}
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup()
{
    lcd.begin(16, 2);
  pinMode(sensorDeFlujo, INPUT);
  Serial.begin(9600);
  attachInterrupt(0, flujo, RISING); // Setup Interrupt
  interrupts(); // Habilitar interrupciones
  tiempoAnterior = millis();
}

void loop ()
{
  // Cada segundo calcular e imprimir Litros/seg
  if ( millis() - tiempoAnterior > 1000)
  {
    tiempoAnterior = millis(); // Updates cloopTime
    // Pulse frequency (Hz) = 6.67 Q, Q is flow rate in L/min. (Results in +/- 3% range)
    // Q = frecuencia / 6.67 (L/min)
    // Q = (frecuencia * 60) / 6.67 (L/hora)
    pulsosAcumulados += pulsos;
    litrosPorHora = (pulsos * 60 / 6.67); // (Pulse frequency x 60 min) / 7.5Q = flow rate in L/hour
    pulsos = 0; // Reset Counter
    Serial.print(litrosPorHora, DEC); // Print litres/hour
    Serial.print(" L/hour");
    //Serial.print(" Pulsos totales: ");
    //Serial.print(pulsosAcumulados);
    litros = pulsosAcumulados * 1.0 / 400; //Cada 400 pulsos = 1 litro
    Serial.print(litros);
    Serial.println();
    precio=litros*2,5 ;//precio de en colores por litro
    Serial.print(precio);
    Serial.println();
    lcd.setCursor(2, 0);
    lcd.print("ANPANMAN");
    lcd.setCursor(4, 1);
    lcd.print("BTS");

  
    // Por ultimo se limpia el puerto y se deja un delay de 100 ms
    Serial.flush();
    delay(100);
  }
}
