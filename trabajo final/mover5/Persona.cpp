#include "Persona.h"
Persona::Persona(){  }
Persona::~Persona(){  }
int Persona::retornar_x() { return x; }
int Persona::retornar_y() { return y; }
int Persona::retornar_dx() { return dx; }
int Persona::retornar_dy() { return dy; }
int Persona::retornar_w() { return w; }
int Persona::retornar_h() { return h; }
int Persona::retornar_indiceX() { return indiceX; }
int Persona::retornar_indiceY() { return indiceY; }
void Persona::cambiar_x(int n) { x = n; }
void Persona::cambiar_y(int n) { y = n; }
void Persona::cambiar_dx(int n) { dx = n; }
void Persona::cambiar_dy(int n) { dy = n; }
void Persona::cambiar_w(int n) { w = n; }
void Persona::cambiar_h(int n) { h = n; }
void Persona::cambiar_indiceX(int n) { indiceX = n; }
void Persona::cambiar_indiceY(int n) { indiceY = n; }
void Persona::dibujar(Graphics^ g, Bitmap^ img){

	Rectangle porcionAUsar = Rectangle(indiceX * w, indiceY * h, w, h);
	Rectangle aumentoPersona = Rectangle(x, y, w*2 , h* 2);
	g->DrawImage(img, aumentoPersona, porcionAUsar, GraphicsUnit::Pixel);
}
void Persona::mover(Graphics^ g, Bitmap^ img){ 

}