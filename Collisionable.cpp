#include "Collisionable.h"
//Implementando funcionalidad a la clase abstracta.
bool Collisionable::isCollisionable(Collisionable& obj) const{
    return getBounds().intersects(obj.getBounds());
}