# Manual de Usuario

## Descripción

Este programa en realizado en el lenguaje C++ utilizando en motor CodeBlocks permite dibujar diversas figuras geométricas en la consola de Windows. Los usuarios pueden elegir entre diferentes figuras, definir sus dimensiones, orientación, caracteres, incluso el color del mismo utilizados para el dibujo. Además, el programa ofrece funcionalidades para guardar y abrir el contenido de la pantalla.

## Requisitos

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

#### Compilación del proyecto
1. Con el proyecto abierto, haz clic en el botón Compilar en la barra de herramientas (o presiona Ctrl+F9).
1. CodeBlocks comenzará a compilar el proyecto. Si todo está configurado correctamente, el proceso de compilación debería completarse sin errores.

#### Ejecución del programa
1. Una vez que el proyecto esté compilado, haz clic en el botón Ejecutar en la barra de herramientas (o presiona Ctrl+F10).
1. El programa se ejecutará en una ventana de consola, donde podrás ver los resultados de tu programa de dibujo geométrico.



## Funcionalidades

### Menú Principal
Al iniciar el programa, se mostrará un menú con las siguientes opciones:

**Elige una opción: | 1. Triángulo (F1) | 2. Cuadrado (F2) | 3. Rectángulo (F3) | 4. Círculo (F4) | 5. Línea (F5) | 6. Rombo (F6) | 7. Hexágono (F7) |
F8 Nuevo Caracter | F9 Borrar Pantalla | F10. Color del Caracter | F12. Grabar Pantalla | Ctrl + A. Abrir Archivo | 0. Salir |**





### Dibujar Figuras

**Triángulo**
- Atajo: F1
- Parámetros:
  
			1. Ingrese el tamaño del triangulo: "Numero entero"  
			2. Seleccione la orientación del triangulo  (1: Arriba, 2: Abajo)

------------

**Cuadrado**
- Atajo: F2
- Parámetros:
  
			1. Ingrese el tamaño del cuadrado: "Numero entero"   
			2. Seleccione la orientación del cuadrado  (1: Arriba, 2: Abajo)
------------


**Rectángulo**
- Atajo: F3
- Parámetros:
  
			1. Ingrese el tamaño del rectangulo: "Numero entero"  
			2. Seleccione la orientación del rectangulo  (1: Arriba, 2: Abajo)

------------


**Círculo**
- Atajo: F4
- Parámetros:
  
			1. Ingrese el tamaño del circulo: "Numero entero"  

------------


**Línea**
- Atajo: F5
- Parámetros:
  
			1. Ingrese el tamaño de la linea: "Numero entero"  
			2. Seleccione la orientación del rectangulo (1: Arriba, 2: Abajo, 3: Derecha, 4: Izquierda,                             5: Diagonal Derecha Arriba, 6: Diagonal Derecha Abajo, 7: Diagonal Izquierda Arriba,                    8: Diagonal Izquierda Abajo):
------------


**Rombo**
- Atajo: F6
- Parámetros:
  
			1. Ingrese el tamaño del rombo: "Numero entero"  
			2. Seleccione la orientación del rombo  (1: Arriba, 2: Abajo)
------------


**Hexágono**
- Atajo: F7
- Parámetros:
  
			1. Ingrese el tamaño del hexágono: "Numero entero"  
			2. Seleccione la orientación del hexágono  (1: Arriba, 2: Abajo)
------------


#### Otras Funcionalidades
**Cambiar Carácter**
- Atajo: F8
- Descripción: Permite cambiar el carácter utilizado para dibujar las figuras.

------------


**Borrar Pantalla**
- Atajo: F9
- Descripción: Limpia la pantalla de la consola.

------------

**Cambiar Color del Carácter**
 - Atajo: F10
- Descripción:
  
		Ingrese el nuevo color (0-15
------------


**Grabar Pantalla**
- Atajo: F12
- Descripción:

     		Ingrese la ruta y el nombre del archivo para guardar (con extension .txt):

------------


**Abrir Archivo**
- Atajo: Ctrl + A
- Descripción:
    
  		 Ingrese la ruta del archivo a abrir (con extension .txt):

------------


**Salir**
- Atajo: 0
- Descripción: Sale del programa.

------------


## Instrucciones de Uso
1. Ejecuta el programa.
2. Usa las teclas de función (F1 a F7) para seleccionar la figura que deseas dibujar.
3. Ingresa los parámetros solicitados (tamaño, orientación, coordenadas, etc.).
4. Usa F8 para cambiar el carácter de dibujo.
5. Usa F9 para limpiar la pantalla.
6. Usa F10 para cambiar el color del carácter.
7. Usa F12 para guardar la pantalla en un archivo de texto.
8. Usa Ctrl + A para abrir un archivo de texto y mostrar su contenido.
9. Presiona 0 para salir del programa.

## Notas Adicionales
- Las figuras se dibujan en coordenadas relativas a la posición del cursor, por lo que la posición inicial del cursor es importante para el dibujo correcto.

- No importa en que posicion de la pantalla este el cursor, ya que tiene la modalidad pantalla circular esta permite que las figuras aunque sobrepase el limite de la pantalla esta aparezca del lado opuesto.



## Ejemplo
Para dibujar un triángulo con base 10, orientado hacia arriba, en la posición (donde guste el usuario) con caracter *

1. Presiona F1.
2. Ingresa 10 para la base.
3. Ingresa 1 para la orientación (arriba).
1.  Ingresa * para el carácter.

El triángulo se dibujará en la consola en la posición especificada.

![image](https://github.com/WilsonRP7/Proyecto-Final-/assets/167270263/30c80ef6-1970-4104-b3a2-94605fecf650)

