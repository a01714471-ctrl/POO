// Evitan que el archivo de encabezado se incluya más de una vez
// durante la compilación, evitando errores por redefiniciones.
#ifndef LEAGUE_H
#define LEAGUE_H

// Incluye la clase Conference, necesaria en League
#include "Conference.h"

// Clase League
// Representa una liga de baloncesto que contiene conferencias
class League {
private:
    string nombreLiga;
    int anio;
    Conference* conferencias[2]; // ahora punteros a Conference en heap
    int cantidadConferencias;

public:
    League();
    League(string nombre, int a);

    string getNombreLiga();
    void setNombreLiga(string nombre);
    int getAnio();
    void setAnio(int a);

    void agregarConferencia(Conference* c);
    void eliminarConferencia(int posicionConferencia);
    Conference* getConferencia(int posicionConferencia);
    int getCantidadConferencias();

    void agregarEquipoEnConferencia(int posicionConf, Team equipo);
    void eliminarEquipoEnConferencia(int posicionConf, int posicionEquipo);

    void agregarJugadorEnEquipo(int posicionConf,
                                int posicionEquipo,
                                Player jugador);
    void eliminarJugadorEnEquipo(int posicionConf,
                                 int posicionEquipo,
                                 int posicionJugador);

    string toString();
};

// IMPLEMENTACIÓN DE MÉTODOS

/**
 * Constructor por defecto
 *
 * @param
 * @return Objeto League con nombre "Sin nombre" y año 0
 */
League::League() {
    nombreLiga = "Sin nombre";
    anio = 0;
    cantidadConferencias = 0;
    for (int i = 0; i < 2; ++i) conferencias[i] = nullptr;
}

/**
 * Constructor con parámetros
 *
 * @param nombre Nombre de la liga
 * @param a Año de la liga
 * @return Objeto League inicializado con valores dados
 */
League::League(string nombre, int a) {
    if (nombre != "") {
        nombreLiga = nombre;
    } else {
        nombreLiga = "Sin nombre";
    }

    if (a >= 0) {
        anio = a;
    } else {
        anio = 0;
    }

    cantidadConferencias = 0;
    for (int i = 0; i < 2; ++i) conferencias[i] = nullptr;
}

/**
 * Devuelve el nombre de la liga
 *
 * @param
 * @return Nombre de la liga
 */
string League::getNombreLiga() {
    return nombreLiga;
}

/**
 * Establece el nombre de la liga con validación
 *
 * @param nombre Nombre de la liga
 * @return
 */
void League::setNombreLiga(string nombre) {
    if (nombre != "") {
        nombreLiga = nombre;
    } else {
        nombreLiga = "Sin nombre";
    }
}

/**
 * Devuelve el año de la liga
 *
 * @param
 * @return Año de la liga
 */
int League::getAnio() {
    return anio;
}

/**
 * Establece el año de la liga con validación
 *
 * @param a Año de la liga
 * @return
 */
void League::setAnio(int a) {
    if (a >= 0) {
        anio = a;
    } else {
        anio = 0;
    }
}

/**
 * Agrega una conferencia a la liga
 *
 * @param c Puntero a Conference (puede ser EastConference o WestConference)
 * @return
 */
void League::agregarConferencia(Conference* c) {
    if (cantidadConferencias < 2) {
        conferencias[cantidadConferencias] = c;
        cantidadConferencias++;
        cout << "Conferencia agregada correctamente." << endl;
    } else {
        cout << "No se pueden agregar mas conferencias. "
             << "Limite alcanzado (2)." << endl;
    }
}

/**
 * Elimina una conferencia por posición
 *
 * @param posicionConferencia Índice de la conferencia a eliminar
 * @return
 */
void League::eliminarConferencia(int posicionConferencia) {
    if (posicionConferencia >= 0 &&
        posicionConferencia < cantidadConferencias) {
        // liberar memoria de la conferencia eliminada
        delete conferencias[posicionConferencia];
        conferencias[posicionConferencia] = nullptr;
        for (int i = posicionConferencia;
             i < cantidadConferencias - 1; i++) {
            conferencias[i] = conferencias[i + 1];
        }
        conferencias[cantidadConferencias - 1] = nullptr;
        cantidadConferencias--;
        cout << "Conferencia eliminada correctamente." << endl;
    } else {
        cout << "Posicion invalida. No se elimino ninguna conferencia."
             << endl;
    }
}

/**
 * Devuelve una conferencia por posición
 *
 * @param posicionConferencia Índice de la conferencia
 * @return Puntero a Conference o nullptr si la posición es inválida
 */
Conference* League::getConferencia(int posicionConferencia) {
    if (posicionConferencia >= 0 &&
        posicionConferencia < cantidadConferencias) {
        return conferencias[posicionConferencia];
    } else {
        cout << "Posicion invalida. Se devuelve nullptr." << endl;
        return nullptr;
    }
}

/**
 * Devuelve la cantidad de conferencias registradas
 *
 * @param
 * @return Número de conferencias
 */
int League::getCantidadConferencias() {
    return cantidadConferencias;
}

/**
 * Agrega un equipo dentro de una conferencia
 *
 * @param posicionConf Índice de la conferencia
 * @param equipo Objeto Team a agregar
 * @return
 */
void League::agregarEquipoEnConferencia(int posicionConf, Team equipo) {
    if (posicionConf >= 0 && posicionConf < cantidadConferencias) {
        if (conferencias[posicionConf] != nullptr) {
            conferencias[posicionConf]->agregarEquipo(equipo);
        } else {
            cout << "Conferencia nula. No se agrego el equipo." << endl;
        }
    } else {
        cout << "Posicion de conferencia invalida. "
             << "No se agrego el equipo." << endl;
    }
}

/**
 * Elimina un equipo dentro de una conferencia
 *
 * @param posicionConf Índice de la conferencia
 * @param posicionEquipo Índice del equipo
 * @return
 */
void League::eliminarEquipoEnConferencia(int posicionConf,
                                         int posicionEquipo) {
    if (posicionConf >= 0 && posicionConf < cantidadConferencias) {
        if (conferencias[posicionConf] != nullptr) {
            conferencias[posicionConf]->eliminarEquipo(posicionEquipo);
        } else {
            cout << "Conferencia nula. No se elimino el equipo." << endl;
        }
    } else {
        cout << "Posicion de conferencia invalida. "
             << "No se elimino el equipo." << endl;
    }
}

/**
 * Agrega un jugador dentro de un equipo
 *
 * @param posicionConf Índice de la conferencia
 * @param posicionEquipo Índice del equipo
 * @param jugador Objeto Player a agregar
 * @return
 */
void League::agregarJugadorEnEquipo(int posicionConf,
                                    int posicionEquipo,
                                    Player jugador) {
    if (posicionConf >= 0 && posicionConf < cantidadConferencias) {
        if (conferencias[posicionConf] != nullptr) {
            conferencias[posicionConf]->agregarJugadorEnEquipo(posicionEquipo,
                                                              jugador);
        } else {
            cout << "Conferencia nula. No se agrego el jugador." << endl;
        }
    } else {
        cout << "Posicion de conferencia invalida. "
             << "No se agrego el jugador." << endl;
    }
}

/**
 * Elimina un jugador dentro de un equipo
 *
 * @param posicionConf Índice de la conferencia
 * @param posicionEquipo Índice del equipo
 * @param posicionJugador Índice del jugador
 * @return
 */
void League::eliminarJugadorEnEquipo(int posicionConf,
                                     int posicionEquipo,
                                     int posicionJugador) {
    if (posicionConf >= 0 && posicionConf < cantidadConferencias) {
        if (conferencias[posicionConf] != nullptr) {
            conferencias[posicionConf]->eliminarJugadorEnEquipo(posicionEquipo,
                                                               posicionJugador);
        } else {
            cout << "Conferencia nula. No se elimino el jugador." << endl;
        }
    } else {
        cout << "Posicion de conferencia invalida. "
             << "No se elimino el jugador." << endl;
    }
}

/**
 * Devuelve toda la información de la liga en formato string
 *
 * @param
 * @return Cadena con la información completa de la liga
 */
string League::toString() {
    string info = "Liga: " + nombreLiga +
                  " Anio: " + to_string(anio) + "\n";
    if (cantidadConferencias == 0) {
        info += "No hay conferencias registradas.\n";
    } else {
        info += "Conferencias:\n";
        for (int i = 0; i < cantidadConferencias; i++) {
            if (conferencias[i] != nullptr) {
                info += conferencias[i]->toString() + "\n";
            }
        }
    }
    return info;
}

#endif // Cierra la protección contra múltiples inclusiones del archivo

