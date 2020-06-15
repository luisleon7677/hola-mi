#pragma once
#include"Balas.h"
#include"Jugador.h"
class DinamicaJuego
{
private:
	Jugador* jugador;
	Balas* bala;
public:
	DinamicaJuego();
	~DinamicaJuego();
	void Init();
	void Dinamica(Graphics^g,Bitmap^img,Bitmap^imgB);
	void cambiar_direccion(Direcciones tecla);
	void disparar();
	
};

