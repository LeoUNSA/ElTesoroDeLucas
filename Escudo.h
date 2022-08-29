#pragma once
#include "SFML/Graphics.hpp"
#include "Collisionable.h"
#pragma once
using namespace sf;
//Definimos los elementos de la clase Escudo y le heredamos el sistema de colisiones de la clase abstracta colisionable.
//Le agregamos la propiedad Drawable de la librería SFML.
class Escudo : public Drawable, public Collisionable{
	Sprite _sprite;
	Texture _textura;
	Vector2f _velocidad;

public:
	Escudo();
	void update(Vector2i pos, Vector2i mouse_pos);
	void draw(RenderTarget& target, RenderStates states)const override;
	void respawn(Vector2i pos);
	FloatRect getBounds() const override;
};
