#include <iostream>
#include <windows.h>
using namespace std;

void mostrarMenu() {
    system("cls");
    cout << "==================================" << endl;
    cout << "          MENU  PING PONG         " << endl;
    cout << "==================================" << endl;
    cout << "1. Jugar" << endl;
    cout << "2. Opciones" << endl;
    cout << "3. Puntuaciones" << endl;
    cout << "4. Instrucciones" << endl;
    cout << "5. Salir" << endl;
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
    cout << "=== INICIANDO JUEGO ===" << endl;
    cout << "El juego comenzara en breve..." << endl;
    pausa();
}

void opciones() {
    system("cls");
    cout << "=== OPCIONES ===" << endl;
    cout << "1. Velocidad: Normal" << endl;
    cout << "2. Puntos para ganar: 11" << endl;
    pausa();
}

void puntuaciones() {
    system("cls");
    cout << "=== MEJORES PUNTUACIONES ===" << endl;
    cout << "1. Jugador1 - 15 puntos" << endl;
    cout << "2. Jugador2 - 12 puntos" << endl;
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
            opciones();
            break;
        case 3:
            puntuaciones();
            break;
        case 4:
            instrucciones();
            break;
        case 5:
            system("cls");
            cout << "¡Gracias por jugar!" << endl;
            break;
        default:
            cout << "Opcion no valida" << endl;
            pausa();
            break;
        }

    } while (opcion != 5);

    return 0;
}