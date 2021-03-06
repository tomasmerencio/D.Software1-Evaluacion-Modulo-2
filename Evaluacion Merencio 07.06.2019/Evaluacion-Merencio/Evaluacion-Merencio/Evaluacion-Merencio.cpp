#include "pch.h"
#include <iostream>
using namespace std;
//Parte A
const int tamañoVector = 7;

const int cantJugadores = 5;

struct jugador {
	int id;
	int maquinas[5];
	int vecesJugadas;
};
int jugadorMasVicio(jugador jugadores[cantJugadores]);
int maquinaMasUtilizada(int acumuladorMaquinas[5]);

int calcularFactorial(int numero);

int main()
{
	//Ejercicio 1
	cout << endl << "-----Ejercicio 1-----" << endl;
	int primerVector[tamañoVector] = { 2,2,2,2,2,2,2 };
	int segundoVector[tamañoVector] = { 1,1,1,1,1,1,1 };
	int tercerVector[tamañoVector] = {};

	cout << "Tercer Vector: " << endl;
	for (int i = 0; i < tamañoVector; i++) {
		if (i % 2 == 0)
			tercerVector[i] = primerVector[i];
		else tercerVector[i] = segundoVector[i];
		cout << "Pos " << i << ": " << tercerVector[i] << endl;
	}

	//Ejercicio 2
	cout << endl << "-----Ejercicio 2-----" << endl;
	int acumuladorMaquinas[5] = {};
	jugador jugadores[cantJugadores];
	int numeroJugador = 0;
	for (int i = 0; i < cantJugadores; i++) {
		cout << "Ingrese cantidad de veces que jugador " << i << " jugo en: " << endl; 
		jugadores[i].vecesJugadas = 0;
			for (int j = 0; j < 5; j++){
				cout << "Maquina " << j << ": ";
				cin >> jugadores[i].maquinas[j];
				jugadores[i].vecesJugadas += jugadores[i].maquinas[j];
				acumuladorMaquinas[j] += jugadores[i].maquinas[j];
			}
		cout << "Veces Jugadas: " << jugadores[i].vecesJugadas << endl;
	}

	cout << "Jugador mas vicio: " << jugadorMasVicio(jugadores) << endl;
	cout << "Maquina mas utilizada: " << maquinaMasUtilizada(acumuladorMaquinas) << endl;

	cout <<"Ingrese Jugador del que desea saber la maquina que mas utilizo: " << endl;
	cin >> numeroJugador;
	cout << "Maquina que mas utilizo: " << maquinaMasUtilizada(jugadores[numeroJugador].maquinas);
	
	//Ejercicio 3
	int numero;
	cout << endl << "-----Ejercicio 3-----" << endl;
	cout << "Ingrese numero: ";
	cin >> numero;
	cout << "Factorial de numero ingresado: " << calcularFactorial(numero) << endl;

}


int jugadorMasVicio(jugador jugadores[cantJugadores]) {
	int jugador = 0;
	int max = 0;
	for (int i = 0; i < cantJugadores; i++) {
		if (jugadores[i].vecesJugadas > max) {
			max = jugadores[i].vecesJugadas;
			jugador = i;
		}
	}
	return jugador;
}

int maquinaMasUtilizada(int acumuladorMaquinas[5]) {
	int max = 0;
	int maquina = 0;
	for (int i = 0; i < 5; i++) {
		if (acumuladorMaquinas[i] > max) {
			max = acumuladorMaquinas[i];
			maquina = i;
		}
	}
	return maquina;
}

int calcularFactorial(int numero) {
	if (numero > 1)
		return numero * calcularFactorial(numero - 1);
	else
		return 1;
}