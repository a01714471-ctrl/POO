// Evitan que el archivo de encabezado se incluya más de una vez
// durante la compilación, evitando errores por redefiniciones.
#ifndef CONFERENCE_H
#define CONFERENCE_H

#include "Team.h"   // Incluye la clase Team, necesaria para usar equipos

// Clase Conference
// Representa una conferencia dentro de la liga
class Conference {
protected:
    string nombre;
    string region;
    Team equipos[15];
    int cantidadEquipos;
public:
    Conference();                   // Constructor por defecto
    Conference(string n, string r); // Constructor con parámetros: nombre y
                                    // región

    // Métodos getter y setter
    string getNombre();
    void setNombre(string n);
    string getRegion();
    void setRegion(string r);

    // Métodos para manejar equipos
    void agregarEquipo(Team t);
    void eliminarEquipo(int posicionEquipo);
    Team getEquipo(int posicionEquipo);
    int getCantidadEquipos();

    // Métodos para manejar jugadores dentro de equipos
    void agregarJugadorEnEquipo(int posicionEquipo,
                                Player jugador);
    void eliminarJugadorEnEquipo(int posicionEquipo,
                                 int posicionJugador);

    // Método para mostrar información completa de la conferencia
    string toString();
};

// Clase EastConference
// Especialización de Conference para la conferencia del Este
class EastConference : public Conference {
private:
    int idConferencia;
    int maxEquipos;
public:
    EastConference();    // Constructor por defecto
    EastConference(string n, string r, int id,
                   int max); // Constructor con parámetros
    int getIdConferencia();
    void setIdConferencia(int id);
    int getMaxEquipos();
    void setMaxEquipos(int m);
};

// Clase WestConference
// Especialización de Conference para la conferencia del Oeste
class WestConference : public Conference {
private:
    int idConferencia;
    int maxEquipos;
public:
    WestConference();    // Constructor por defecto
    WestConference(string n, string r, int id,
                   int max); // Constructor con parámetros
    int getIdConferencia();
    void setIdConferencia(int id);
    int getMaxEquipos();
    void setMaxEquipos(int m);
};

// IMPLEMENTACIÓN DE MÉTODOS

/**
 * Constructor por defecto
 *
 * @param
 * @return Objeto Conference con nombre "Sin nombre", región "Sin region"
 * y 0 equipos
 */
Conference::Conference() {
    nombre = "Sin nombre";   // Nombre por defecto
    region = "Sin region";   // Región por defecto
    cantidadEquipos = 0;     // No hay equipos al inicio
}

/**
 * Constructor con parámetros
 *
 * @param n Nombre de la conferencia
 * @param r Región de la conferencia
 * @return Objeto Conference inicializado con valores dados y 0 equipos
 */
Conference::Conference(string n, string r) {
    if (n != "") {
        nombre = n;          // Asigna nombre válido
    } else {
        nombre = "Sin nombre"; // Valor por defecto
    }

    if (r != "") {
        region = r;          // Asigna región válida
    } else {
        region = "Sin region"; // Valor por defecto
    }

    cantidadEquipos = 0;     // Al inicio no hay equipos
}

/**
 * Devuelve el nombre de la conferencia
 *
 * @param
 * @return Nombre de la conferencia
 */
string Conference::getNombre() {
    return nombre;
}

/**
 * Establece el nombre de la conferencia con validación
 *
 * @param n Nombre de la conferencia
 * @return
 */
void Conference::setNombre(string n) {
    if (n != "") {
        nombre = n;
    } else {
        nombre = "Sin nombre"; // Valor por defecto
    }
}

/**
 * Devuelve la región de la conferencia
 *
 * @param
 * @return Región de la conferencia
 */
string Conference::getRegion() {
    return region;
}

/**
 * Establece la región de la conferencia con validación
 *
 * @param r Región de la conferencia
 * @return
 */
void Conference::setRegion(string r) {
    if (r != "") {
        region = r;
    } else {
        region = "Sin region"; // Valor por defecto
    }
}

/**
 * Agrega un equipo a la conferencia
 *
 * @param t Objeto Team a agregar
 * @return
 */
void Conference::agregarEquipo(Team t) {
    if (cantidadEquipos < 15) { // Máximo 15 equipos
        equipos[cantidadEquipos] = t; // Se guarda en el arreglo
        cantidadEquipos++;            // Se incrementa el contador
        cout << "Equipo agregado correctamente." << endl;
    } else {
        cout << "No se pueden agregar mas equipos. "
             << "Limite alcanzado (15)." << endl;
    }
}

/**
 * Elimina un equipo por posición
 *
 * @param posicionEquipo Índice del equipo a eliminar
 * @return
 */
void Conference::eliminarEquipo(int posicionEquipo) {
    if (posicionEquipo >= 0 && posicionEquipo < cantidadEquipos) {
        // Se recorre el arreglo para compactar
        for (int i = posicionEquipo; i < cantidadEquipos - 1; i++) {
            equipos[i] = equipos[i + 1];
        }
        cantidadEquipos--; // Se reduce el contador
        cout << "Equipo eliminado correctamente." << endl;
    } else {
        cout << "Posicion invalida. No se elimino ningun equipo." << endl;
    }
}

/**
 * Devuelve un equipo por posición
 *
 * @param posicionEquipo Índice del equipo
 * @return Objeto Team válido o vacío si la posición es inválida
 */
Team Conference::getEquipo(int posicionEquipo) {
    if (posicionEquipo >= 0 && posicionEquipo < cantidadEquipos) {
        return equipos[posicionEquipo]; // Devuelve equipo válido
    } else {
        cout << "Posicion invalida. Se devuelve un equipo vacio."
             << endl;
        return Team(); // Devuelve equipo vacío si posición inválida
    }
}

/**
 * Devuelve la cantidad de equipos registrados
 *
 * @param
 * @return Número de equipos en la conferencia
 */
int Conference::getCantidadEquipos() {
    return cantidadEquipos;
}

/**
 * Agrega un jugador dentro de un equipo
 *
 * @param posicionEquipo Índice del equipo
 * @param jugador Objeto Player a agregar
 * @return
 */
void Conference::agregarJugadorEnEquipo(int posicionEquipo,
                                        Player jugador) {
    if (posicionEquipo >= 0 && posicionEquipo < cantidadEquipos) {
        equipos[posicionEquipo].agregarJugador(jugador);
    } else {
        cout << "Posicion de equipo invalida. "
             << "No se agrego el jugador." << endl;
    }
}

/**
 * Elimina un jugador dentro de un equipo
 *
 * @param posicionEquipo Índice del equipo
 * @param posicionJugador Índice del jugador
 * @return
 */
void Conference::eliminarJugadorEnEquipo(int posicionEquipo,
                                         int posicionJugador) {
    if (posicionEquipo >= 0 && posicionEquipo < cantidadEquipos) {
        equipos[posicionEquipo].eliminarJugador(posicionJugador);
    } else {
        cout << "Posicion de equipo invalida. "
             << "No se elimino el jugador." << endl;
    }
}

/**
 * Devuelve toda la información de la conferencia en formato string
 *
 * @param
 * @return Cadena con nombre, región y los equipos registrados
 */
string Conference::toString() {
    string info = "Conferencia: " + nombre +
                  " Region: " + region + "\n";
    if (cantidadEquipos == 0) {
        info += "No hay equipos registrados.\n";
    } else {
        info += "Equipos:\n";
        // Recorre todos los equipos y concatena su información
        for (int i = 0; i < cantidadEquipos; i++) {
            info += equipos[i].toString() + "\n";
        }
    }
    return info; // Devuelve la información completa de la conferencia
}

// EastConference

/**
 * Constructor por defecto
 *
 * @param
 * @return Objeto EastConference con ID 0 y máximo 15 equipos
 */
EastConference::EastConference() : Conference() {
    idConferencia = 0;   // ID por defecto
    maxEquipos = 15;     // Máximo por defecto
}

/**
 * Constructor con parámetros
 *
 * @param n Nombre de la conferencia
 * @param r Región de la conferencia
 * @param id Identificador único
 * @param max Máximo de equipos permitidos
 * @return Objeto EastConference inicializado con valores dados
 */
EastConference::EastConference(string n, string r, int id, int max)
    : Conference(n, r) {
    idConferencia = (id >= 0) ? id : 0;     // Asigna ID recibido (>=0) o 0
    maxEquipos   = (max > 0) ? max : 15;    // Asigna máximo (>0) o 15
}

/**
 * Devuelve el ID de la conferencia
 *
 * @param
 * @return ID de la conferencia
 */
int EastConference::getIdConferencia() {
    return idConferencia;
}

/**
 * Establece el ID de la conferencia con validación
 *
 * @param id Identificador único
 * @return
 */
void EastConference::setIdConferencia(int id) {
    idConferencia = (id >= 0) ? id : 0;
}

/**
 * Devuelve el máximo de equipos permitidos
 *
 * @param
 * @return Máximo de equipos
 */
int EastConference::getMaxEquipos() {
    return maxEquipos;
}

/**
 * Establece el máximo de equipos permitidos con validación
 *
 * @param m Máximo de equipos
 * @return
 */
void EastConference::setMaxEquipos(int m) {
    maxEquipos = (m > 0) ? m : 15;
}

// WestConference

/**
 * Constructor por defecto
 *
 * @param
 * @return Objeto WestConference con ID 0 y máximo 15 equipos
 */
WestConference::WestConference() : Conference() {
    idConferencia = 0;   // ID por defecto
    maxEquipos = 15;     // Máximo por defecto
}

/**
 * Constructor con parámetros
 *
 * @param n Nombre de la conferencia
 * @param r Región de la conferencia
 * @param id Identificador único
 * @param max Máximo de equipos permitidos
 * @return Objeto WestConference inicializado con valores dados
 */
WestConference::WestConference(string n, string r, int id, int max)
    : Conference(n, r) {
    idConferencia = (id >= 0) ? id : 0;     // Asigna ID recibido (>=0) o 0
    maxEquipos   = (max > 0) ? max : 15;    // Asigna máximo (>0) o 15
}

/**
 * Devuelve el ID de la conferencia
 *
 * @param
 * @return ID de la conferencia
 */
int WestConference::getIdConferencia() {
    return idConferencia;
}

/**
 * Establece el ID de la conferencia con validación
 *
 * @param id Identificador único
 * @return
 */
void WestConference::setIdConferencia(int id) {
    idConferencia = (id >= 0) ? id : 0;
}

/**
 * Devuelve el máximo de equipos permitidos
 *
 * @param
 * @return Máximo de equipos
 */
int WestConference::getMaxEquipos() {
    return maxEquipos;
}

/**
 * Establece el máximo de equipos permitidos con validación
 *
 * @param m Máximo de equipos
 * @return
 */
void WestConference::setMaxEquipos(int m) {
    maxEquipos = (m > 0) ? m : 15;
}

#endif // Cierra la protección contra múltiples inclusiones del archivo
