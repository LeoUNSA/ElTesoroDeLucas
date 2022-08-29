    #include "Item.h"
#include <stdlib.h>
using namespace sf;

Item::Item()
{
    _texture.loadFromFile("Recursos/Rupia.png");

    //agregar textura al sprite
    _sprite.setTexture(_texture);

    //modificamos el punto de agarre del sprite 
    _sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
}

void Item::update()
{

}

void Item::draw(RenderTarget& target, RenderStates states) const
{
    target.draw(_sprite, states);
}

void Item::respawn()
{
    //ponemos una posicion aleatoria para nuestro item(anillo)
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

FloatRect Item::getBounds() const
{
    return _sprite.getGlobalBounds();
}