#include "Escudo.h"
using namespace sf;
Escudo::Escudo()
{
    Color es (255, 218, 235);
    _velocidad = { 2,-2 };
    _textura.loadFromFile("Recursos/esfera.png");
    _sprite.setTexture(_textura);
    //modificamos el punto de agarre del sprite 
    _sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
}
void Escudo::update(Vector2i pos, Vector2i mouse_pos)
{
    _velocidad.x = (pos.x - mouse_pos.x)/100;
    _velocidad.y = (pos.y - mouse_pos.y) / 100;
    _sprite.move(_velocidad);
}


void Escudo::draw(RenderTarget& target, RenderStates states)const
{
    target.draw(_sprite, states);
}
//Función para la aparición/reaparición del Escudo.
void Escudo::respawn(Vector2i pos)
{
    _sprite.setPosition(pos.x+1,pos.y-30);

}
FloatRect Escudo::getBounds() const
{
    return _sprite.getGlobalBounds();
}
