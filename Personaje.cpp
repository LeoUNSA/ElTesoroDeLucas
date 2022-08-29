#include "Personaje.h"
using namespace std;
using namespace sf;
Personaje::Personaje()
{
    _frame = 0;
    _velocidad = { 4,4 };


    _textura.loadFromFile("Recursos/Player.png");
    //agregar textura al sprite
    _sprite.setTexture(_textura);
    _sprite.setTextureRect({ 0, 0, 30, 40 });

    //modificamos el punto de agarre del sprite 
    _sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height);

}

void Personaje::update()
{
    Vector2f velocidad = { 0,0 };
    //_frame += 0.2;
    //_sprite.setTextureRect({ 0 + int(_frame) * 64,0,62,60 });

    if (_frame >= 4) {
        _frame = 0;
    }
    //recogiendo los eventos de movimiento y asignandoles animaciones
    if (Keyboard::isKeyPressed(Keyboard::Up)) {
        velocidad.y = -_velocidad.y;
        _sprite.setTextureRect({ 0 + int(_frame) * 33,146,32,40 });
    }
    else if (Keyboard::isKeyPressed(Keyboard::Down)) {
        velocidad.y = +_velocidad.y;
        _sprite.setTextureRect({ 0 + int(_frame) * 33,0,30,40 });
    }
    else if (Keyboard::isKeyPressed(Keyboard::Left)) {
        velocidad.x = -_velocidad.x;
        _sprite.setTextureRect({ 0 + int(_frame) * 31,50,30,40 });
    }
    else if (Keyboard::isKeyPressed(Keyboard::Right)) {
        velocidad.x = +_velocidad.x;
        _sprite.setTextureRect({ 0 + int(_frame) * 32,98,30,40 });
    }
    else {
        _sprite.setTextureRect({ 0 + int(_frame) * 31,0,32,40 });
    }


    //gira el sprite de manera que mire a donde camina
    _sprite.move(velocidad);

    if (velocidad.x < 0 || velocidad.y < 0) {
        //_sprite.setScale(1, 1);
        _frame += 0.2;
    }
    else if (velocidad.x > 0 || velocidad.y > 0) {
        //_sprite.setScale(-1, 1);
        _frame += 0.2;

    }

    //delimitar margenes de la pantalla
    if (_sprite.getGlobalBounds().left < 0) {
        _sprite.setPosition(_sprite.getOrigin().x, _sprite.getPosition().y);
    }
    if (_sprite.getGlobalBounds().top < 0) {
        _sprite.setPosition(_sprite.getPosition().x, _sprite.getOrigin().y);
    }
    if (_sprite.getGlobalBounds().left + _sprite.getGlobalBounds().width > 800) {
        _sprite.setPosition(800 - (_sprite.getGlobalBounds().width - _sprite.getOrigin().x), _sprite.getPosition().y);
    }
    if (_sprite.getGlobalBounds().top + _sprite.getGlobalBounds().height > 600) {
        _sprite.setPosition(_sprite.getPosition().x, 600 + (_sprite.getGlobalBounds().height - _sprite.getOrigin().y));
    }
}
//Pasando parametros necesarios para que sea dibujado
void Personaje::draw(RenderTarget& target, RenderStates states)const
{
    target.draw(_sprite, states);
}
//Método de colisiones implementado.
FloatRect Personaje::getBounds() const
{
    return _sprite.getGlobalBounds();
}

void Personaje::hited()
{
}
//Función para añadirle velocidad al personaje con los power ups
void Personaje::agregarVelocidad(float velocidad)
{
    _velocidad.x += velocidad;
    _velocidad.y += velocidad;

}
//Implementación del sistema de vídas y método para obtener las vidas del jugador.
int Personaje::getVida() {
    return this->vida_jugador;
}
void Personaje::operator()(Vida obj) {
    this->vida_jugador += obj.get_valor();
}
//Método para recibir daño.
void Personaje::daño() {
    this->vida_jugador -= 1;
}
//Método para obtener posición.
Vector2i Personaje::obtener_pos()
{
    sf::Vector2i pos;
    pos.x = int(_sprite.getPosition().x);
    pos.y = int(_sprite.getPosition().y);
    return pos;
}
