#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#define Max_main_menu 4
//Definimos los miembros de clase.
class MenuP {
public:
	MenuP(float width, float height);
	void draw(RenderWindow& window);
	void Arriba();
	void Abajo();
	int MenuPressed() {
		return MenuSelec;
	}
	~MenuP();
private:
	int MenuSelec;
	Font font;
	Text menuP[Max_main_menu],titulo;
};