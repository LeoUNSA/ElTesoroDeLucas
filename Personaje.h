#include "SFML/Graphics.hpp"
#include "Collisionable.h"
#include "Vida.h"
#pragma once
using namespace sf;
//Definimos los elementos de la clase Personajey le heredamos el sistema de colisiones de la clase abstracta colisionable.
//Le agregamos la propiedad Drawable de la librería SFML.
class Personaje: public Drawable, public Collisionable{
	int vida_jugador = 3;
	Sprite _sprite;
	Texture _textura;
	Vector2f _velocidad;
	float _frame;
public:
	Personaje();
	void update();
	void draw(RenderTarget& target, RenderStates states)const override;
	FloatRect getBounds() const override;
	void hited();
	Vector2i obtener_pos();
	void agregarVelocidad(float velocity);
	int getVida();
	void operator()(Vida obj);
	void daño();
};

