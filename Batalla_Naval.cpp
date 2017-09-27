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
void ubicarpesquero (Pesquero &pesquero, Tablero &tablero);
void ubicarsubmarino (Submarino &submarino, Tablero &tablero);
void ubicaracorazado (Acorazado &acorazado, Tablero &tablero);
void ubicarportaaviones(Portaaviones &portaaviones , Tablero &tablero);
Pesquero crear_pesquero ();
Submarino crear_submarino ();
Acorazado crear_acorazado();
Portaaviones crear_portaaviones();

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
    p1 = crear_pesquero();
    ubicarpesquero(p1, tablero);
    mostrartablero(tablero);
    s1 = crear_submarino();
    ubicarsubmarino(s1, tablero);
    mostrartablero(tablero);
    a1 = crear_acorazado();
    ubicaracorazado(a1, tablero);
    mostrartablero(tablero);
    pa1 = crear_portaaviones();
    ubicarportaaviones(pa1, tablero);
    mostrartablero(tablero);
    guardar_tablero(tablero);
    return 0;
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

void ubicarpesquero (Pesquero &pesquero, Tablero &tablero)
{
    tablero.columna[pesquero.fila_1][pesquero.columna_1] = pesquero.taman;
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

void ubicaracorazado (Acorazado &acorazado, Tablero &tablero)
{
    int dir;
    cout << "cin >> dir" << endl;
    cin >> dir;
    if (dir == 1){ // Derecha
        for (int i = acorazado.columna_1 ; i < acorazado.columna_1+acorazado.taman ; i++){
            tablero.columna[acorazado.fila_1][i] = acorazado.taman;
            acorazado.fila_2 = acorazado.fila_1;
            acorazado.columna_2 = i;
        }
    }
    else if (dir == 2){  // Arriba
        for (int i = acorazado.fila_1 ; i > acorazado.fila_1-acorazado.taman ; i--){
            tablero.columna[i][acorazado.columna_1] = acorazado.taman;
            acorazado.columna_2 = acorazado.columna_1;
            acorazado.fila_2 = i;
        }
    }
    else if (dir == 3){ // Izquierda
        for (int i = acorazado.columna_1 ; i > acorazado.columna_1-acorazado.taman ; i--){
            tablero.columna[acorazado.fila_1][i] = acorazado.taman;
            acorazado.fila_2 = acorazado.fila_1;
            acorazado.columna_2 = i;
        }
    }
    else if (dir == 4){ // Abajo
        for (int i = acorazado.fila_1 ; i < acorazado.fila_1+acorazado.taman ; i++){
            tablero.columna[i][acorazado.columna_1] = acorazado.taman;
            acorazado.columna_2 = acorazado.columna_1;
            acorazado.fila_2 = i;
        }
    }
}

void ubicarportaaviones (Portaaviones &portaaviones, Tablero &tablero)
{
    int dir;
    cout << "cin >> dir" << endl;
    cin >> dir;
    if (dir == 1){ // Derecha
        for (int i = portaaviones.columna_1 ; i < portaaviones.columna_1+portaaviones.taman ; i++){
            tablero.columna[portaaviones.fila_1][i] = portaaviones.taman;
            portaaviones.fila_2 = portaaviones.fila_1;
            portaaviones.columna_2 = i;
        }
    }
    else if (dir == 2){  // Arriba
        for (int i = portaaviones.fila_1 ; i > portaaviones.fila_1-portaaviones.taman ; i--){
            tablero.columna[i][portaaviones.columna_1] = portaaviones.taman;
            portaaviones.columna_2 = portaaviones.columna_1;
            portaaviones.fila_2 = i;
        }
    }
    else if (dir == 3){ // Izquierda
        for (int i = portaaviones.columna_1 ; i > portaaviones.columna_1-portaaviones.taman ; i--){
            tablero.columna[portaaviones.fila_1][i] = portaaviones.taman;
            portaaviones.fila_2 = portaaviones.fila_1;
            portaaviones.columna_2 = i;
        }
    }
    else if (dir == 4){ // Abajo
        for (int i = portaaviones.fila_1 ; i < portaaviones.fila_1+portaaviones.taman ; i++){
            tablero.columna[i][portaaviones.columna_1] = portaaviones.taman;
            portaaviones.columna_2 = portaaviones.columna_1;
            portaaviones.fila_2 = i;
        }
    }
}

Pesquero crear_pesquero ()
{

    int direccion;
    Pesquero pesquero;
    pesquero.taman = 1;
    cout << "Columna inicial pesquero: ";
    cin >> pesquero.columna_1;
    cout << endl << "Fila incial pesquero: ";
    cin >> pesquero.fila_1;
    return pesquero;
}

Submarino crear_submarino ()
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

Acorazado crear_acorazado ()
{

    int direccion;
    Acorazado acorazado;
    acorazado.taman = 3;
    cout << "Columna inicial acorazado: ";
    cin >> acorazado.columna_1;
    cout << endl << "Fila incial acorazado: ";
    cin >> acorazado.fila_1;
    return acorazado;
}

Portaaviones crear_portaaviones ()
{

    int direccion;
    Portaaviones portaaviones;
    portaaviones.taman = 4;
    cout << "Columna inicial portaaviones: ";
    cin >> portaaviones.columna_1;
    cout << endl << "Fila incial portaaviones: ";
    cin >> portaaviones.fila_1;
    return portaaviones;
}




