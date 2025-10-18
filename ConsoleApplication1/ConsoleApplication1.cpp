#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

const int ANCHO = 80;
const int ALTO = 25;
const char PALA = '|';
const char PELOTA = 'O';
const char PARED = '#';
const char VACIO = ' ';


int pelotaX, pelotaY;
int velocidadX, velocidadY;
int palaIzqY, palaDerY;
int puntajeIzq, puntajeDer;
bool juegoActivo;

void InicializarJuego() {

    pelotaX = ANCHO / 2;
    pelotaY = ALTO / 2;


    velocidadX = -1;
    velocidadY = 1;

    palaIzqY = ALTO / 2;
    palaDerY = ALTO / 2;

    puntajeIzq = 0;
    puntajeDer = 0;

    juegoActivo = true;
}

void DibujarCampo() {
    system("cls");

    for (int i = 0; i < ANCHO + 2; i++)
        cout << PARED;
    cout << endl;

    for (int y = 0; y < ALTO; y++) {
        for (int x = 0; x < ANCHO; x++) {

            if (x == 0)
                cout << PARED;


            if (x == pelotaX && y == pelotaY)
                cout << PELOTA;
            else if (x == 1 && (y >= palaIzqY - 2 && y <= palaIzqY + 2))
                cout << PALA;
            else if (x == ANCHO - 1 && (y >= palaDerY - 2 && y <= palaDerY + 2))
                cout << PALA;
            else
                cout << VACIO;

            if (x == ANCHO - 1)
                cout << PARED;
        }
        cout << endl;
    }

    for (int i = 0; i < ANCHO + 2; i++)
        cout << PARED;
    cout << endl;

    cout << "Jugador 1: " << puntajeIzq << "  -  Jugador 2: " << puntajeDer << endl;
    cout << "Controles: W/S (Jugador 1) - Flechas 5/2 (Jugador 2)" << endl;
}

void MoverPelota() {

    pelotaX += velocidadX;
    pelotaY += velocidadY;

    if (pelotaY <= 0 || pelotaY >= ALTO - 1) {
        velocidadY = -velocidadY;
    }


    if (pelotaX == 2) {
        if (pelotaY >= palaIzqY - 2 && pelotaY <= palaIzqY + 2) {
            velocidadX = -velocidadX;


            if (pelotaY < palaIzqY) velocidadY = -1;
            else if (pelotaY > palaIzqY) velocidadY = 1;
            else velocidadY = 0;
        }
    }

    if (pelotaX == ANCHO - 2) {
        if (pelotaY >= palaDerY - 2 && pelotaY <= palaDerY + 2) {
            velocidadX = -velocidadX;


            if (pelotaY < palaDerY) velocidadY = -1;
            else if (pelotaY > palaDerY) velocidadY = 1;
            else velocidadY = 0;
        }
    }


    if (pelotaX <= 0) {
        puntajeDer++;

        pelotaX = ANCHO / 2;
        pelotaY = ALTO / 2;
        velocidadX = 1;
    }


    if (pelotaX >= ANCHO - 1) {
        puntajeIzq++;

        pelotaX = ANCHO / 2;
        pelotaY = ALTO / 2;
        velocidadX = -1;
    }
}

void ProcesarEntrada() {

    if (_kbhit()) {
        char tecla = _getch();


        if (tecla == 'w' && palaIzqY > 2)
            palaIzqY--;
        if (tecla == 's' && palaIzqY < ALTO - 3)
            palaIzqY++;


        if (tecla == '5' || tecla == '2') {
            tecla = _getch();
            if (tecla == '5' && palaDerY > 2)
                palaDerY--;
            if (tecla == '2' && palaDerY < ALTO - 3)
                palaDerY++;
        }


        if (tecla == 'q')
            juegoActivo = false;
    }
}




void mostrarMenu() {
    system("cls");
    cout << "==================================" << endl;
    cout << "          MENU  PING PONG         " << endl;
    cout << "==================================" << endl;
    cout << "1. Jugar" << endl;
    cout << "2. Puntuaciones" << endl;
    cout << "3. Instrucciones" << endl;
    cout << "4. Salir" << endl;
    cout << "==================================" << endl;
    cout << "Selecciona una opcion: ";
}

void pausa() {
    cout << "Presiona Enter para continuar..." << endl;
    cin.ignore();
    cin.get(); 
}

void jugar() {
    system("cls");
    InicializarJuego();

    cout << "=== PING PONG ===" << endl;
    cout << "Preparado para comenzar..." << endl;
    Sleep(2000);


    while (juegoActivo) {
        DibujarCampo();
        MoverPelota();
        ProcesarEntrada();
        Sleep(50);
    }

    cout << "Juego terminado!" << endl;
    cout << "Puntaje final - Jugador 1: " << puntajeIzq << " | Jugador 2: " << puntajeDer << endl;
}


void puntuaciones() {
    system("cls");
    cout << "=== MEJORES PUNTUACIONES ===" << endl;
    cout << "1. Jugador1 - " << puntajeIzq << endl;
    cout << "2. Jugador2 - " << puntajeDer << endl;
    pausa();
}

void instrucciones() {
    system("cls");
    cout << "=== INSTRUCCIONES ===" << endl;
    cout << "Golpea la pelota con tu paleta" << endl;
    cout << "El oponente pierde punto si no la devuelve" << endl;
    pausa();
}

int main() {
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
        case 1:
            jugar();
            break;
        case 2:
            puntuaciones();
            break;
        case 3:
            instrucciones();
            break;
        case 4:
            system("cls");
            cout << "¡Gracias por jugar!" << endl;
            break;
        default:
            cout << "Opcion no valida" << endl;
            pausa();
            break;
        }

    } while (opcion != 4);

    return 0;
}