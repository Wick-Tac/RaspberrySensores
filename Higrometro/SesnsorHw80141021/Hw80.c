/*
 * Este programa enciende u led color azul cada que el sensor HW8010
 * detecta humedad despues de un segudno lo apaga, enciende un led color 
 * rojo cada que el sensor no detecte humedad. 
 * 
 * Como compilar desde la terminal
 * gcc Hw80.c -o sensor  -lwiringPi
 * sudo ./sensor
 * 
 */

#include <wiringPi.h>
#include <stdio.h>

int main(void)
{
	wiringPiSetup();

	int ledRojo = 25;
	int ledVerde = 24;
	int s_Humedad = 4;
	
	pinMode(ledRojo, OUTPUT);
	pinMode(ledVerde, OUTPUT);
	pinMode(s_Humedad, INPUT);
	
	int leer;
 
	while (1){
		leer = digitalRead(s_Humedad);
		if (leer == 1){
			printf("Se detecto humedad\n");
			digitalWrite(ledVerde, HIGH);
			delay(3000);
			digitalWrite(ledVerde, LOW);
		}
		else{
			printf("No se detecto humedad\n");
			digitalWrite(ledRojo, HIGH);
			delay(3000);
			digitalWrite(ledRojo, LOW);
		}
		delay(5000);
	}

		
	return 0;
}

