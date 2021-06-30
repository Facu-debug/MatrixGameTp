#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

void presentacion(void);
void reglas(void);
void ingresoDatos(int [6][6], int&, int&, char&, int&);
void posPuntaje(char [10][50], char [10][50], char [], int [], char [], int, int, int, int[]);
void mostrarPuntajes(char[10][50], char[10][50], int[], int[]);
void mostrarRonda(char[], int, int[]);

//funciones de matriz
void cargaMatriz(int[6][6], int, int);
void cargarMatrizChar(char[6][6], int, int);
void cargarMatrizBool(bool[6][6], int, int);
void mostrarMatriz(char[6][6], int[6][6], bool[6][6]);
void operacionMatriz(int[6][6], bool[6][6], int, int, int, bool, int&, int&);
bool validarPosiciones(bool [6][6], int, int, int);

//funciones de operacion
bool Operacion(char, int[6][6], int, int, int);
bool tipoDireccionSuma(int[6][6], int, int, int);
bool tipoDireccionResta(int[6][6], int, int, int);
bool tipoDireccionMultiplicacion(int[6][6], int, int, int);
bool tipoDireccionDivicion(int[6][6], int, int, int);
bool tipoDireccionResto(int[6][6], int, int, int);

#endif // FUNCIONES_H_INCLUDED
