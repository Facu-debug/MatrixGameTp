#include <iostream>
using namespace std;
#include "rlutil.h"
#include "funciones.h"
#include <ctime>
#include <stdio.h>
#include <stdlib.h>





int main()
{
    //variables para el parcial
    char Operadores[5] = {'+', '-', '*', '/', '%'};
    int cantOperador[5] = {};

    //Variables:
    const int fil = 6;
    const int col = 6;
    int matriz[fil][col];
    char matrizChar[fil][col];
    bool matrizBool[fil][col];
    char nombre[20];
    char calculador[20];
    char nomPtjMax[10][50];
    char calcuVec[10][50];
    int rondas[10];
    int ptj[10];
    setlocale(LC_ALL,"spanish");

    //Variables del juego:
    bool resultado;
    int n;
    int num_col;
    int num_fila;
    int direccion;
    int cont;
    int inicio;
    int puntaje = 0;
    int pilas;
    char salir;
    char operador_mat;

    //INICIO
    inicio = 0;
    presentacion(); ///Presentacion
    do
    {
        ///Menu
        cout << endl;
        cout << "   MATHRIX GAME:\n";
        rlutil::setColor(rlutil::GREEN);
        cout << " --------------------\n";
        rlutil::setColor(rlutil::WHITE);
        cout << " 1 - JUGAR \n";
        cout << " 2 - ESTADISTICAS\n";
        cout << " 3 - CREDITOS\n";
        rlutil::setColor(rlutil::GREEN);
        cout << " --------------------\n";
        rlutil::setColor(rlutil::WHITE);
        cout << " 0 - SALIR\n\n";
        cout << "Ingresar opcion: ";
        cin >> n;

        /// Cuatro opciones de switch():
        switch(n)
        {
        case 1:
            //Juego
            rlutil::cls();
            /// Inicio de variables
            puntaje = 0;
            cont = 0;
            pilas = 3;

            /// Inicio
            cout << "Ingrese su nombre: ";
            cin >> gets(nombre);
            cout << "Ingrese el Modelo de Calculadora favorito: ";
            cin >> gets(calculador);
            rlutil::cls();
            cout << "Hola " << nombre << " , bienvenido!\n\n";
            rlutil::anykey();
            ///mostrar las reglas
            reglas();

            /// Funciones de cargar matriz
            cargaMatriz (matriz, fil, col); /// funcion de carga matriz principal
            cargarMatrizChar (matrizChar, fil, col); /// funcion de carga de chars
            cargarMatrizBool (matrizBool, fil, col); /// funcion de caga matriz bool

            /// CICLO PRINCIPAL DE JUEGO:
            do
            {
                cout << " --- Partida de " << nombre << " ---" << endl;
                cout << " -Puntaje acumulado: ";
                rlutil::setColor(rlutil::GREEN);
                cout << puntaje << endl;;
                rlutil::setColor(rlutil::WHITE);

                cout << " -Cantidad de pilas: ";
                rlutil::setColor(rlutil::RED);
                cout << pilas << endl;;
                rlutil::setColor(rlutil::WHITE);

                /// Funcion mostrarMatriz
                mostrarMatriz (matrizChar, matriz, matrizBool);
                cout << endl;
                /// Vuelta inicial
                if(cont == 0)
                {
                    inicio ++;
                    ///Ingreso de datos:
                    cout << "Ingresar num fila: ";
                    cin >> num_fila;
                    num_fila --;
                    cout << "Ingresar num columna: ";
                    cin >> num_col;
                    num_col --;
                    cout << "Posicion elegida: " << matriz[num_fila][num_col] << endl;
                    cout << "Ingresar el operador matematico: ";
                    cin >> operador_mat;
                    cout << "Ingresar direccion a jugar: ";
                    cin >> direccion;

                    //consigna de parcial cantOperadores
                    for(int i=0; i<5; i++)
                    {
                        if(operador_mat == Operadores[i])
                        {
                            cantOperador[i] ++;
                        }
                    }

                    /// Operaciones principales con los datos:
                    resultado = Operacion (operador_mat, matriz, num_fila, num_col, direccion); //nos dice si la operacion suma o no puntos
                    operacionMatriz (matriz, matrizBool, num_fila, num_col, direccion, resultado, pilas, puntaje); //modifica la matriz del juego
                    posPuntaje(nomPtjMax, calcuVec, nombre, rondas, calculador, puntaje, cont, inicio, ptj); //carga los puntajes para estadisticas

                    cout << endl;
                    if(resultado)
                    {
                        cout << "Correcto! sumaste puntos en esta ronda... :D\n";
                    }
                    else
                    {
                        cout << "Incorrecto!, se te restara una pila... D:\n";
                    }
                    cont ++;
                    rlutil::anykey();
                    rlutil::cls();
                }
                else /// Siguientes vueltas
                {
                    cout << "Continuar partida? (y/n) ";
                    cin  >> salir;
                    if(salir == 'n')
                    {
                        pilas = 0;
                        cout << endl;
                        rlutil::setColor(rlutil::RED);
                        cout << "Partida terminada!\n";
                        rlutil::setColor(rlutil::WHITE);
                        break;
                    }

                    ///Ingreso de datos:
                    cout << "Ingresar num fila: ";
                    cin >> num_fila;
                    num_fila --;
                    cout << "Ingresar num columna: ";
                    cin >> num_col;
                    num_col --;
                    cout << "Posicion elegida: " << matriz[num_fila][num_col] << endl;
                    cout << "Ingresar el operador matematico: ";
                    cin >> operador_mat;
                    cout << "Ingresar direccion a jugar: ";
                    cin >> direccion;

                    //consigna parcial cantOperadores
                    for(int i=0; i<5; i++)
                    {
                        if(operador_mat == Operadores[i])
                        {
                            cantOperador[i] ++;
                        }
                    }

                    /// Operaciones principales con los datos
                    resultado = Operacion (operador_mat, matriz, num_fila, num_col, direccion); //funcion operacion principal
                    operacionMatriz (matriz, matrizBool, num_fila, num_col, direccion, resultado, pilas, puntaje); //funcion para modificar matriz
                    posPuntaje(nomPtjMax, calcuVec, nombre, rondas, calculador, puntaje, cont, inicio, ptj); //carga los puntajes para estadisticas
                    cout << endl;

                    if(resultado)
                    {
                        cout << "Correcto! sumaste puntos en esta ronda... :D\n";
                    }
                    else
                    {
                        cout << "Incorrecto!, se te restara una pila... D:\n";
                    }

                    cont ++;
                    rlutil::anykey();
                    if(pilas == 0)
                    {
                        cout << endl;
                        rlutil::setColor(rlutil::RED);
                        cout << "Partida terminada!\n";
                        rlutil::setColor(rlutil::WHITE);
                        rlutil::anykey();
                    }
                    rlutil::cls();
                }

            }
            while(pilas > 0);

            //muestro las consignas de parcial

            mostrarRonda(nombre, puntaje, cantOperador);
            rlutil::anykey();
            rlutil::cls();
            break;

        /// Fin del ciclo principal de juego
        /// OTRAS OPCIONES:
        case 2:
            //Estadisticas
            rlutil::cls();
            ///Ver puntajes acumulados
            mostrarPuntajes(nomPtjMax, calcuVec, ptj, rondas);
            rlutil::anykey();
            break;

        case 3:
            //Creditos
            rlutil::cls();
            rlutil::setColor(rlutil::GREEN);
            cout << "  ------ Creado por: ------\n\n";
            rlutil::setColor(rlutil::WHITE);
            cout << " Nombre del Equipo: 'Equipo del Canal Cultural' \n\n";
            cout << "Integrantes: \n";
            cout << "- Facundo Gabriel Amarilla \n";
            cout << " Nro Legajo: 24461\n";
            cout << endl;
            cout << "- Mariano Javier Gomez \n";
            cout << " Nro Legajo: 25102\n";
            rlutil::anykey();
            break;

        case 0:
            //Salir
            cout << "Desea salir del juego? ";
            cout << "(y/n) ";
            cin  >> salir;
            if(salir == 'y')
            {
                rlutil::cls();
                cout << "GRACIAS POR JUGAR :D !! \n";
                rlutil::anykey();
                break;
            }
            else
            {
                n ++;
                break;
            }

        default:
            cout << "Opcion incorrecta, ingrese otro numero (1, 2, 3 o 0).";
            rlutil::anykey();
            break;
        }
        rlutil::cls();

    }
    while(n!=0);

    return 0;
}
