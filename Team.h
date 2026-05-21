// Evitan que el archivo de encabezado se incluya más de una vez
// durante la compilación, evitando errores por redefiniciones.
#ifndef TEAM_H
#define TEAM_H

#include "Person.h"   // Incluye la clase Person (base para Player y Coach)
#include "Ball.h"     // Incluye la clase Ball

// Clase Team
// Representa un equipo dentro de una conferencia
class Team {
private:
    string nombreEquipo;
    string ciudad;
    Player jugadores[10];
    int cantidadJugadores;
    Coach coach;
    Ball balon;
public:
    Team();
    Team(string n, string c, Coach co, Ball b);
    string getNombreEquipo();
    void setNombreEquipo(string n);
    string getCiudad();
    void setCiudad(string c);
    void agregarJugador(Player p);
    void eliminarJugador(int posicionJugador);
    int getCantidadJugadores();
    void setCoach(Coach c);
    Coach getCoach();
    void setBalon(Ball b);
    Ball getBalon();
    string toString();
};

// IMPLEMENTACIÓN DE MÉTODOS

/**
 * Constructor por defecto
 *
 * @param
 * @return Objeto Team con nombre "Sin nombre", ciudad "Sin ciudad" y 0 jugadores
 */
// Constructor por defecto: inicializa con valores genéricos
Team::Team() {
    nombreEquipo = "Sin nombre";   // Nombre por defecto
    ciudad = "Sin ciudad";         // Ciudad por defecto
    cantidadJugadores = 0;         // No hay jugadores al inicio
}

/**
 * Constructor con parámetros
 *
 * @param n Nombre del equipo
 * @param c Ciudad del equipo
 * @param co Entrenador del equipo (Coach)
 * @param b Balón asociado (Ball)
 * @return Objeto Team inicializado con los valores dados y 0 jugadores
 */
// Constructor con parámetros: inicializa con nombre, ciudad, entrenador y balón
Team::Team(string n, string c, Coach co, Ball b) {
    if (n != "") {
        nombreEquipo = n;          // Asigna nombre válido
    } else {
        nombreEquipo = "Sin nombre"; // Valor por defecto
    }

    if (c != "") {
        ciudad = c;                // Asigna ciudad válida
    } else {
        ciudad = "Sin ciudad";     // Valor por defecto
    }

    coach = co;                    // Se asigna el entrenador
    balon = b;                     // Se asigna el balón
    cantidadJugadores = 0;         // Al inicio no hay jugadores
}

/**
 * Devuelve el nombre del equipo
 *
 * @param
 * @return Nombre del equipo
 */
// Getter del nombre del equipo
string Team::getNombreEquipo() {
    return nombreEquipo;
}

/**
 * Establece el nombre del equipo con validación
 *
 * @param n Nombre del equipo
 * @return
 */
// Setter del nombre del equipo con validación
void Team::setNombreEquipo(string n) {
    if (n != "") {
        nombreEquipo = n;
    } else {
        nombreEquipo = "Sin nombre"; // Valor por defecto
    }
}

/**
 * Devuelve la ciudad del equipo
 *
 * @param
 * @return Ciudad del equipo
 */
// Getter de la ciudad del equipo
string Team::getCiudad() {
    return ciudad;
}

/**
 * Establece la ciudad del equipo con validación
 *
 * @param c Ciudad del equipo
 * @return
 */
// Setter de la ciudad con validación
void Team::setCiudad(string c) {
    if (c != "") {
        ciudad = c;
    } else {
        ciudad = "Sin ciudad"; // Valor por defecto
    }
}

/**
 * Agrega un jugador al equipo
 *
 * @param p Objeto Player a agregar
 * @return
 */
// Agregar un jugador al equipo
void Team::agregarJugador(Player p) {
    if (cantidadJugadores < 10) { // Máximo 10 jugadores
        jugadores[cantidadJugadores] = p; // Se guarda en el arreglo
        cantidadJugadores++;              // Se incrementa el contador
    } else {
        cout << "No se pueden agregar mas jugadores. "
             << "Limite alcanzado (10)." << endl;
    }
}

/**
 * Elimina un jugador por posición
 *
 * @param posicionJugador Índice del jugador a eliminar
 * @return
 */
// Eliminar un jugador por posición
void Team::eliminarJugador(int posicionJugador) {
    if (posicionJugador >= 0 && posicionJugador < cantidadJugadores) {
        // Se recorre el arreglo para compactar los jugadores
        for (int i = posicionJugador; i < cantidadJugadores - 1; i++) {
            jugadores[i] = jugadores[i + 1];
        }
        cantidadJugadores--; // Se reduce el contador
        cout << "Jugador eliminado correctamente." << endl;
    } else {
        cout << "Posicion invalida. No se elimino ningun jugador." << endl;
    }
}

/**
 * Devuelve la cantidad de jugadores registrados
 *
 * @param
 * @return Número actual de jugadores del equipo
 */
// Obtener la cantidad de jugadores registrados
int Team::getCantidadJugadores() {
    return cantidadJugadores;
}

/**
 * Establece el entrenador del equipo
 *
 * @param c Objeto Coach
 * @return
 */
// Setter del entrenador
void Team::setCoach(Coach c) {
    coach = c;
}

/**
 * Devuelve el entrenador del equipo
 *
 * @param
 * @return Objeto Coach
 */
// Getter del entrenador
Coach Team::getCoach() {
    return coach;
}

/**
 * Establece el balón del equipo
 *
 * @param b Objeto Ball
 * @return
 */
// Setter del balón
void Team::setBalon(Ball b) {
    balon = b;
}

/**
 * Devuelve el balón del equipo
 *
 * @param
 * @return Objeto Ball
 */
// Getter del balón
Ball Team::getBalon() {
    return balon;
}

/**
 * Devuelve la información completa del equipo en formato string
 *
 * @param
 * @return Cadena con nombre, ciudad, entrenador, balón y jugadores
 */
// Mostrar toda la información del equipo
string Team::toString() {
    // Información básica del equipo
    string info = "Equipo: " + nombreEquipo +
                  " Ciudad: " + ciudad + "\n";

    // Información del entrenador
    info += "Entrenador: " + coach.toString() + "\n";

    // Información del balón
    info += balon.toString() + "\n";

    // Información de jugadores
    if (cantidadJugadores == 0) {
        info += "No hay jugadores registrados.\n";
    } else {
        info += "Jugadores:\n";
        // Se recorre el arreglo de jugadores y se concatena su información
        for (int i = 0; i < cantidadJugadores; i++) {
            info += " - " + jugadores[i].toString() + "\n";
        }
    }
    return info; // Devuelve la información completa del equipo
}

#endif // Cierra la protección contra múltiples inclusiones del archivo
