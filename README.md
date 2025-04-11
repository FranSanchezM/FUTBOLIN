# FUTBOLIN: Juego en C++ con SFML

![capturadeljuego](https://github.com/user-attachments/assets/c1a70044-254a-40fd-934c-ecc206b4e3d9)


## Descripción

FUTBOLIN es un juego de futbolín (o metegol) desarrollado en C++ utilizando la biblioteca multimedia SFML (Simple and Fast Multimedia Library). El objetivo del juego es simular la experiencia clásica del futbolín, permitiendo a los jugadores controlar sus barras de jugadores para golpear la pelota e intentar marcar goles en la portería del oponente.

Este proyecto se creó como un ejercicio de aprendizaje y aplicación de conceptos de programación en C++ y el uso de SFML para la creación de gráficos, manejo de eventos y posiblemente audio.

## Características Principales

* **Gráficos:** Renderizado 2D del campo de juego, las barras de jugadores y la pelota utilizando SFML.
* **Controles:** Implementación de controles para mover las barras de jugadores (especificar los controles, por ejemplo, teclas).
* **Física básica de la pelota:** Simulación del movimiento de la pelota, colisiones con los jugadores y las paredes del campo.
* **Sistema de puntuación:** Seguimiento de los goles marcados por cada jugador.
* **Interfaz de usuario básica:** (Si aplica) Menú principal, pantalla de juego, pantalla de puntuación, etc.
* **(Otras características que hayas implementado)**

## Cómo Jugar

1.  **Descarga el juego:** (Si tienes una versión ejecutable para compartir) Descarga la última versión desde la sección de Releases (si la creas).
2.  **Ejecuta el juego:** (Si tienes una versión ejecutable) Ejecuta el archivo ejecutable (`Futol.exe` en Windows, por ejemplo).
3.  **Controles:**
    * **Jugador 1:** (Especifica las teclas, por ejemplo: W/S para mover la barra superior, A/D para la inferior).
    * **Jugador 2:** (Especifica las teclas, por ejemplo: Flecha Arriba/Abajo para la barra superior, Flecha Izquierda/Derecha para la inferior).
4.  **Objetivo:** Intenta golpear la pelota y marcar más goles que tu oponente antes de que termine el partido (si hay un límite de tiempo o goles).

## Cómo Compilar (Para Desarrolladores)

Si deseas compilar el juego desde el código fuente, necesitarás tener instalado lo siguiente:

* **Compilador de C++:** (Por ejemplo, g++, MinGW, Visual Studio C++).
* **SFML (Simple and Fast Multimedia Library):** Asegúrate de tener la versión correcta de SFML instalada y configurada en tu sistema, incluyendo los archivos de encabezado (`include`) y las bibliotecas (`lib`).

**Pasos para compilar con Code::Blocks (Ejemplo):**

1.  Abre el proyecto `Futbol.cbp` en Code::Blocks.
2.  Asegúrate de que las rutas a los archivos de encabezado y las bibliotecas de SFML estén correctamente configuradas en las opciones del compilador y enlazador del proyecto (`Project` -> `Build Options...`).
3.  Selecciona el objetivo de compilación (Debug o Release).
4.  Haz clic en "Build" (Ctrl+F9) para compilar el proyecto.
5.  Si la compilación es exitosa, haz clic en "Run" (Ctrl+F10) para ejecutar el juego.

**Pasos para compilar con g++ (Ejemplo desde la línea de comandos):**

1.  Abre una terminal o línea de comandos en la raíz de tu proyecto.
2.  Ejecuta el siguiente comando (ajusta los nombres de los archivos fuente y las rutas de SFML según tu configuración):
    ```bash
    g++ src/main.cpp src/Usuario.cpp src/Gameplay.cpp -o Futol -I/ruta/a/SFML/include -L/ruta/a/SFML/lib -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system -std=c++14
    ```
    Reemplaza `/ruta/a/SFML/include` y `/ruta/a/SFML/lib` con las rutas reales a tus archivos de encabezado y bibliotecas de SFML.
3.  Ejecuta el juego con `./Futol` (en Linux/macOS) o `Futol.exe` (en Windows).

4.  ## Dependencias

* **SFML (Simple and Fast Multimedia Library):** [https://www.sfml-dev.org/](https://www.sfml-dev.org/)

Asegúrate de tener instalada la versión adecuada de SFML para tu sistema.
