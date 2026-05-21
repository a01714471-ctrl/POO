// Evitan que el archivo de encabezado se incluya más de una vez
// durante la compilación, evitando errores por redefiniciones.
#ifndef PERSON_H
#define PERSON_H

#include <iostream>   // Librería estándar para entrada y salida
using namespace std;  // Permite usar cout y string sin prefijo std::

// Clase base Person
// Representa una persona genérica con nombre y edad
class Person {
protected:
    string nombre;   // Nombre de la persona
    int edad;        // Edad de la persona
public:
    Person();
    Person(string n, int e);
    string getNombre();
    void setNombre(string n);
    int getEdad();
    void setEdad(int e);
    string toString();
};

// Clase Player
// Hereda de Person y representa a un jugador de baloncesto
class Player : public Person {
private:
    string posicion;
    int numero;
public:
    Player();
    Player(string n, int e, string pos, int num);
    string getPosicion();
    void setPosicion(string p);
    int getNumero();
    void setNumero(int n);
    string toString();
};

// Clase Coach
// Hereda de Person y representa a un entrenador
class Coach : public Person {
private:
    int aniosExperiencia;
    string especialidad;
public:
    Coach();
    Coach(string n, int e, int exp, string esp);
    int getAniosExperiencia();
    void setAniosExperiencia(int a);
    string getEspecialidad();
    void setEspecialidad(string s);
    string toString();
};

// IMPLEMENTACIÓN DE MÉTODOS

/**
 * Constructor por defecto
 *
 * @param
 * @return Objeto Person con nombre "Desconocido" y edad 0
 */
Person::Person() {
    nombre = "Desconocido";
    edad = 0;
}

/**
 * Constructor con parámetros
 *
 * @param n Nombre de la persona
 * @param e Edad de la persona
 * @return Objeto Person inicializado con valores dados
 */
Person::Person(string n, int e) {
    if (n != "") {
        nombre = n;
    } else {
        nombre = "Desconocido";
    }

    if (e >= 0) {
        edad = e;
    } else {
        edad = 0;
    }
}

/**
 * Devuelve el nombre de la persona
 *
 * @param
 * @return Nombre de la persona
 */
string Person::getNombre() {
    return nombre;
}

/**
 * Establece el nombre de la persona con validación
 *
 * @param n Nombre de la persona
 * @return
 */
void Person::setNombre(string n) {
    if (n != "") {
        nombre = n;
    } else {
        nombre = "Desconocido";
    }
}

/**
 * Devuelve la edad de la persona
 *
 * @param
 * @return Edad de la persona
 */
int Person::getEdad() {
    return edad;
}

/**
 * Establece la edad de la persona con validación
 *
 * @param e Edad de la persona
 * @return
 */
void Person::setEdad(int e) {
    if (e >= 0) {
        edad = e;
    } else {
        edad = 0;
    }
}

/**
 * Devuelve la información completa de la persona
 *
 * @param
 * @return Cadena con nombre y edad
 */
string Person::toString() {
    return "Nombre: " + nombre +
           " Edad: " + to_string(edad);
}

// Player

/**
 * Constructor por defecto
 *
 * @param
 * @return Objeto Player con posición "Sin posicion" y número 0
 */
Player::Player() : Person() {
    posicion = "Sin posicion";
    numero = 0;
}

/**
 * Constructor con parámetros
 *
 * @param n Nombre del jugador
 * @param e Edad del jugador
 * @param pos Posición del jugador
 * @param num Número de camiseta
 * @return Objeto Player inicializado con valores dados
 */
Player::Player(string n, int e, string pos, int num) : Person(n, e) {
    if (pos != "") {
        posicion = pos;
    } else {
        posicion = "Sin posicion";
    }

    if (num >= 0) {
        numero = num;
    } else {
        numero = 0;
    }
}

/**
 * Devuelve la posición del jugador
 *
 * @param
 * @return Posición del jugador
 */
string Player::getPosicion() {
    return posicion;
}

/**
 * Establece la posición del jugador con validación
 *
 * @param p Posición del jugador
 * @return
 */
void Player::setPosicion(string p) {
    if (p != "") {
        posicion = p;
    } else {
        posicion = "Sin posicion";
    }
}

/**
 * Devuelve el número de camiseta del jugador
 *
 * @param
 * @return Número de camiseta
 */
int Player::getNumero() {
    return numero;
}

/**
 * Establece el número de camiseta con validación
 *
 * @param n Número de camiseta
 * @return
 */
void Player::setNumero(int n) {
    if (n >= 0) {
        numero = n;
    } else {
        numero = 0;
    }
}

/**
 * Devuelve la información completa del jugador
 *
 * @param
 * @return Cadena con nombre, edad, posición y número
 */
string Player::toString() {
    return Person::toString() +
           " Posicion: " + posicion +
           " Numero: " + to_string(numero);
}

// Coach

/**
 * Constructor por defecto
 *
 * @param
 * @return Objeto Coach con experiencia 0 y especialidad "General"
 */
Coach::Coach() : Person() {
    aniosExperiencia = 0;
    especialidad = "General";
}

/**
 * Constructor con parámetros
 *
 * @param n Nombre del entrenador
 * @param e Edad del entrenador
 * @param exp Años de experiencia
 * @param esp Especialidad
 * @return Objeto Coach inicializado con valores dados
 */
Coach::Coach(string n, int e, int exp, string esp)
    : Person(n, e) {
    if (exp >= 0) {
        aniosExperiencia = exp;
    } else {
        aniosExperiencia = 0;
    }

    if (esp != "") {
        especialidad = esp;
    } else {
        especialidad = "General";
    }
}

/**
 * Devuelve los años de experiencia del entrenador
 *
 * @param
 * @return Años de experiencia
 */
int Coach::getAniosExperiencia() {
    return aniosExperiencia;
}

/**
 * Establece los años de experiencia con validación
 *
 * @param a Años de experiencia
 * @return
 */
void Coach::setAniosExperiencia(int a) {
    if (a >= 0) {
        aniosExperiencia = a;
    } else {
        aniosExperiencia = 0;
    }
}

/**
 * Devuelve la especialidad del entrenador
 *
 * @param
 * @return Especialidad
 */
string Coach::getEspecialidad() {
    return especialidad;
}

/**
 * Establece la especialidad del entrenador con validación
 *
 * @param s Especialidad
 * @return
 */
void Coach::setEspecialidad(string s) {
    if (s != "") {
        especialidad = s;
    } else {
        especialidad = "General";
    }
}

/**
 * Devuelve la información completa del entrenador
 *
 * @param
 * @return Cadena con nombre, edad, experiencia y especialidad
 */
string Coach::toString() {
    return Person::toString() +
           " Experiencia: " + to_string(aniosExperiencia) +
           " anios, Especialidad: " + especialidad;
}

#endif // Cierra la protección contra múltiples inclusiones del archivo
