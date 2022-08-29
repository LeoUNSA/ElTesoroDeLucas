#include "Vida.h"
using namespace sf;

Vida::Vida()
{
    _textura.loadFromFile("Recursos/vida.png");

    //agregar textura al sprite
    _sprite.setTexture(_textura);

    //modificamos el punto de agarre del sprite 
    _sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
}
//Update actualiza el estado
void Vida::update()
{

}
//Pasamos parámetros necesarios para el dibujo.
void Vida::draw(RenderTarget& target, RenderStates states) const
{
    target.draw(_sprite, states);
}
//Función para la aparición/reaparición de Enemy.
void Vida::respawn()
{
    //ponemos una posicion aleatoria para nuestra instancia.
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
//Método get
int Vida::get_valor()
{
    return this->valor;
}
//Colisiones implementadas
FloatRect Vida::getBounds() const
{
    return _sprite.getGlobalBounds();
}
