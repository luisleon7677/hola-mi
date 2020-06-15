#pragma once
using namespace System::Drawing;
class Persona
{
protected:
	int x, y, dx, dy, w, h;
	int indiceY, indiceX;
public:
	Persona();
	~Persona();
	int retornar_x();
	int retornar_y();
	int retornar_dx();
	int retornar_dy();
	int retornar_w();
	int retornar_h();
	int retornar_indiceX();
	int retornar_indiceY();
	void cambiar_x(int n);
	void cambiar_y(int n);
	void cambiar_dx(int n);
	void cambiar_dy(int n);
	void cambiar_w(int n);
	void cambiar_h(int n);
	void cambiar_indiceX(int n);
	void cambiar_indiceY(int n);
	void dibujar(Graphics^g,Bitmap^img);
	virtual void mover(Graphics^ g, Bitmap^ img);

};

