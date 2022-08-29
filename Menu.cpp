#include "Menu.h"
//Importamos la fuente y colocamos las opciones.
MenuP::MenuP(float width, float height) {
	if (!font.loadFromFile("Recursos/MagicalStory.ttf")) {
		cout << "No se encontró la fuente";
	}
	titulo.setFont(font);
	titulo.setFillColor(Color::Red);
	titulo.setPosition(200, 50);
	titulo.setCharacterSize(100);
	titulo.setString("El tesoro de Lucas: ");
	menuP[0].setFont(font);
	menuP[0].setFillColor(Color::White);
	menuP[0].setString("Jugar");
	menuP[0].setCharacterSize(70);
	menuP[0].setPosition(400, 200);
	menuP[1].setFont(font);
	menuP[1].setFillColor(Color::White);
	menuP[1].setString("Información");
	menuP[1].setCharacterSize(70);
	menuP[1].setPosition(400, 300);	menuP[0].setFont(font);
	menuP[2].setFont(font);
	menuP[2].setFillColor(Color::White);
	menuP[2].setString("Salir");
	menuP[2].setCharacterSize(70);
	menuP[2].setPosition(400, 400);
	MenuSelec = -1;
}
MenuP::~MenuP() {
}
void MenuP::draw(RenderWindow& window) {
	for (int i = 0; i < Max_main_menu; ++i) {
		window.draw(titulo);
		window.draw(menuP[i]);
	}
}
//Funciones para navegar por la interfaz del Menu
void MenuP::Arriba() {
	if (MenuSelec - 1 >= 0) {
		menuP[MenuSelec].setFillColor(Color::White);
		MenuSelec--;
		if (MenuSelec == -1) {
			MenuSelec = 2;
		}
		menuP[MenuSelec].setFillColor(Color::Yellow);
	}
}
void MenuP::Abajo() {
	if (MenuSelec + 1 <= Max_main_menu) {
		menuP[MenuSelec].setFillColor(Color::White);
		MenuSelec++;
		if (MenuSelec == 4) {
			MenuSelec = 0;
		}
		menuP[MenuSelec].setFillColor(Color::Yellow);
	}
}