#include <iostream>
#include <windows.h>
#include <cmath>
#include <conio.h>
#include <vector>
#include <fstream>


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
void Triangulo(int base, int x, int y, int orientacion, char caracter) {
    int altura = static_cast<int>(sqrt(4) * base / 2);
    int inicioX = x - base / 2;
    if (orientacion == 1) { // Arriba del cursor
    for (int i = 0; i < altura; ++i) {
        for (int j = 0; j < base / 2 - i; ++j) {
            cursor((inicioX + j) % 140, (y - 1 - i) % 40);
            cout << " ";
        }

        for (int k = 0; k < 2 * i + 1; ++k) {
            cursor((inicioX + base / 2 - i + k) % 140, (y -1 - i) % 40);
            cout << caracter;
          }
        }
    } else if (orientacion == 2) { // Abajo del cursor
        for (int i = 0; i < altura; ++i) {
            for (int j = 0; j < base / 2 - i; ++j) {
                cursor((inicioX + j) % 140, (y + i) % 40);
                cout << " ";
            }

            for (int k = 0; k < 2 * i + 1; ++k) {
                cursor((inicioX + base / 2 - i + k) % 140, (y + i) % 40);
                cout << caracter;
            }
        }
     } else if (orientacion == 3) { // Derecha del cursor
        for (int i = 0; i < altura; ++i) {
            for (int j = 0; j < base / 2 - i; ++j) {
                cursor((inicioX + j) % 140, (y + i) % 40);
                cout << " ";
            }

            for (int k = 0; k < 2 * i + 1; ++k) {
                cursor((inicioX + 7 + base / 2 - i + k) % 140, (y -3+ i) % 40);
                cout << caracter;
            }
        }
     } else if (orientacion == 4) { // Izquierda del cursor
        for (int i = 0; i < altura; ++i) {
            for (int j = 0; j < base / 2 - i; ++j) {
                cursor((inicioX + j) % 140, (y + i) % 40);
                cout << " ";
            }

            for (int k = 0; k < 2 * i + 1; ++k) {
                cursor((inicioX - 7+ base / 2 - i + k) % 140, (y -3+ i) % 40);
                cout << caracter;
            }
        }
    }
}
// Función para dibujar el cuadrado
void Cuadrado(int lado, int orientacion, int x, int y, char caracter) {
    if (orientacion == 1) {
        for (int i = 0; i < lado; ++i) {
            for (int j = 0; j < lado; ++j) {
                cursor((x + j) % 140, ((y - 1 - i)) % 40); // Arriba del cursor
                cout <<caracter;
            }
        }
    } else { // Abajo del cursor
        for (int i = 0; i < lado; ++i) {
            for (int j = 0; j < lado; ++j) {
                cursor((x + j) % 140, (y + i) % 40); // Abajo del cursor
                cout << caracter;
            }
        }
    }
}
// Función para dibujar el rectángulo
void Rectangulo(int ancho, int alto, int x, int y, int orientacion, char caracter) {
    ancho= ancho + 2;
    if (orientacion == 1 ) { // Orientación por defecto (horizontal)
        for (int i =0; i < alto; ++i) {
            for (int j = 0; j < ancho; ++j) {
                cursor((x + j + 1) % 140, (y -0- i + 40) % 40);
                cout <<caracter;
            }
        }
    } else { // Orientación vertical
        for (int i = 0; i < ancho; ++i) {
            for (int j = 0; j < alto; ++j) {
                cursor((x + i + 1) % 140, (y + j + 1) % 40);
                cout <<caracter;
            }
        }
    }
}

// Función para dibujar el círculo
void Circulo(int radio, int orientacion, int x0, int y0, char caracter) {
      for (int y = -radio; y <= radio; ++y) {
        for (int x = -radio; x <= radio; ++x) {
            if (x * x + y * y <= radio * radio) {
                cursor((x0 + x) % 140, (y0 + y) % 40);
                cout <<caracter; // Imprime el caracter en la posición del círculo
            }
        }
    }
}

// Función para dibujar la línea en diferentes orientaciones
void Linea(int longitud, int orientacion, int x, int y, char caracter) {
    switch (orientacion) {
        case 1: // Arriba
            for (int i = 0; i < longitud; ++i) {
                cursor(x, (y - i + 40) % 40);
                cout <<caracter;
            }
            break;
        case 2: // Abajo
            for (int i = 0; i < longitud; ++i) {
                cursor(x, (y + i) % 40);
                cout <<caracter;
            }
            break;
        case 3: // Derecha
            for (int i = 0; i < longitud; ++i) {
                cursor((x + i) % 140, y);
                cout <<caracter;
            }
            break;
        case 4: // Izquierda
            for (int i = 0; i < longitud; ++i) {
                cursor((x - i + 140) % 140, y);
                cout <<caracter;
            }
            break;
        case 5: // Diagonal Derecha Arriba
            for (int i = 0; i < longitud; ++i) {
                cursor((x + i) % 140, (y - i + 40) % 40);
                cout <<caracter;
            }
            break;
        case 6: // Diagonal Derecha Abajo
            for (int i = 0; i < longitud; ++i) {
                cursor((x + i) % 140, (y + i) % 40);
                cout <<caracter;
            }
            break;
        case 7: // Diagonal Izquierda Arriba
            for (int i = 0; i < longitud; ++i) {
                cursor((x - i + 140) % 140, (y - i + 40) % 40);
                cout <<caracter;
            }
            break;
        case 8: // Diagonal Izquierda Abajo
            for (int i = 0; i < longitud; ++i) {
                cursor((x - i + 140) % 140, (y + i) % 40);
                cout <<caracter;
            }
            break;
    }
}

// Función para dibujar el rombo
void Rombo(int lado, int orientacion, int x, int y, char caracter) {
    int diagonal = 2 * lado;
    int mitad = diagonal / 2;
    if (orientacion == 2) { // Arriba
        for (int i = 0; i <= mitad; ++i) {
            for (int j = 0; j < mitad - i; ++j) {
                cursor((x + j) % 140, (y + i) % 40);
                cout << " ";
            }
            for (int k = 0; k < 2 * i + 1; ++k) {
                cursor((x + mitad - i + k) % 140, (y + i) % 40);
                cout <<caracter;
            }
        }
        for (int i = mitad - 1; i >= 0; --i) {
            for (int j = 0; j < mitad - i; ++j) {
                cursor((x + j) % 140, (y + diagonal - i - 1) % 40);
                cout << " ";
            }
            for (int k = 0; k < 2 * i + 1; ++k) {
                cursor((x + mitad - i + k) % 140, (y + diagonal - i - 1) % 40);
                cout << caracter;
            }
        }
    } else { // Abajo
        for (int i = 0; i <= mitad; ++i) {
            for (int j = 0; j < mitad - i; ++j) {
                cursor((x + j) % 140, (y - i + 40) % 40);
                cout << " ";
            }
            for (int k = 0; k < 2 * i + 1; ++k) {
                cursor((x + mitad - i + k) % 140, (y -1- i + 40) % 40);
                cout <<caracter;
            }
        }
        for (int i = mitad - 1; i >= 0; --i) {
            for (int j = 0; j < mitad - i; ++j) {
                cursor((x + j) % 140, (y - diagonal + i + 40) % 40);
                cout << " ";
            }
            for (int k = 0; k < 2 * i + 1; ++k) {
                cursor((x + mitad - i + k) % 140, (y - diagonal + i + 40) % 40);
                cout <<caracter;
            }
        }
    }
}

// Función para dibujar el hexágono
void Hexagono(int lado, int orientacion, int x, int y, char caracter) {
    int altura = lado * 2 - 1;
    int ancho = lado * 4 - 3;
    int espacio = lado;

    if (orientacion == 2) { // Vertical
        // Parte superior del hexágono
        for (int i = 0; i < lado; ++i) {
            for (int j = 0; j < espacio - i - 1; ++j) {
                cursor(x + j, y + i);
                cout << " ";
            }
            for (int k = 0; k < lado + 2 * i; ++k) {
                cursor(x + espacio - i + k, y + i);
                cout << caracter;
            }
            cout << endl;
        }

        // Parte inferior del hexágono
        for (int i = lado - 2; i >= 0; --i) {
            for (int j = 0; j < espacio - i - 1; ++j) {
                cursor(x + j, y + altura - i - 1);
                cout << " ";
            }
            for (int k = 0; k < lado + 2 * i; ++k) {
                cursor(x + espacio - i + k, y + altura - i - 1);
                cout << caracter;
            }
            cout << endl;
        }
    } else { // Horizontal
        // Parte izquierda del hexágono
         for (int i = 0; i < lado; ++i) {
            for (int j = 0; j < espacio - i - 1; ++j) {
                cursor(x + j, y + i);
                cout << " ";
            }
            for (int k = 0; k < lado + 2 * i; ++k) {
                cursor(x + espacio - i + k, y -1- i);
                cout << caracter;
            }
            cout << endl;
        }

        // Parte inferior del hexágono
        for (int i = lado - 2; i >= 0; --i) {
            for (int j = 0; j < espacio - i - 1; ++j) {
                cursor(x + j, y + altura - i - 1);
                cout << " ";
            }
            for (int k = 0; k < lado + 2 * i; ++k) {
                cursor(x + espacio - i + k, y - altura + i );
                cout << caracter;
            }
            cout << endl;
        }
    }
}

// Limpia la pantalla
void BorrarPantalla() {
    COORD topLeft = {0, 0};
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
    FillConsoleOutputAttribute(console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE, screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
    SetConsoleCursorPosition(console, topLeft);
}
struct Figura {
    char tipo;
    int tamano1;
    int tamano2;
    int x;
    int y;
    int a;
    char c;
};

vector<Figura> figuras;


void Menu() {
    cursor(0, 0);
    cout << "Elige una opcion: | 1. Triangulo (F1) | 2. Cuadrado (F2) | 3. Rectangulo (F3) | 4. Circulo (F4) |5. Linea (F5) |6. Rombo (F6) | 7. Hexagono (F7) |";
    cursor(0, 1);
    cout << " F8 Nuevo Caracter | F9 Borrar Pantalla |F10. Color del Caracter | ";
    cout << " F12. Grabar Pantalla | Ctrl + A. Abrir Archivo | 0. Salir | ";
}
char PedirCaracter() {
    char caracter;
    cursor(0, 2); // Mueve el cursor a la segunda línea
    cout << "\nIngresa el nuevo caracter para dibujar las figuras: ";
    cin >> caracter;
    cursor(0, 2); // Limpia la línea donde se pidió el carácter
    cout << string(400, ' ');
    return caracter;
}
int PedirTamano() {
    int tamano;
    cursor(0, 2); // Mueve el cursor a la segunda línea
    cout << "\nIngresa el tamano: \b";
    cin >> tamano;
    cursor(0, 2); // Limpia la línea donde se pidió el tamaño
    cout << string(30, ' ');
    return tamano;
}

void PedirDimensiones(int &ancho, int &alto) {
    cursor(0, 2); // Mueve el cursor a la segunda línea
    cout << "\nIngresa el ancho: ";
    cin >> ancho;
    cursor(0, 2); // Limpia la línea donde se pidió el ancho
    cout << string(400, ' ');
    cursor(0, 2); // Mueve el cursor nuevamente a la segunda línea
    cout << "\nIngresa el alto: ";
    cin >> alto;
    cursor(0, 2); // Limpia la línea donde se pidió el alto
    cout << string(400, ' ');
}
int PedirOrientacionTriangulo() {
    int orientacion;
    cursor(0, 2); // Mueve el cursor a la segunda línea
    cout << "\nSelecciona la orientacion del cuadrado (1: Arriba, 2: Abajo): ";
    cin >> orientacion;
    cursor(0, 2); // Limpia la línea donde se pidió la orientación
    cout << string(400, ' ');
    return orientacion;
}
int PedirOrientacionCuadrado() {
    int orientacion;
    cursor(0, 2); // Mueve el cursor a la segunda línea
    cout << "\nSelecciona la orientacion del cuadrado (1: Arriba, 2: Abajo): ";
    cin >> orientacion;
    cursor(0, 2); // Limpia la línea donde se pidió la orientación
    cout << string(400, ' ');
    return orientacion;
}
int PedirOrientacionRectangulo() {
    int orientacion;
    cursor(0, 2); // Mueve el cursor a la segunda línea
    cout << "\nSelecciona la orientacion del Rectangulo (1: Arriba, 2: Abajo): ";
    cin >> orientacion;
    cursor(0, 2); // Limpia la línea donde se pidió la orientación
    cout << string(400, ' ');
    return orientacion;
}
int PedirOrientacion() {
    int orientacion;
    cursor(0, 2); // Mueve el cursor a la segunda línea
    cout << "\nSelecciona la orientacion (1: Arriba, 2: Abajo, 3: Derecha, 4: Izquierda, 5: Diagonal Derecha Arriba, 6: Diagonal Derecha Abajo, 7: Diagonal Izquierda Arriba, 8: Diagonal Izquierda Abajo): ";
    cin >> orientacion;
    cursor(0, 2); // Limpia la línea donde se pidió la orientación
    cout << string(600, ' ');
    return orientacion;
}
int PedirOrientacionCirculo() {
    int orientacion;

    return orientacion;
}
int PedirOrientacionRombo() {
    int orientacion;
    cursor(0, 2); // Mueve el cursor a la segunda línea
    cout << "\nSelecciona la orientacion del rombo (1: Arriba, 2: Abajo): ";
    cin >> orientacion;
    cursor(0, 2); // Limpia la línea donde se pidió la orientación
    cout << string(400, ' ');
    return orientacion;
}

int PedirOrientacionHexagono() {
    int orientacion;
    cursor(0, 2); // Mueve el cursor a la segunda línea
    cout << "\nSelecciona la orientacion del hexagono (1: Vertical, 2: Horizontal): ";
    cin >> orientacion;
    cursor(0, 2); // Limpia la línea donde se pidió la orientación
    cout << string(400, ' ');
    return orientacion;
}

// Función para redibujar todas las figuras almacenadas
void RedibujarFiguras() {
    for ( const auto& figura : figuras) {
        switch (figura.tipo) {
            case 'T':
                Triangulo(figura.tamano1, figura.x, figura.y, figura.a, figura.c);
                break;
            case 'C':
                Cuadrado(figura.tamano1, figura.tamano2, figura.x, figura.y, figura.c);
                break;
            case 'R':
                Rectangulo(figura.tamano1, figura.tamano2, figura.x, figura.y, figura.a, figura.c);
                break;
            case 'O':
                Circulo(figura.tamano1, figura.tamano2, figura.x, figura.y, figura.c);
                break;
            case 'L':
                Linea(figura.tamano1, figura.tamano2, figura.x, figura.y, figura.c);
                break;
            case 'D':
                Rombo(figura.tamano1, figura.tamano2, figura.x, figura.y, figura.c);
                break;
            case 'H':
                Hexagono(figura.tamano1, figura.tamano2, figura.x, figura.y, figura.c);
                break;
        }
    }
}

// Función para capturar y guardar el contenido de la pantalla
void GrabarPantalla() {
    // Solicitar nombre y ruta del archivo
    string ruta;
    cursor(0, 2);
    cout << "\nIngrese la ruta y el nombre del archivo (con extension .txt): ";
    cin >> ruta;
    cursor(0, 2); // Limpia la línea donde se pidió la orientación
    cout << string(400, ' ');

    // Capturar contenido de la pantalla
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    int ancho = csbi.dwSize.X;
    int alto = csbi.dwSize.Y;

    CHAR_INFO *buffer = new CHAR_INFO[ancho * alto];
    COORD bufferSize = { (SHORT)ancho, (SHORT)alto };
    COORD bufferCoord = { 0, 0 };
    SMALL_RECT readRegion = { 0, 0, (SHORT)(ancho - 1), (SHORT)(alto - 1) };

    ReadConsoleOutput(hConsole, buffer, bufferSize, bufferCoord, &readRegion);

    // Guardar contenido en el archivo
    ofstream archivo(ruta);
    if (archivo.is_open()) {
        for (int i = 0; i < alto; ++i) {
            for (int j = 0; j < ancho; ++j) {
                archivo << buffer[i * ancho + j].Char.AsciiChar;
            }
            archivo << endl;
        }
        archivo.close();
        cursor(0, 2);
        cout << "\nPantalla guardada en " << ruta << endl;
        cursor(0, 2); // Limpia la línea donde se pidió la orientación
        cout << string(400, ' ');
    } else {
        cursor(0, 2);
        cout << "\nNo se pudo abrir el archivo " << ruta << endl;
        cursor(0, 2); // Limpia la línea donde se pidió la orientación
        cout << string(400, ' ');
    }
    delete[] buffer;
}

// Función para abrir un archivo y mostrar su contenido en la consola
void AbrirArchivo() {
    // Solicitar la ruta del archivo
    string ruta;
    cursor(0, 2);
    cout << "\nIngrese la ruta del archivo a abrir (con extension .txt): ";
    cin >> ruta;
    cursor(0, 2); // Limpia la línea donde se pidió la orientación
    cout << string(400, ' ');

    // Leer el contenido del archivo
    ifstream archivo(ruta);
    if (archivo.is_open()) {
        string linea;
        int y = 0;
        BorrarPantalla(); // Borra la pantalla antes de mostrar el contenido del archivo
        while (getline(archivo, linea)) {
            cursor(0, y++);
            cout << linea;
        }
        archivo.close();

    } else {
        cursor(0, 2);
        cout << "\nNo se pudo abrir el archivo " << ruta << endl;
    }
}

int main() {
    TamConsola(140, 40); // Tamaño de consola

    int opcion;
    int x = 60, y = 15; // Posición inicial del cursor
    int tecla;
    char caracter = '*'; // Carácter predeterminado para dibujar figuras
    int color = 7; // Color por defecto (blanco)

    Menu();
    cursor(x, y);
    // Captura la tecla presionada según su valor
    do {
         if ((GetAsyncKeyState(VK_CONTROL) & 0x8000) && (GetAsyncKeyState(0x41) & 0x8000)) { // Si se detecta Ctrl + A
            AbrirArchivo();
            Menu();
            cursor(x, y);
            continue;
        }

        if (GetAsyncKeyState(VK_F12) & 0x8000) { // Si se detecta F12
            GrabarPantalla();
            Menu();
            cursor(x, y);
            continue;
        }

        if (GetAsyncKeyState(VK_F9) & 0x8000) { // Si se detecta F9
            BorrarPantalla();
            x = 60;
            y = 15;
            cursor(x, y);
            continue;
        }

        if (GetAsyncKeyState(VK_F10) & 0x8000) { // Si se detecta F10
            cursor(0, 2);
            cout << "\nIngrese el nuevo color (0-15): ";
            cin >> color;
            cursor(0, 2); // Limpia la línea donde se pidió la orientación
            cout << string(400, ' ');
            continue;
        }
        tecla = _getwch();

        switch (tecla) {
            case 66: // F8 cambiar caracter
                caracter = PedirCaracter();
                RedibujarFiguras();
                break;
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

                case 59: { // Tecla 'F1' para dibujar un triángulo
                int base = PedirTamano();
                int orientacion = PedirOrientacionTriangulo();
                figuras.push_back({'T', base, 0, x, y, orientacion, caracter});
                RedibujarFiguras();
                break;
            }
           case 60: { // Tecla 'F2' para dibujar un cuadrado
                int lado = PedirTamano();
                int orientacion = PedirOrientacionCuadrado();
                figuras.push_back({'C', lado,  orientacion, x, y,0, caracter}); // Añadir la orientación al final
                RedibujarFiguras();
                break;
            }
            case 61: { // Tecla 'F3' para dibujar un rectángulo
                int ancho, alto;
                PedirDimensiones(ancho, alto);
                int orientacion = PedirOrientacionRectangulo();
                figuras.push_back({'R', ancho, alto,  x, y, orientacion, caracter});
                RedibujarFiguras();
                break;
            }
            case 62: { // Tecla 'F4' para dibujar un círculo
                int radio = PedirTamano();
                int orientacion = PedirOrientacionCirculo();
                figuras.push_back({'O', radio, orientacion, x, y,0, caracter}); // Utilizar el último carácter ingresado
                RedibujarFiguras();
                break;
            }
            case 63: { // Tecla 'F5' para dibujar una línea
                int longitud = PedirTamano();
                int orientacion = PedirOrientacion();
                figuras.push_back({'L', longitud, orientacion, x, y,0, caracter});
                RedibujarFiguras();
                break;
            }
            case 64: { // Tecla 'F6' para dibujar un rombo
                int lado = PedirTamano();
                int orientacion = PedirOrientacionRombo();
                figuras.push_back({'D', lado, orientacion, x, y,0, caracter});
                RedibujarFiguras();
                break;
            }
            case 65: { // Tecla 'F7' para dibujar un hexágono
                int lado = PedirTamano();
                int orientacion = PedirOrientacionHexagono();
                figuras.push_back({'H', lado, orientacion, x, y,0, caracter});
                RedibujarFiguras();
                break;
            }
            case 67: // Tecla 'F9' para borrar la pantalla
                BorrarPantalla();
                figuras.clear();
                break;
            case 48: // Tecla "0" para salir del programa
                cout << "Saliendo...\n";
                break;
            default:
                break;
        }
         // Cambiar el color del carácter
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
        Menu();
        cursor(x, y); // Posiciona el cursor en la posición anterior

    } while (tecla != 48);

    return 0;
}
