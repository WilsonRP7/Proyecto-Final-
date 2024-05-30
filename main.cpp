#include <iostream>
#include <windows.h>
#include <cmath>

using namespace std;

// Función de colocación de cursor
void cursor(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Función de tamaño de pantalla y movilización con teclas
void TamConsola(int ancho, int alto) {
    COORD coord;
    coord.X = ancho;
    coord.Y = alto;

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT rect;
    rect.Left = 0;
    rect.Top = 0;
    rect.Right = ancho - 1;
    rect.Bottom = alto - 1;

    SetConsoleScreenBufferSize(hConsole, coord);
    SetConsoleWindowInfo(hConsole, TRUE, &rect);
}

// Función para dibujar el triángulo
void Triangulo(int base, int x, int y) {
    int altura = static_cast<int>(sqrt(3) * base / 2);
    int inicioX = x - base / 2;
    for (int i = 0; i < altura; ++i) {
        for (int j = 0; j < base / 2 - i; ++j) {
            cursor((inicioX + j) % 140, (y + i) % 40);
            cout << " ";
        }

        for (int k = 0; k < 2 * i + 1; ++k) {
            cursor((inicioX + base / 2 - i + k) % 140, (y + i) % 40);
            cout << "*";
        }
    }
}

// Función para dibujar el cuadrado
void Cuadrado(int lado, int x, int y) {
    for (int i = 0; i < lado; ++i) {
        for (int j = 0; j < lado; ++j) {
            cursor((x + j) % 150, (y + i) % 40);
            cout << "*";
        }
    }
}

// Función para dibujar el rectángulo
void Rectangulo(int ancho, int alto, int x, int y) {
    for (int i = 0; i < alto; ++i) {
        for (int j = 0; j < ancho; ++j) {
            cursor((x + j + 1) % 140, (y + i + 1) % 40);
            cout << "*";
        }
    }
}

// Función para dibujar el círculo
void Circulo(int radio, int x0, int y0) {
    for (int y = -radio; y <= radio; ++y) {
        for (int x = -radio; x <= radio; ++x) {
            double distancia = sqrt(x * x + y * y);
            if (distancia <= radio) {
                cursor((x0 + x) % 140, (y0 + y) % 40);
                cout << "*";
            }
        }
    }
}

// Función para borrar la pantalla y mostrar el menú


// Impresión de texto sobre menú
void Menu() {
    cursor(0, 0); //
    cout << "Elige una opcion: | ";
    cout << "1. Triangulo (F2) | ";
    cout << "2. Cuadrado (F3) | ";
    cout << "3. Rectangulo (F4) | ";
    cout << "4. Circulo (F5) | ";
    cout << "F12. Borrar Pantalla | ";
    cout << "0. Salir | ";

}
void BorrarPantalla() {
    system("cls"); // Esto borra la pantalla
    Menu(); // Vuelve a mostrar el menú
}
int main() {
    TamConsola(140, 40); // Tamaño de consola

    int opcion;
    int x = 70, y = 20; // Posición inicial del cursor
    int tecla;

    Menu();
    cursor(x, y);
    // Captura la tecla presionada según su valor
    do {
        tecla = _getwch();

        switch (tecla) {
            case 72: // Flecha arriba
                y = (y - 1 + 40) % 40;
                break;
            case 80: // Flecha abajo
                y = (y + 1) % 40;
                break;
            case 75: // Flecha izquierda
                x = (x - 1 + 140) % 140;
                break;
            case 77: // Flecha derecha
                x = (x + 1) % 140;
                break;
            case 60: // Tecla 'F2' para dibujar un triángulo
                Triangulo(5, x, y);
                break;
            case 61: // Tecla 'F3' para dibujar un cuadrado
                Cuadrado(5, x, y);
                break;
            case 62: // Tecla 'F4' para dibujar un rectángulo
                Rectangulo(10, 5, x, y);
                break;
            case 63: // Tecla 'F5' para dibujar un círculo
                Circulo(5, x, y);
                break;
            case 64: // Tecla 'F6' para borrar la pantalla
                BorrarPantalla();
                break;
            case 48: // Tecla "0" para salir del programa
                cout << "Saliendo...\n";
                break;
            default:
                break;
        }

        Menu();
        cursor(x, y); // Posiciona el cursor en la posición anterior

    } while (tecla != 48);

    return 0;
}
