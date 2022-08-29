#pragma once
#include "SFML/Graphics.hpp"
#include "Collisionable.h"
#pragma once
using namespace sf;
//Definimos los elementos de la clase Escudo y le heredamos el sistema de colisiones de la clase abstracta colisionable.
//Le agregamos la propiedad Drawable de la librería SFML.
class Vida : public Drawable, public Collisionable{
	int valor = 1;
	Sprite _sprite;
	Texture _textura;
	Vector2f _velocidad;

public:
	Vida();
	void update();
	void draw(RenderTarget& target, RenderStates states)const override;
	void respawn();
	int get_valor();
	FloatRect getBounds() const override;

};
