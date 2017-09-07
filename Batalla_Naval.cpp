#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

struct Tablero
{
    int casillero;
    int* fila;
    int** columna;
};

struct Pesquero
{
    int taman;
    int fila_1;
    int columna_1;
};

struct Submarino
{
    int taman;
    int fila_1;
    int fila_2;
    int columna_1;
    int columna_2;
};

struct Acorazado
{
    int taman;
    int fila_1;
    int fila_2;
    int fila_3;
    int columna_1;
    int columna_2;
    int columna_3;
};

struct Portaaviones
{
    int taman;
    int fila_1;
    int fila_2;
    int fila_3;
    int fila_4;
    int columna_1;
    int columna_2;
    int columna_3;
    int columna_4;
};

Tablero creartablero ();
void mostrartablero (Tablero T_Naval);
void guardar_tablero (Tablero tableroguarda);
Tablero cargar_tablero ();
Pesquero crear_pesquero ();
void ubicarsubmarino (Submarino &submarino, Tablero &tablero);
Submarino crear_submarino (Tablero &tablero);

int main()
{
    Pesquero p1;
    Pesquero p2;
    Submarino s1;
    Submarino s2;
    Acorazado a1;
    Acorazado a2;
    Portaaviones pa1;
    Portaaviones pa2;
    int cantbarc1 = 1;
    int cantbarc2 = 1;
    Submarino submarino;

    Tablero tablero = creartablero();
     mostrartablero(tablero);
    s1 = crear_submarino(tablero);
    ubicarsubmarino(s1, tablero);
    cout << submarino.fila_1 << ":" << submarino.columna_1 << "-" << submarino.fila_2 << ":" << submarino.columna_2 << endl;
    mostrartablero(tablero);
    guardar_tablero(tablero);
    return 0;
}

Pesquero crear_pesquero (Tablero &tablero)
{
    Pesquero pesquero;
    pesquero.taman = 1;
    cin >> pesquero.columna_1;
    cin >> pesquero.fila_1;
    return pesquero;
}

Submarino crear_submarino (Tablero &tablero)
{

    int direccion;
    Submarino submarino;
    submarino.taman = 2;
    cout << "Columna inicial submarino: ";
    cin >> submarino.columna_1;
    cout << endl << "Fila incial submarino: ";
    cin >> submarino.fila_1;
    return submarino;
}

void ubicarsubmarino (Submarino &submarino, Tablero &tablero)
{
    int dir;
    cout << "cin >> dir" << endl;
    cin >> dir;
    if (dir == 1){ // Derecha
        for (int i = submarino.columna_1 ; i < submarino.columna_1+submarino.taman ; i++){
            tablero.columna[submarino.fila_1][i] = submarino.taman;
            submarino.fila_2 = submarino.fila_1;
            submarino.columna_2 = i;
        }
    }
    else if (dir == 2){  // Arriba
        for (int i = submarino.fila_1 ; i > submarino.fila_1-submarino.taman ; i--){
            tablero.columna[i][submarino.columna_1] = submarino.taman;
            submarino.columna_2 = submarino.columna_1;
            submarino.fila_2 = i;
        }
    }
    else if (dir == 3){ // Izquierda
        for (int i = submarino.columna_1 ; i > submarino.columna_1-submarino.taman ; i--){
            tablero.columna[submarino.fila_1][i] = submarino.taman;
            submarino.fila_2 = submarino.fila_1;
            submarino.columna_2 = i;
        }
    }
    else if (dir == 4){ // Abajo
        for (int i = submarino.fila_1 ; i < submarino.fila_1+submarino.taman ; i++){
            tablero.columna[i][submarino.columna_1] = submarino.taman;
            submarino.columna_2 = submarino.columna_1;
            submarino.fila_2 = i;
        }
    }
}

Acorazado crear_acorazado (Tablero &tablero)
{
    Acorazado acorazado;
    acorazado.taman = 3;

    cin >> acorazado.columna_1;
    cin >> acorazado.fila_1;
    cin >> acorazado.columna_2;
    cin >> acorazado.fila_2;
}

Tablero creartablero ()
{


// Se crea el tablero y se asigna un valor "0" a cada casillero

    Tablero T_Naval;

    T_Naval.columna = new int*[10];

    for(int i = 0 ; i < 10 ; i++)
    {
        T_Naval.columna[i] = T_Naval.fila = new int [10];
        for (int j = 0 ; j < 10 ; j++)
        {
            T_Naval.columna[i][j] = 0;
        }
    }

    return T_Naval;
}

void mostrartablero (Tablero T_Naval)
//Muestra en pantalla el tablero en el estado deseado
{
    for (int i = 0 ; i < 10 ; i++)
    {
        for (int j = 0 ; j < 10 ; j++)
        {
            if(j != 9)
            {
                cout << T_Naval.columna[i][j]  << ':';
            }
            else
            {
                cout << T_Naval.columna[i][j];
            }
        }
        cout << endl;
    }
}

Tablero cargar_tablero ()
{
    ifstream miTablero;
    Tablero tablerocarga;
    tablerocarga = creartablero();
    miTablero.open("tablerete.txt");
        if(miTablero.is_open())
        {
            for(int i = 0; i < 10; i++)
            {
                for(int j = 0; j < 10; j++)
                {

                   miTablero >> tablerocarga.columna[i][j];
                }
            }
        }
    return tablerocarga;
}

void guardar_tablero (Tablero tableroguarda)
{
    ofstream miTablero;
    miTablero.open("tablerete.txt");
        if(miTablero.is_open())
        {
            for(int i = 0; i < 10; i++)
            {
                for(int j = 0; j < 10; j++)
                {
                    miTablero << tableroguarda.columna[i][j];
                    miTablero << ' ';
                }
            }
        }
        cout << "Se ha guardado el barco con exito!" << endl;
        system("pause");
}


