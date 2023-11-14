#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>
#define COLOR_VERDE
#define COLOR_AMARILLO
#define COLOR_ROJO
#define COLOR_RESET

struct Semaforo {
	int luzVerde;
	int luzAmarilla;
	int luzRoja;
};

int main() {
	struct Semaforo semaforo = {0, 0, 1};
	
	int tiempoVerde = 20;
	int tiempoAmarillo = 5;
	int tiempoRojo = 15;
	
	while (1) {
		if (semaforo.luzVerde) {
			printf(COLOR_VERDE);
		} else if (semaforo.luzAmarilla) {
			printf(COLOR_AMARILLO);
		} else {
			printf(COLOR_ROJO);
		}
		
		if (semaforo.luzVerde) {
			printf("Luz Verde encendida\n");
			system("Color A0");
		} else if (semaforo.luzAmarilla) {
			printf("Luz Amarilla encendida\n");
			system("Color E0");
		} else {
			printf("Luz Roja encendida\n");
			system("Color 48");
		}
		
		printf(COLOR_RESET);
		
		if (semaforo.luzVerde) {
			sleep(tiempoVerde);
			semaforo.luzVerde = 0;
			semaforo.luzAmarilla = 1;
		} else if (semaforo.luzAmarilla) {
			sleep(tiempoAmarillo);
			semaforo.luzAmarilla = 0;
			semaforo.luzRoja = 1;
		} else {
			sleep(tiempoRojo);
			semaforo.luzRoja = 0;
			semaforo.luzVerde = 1;
		}
	}
	
	return 0;
}
