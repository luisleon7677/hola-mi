#pragma once
#include "Persona.h"
#include"Balas.h"
enum Direcciones{derecha,izquierda,abajo,arriba,ninguna};
class Jugador :
	public Persona
{
private:
	Balas** arreglo;
	int* cantidad;
	Direcciones ultimaTecla;
public:
	Jugador();
	~Jugador();
	Direcciones direccion;
	void mover(Graphics^g,Bitmap^img);
	Direcciones retornar_direccion();
	void cambiar_direccion(Direcciones nuevaD);
	void disparar();
	void mover_balas(Graphics^ g, Bitmap^ img);
	int retornar_cantidad();
	Balas* retornar_bala(int indice);
};

