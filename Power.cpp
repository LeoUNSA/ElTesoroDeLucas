#include <stdlib.h>
#include "Power.h"
using namespace sf;
Power::Power()
{
    _texture.loadFromFile("Recursos/Chile.png");

    //agregar textura al sprite
    _sprite.setTexture(_texture);

    //modificamos el punto de agarre del sprite 
    _sprite.setOrigin(_sprite.getGlobalBounds().width/2,_sprite.getGlobalBounds().height/2);
}

void Power::update()
//Actualiza el estado de Power
{

}

void Power::draw(RenderTarget& target, RenderStates states) const
{
    target.draw(_sprite, states);
}
//Función para la aparición/reaparición de Power.
void Power::respawn()
{
    _sprite.setPosition(std::rand() % 700 + _sprite.getGlobalBounds().width, std::rand() % 500 + _sprite.getGlobalBounds().height);
    if (_sprite.getGlobalBounds().left < 0) {
        respawn();
    }
    if (_sprite.getGlobalBounds().top < 0) {
        respawn();
    }
    if (_sprite.getGlobalBounds().left + _sprite.getGlobalBounds().width > 800) {
        respawn();
    }
    if (_sprite.getGlobalBounds().top + _sprite.getGlobalBounds().height > 600) {
        respawn();
    }
    
}
//Método de colisiones implementado.
FloatRect Power::getBounds() const
{
    return _sprite.getGlobalBounds();
}

