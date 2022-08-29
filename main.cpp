#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <ctime>
#include <fstream>
#include <iostream>
#include <memory>
#include <stdlib.h>
#include "Personaje.h"
#include "Item.h"
#include "Power.h"
#include "Enemy.h"
#include "Menu.h"
#include "Vida.h"
#include "Escudo.h"
using namespace std;
using namespace sf;
void main() {
    srand((unsigned)std::time(0));
    //Definimos las variables de tipo int que usará el programa.
    int puntos = 0,_MPuntaje = 0,timer = 60 * 5,vtimer=60*30; //timer=temporizador para que cada 5 segundos aparesca un objeto Power
    //Trabajamos con el texto que será usado en el programa, definiendolos, asignandoles fuente, posición y tamaño.
    Font font;font.loadFromFile("Recursos/MagicalStory.ttf");
    Text text, textVidas, textover, textmpuntaje,pruebat,inftext;
    text.setFont(font), textVidas.setFont(font), textover.setFont(font), textmpuntaje.setFont(font),inftext.setFont(font),pruebat.setFont(font);
    inftext.setPosition({ 25,30 }); inftext.setFillColor(Color::Yellow);
    pruebat.setPosition({ 0,50 });
    textover.setCharacterSize(75); textover.setPosition({ 200,200 });
    textmpuntaje.setCharacterSize(30);textmpuntaje.setPosition({ 250,300 });
    //Creamos las instancias de clase que usaremos:
    Personaje n1; Item item; Power power; Enemy enemy; Escudo escudo; Vida s_vidas;
    item.respawn(); power.respawn(); enemy.respawn(); s_vidas.respawn();
    //Creamos los objetos que harán de fondos y texturas, les asignamos dimensiones e imágenes.
    RectangleShape background,Infbg,Jugarbg; 
    Texture Jugartexture,Maintexture,Inftexture;
    Jugartexture.loadFromFile("Recursos/fondo.png");Maintexture.loadFromFile("Recursos/background.png");Inftexture.loadFromFile("Recursos/Infbg.png");
    background.setSize(Vector2f(960, 720));Jugarbg.setSize(Vector2f(800, 600));Infbg.setSize(Vector2f(1000, 600));
    background.setTexture(&Maintexture);Infbg.setTexture(&Inftexture);Jugarbg.setTexture(&Jugartexture); //Seteamos las texturas por referencia.
    //Definimos los sonidos y buffers que nos servirán para reproducirlos.
    SoundBuffer buffer,choque,sound_power;
    Sound sound,cho,power_s;
    sound.setBuffer(buffer);cho.setBuffer(choque);power_s.setBuffer(sound_power);
    buffer.loadFromFile("Recursos/Puntos.wav");choque.loadFromFile("Recursos/choque.wav");sound_power.loadFromFile("Recursos/life.wav");
    //Renderizamos la ventana principal (Menú)
    RenderWindow MENU(VideoMode(960, 720), "Menu Principal", Style::Default);
    MenuP menuP(MENU.getSize().x, MENU.getSize().y);
    while (MENU.isOpen()) {
        Event event;
        while (MENU.pollEvent(event)) {
            if (event.type == Event::Closed) {
                MENU.close();
            }
            if (event.type == Event::KeyReleased) {
                //Al presionar arriba o abajo podremos seleccionar una opción en el Menu
                if (event.key.code == Keyboard::Up) {
                    menuP.Arriba();
                    break;
                }
                if (event.key.code == Keyboard::Down) {
                    menuP.Abajo();
                    break;
                }
                if (event.key.code == Keyboard::Return) {
                    RenderWindow Jugar(VideoMode(800, 600), "Juego"); Jugar.setFramerateLimit(60);
                    RenderWindow Informacion(VideoMode(1000, 600), "Información");
                    int x = menuP.MenuPressed();
                    //Generamos un if para cada caso del Menu, con un total de 3 opciones
                    if (x == 0) {
                        //Sección del juego
                        while (Jugar.isOpen()) {
                            Event aevent;
                            while (Jugar.pollEvent(aevent)) {
                                //Al cerrar la ventana el juego se cerrará.
                                if (aevent.type == Event::Closed) {
                                    Jugar.close();
                                }
                                //Al presionar escape el juego se cerrará.
                                if (aevent.type == Event::KeyPressed) {
                                    if (aevent.key.code == Keyboard::Escape) {
                                        Jugar.close();
                                    }
                                }
                                //Al presionar R al finalizar el juego, este se reiniciará.
                                if (aevent.type == Event::KeyPressed) {
                                    if (aevent.key.code == Keyboard::R) {
                                        Jugar.clear(); n1(s_vidas); n1(s_vidas); n1(s_vidas); puntos = 0;
                                    }
                                }
                            }
                            //Si las vidas son mayores a 0 el juego continúa actualizando sus estados.
                            if (n1.getVida() > 0) {
                                enemy.update();
                                //Hace que los timers funcionen correctamente, haciendo que mientras no lleguen a cero, bajen a razón de 1 cada segundo.
                                if (timer > 0) {
                                    timer--;
                                }
                                if (vtimer > 0) {
                                    vtimer--;
                                }
                                //Actualiza el estado del personaje.
                                n1.update();
                                //Cuando el jugador colisiona con una rupia, sus puntos incrementan.
                                if (n1.isCollisionable(item)) {
                                    item.respawn();
                                    puntos++;
                                    sound.play();
                                }
                                //Cuando el jugador colisiona con un chile, su velocidad aumenta.
                                if (timer == 0 && n1.isCollisionable(power)) {
                                    n1.agregarVelocidad(1);
                                    timer = 60 * 5;
                                    power.respawn();
                                    power_s.play();
                                }
                                //Cuando el jugador colisiona con una vida y tiene 2 o menos vidas, se le aumenta una vida.
                                if (vtimer == 0 && n1.isCollisionable(s_vidas)) {
                                    if (n1.getVida() <= 2) {
                                        n1(s_vidas);
                                    }
                                    vtimer = 60 * 30;
                                    s_vidas.respawn();
                                }
                                //Cuando el jugador colisiona con un enemigo, se le resta una vida y el enemigo reaparece en otro lugar.
                                if (n1.isCollisionable(enemy)) {
                                    n1.hited();
                                    n1.daño();
                                    enemy.youDamaged();
                                    enemy.respawn();
                                }
                                //Cuando el jugador usa el escudo para evitar la colisión con un enemigo, el enemigo reaparece en otro lugar, el jugador no recibe daño.
                                //Pero se restan 10 puntos por cada vez que esto suceda.
                                if (escudo.isCollisionable(enemy)) {
                                    enemy.respawn();
                                    puntos -= 10;
                                    cho.play();
                                }
                            }
                            //Asignamos el texto a las variables de tipo Text definidas previamente.
                            text.setString("Puntos: " + std::to_string(puntos));
                            textover.setString("G A M E  O V E R");
                            pruebat.setString("Vidas: " + std::to_string(n1.getVida()));
                            textmpuntaje.setString("Mejor puntaje:\t" + std::to_string(_MPuntaje) + "\nPara volver a jugar presiona R.\nPara salir presiona escape.");
                            //Se limpia la pantalla y se dibujan los objetos.
                            Jugar.clear();
                            Jugar.draw(Jugarbg);
                            Jugar.draw(n1);
                            Jugar.draw(item);
                            Jugar.draw(enemy);
                            Jugar.draw(text);
                            Jugar.draw(textVidas);
                            Jugar.draw(pruebat);
                            //Al presionar espacio, se genera el escudo que protegerá al jugador del enemigo.
                            if (Keyboard::isKeyPressed(Keyboard::Space)) {
                                escudo.respawn(n1.obtener_pos());
                                Jugar.draw(escudo);
                            }
                            else {
                                Vector2i pp = { -100,-100 };
                                escudo.respawn(pp);
                            }
                            //Cuando el timer usado para los Chiles llega a 0, este se dibuja en pantalla.
                            if (timer == 0) {
                                Jugar.draw(power);
                            }
                            //Cuando el timer usado para las vidas extra llega a 0, esta se dibuja en pantalla.
                            if (vtimer == 0) {
                                Jugar.draw(s_vidas);
                            }
                            //Si las vidas del jugador llegan a 0, se termina el juego y se muestra un game over.
                            if (n1.getVida()<=0) {
                                Jugar.clear();
                                Jugar.draw(textover);
                                Jugar.draw(textmpuntaje);
                                //Se lee el puntaje más alto almacenado en un archivo de texto para mostrarlo en pantalla.
                                ifstream readFile;
                                readFile.open("Recursos/MPuntaje.txt");
                                if (readFile.is_open()) {
                                    while (!readFile.eof()) {
                                        readFile >> _MPuntaje;
                                    }
                                }
                                readFile.close();
                                //En caso el puntaje actual sea mayor al antiguo mejor puntaje, se sobreescribe el archivo.
                                ofstream writeFile("Recursos/MPuntaje.txt");
                                if (writeFile.is_open()) {
                                    if (puntos > _MPuntaje) {
                                        _MPuntaje = puntos;
                                    }
                                    writeFile << _MPuntaje;
                                }
                                writeFile.close();
                            }
                            Informacion.close();
                            Jugar.display();
                        }
                    }
                    if (x == 1) {
                        //Sección de Información
                        while (Informacion.isOpen()) {
                            Event aevent;
                            while (Informacion.pollEvent(aevent)) {
                                if (aevent.type == Event::Closed) {
                                    Informacion.close();
                                }
                                if (aevent.type == Event::KeyPressed) {
                                    if (aevent.key.code == Keyboard::Escape) {
                                        Informacion.close();
                                    }
                                }
                            }
                            Jugar.close();
                            Informacion.clear();
                            ifstream readFile;
                            readFile.open("Recursos/MPuntaje.txt");
                            if (readFile.is_open()) {
                                while (!readFile.eof()) {
                                    readFile >> _MPuntaje;
                                }
                            }
                            readFile.close();
                            inftext.setString("Bienvenido:\nLas reglas son simples, recolecta tantas rupias como puedas!\n-Muevete con las flechas direccionales.\n-Los chiles picantes te harán correr más rápido para recolectar más puntos!\n-Ocasionalmente aparecerán vidas, pero estas solo serán efectivas si tienes 2 o menos.\n-Presionando espacio puedes crear un escudo para evitar al enemigo.\n (Hacerlo te costará 10 puntos).\nEl mejor puntaje registrado hasta la fecha es: "+std::to_string(_MPuntaje)+"\nPresiona escape para volver. Buena suerte!");
                            Informacion.draw(Infbg);
                            Informacion.draw(inftext);
                            Informacion.display();
                        }
                    }
                    //Salir del Menu.
                    if (x == 2) {
                        MENU.close();
                        break;
                    }
                }
            }
        }
        MENU.clear();
        MENU.draw(background);
        menuP.draw(MENU);
        MENU.display();
    }
}