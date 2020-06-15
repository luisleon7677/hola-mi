#include "Balas.h"
Balas::Balas() { eliminar = false; w = 20; h = 20; }
Balas::~Balas(){  }
void Balas::mover(Graphics^ g, Bitmap^ img) {

	if (x + dx<g->VisibleClipBounds.Left || x + dx + w>g->VisibleClipBounds.Right)
		eliminar = true;
	if (y + dy<g->VisibleClipBounds.Top || y + dy + w>g->VisibleClipBounds.Bottom)
		eliminar = true;

	x += dx;
	y += dy;
	dibujar(g, img);

}
bool Balas::retonar_eliminar() { return eliminar; }
void Balas::cambiar_eliminar(bool n) { eliminar=n; }