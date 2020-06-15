#include "Jugador.h"
Jugador::Jugador(){ 

	direccion = Direcciones::ninguna;
	ultimaTecla = Direcciones::abajo;
	cantidad = new int; *cantidad = 0;

}
Jugador::~Jugador(){
	for (int i = 0; i < *cantidad; i++)
		delete arreglo[i];
	delete cantidad;
}
void Jugador::mover(Graphics^ g, Bitmap^ img){
	switch (direccion) {
		
	case Direcciones::abajo:
		indiceY = 0;
		if (indiceX >= 0 && indiceX < 3)
			indiceX++;
		else
			indiceX = 0;
			dx = 0;
			dy = 10;
		ultimaTecla = abajo;
		break;
	case Direcciones::arriba:
		indiceY = 3;
		if (indiceX >= 0 && indiceX < 3)
			indiceX++;
		else
			indiceX = 0;
		dx = 0;
		dy = -10;
		ultimaTecla = arriba;
		break;
	case Direcciones::derecha:
		indiceY = 2;
			if (indiceX >= 0 && indiceX < 3)
				indiceX++;
			else
				indiceX = 0;
			dx = 10;
			dy = 0;
		ultimaTecla = derecha;
		break;
	case Direcciones::izquierda:
		indiceY = 1;
			if (indiceX >= 0 && indiceX < 3)
				indiceX++;
			else
				indiceX = 0;
			dx = -10;
			dy = 0;
		ultimaTecla = izquierda;
		break;
	case Direcciones::ninguna:
		dx = 0; dy = 0;
		switch (ultimaTecla)
		{
		case Direcciones::abajo:
			indiceX = 0;
			indiceY = 0;
			break;
		case Direcciones::arriba:
			indiceX = 0;
			indiceY = 3;
			break;
		case Direcciones::derecha:
			indiceX = 0;
			indiceY = 2;
			break;
		case Direcciones::izquierda:
			indiceX = 0;
			indiceY = 1;
			break;
		}
		break;
}
	x += dx;
	y += dy;
	dibujar(g,img);
}

Direcciones Jugador::retornar_direccion()
{
	return direccion;
}

void Jugador::cambiar_direccion(Direcciones nuevaD)
{
	direccion = nuevaD;
}
void Jugador::disparar(){
	Balas** copia = new Balas * [*cantidad + 1];
	for (int i = 0; i < *cantidad; i++)
		copia[i] = arreglo[i];
	copia[*cantidad] = new Balas();
	copia[*cantidad]->cambiar_dx(0);
	copia[*cantidad]->cambiar_dy(0);
	copia[*cantidad]->cambiar_indiceX(0);
	copia[*cantidad]->cambiar_indiceY(0);
	if (direccion == Direcciones::abajo) {
		copia[*cantidad]->cambiar_y(y + h);
		copia[*cantidad]->cambiar_x(x+ w / 2);
		copia[*cantidad]->cambiar_dy(7);
	}
	if (direccion == Direcciones::arriba) {
		copia[*cantidad]->cambiar_y(y);
		copia[*cantidad]->cambiar_x(x + w / 2);
		copia[*cantidad]->cambiar_dy(-7);
	}

	if (direccion == Direcciones::derecha) {
		copia[*cantidad]->cambiar_y(y+ h/2);
		copia[*cantidad]->cambiar_x(x+w);
		copia[*cantidad]->cambiar_dx(7);
	}

	if (direccion == Direcciones::izquierda) {
		copia[*cantidad]->cambiar_y(y+ h/2);
		copia[*cantidad]->cambiar_x(x);
		copia[*cantidad]->cambiar_dx(-7);
	}
	if (direccion == Direcciones::ninguna) {
	
		switch (ultimaTecla)
		{
		case Direcciones::arriba:
			copia[*cantidad]->cambiar_y(y);
			copia[*cantidad]->cambiar_x(x + w / 2);
			copia[*cantidad]->cambiar_dy(-7);
			break;
		case Direcciones::abajo:
			copia[*cantidad]->cambiar_y(y + h);
			copia[*cantidad]->cambiar_x(x+ w / 2);
			copia[*cantidad]->cambiar_dy(7);
			break;
		case Direcciones::derecha:
			copia[*cantidad]->cambiar_y(y+ h / 2);
			copia[*cantidad]->cambiar_x(x + w);
			copia[*cantidad]->cambiar_dx(7);
			break;
		case Direcciones::izquierda:
			copia[*cantidad]->cambiar_y(y+ h / 2);
			copia[*cantidad]->cambiar_x(x);
			copia[*cantidad]->cambiar_dx(-7);
			break;
		}
	}
	*cantidad = *cantidad + 1;
	arreglo = copia;


}
void Jugador::mover_balas(Graphics^ g, Bitmap^ img){
	int cant = 0;
	for (int i = 0; i < *cantidad ; i++)
		cant += arreglo[i]->retonar_eliminar() ? 1 : 0;

	Balas** copia = new Balas * [*cantidad - cant];
	int j = 0;
	for (int i = 0; i < *cantidad; i++) {
		if (!arreglo[i]->retonar_eliminar())
		{
			copia[j] = arreglo[i];
			j++;

		}

	}
	*cantidad = *cantidad - cant;
	arreglo = copia;
	for (int i = 0; i < *cantidad; i++)
		arreglo[i]->mover(g, img);
}
int  Jugador::retornar_cantidad() { return *cantidad; }
Balas* Jugador::retornar_bala(int indice) { return arreglo[indice]; }