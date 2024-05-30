
# Manual Técnico 


## Descripción General
Este programa permite dibujar varias figuras geométricas en la consola de Windows utilizando el lenguaje de programación C++. Las figuras incluyen triángulos, cuadrados, rectángulos, círculos, líneas, rombos y hexágonos. El usuario puede seleccionar la figura, su tamaño, orientación y el carácter con el que se dibuja. Además, el programa permite guardar y cargar el estado de la pantalla, cambiar el carácter de dibujo y cambiar el color del texto.

## Requisitos del Sistema
- Sistema operativo: Windows
- Motor: CodeBlock
- Compilador de C++ (GNU GGC)



## Instalación

#### Descarga e instalación de CodeBlocks
1. Visita la página oficial de CodeBlocks:https://www.codeblocks.org/downloads/binaries/
1. Descarga la versión que incluya el compilador 
1. Ejecuta el instalador y sigue las instrucciones para completar la instalación.

#### Abrir el proyecto en CodeBlocks
1. Inicia Code::Blocks.
1. Ve a Archivo > Abrir y selecciona el archivo de proyecto nombre: Proyecto_Final_2.0.
1. El proyecto se abrirá y podrás ver todos los archivos fuente en el área de exploración del proyecto.

#### Configuración del compilador
1. Ve a Configuración > Configurador de compiladores....
1. Asegúrate de que el compilador seleccionado sea "GNU GCC Compiler" (o el compilador que estés utilizando).
1. Configura las opciones de compilación según las necesidades de tu proyecto (opcional).

## Funcionalidades

- Triángulo
- Cuadrado
- Rectángulo
- Círculo
- Línea
- Rombo
- Hexágono
### Operaciones con las Figuras
- Definir tamaño y orientación de la figura.
- Elegir el carácter con el que se dibuja la figura.
- Guardar y cargar el estado de la pantalla.
- Borrar la pantalla.
- Cambiar el carácter de dibujo.
- Cambiar el color del texto.

### Control del Programa
- Navegación y control utilizando el teclado.
- Menú de opciones para seleccionar figuras y operaciones.

## Estructura del Código
### Archivos Principales
		-main.cpp: Contiene la lógica principal del programa y la definición de funciones.
### Librerias
		windows.h: Para la manipulación de la consola de Windows.
		cmath: Para operaciones matemáticas (e.g., cálculo de la altura del triángulo).
		conio.h: Para captura de teclas.
		vector: Para almacenar las figuras.
		fstream: Para operaciones de entrada/salida con archivos.
### Funciones Principales
- #### Función cursor
      void cursor(int x, int y) {
         COORD coord;
         coord.X = x;
         coord.Y = y;
         SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
   Mueve el cursor de la consola a la posición especificada.

- #### Función Tamaño de Consola
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
    Ajusta el tamaño de la ventana de la consola.

- #### Función Triangulo
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
    
  Dibuja un triángulo en la consola.

- #### Función Cuadrado
          
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

   Dibuja un cuadrado en la consola.
- #### Función Rectangulo
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
     Dibuja un rectángulo en la consola.

- #### Función Circulo
       void Circulo(int radio, int orientacion, int x0, int y0, char caracter) {
          for (int y = -radio; y <= radio; ++y) {
            for (int x = -radio; x <= radio; ++x) {
                if (x * x + y * y <= radio * radio) {
                    cursor((x0 + x) % 140, (y0 + y) % 40);
                    cout <<caracter; // Imprime el caracter en la posición del círculo
                }
            }
        }
     Dibuja un círculo en la consola.

- #### Función Linea
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
     Dibuja una línea en la consola.

- #### Función Rombo
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
  Dibuja un rombo en la consola.

- #### Función Hexagono
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
  Dibuja un hexágono en la consola.

- #### Función BorrarPantalla
		void BorrarPantalla() {
				COORD topLeft = {0, 0};
				HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
				CONSOLE_SCREEN_BUFFER_INFO screen;
				DWORD written;

				GetConsoleScreenBufferInfo(console, &screen);
				FillConsoleOutputCharacterA(console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
				FillConsoleOutputAttribute(console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE, 
                screen.dwSize.X * screen.dwSize.Y, topLeft, &written);
				SetConsoleCursorPosition(console, topLeft);
			}
   Limpia la pantalla de la consola.



0 = Negro
1 = Azul
2 = Verde
3 = Aqua
4 = Rojo
5 = Púrpura
6 = Amarillo
7 = Blanco
8 = Gris
9 = Azul claro
A = Verde claro
B = Aqua claro
C = Rojo claro
D = Púrpura claro
E = Amarillo claro
F = Blanco brillante
## Menú y Entrada del Usuario
- #### Función Menu
		void Menu() {
				cursor(0, 0);
				cout << "Elige una opcion: | 1. Triangulo (F1) | 2. Cuadrado (F2) | 3. Rectangulo (F3) | 4. Circulo 
                (F4) |5. 
                Linea (F5) |6. Rombo (F6) | 7. Hexagono (F7) |";
				cursor(0, 1);
				cout << " F8 Nuevo Caracter | F9 Borrar Pantalla |F10. Color del Caracter | ";
				cout << " F12. Grabar Pantalla | Ctrl + A. Abrir Archivo | 0. Salir | ";
			}
  Muestra el menú de opciones en la consola.

- #### Funciones de Entrada del Usuario
1. ##### Pedir Caracter
			char PedirCaracter() {
				char caracter;
				cursor(0, 2); // Mueve el cursor a la segunda línea
				cout << "\nIngresa el nuevo caracter para dibujar las figuras: ";
				cin >> caracter;
				cursor(0, 2); // Limpia la línea donde se pidió el carácter
				cout << string(400, ' ');
				return caracter;
			}
   Pide al usuario que ingrese cualquier caracter ASCII para dibujar las figuras.
1. ##### Pedir Tamaño
		 int PedirTamano() {
				int tamano;
				cursor(0, 2); // Mueve el cursor a la segunda línea
				cout << "\nIngresa el tamano: \b";
				cin >> tamano;
				cursor(0, 2); // Limpia la línea donde se pidió el tamaño
				cout << string(30, ' ');
				return tamano;
			}
   Pide al usario el tamaño de la figura (Numero entero).
1. ##### Pedir Dimensiones
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
   Pide al usuario la altura y ancho de ciertas figuras.   

1. ##### Pedir Orientacion Triangulo
	    int PedirOrientacionTriangulo() {
		    int orientacion;
		    cursor(0, 2); // Mueve el cursor a la segunda línea
		    cout << "\nSelecciona la orientacion del cuadrado (1: Arriba, 2: Abajo): ";
		    cin >> orientacion;
		    cursor(0, 2); // Limpia la línea donde se pidió la orientación
		    cout << string(400, ' ');
		    return orientacion;
		   }
   Pide la orientación al usuario refetente al triangulo (1: Arriba, 2: Abajo)
1. ##### Pedir Orientacion Cuadrado
	   int PedirOrientacionCuadrado() {
		    int orientacion;
		    cursor(0, 2); // Mueve el cursor a la segunda línea
		    cout << "\nSelecciona la orientacion del cuadrado (1: Arriba, 2: Abajo): ";
		    cin >> orientacion;
		    cursor(0, 2); // Limpia la línea donde se pidió la orientación
		    cout << string(400, ' ');
		    return orientacion;
		 } 
  Pide la orientación al usuario refetente al cuadrado (1: Arriba, 2: Abajo)
1. ##### Pedir Orientacion Rectangulo
		 int PedirOrientacionRectangulo() {
		    int orientacion;
		    cursor(0, 2); // Mueve el cursor a la segunda línea
		    cout << "\nSelecciona la orientacion del Rectangulo (1: Arriba, 2: Abajo): ";
		    cin >> orientacion;
		    cursor(0, 2); // Limpia la línea donde se pidió la orientación
		    cout << string(400, ' ');
		    return orientacion;
		}
   Pide la orientación al usuario refetente al cuadrado (1: Arriba, 2: Abajo)
1. ##### Pedir Orientacion Linea
		 int PedirOrientacionRombo() {
		    int orientacion;
		    cursor(0, 2); // Mueve el cursor a la segunda línea
		    cout << "\nSelecciona la orientacion del rombo (1: Arriba, 2: Abajo): ";
		    cin >> orientacion;
		    cursor(0, 2); // Limpia la línea donde se pidió la orientación
		    cout << string(400, ' ');
		    return orientacion;
		}
   Pide la orientación al usuario refetente al cuadrado (1: Arriba, 2: Abajo, 3: Derecha, 4: Izquierda, 5: Diagonal 
   Derecha Arriba, 6: Diagonal Derecha Abajo, 7: Diagonal Izquierda Arriba, 8: Diagonal Izquierda Abajo)
1. ##### Pedir Orientacion Rombo
		 int PedirOrientacionRombo() {
		    int orientacion;
		    cursor(0, 2); // Mueve el cursor a la segunda línea
		    cout << "\nSelecciona la orientacion del rombo (1: Arriba, 2: Abajo): ";
		    cin >> orientacion;
		    cursor(0, 2); // Limpia la línea donde se pidió la orientación
		    cout << string(400, ' ');
		    return orientacion;
		}
   Pide la orientación al usuario refetente al cuadrado (1: Arriba, 2: Abajo)
1. ##### Pedir Orientacion Hexagono
		 int PedirOrientacionHexagono() {
		    int orientacion;
		    cursor(0, 2); // Mueve el cursor a la segunda línea
		    cout << "\nSelecciona la orientacion del hexagono (1: Vertical, 2: Horizontal): ";
		    cin >> orientacion;
		    cursor(0, 2); // Limpia la línea donde se pidió la orientación
		    cout << string(400, ' ');
		    return orientacion;
		 } 
    Pide la orientación al usuario refetente al cuadrado (1: Arriba, 2: Abajo)
   
Estas funciones solicitan al usuario los parámetros necesarios para dibujar las figuras.

### Guardar y Cargar el Estado de la Pantalla
1. #### Función GrabarPantalla
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
   Guarda el estado actual de la pantalla en un archivo de texto.

1. #### Función AbrirArchivo
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

	Carga el contenido de un archivo de texto y lo muestra en la consola.

## Función Principal
#### main
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
		         if ((GetAsyncKeyState(VK_CONTROL) & 0x8000) && (GetAsyncKeyState(0x41) & 0x8000)) { // Si se detecta 
                Ctrl + A
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
  La función principal del programa gestiona el ciclo de ejecución, presentando el menú y capturando las entradas del 
  usuario para dibujar las figuras o realizar otras operaciones. A continuación se presenta una visión general del 
  flujo de la función main:

## Inicialización:

### Configura el tamaño de la consola.
Llama a la función Menu para mostrar las opciones disponibles.
Bucle Principal:

Captura la entrada del usuario para determinar la acción a realizar.
Llama a las funciones correspondientes basadas en la selección del usuario (e.g., dibujar una figura, guardar la pantalla, cargar una pantalla guardada, borrar la pantalla, cambiar el carácter de dibujo, cambiar el color del texto).
Lógica de Dibujado:

Solicita los parámetros necesarios para la figura seleccionada (e.g., tamaño, orientación, carácter).
Llama a la función de dibujo correspondiente con los parámetros proporcionados por el usuario.
Operaciones de Guardado/Carga:

Llama a GrabarPantalla para guardar el estado actual de la consola.
Llama a AbrirArchivo para cargar un estado guardado previamente.
Cambio de Carácter:

Solicita el nuevo carácter al usuario y actualiza el carácter de dibujo.
Cambio de Color:

Solicita el código de color al usuario y actualiza el color del texto en la consola.
Finalización:

Permite al usuario salir del programa o volver al menú para realizar más acciones.
Ejemplo de Ejecución
A continuación se presenta un ejemplo de cómo podría verse una sesión de uso del programa:

El programa muestra el menú de opciones.
El usuario selecciona "Dibujar Triángulo".
El programa solicita la base, la posición, la orientación y el carácter para el triángulo.
El triángulo se dibuja en la consola.
El usuario selecciona "Cambiar Carácter" y proporciona un nuevo carácter.
El usuario selecciona "Dibujar Cuadrado" y el cuadrado se dibuja con el nuevo carácter.
El usuario selecciona "Cambiar Color" y proporciona un nuevo código de color.
El color del texto en la consola cambia.
El usuario selecciona "Guardar Pantalla" y el estado actual se guarda en un archivo.
El usuario selecciona "Borrar Pantalla" y la consola se limpia.
El usuario selecciona "Cargar Pantalla" y se carga el estado previamente guardado.
El usuario selecciona "Salir" para finalizar el programa.
