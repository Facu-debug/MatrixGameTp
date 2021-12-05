#include <iostream>
using namespace std;
#include "rlutil.h"
#include <ctime>
#include <stdlib.h>

int i, x;

//presentacion
void presentacion(void) ///muetra presentacion
{
    cout << "  --- WELCOME TO THE BEST GAME OF THE YEAR ---\n";
    rlutil::anykey();
    cout << " En el próximo tiempo tu vida cambiará en este juego ... ¿estás listo? \n\n";
    rlutil::anykey();
    cout << " (cargando complejas ecuaciones matematicas)\n";
    Sleep(2500);///temporizador de 2.5 segundos
    cout << "Pulse cualquier tecla para Iniciar.\n";
    rlutil::anykey();
    rlutil::cls();
}

//reglas
void reglas(void) /// muestra las reglas
{
    cout << "-Las reglas son las siguientes: \n\n";
    cout << "El objetivo general del juego es sumar la mayor cantidad de puntos en el transcurso de las \n";
    cout << "rondas hasta quedarse sin pilas. El juego comienza con un total de tres pilas.\n";
    cout << "En el transcurso de una ronda el jugador debe ingresar la coordenada del primer número\n";
    cout << "con el que desea elaborar una ecuación.\n";
    cout << "El juego debe intentar resolver la ecuación teniendo en cuenta los valores ingresados por el\n";
    cout << "partiendo de la celda seleccionada y utilizando las celdas adyacentes que se\n";
    cout << "encuentren en la dirección elegida.\n";
    cout << "Toda ecuación se formula de la siguiente manera: A ± B = C, se permiten +, -, *, / y %.\n";
    cout << "Si la ecuacion es correcta, se suman los tres valores, si no se pierde una Pila.\n\n";
    cout << " Ejemplo:  A + B = C, \n";
    cout << " coordenadas (1,1) + (1,2) = (1,3)\n";
    cout << " Esto es: 1 + 2 = 3\n";
    cout << " -------------\n";
    cout << " | 1 | 2 | 3 |\n";
    cout << " | 5 | 2 | 0 |\n";
    cout << " | 9 | 6 | 3 |\n";
    cout << " -------------\n";
    cout << "No se permiten hacer operaciones por fuera de la matriz o en valores anulados, se resta una Pila si se lo intenta\n\n";
    cout << "Pulse cualquier tecla para continuar.\n";
    rlutil::anykey();
    rlutil::cls();
}

//ingreso Datos
void ingresoDatos(int n[6][6], int& nf, int& nc, char& op, int& dir) ///no usada
{
    cout << "Ingresar num fila: ";
    cin >> nf;
    nf --;
    cout << "Ingresar num columna: ";
    cin >> nc;
    nc --;
    cout << "Posicion elegida: " << n[nf][nc] << endl;
    cout << "Ingresar el operador matematico: ";
    cin >> op;
    cout << "Ingresar direccion a jugar: ";
    cin >> dir;
}

//Mostrar Datos de Ronda
void mostrarRonda(char nomFinal[20], int puntaje, int cantOperador[])
{

    rlutil::anykey();
    rlutil::cls();
    cout << " ### Fin de Partida ###\n\n";
    cout << " -------------------------------------------------\n";
    cout << " El jugador de nombre: " << nomFinal << " acumulo el siguiente puntaje: \n";
    cout << " - Puntaje: " << puntaje << endl;
    cout << " -------------------------------------------------\n";
    cout << " Realizo la cantidad de las siguientes operaciones: \n";
    cout << " - Sumas : " << cantOperador[0] << endl;
    cout << " - Resta : " << cantOperador[1] << endl;
    cout << " - Multiplicacion : " << cantOperador[2] << endl;
    cout << " - Diviciones : " << cantOperador[3] + cantOperador [4] << endl;
    cout << endl;
    cout << "Pulse cualquier tecla para volver al menu principal.\n";

}

//matriz numeros
void cargaMatriz(int n[6][6], int f, int c) ///carga matriz numeros
{
    srand(time(NULL));

    for(x=0; x<f; x++)
    {
        for(i=0; i<c; i++)
        {
            n[x][i] = (rand()%10);
        }
    }
}

//matriz de char
void cargarMatrizChar(char v[6][6], int f, int c) ///carga matriz char
{

    for(x=0; x<f; x++)
    {
        for(i=0; i<c; i++)
        {
            v[x][i] = '-';
        }
    }
}

//matriz de bool
void cargarMatrizBool(bool bl[6][6], int f, int c) ///carga matriz bool
{
    for(x=0; x<f; x++)
    {
        for(i=0; i<c; i++)
        {
            bl[x][i] = true;
        }
    }
}

//operacopn matriz
///funcion que se encarga de quitar las pos de la matriz que no se pueden usar mas
void operacionMatriz(int n[6][6], bool bl[6][6], int nf, int nc, int dir, bool resultado, int& pilas, int& puntaje)
{
    switch (dir)
    {
    case 4:
        ///izquierda
        if( resultado )
        {
            bl[nf][nc] = false;
            bl[nf][nc-1] = false;
            bl[nf][nc-2] = false;

            puntaje += (n[nf][nc] + n[nf][nc-1] + n[nf][nc-2]);
        }
        else
        {
            pilas --;
        }
        break;

    case 8:
        ///arriba
        if( resultado )
        {
            bl[nf][nc] = false;
            bl[nf-1][nc] = false;
            bl[nf-2][nc] = false;
            puntaje += (n[nf][nc] + n[nf-1][nc] + n[nf-2][nc]);
        }
        else
        {
            pilas --;
        }
        break;

    case 6:
        ///derecha
        if( resultado )
        {
            bl[nf][nc] = false;
            bl[nf][nc+1] = false;
            bl[nf][nc+2] = false;
            puntaje += n[nf][nc] + n[nf][nc+1] + n[nf][nc+2];
        }
        else
        {
            pilas --;
        }
        break;

    case 2:
        ///abajo
        if( resultado )
        {
            bl[nf][nc] = false;
            bl[nf+1][nc] = false;
            bl[nf+2][nc] = false;
            puntaje += (n[nf][nc] + n[nf+1][nc] + n[nf+2][nc]);
        }
        else
        {
            pilas --;
        }
        break;
    }
}

//mostrar matriz
void mostrarMatriz(char ch[6][6], int n[6][6], bool bl[6][6]) /// carga y muestra matriz tras operacion
{
    cout <<"  -----------------------------------------------\n";
    for(x=0; x<6; x++)
    {
        for(i=0; i<6; i++)
        {
            if(bl[x][i] == true)
            {
                cout <<" |   "<<n[x][i]<<"  ";
            }
            else
            {
                cout <<" |   "<<ch[x][i]<<"  ";
            }
        }
        cout <<" |\n  -----------------------------------------------\n";
    };
}

//posicion Puntajes
void posPuntaje(char chp[10][50], char chc[10][50], char nom[], int rond[], char cal[], int ptj, int cont, int ini, int pt[])
{
    if(ini == 1)
    {
        pt[0] = ptj;
        strcpy(chp[0], nom);
        strcpy(chc[0], cal);
        rond[0] = cont;
    }
    if(ini > 1)
    {
        pt[1] = ptj;
        strcpy(chp[1], nom);
        strcpy(chc[1], cal);
        rond[1] = cont;
    }
}
//mostrar Puntajes
void mostrarPuntajes(char chp[10][50], char chc[10][50], int pt[], int rond[])
{
    if(pt[0]>pt[1])
    {
        rlutil::setColor(rlutil::GREEN);
        cout << "--- ESTADISTICAS ---\n\n";
        rlutil::setColor(rlutil::WHITE);
        cout << " - Nombre: " << chp[0] << endl;
        cout << " - Rondas: " << rond[0] << endl;
        cout << " - Calculadora: " << chc[0] << endl;
        cout << " - Puntaje: " << pt[0] << endl;
        cout << endl;
        cout << " - Nombre: " << chp[1] << endl;
        cout << " - Rondas: " << rond[1] << endl;
        cout << " - Calculadora: " << chc[1] << endl;
        cout << " - Puntaje: " << pt[1] << endl;
    }
    else
    {
        rlutil::setColor(rlutil::GREEN);
        cout << "--- ESTADISTICAS ---\n\n";
        rlutil::setColor(rlutil::WHITE);
        cout << " - Nombre: " << chp[1] << endl;
        cout << " - Rondas: " << rond[1] << endl;
        cout << " - Calculadora: " << chc[1] << endl;
        cout << " - Puntaje: " << pt[1] << endl;
        cout << endl;
        cout << " - Nombre: " << chp[0] << endl;
        cout << " - Rondas: " << rond[0] << endl;
        cout << " - Calculadora: " << chc[0] << endl;
        cout << " - Puntaje: " << pt[0] << endl;
    }
}
