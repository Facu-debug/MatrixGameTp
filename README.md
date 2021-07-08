# MatrixGameTp
Este es un juego matematico para consola realizado como trabajo practico de fin del primer curso de Laboratorio, en C++. para la UTN. 

Mathrix es un juego individual donde ponés a prueba tu destreza matemática. Consiste en
una matriz de 6x6 que se completa con números del 0 al 9 ubicados aleatoriamente.

El objetivo general del juego es sumar la mayor cantidad de puntos en el transcurso de las
rondas hasta quedarse sin pilas (vidas). El juego comienza con un total de tres pilas.
En el transcurso de una ronda, el jugador debe ingresar la coordenada del primer número
con el que desea elaborar una ecuación.

Luego de este paso, debe elegir el operador matemático necesario para la ecuación:

-Suma +

-Resta -

-Multiplicacion *

-Division /

-Resto %

Por último, debe elegir la dirección hacia donde se resuelve la ecuación. Los valores pueden
ser:

-Arriba 8

-Abajo 2

-Izquierda 4

-Derecha 6

El juego debe intentar resolver la ecuación teniendo en cuenta los valores ingresados por el
usuario, partiendo de la celda seleccionada y utilizando las celdas adyacentes que se
encuentren en la dirección elegida.
Toda ecuación se puede formular de la siguiente manera: A ± B = C (la suma y resta son de ejemplo).

Como la ecuación es correcta, el usuario obtendrá como puntaje de esa ronda el equivalente
a la suma de los tres números que intervinieron en la cuenta.

A continuación, el juego debe bloquear las celdas utilizadas y avanzar a la siguiente ronda.
En caso de que se intente realizar una ecuación cuyo resultado no es correcto el usuario
pierde una pila.

EJECUTAR:  bin/juego.exe

VER:  main.cpp, funciones.cpp, operaciones.cpp, funciones.h

Créditos:
- Adaptación del juego Mathrix - piecepack game creado por Clark D. Rodeffer.
- Uso de la libreria rlutil.h creada por Tapio Vierros
