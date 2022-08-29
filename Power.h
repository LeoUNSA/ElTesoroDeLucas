#pragma once
#include "SFML/Graphics.hpp"
#include "Collisionable.h"
using namespace sf;
//Definimos los elementos de la clase Power y le heredamos el sistema de colisiones de la clase abstracta colisionable.
//Le agregamos la propiedad Drawable de la librería SFML.
class Power : public Drawable, public Collisionable{
    Sprite _sprite;
    Texture _texture;

    public:
        Power();
        void update();
        void draw(RenderTarget& target, RenderStates states) const override;
        void respawn();
        FloatRect getBounds() const override;
};