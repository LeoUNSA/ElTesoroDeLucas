# Overview
Este juego usa SFML (Simple and Fast Multimedia Library) para dibujar objetos en la pantalla cada frame. También usa vectores, invocaciones, recursión y grafos para incorporar cada objeto al juego.
(Aunque este trabajo no llegó a utilizar todo lo que ofrece la libreria).
Por nuestra parte, logramos implementar la mayoría de requerimientos, como son: Polimorfismo, herencia, funtores, referencias, modificadores de acceso y sobrecarga de operadores.
Lastimosamente, también hubieron varias cosas que no se pudieron implementar, como: Smart pointers, metaprogramación, templates y patrones de diseño.
Como jugador, tú misión es sumar puntos recolectando tantas rupias como puedas.
El enemigo se moverá aleatoriamente en alguna dirección en intervalos definidos, tu deber es esquivarlo e ir a por las rupias, corazones y chiles que te harán ir más rápido.
El teclado es el periférico que nos permitirá navegar por el Menú y jugar, los controles son:
# Controles
### Flecha Arriba - Moverse hacia Arriba
### Flecha Abajo - Moverse hacia Abajo
### Flecha Izquierda - Moverse hacia la Izquierda
### Flecha Derecha - Moverse hacia la Derecha
### Espacio - Generar escudo
# Interfaz
Se implementó un Menú simple con el cuál se puede navegar entre pantallas usando las flechas direccionales arriba y abajo, así como la tecla Enter para seleccionar.
# Instalación del juego.
En teoría, con descargarte el .zip de este reopositorio y ejecutar el .exe debería correr sin problemas. Pero, en caso no lo haga, puede deberse a varios factores, como:
El no haber instalado la libreria de SFML.
El no tener los dlls necesarios para ejecutar el juego, entre otros.
Me gustaría listar las soluciones, pero los errores que pueden salir varían, lo más eficaz es intentar crear un ambiente similar al que yo tuve al elaborar el trabajo y hacer un Build del juego por ti mismo.
(Usar Visual Studio 2022 - Seteado para C++ y la libería de SFML) 
(Así como incluir adecuadamente los archivos de la libreria en el código mediante la interfaz de Visual Studio y linkear los recursos utilizados)