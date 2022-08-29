#pragma once
#include "SFML/Graphics.hpp"
#include "Collisionable.h"
#include "SFML/Audio.hpp"
using namespace sf;
//Definimos los elementos de la clase Enemy y le heredamos el sistema de colisiones de la clase abstracta colisionable.
//Le agregamos la propiedad Drawable de la librería SFML.
class Enemy :public Drawable, public Collisionable {
    Sprite _sprite;
    Texture _texture;
    int _timeRespawn;
    Sound _canal;
    SoundBuffer _risa;
    Vector2f _newPosition;
public:
    Enemy();
    void update();
    void draw(RenderTarget& target, RenderStates states) const override;
    void respawn();
    void youDamaged();
    FloatRect getBounds() const override;
};