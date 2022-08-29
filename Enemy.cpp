#include <stdLib.h>
#include "Enemy.h"
using namespace sf;
//Importamos los recursos de la clase Enemy (Sonido,Sprite).
Enemy::Enemy(){
    _texture.loadFromFile("Recursos/Enemy.png");
    _sprite.setTexture(_texture);
    _sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
    _risa.loadFromFile("Recursos/Oof.wav");
    _canal.setBuffer(_risa);
}
//Update actualiza el estado del enemigo.
void Enemy::update() {
    _timeRespawn--;
    //Temporizador que hace que 2 segundos después de su ataque realice otro.
    //Sistema de movimientos aleatorios y velocidad.
    if (_timeRespawn < 0) {
        _timeRespawn = 60 * 2;
        _newPosition = { std::rand() % 700 + _sprite.getGlobalBounds().width, std::rand() % 500 + _sprite.getGlobalBounds().height };
    }
    if (_newPosition.x > _sprite.getPosition().x) {
        _sprite.move(5, 0);
    }
    if (_newPosition.x < _sprite.getPosition().x) {
        _sprite.move(-5, 0);
    }
    if (_newPosition.y > _sprite.getPosition().y) {
        _sprite.move(0, 5);
    }
    if (_newPosition.y < _sprite.getPosition().y) {
        _sprite.move(0, -5);
    }
    if (std::abs(_newPosition.x - _sprite.getPosition().x) < 5) {
        _sprite.move(0, -5);
    }
    //Hacemos que Enemy reconozca los límites de la ventana e impedimos que salga de la misma.
    if (_sprite.getGlobalBounds().left < 0) {
        _sprite.setPosition(_sprite.getOrigin().x, _sprite.getPosition().y);
    }
    if (_sprite.getGlobalBounds().top < 0) {
        _sprite.setPosition(_sprite.getPosition().x,_sprite.getOrigin().y);
    }
    if (_sprite.getGlobalBounds().left + _sprite.getGlobalBounds().width > 800) {
        _sprite.setPosition(800 -( _sprite.getGlobalBounds().width -_sprite.getOrigin().x), _sprite.getPosition().y);
    }
    if (_sprite.getGlobalBounds().top + _sprite.getGlobalBounds().height > 600) {
        _sprite.setPosition(_sprite.getPosition().x, 600 + (_sprite.getGlobalBounds().height- _sprite.getOrigin().y));
    }
}   
//Pasamos los parámetros necesarios para que se dibuje en pantalla.
void Enemy::draw(RenderTarget& target, sf::RenderStates states) const{
    target.draw(_sprite, states);
}
//Función para la aparición/reaparición de Enemy.
void Enemy::respawn(){
    _sprite.setPosition(std::rand() % 700 + _sprite.getGlobalBounds().width, std::rand() % 500 + _sprite.getGlobalBounds().height);
    _timeRespawn = 60 * 2;
}
//Función ejecutada al momento de hacerle daño al jugador, haciendo un respawn() y reproduciendo el sonido.
void Enemy::youDamaged() {
    respawn();
    _canal.play();
}
//Método de colisiones implementado.
FloatRect Enemy::getBounds() const{
    return _sprite.getGlobalBounds();
}