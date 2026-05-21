// Evitan que el archivo de encabezado se incluya más de una vez
// durante la compilación, evitando errores por redefiniciones.
#ifndef BALL_H
#define BALL_H

#include <iostream>   // Librería estándar para entrada y salida (cout)
using namespace std;  // Permite usar cout y string sin prefijo std::

// Clase Ball
// Representa un balón de baloncesto con marca y tamaño
class Ball {
private:
    string marca;   // Marca del balón (ejemplo: Spalding, Molten)
    float tamano;   // Tamaño del balón (ejemplo: 7.5)
public:
    Ball();                         // Constructor por defecto
    Ball(string m, float t);        // Constructor con parámetros: marca y
                                    // tamaño
    string getMarca();              // Devuelve la marca del balón
    void setMarca(string m);        // Establece la marca del balón
    float getTamano();              // Devuelve el tamaño del balón
    void setTamano(float t);        // Establece el tamaño del balón
    void rebotar();                 // Simula que el balón rebota (mensaje en
                                    // consola)
    string toString();              // Devuelve info completa del balón en
                                    // formato string
};

// IMPLEMENTACIÓN DE MÉTODOS

/**
 * Constructor por defecto
 *
 * @param
 * @return Objeto Ball con marca "Generica" y tamaño 0.0
 */
Ball::Ball() {
    marca = "Generica";   // Marca por defecto si no se especifica
    tamano = 0.0f;        // Tamaño por defecto (sin valor válido)
}

/**
 * Constructor con parámetros
 *
 * @param m Marca del balón
 * @param t Tamaño del balón
 * @return Objeto Ball inicializado con valores dados
 */
Ball::Ball(string m, float t) {
    if (m != "") {
        marca = m;
    } else {
        marca = "Generica";
    }

    if (t > 0) {
        tamano = t;
    } else {
        tamano = 0.0f;
    }
}

/**
 * Devuelve la marca del balón
 *
 * @param
 * @return Marca del balón
 */
string Ball::getMarca() {
    return marca;
}

/**
 * Establece la marca del balón con validación
 *
 * @param m Marca del balón
 * @return
 */
void Ball::setMarca(string m) {
    if (m != "") {
        marca = m;
    } else {
        marca = "Generica";
    }
}

/**
 * Devuelve el tamaño del balón
 *
 * @param
 * @return Tamaño del balón
 */
float Ball::getTamano() {
    return tamano;
}

/**
 * Establece el tamaño del balón con validación
 *
 * @param t Tamaño del balón
 * @return
 */
void Ball::setTamano(float t) {
    if (t > 0) {
        tamano = t;
    } else {
        tamano = 0.0f;
    }
}

/**
 * Simula que el balón rebota mostrando un mensaje en consola
 *
 * @param
 * @return
 */
void Ball::rebotar() {
    cout << "El balon de marca " << marca
         << " rebota con fuerza!" << endl;
}

/**
 * Devuelve la información completa del balón en formato string
 *
 * @param
 * @return Cadena con marca y tamaño del balón
 */
string Ball::toString() {
    return "Balon: Marca " + marca +
           " Tamanio " + to_string(tamano);
}

#endif // Cierra la protección contra múltiples inclusiones del archivo
