#include <iostream>
//Esta es la batalla2
using namespace std;

struct Tablero
{
    int casillero;
    int* fila;
    int** columna;
};

struct Barco
{
    int taman;
    int fila_i;
    int columna_i;
    int dir;
};

Tablero creartablero ();
void mostrartablero (Tablero T_Naval);
Barco crearbarco (int columna_i, int fila_i, int dir, int &cantbarc);
void cargarbarcos (int &cantbarc, Barco &barco);
void ubicarbarco (Barco barco, Tablero &tablero);

int main()
{
    int cantbarc1 = 1;
    int cantbarc2 = 1;
    Barco pesquero1;
    Barco submarino1;
    Barco acorazado1;
    Barco portaaviones1;
    Barco pesquero2;
    Barco submarino2;
    Barco acorazado2;
    Barco portaaviones2;
    Tablero tablero = creartablero();
    mostrartablero(tablero);
    cargarbarcos(cantbarc1, portaaviones1);
    ubicarbarco(portaaviones1,tablero);
    mostrartablero(tablero);
    cargarbarcos(cantbarc1, acorazado1);
    ubicarbarco(acorazado1,tablero);
    mostrartablero(tablero);
    cargarbarcos(cantbarc1, submarino1);
    ubicarbarco(submarino1,tablero);
    mostrartablero(tablero);
    cargarbarcos(cantbarc1, pesquero1);
    ubicarbarco(pesquero1,tablero);
    mostrartablero(tablero);




    return 0;
}

Barco crearbarco (int columna_i, int fila_i, int dir, int &cantbarc)
{
    Barco barco;
    barco.taman = cantbarc;
    barco.columna_i = columna_i;
    barco.fila_i = fila_i;
    barco.dir = dir;
    cantbarc++;
    return barco;
}

void cargarbarcos (int &cantbarc, Barco &barco)
{
    int columna;
    int fila;
    int dir;
    cout << "Fila del barco N " << cantbarc << endl;
    cin >> columna;  // Creando Portaaviones
    cout << "Columna del barco N " << cantbarc << endl;
    cin >> fila;
    cout << "Direccion del barco N " << cantbarc << endl;
    cin >> dir;
    barco = crearbarco(columna, fila, dir, cantbarc);
}

void ubicarbarco (Barco barco, Tablero &tablero)
{
    if (barco.dir == 1){
        for (int i = barco.columna_i ; i < barco.columna_i+barco.taman ; i++){
            tablero.columna[i][barco.fila_i] = barco.taman;
        }
    }
    else if (barco.dir == 2){
        for (int i = barco.fila_i ; i > barco.fila_i-barco.taman ; i--){
            tablero.columna[barco.columna_i][i] = barco.taman;
        }
    }
    else if (barco.dir == 3){
        for (int i = barco.columna_i ; i > barco.columna_i-barco.taman ; i--){
            tablero.columna[i][barco.fila_i] = barco.taman;
        }
    }
    else if (barco.dir == 4){
        for (int i = barco.fila_i ; i < barco.fila_i+barco.taman ; i++){
            tablero.columna[barco.columna_i][i] = barco.taman;
        }
    }
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

