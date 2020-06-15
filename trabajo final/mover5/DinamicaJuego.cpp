#include "DinamicaJuego.h"
DinamicaJuego::DinamicaJuego(){ 
	Init();
}
DinamicaJuego::~DinamicaJuego() { delete jugador; }
void DinamicaJuego::Init(){
	jugador = new Jugador();
	jugador->cambiar_x(50);
	jugador->cambiar_y(50);
	jugador->cambiar_dx(0);
	jugador->cambiar_dy(0);
	jugador->cambiar_h(48);
	jugador->cambiar_w(32);

}
void DinamicaJuego::Dinamica(Graphics^ g, Bitmap^ img, Bitmap^ imgB){
	jugador->mover(g, img);
	jugador->mover_balas(g, imgB);
}

void DinamicaJuego::cambiar_direccion(Direcciones tecla)
{
	
	
	if (tecla == abajo) {
		jugador->cambiar_direccion(abajo);
	}
	if (tecla == arriba) {
		jugador->cambiar_direccion(arriba);
	}
	if (tecla == derecha) {
		jugador->cambiar_direccion(derecha);
	}
	if (tecla == izquierda) {
		jugador->cambiar_direccion(izquierda);
	}
	if (tecla == ninguna) {
		jugador->cambiar_direccion(ninguna);
	}

}

void DinamicaJuego::disparar()
{
	jugador->disparar();
}
