#pragma once
#include "SFML/Graphics.hpp"
using namespace sf;
//Clase abstracta para programar las colisiones en las demás clases por medio de herencia.
class Collisionable{
public:
    virtual FloatRect getBounds() const = 0;
    bool isCollisionable(Collisionable& col) const;
};