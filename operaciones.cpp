#include <iostream>
using namespace std;
#include "rlutil.h"
#include <ctime>
#include <stdlib.h>

bool tipoDireccionSuma(int[6][6], int, int, int);
bool tipoDireccionResta(int[6][6], int, int, int);
bool tipoDireccionMultiplicacion(int[6][6], int, int, int);
bool tipoDireccionDivicion(int[6][6], int, int, int);
bool tipoDireccionResto(int[6][6], int, int, int);

//Operacion
bool Operacion(char op, int n[6][6], int nf, int nc, int dir)
{
    ///buscamos un indx relacionado operador que ingreso el usuario
    bool r;
    int i, indx;
    char operadores[5] = {'+','-','*','/','%'};
    for(i=0; i<5; i++)
    {
        if(operadores[i] == op)
        {
           indx = i;
        }
    }
    ///llamamos a la funcion correspondiente a la operacion ingresada
    switch(indx)
    {
    case 0:
        r =  tipoDireccionSuma(n, nf, nc, dir); ///funcion suma
        break;
    case 1:
        r =  tipoDireccionResta(n, nf, nc, dir); ///funcion resta
        break;
    case 2:
        r =  tipoDireccionMultiplicacion(n, nf, nc, dir); ///funcion mul
        break;
    case 3:
        r =  tipoDireccionDivicion(n, nf, nc, dir); ///funcion div
        break;
    case 4:
        r =  tipoDireccionResto(n, nf, nc, dir); ///funcion resto
        break;
    }
    return r; // true si se cumpple condicion de juego , false si no
}

//tipoDireccion SUMA
bool tipoDireccionSuma(int n[6][6], int nf, int nc, int dir)
{
    int res;
    switch (dir)
    {
    case 4: ///izquierda
        res = n[nf][nc] + n[nf][nc-1];
        if(res == n[nf][nc-2])
        {
           return true;
        }
        else
        {
            return false;
        }
        break;
    case 8: ///arriba
        res = n[nf][nc] + n[nf-1][nc];
        if(res == n[nf-2][nc])
        {
            return true;
        }
        else
        {
            return false;
        }
        break;
    case 6: ///derecha
        res = n[nf][nc] + n[nf][nc+1];
        if(res == n[nf][nc+2])
        {
            return true;
        }
        else
        {
            return false;
        }
        break;
    case 2: ///abajo
        res = n[nf][nc] + n[nf+1][nc];
        if(res == n[nf+2][nc])
        {
            return true;
        }
        else
        {
            return false;
        }
        break;
    }
}

//tipoDireccion RESTA
bool tipoDireccionResta(int n[6][6], int nf, int nc, int dir)
{
    int res;
    switch (dir)
    {
    case 4: ///izquierda
        res = n[nf][nc] - n[nf][nc-1];
        if(res == n[nf][nc-2])
        {
            return true;
        }
        else
        {
            return false;
        }
        break;
    case 8: ///arriba
        res = n[nf][nc] - n[nf-1][nc];
        if(res == n[nf-2][nc])
        {
            return true;
        }
        else
        {
            return false;
        }
        break;
    case 6: ///derecha
        res = n[nf][nc] - n[nf][nc+1];
        if(res == n[nf][nc+2])
        {
            return true;
        }
        else
        {
            return false;
        }
        break;
    case 2: ///abajo
        res = n[nf][nc] - n[nf+1][nc];
        if(res == n[nf+2][nc])
        {
            return true;
        }
        else
        {
            return false;
        }
        break;
    }
}

//tipoDireccion MUlTIPLICACION
bool tipoDireccionMultiplicacion(int n[6][6], int nf, int nc, int dir)
{
    int res;
    switch (dir)
    {
    case 4: ///izquierda
        res = n[nf][nc] * n[nf][nc-1];
        if(res == n[nf][nc-2])
        {
            return true;
        }
        else
        {
            return false;
        }
        break;
    case 8: ///arriba
        res = n[nf][nc] * n[nf-1][nc];
        if(res == n[nf-2][nc])
        {
            return true;
        }
        else
        {
            return false;
        }
        break;
    case 6: ///derecha
        res = n[nf][nc] * n[nf][nc+1];
        if(res == n[nf][nc+2])
        {
            return true;
        }
        else
        {
            return false;
        }
        break;
    case 2: ///abajo
        res = n[nf][nc] * n[nf+1][nc];
        if(res == n[nf+2][nc])
        {
            return true;
        }
        else
        {
            return false;
        }
        break;
    }
}

//tipoDireccion DIVICION
bool tipoDireccionDivicion(int n[6][6], int nf, int nc, int dir)
{
    int res;
    switch (dir)
    {
    case 4: ///izquierda
        res = n[nf][nc] / n[nf][nc-1];
        if(res == n[nf][nc-2])
        {
            return true;
        }
        else
        {
            return false;
        }
        break;
    case 8: ///arriba
        res = n[nf][nc] / n[nf-1][nc];
        if(res == n[nf-2][nc])
        {
            return true;
        }
        else
        {
            return false;
        }
        break;
    case 6: ///derecha
        res = n[nf][nc] / n[nf][nc+1];
        if(res == n[nf][nc+2])
        {
            return true;
        }
        else
        {
            return false;
        }
        break;
    case 2: ///abajo
        res = n[nf][nc] / n[nf+1][nc];
        if(res == n[nf+2][nc])
        {
            return true;
        }
        else
        {
            return false;
        }
        break;
    }
}

//tipoDireccion RESTO
bool tipoDireccionResto(int n[6][6], int nf, int nc, int dir)
{
    int res;
    switch (dir)
    {
    case 4: ///izquierda
        res = n[nf][nc] % n[nf][nc-1];
        if(res == n[nf][nc-2])
        {
            return true;
        }
        else
        {
            return false;
        }
        break;
    case 8: ///arriba
        res = n[nf][nc] % n[nf-1][nc];
        if(res == n[nf-2][nc])
        {
            return true;
        }
        else
        {
            return false;
        }
        break;
    case 6: ///derecha
        res = n[nf][nc] % n[nf][nc+1];
        if(res == n[nf][nc+2])
        {
            return true;
        }
        else
        {
            return false;
        }
        break;
    case 2: ///abajo
        res = n[nf][nc] % n[nf+1][nc];
        if(res == n[nf+2][nc])
        {
            return true;
        }
        else
        {
            return false;
        }
        break;
    }
}
