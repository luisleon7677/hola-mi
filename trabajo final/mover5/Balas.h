#pragma once
#include "Persona.h"
class Balas :
	public Persona
{
private:
	bool eliminar;
public:
	Balas();
	~Balas();
	void mover(Graphics^g,Bitmap^img);
	bool retonar_eliminar();
	void cambiar_eliminar(bool n);
};

