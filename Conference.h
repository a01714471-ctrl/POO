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
    Team* equipos[15];   // punteros a Team en heap
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
                                const Person& jugador); // recibe Person por referencia
    void eliminarJugadorEnEquipo(int posicionEquipo,
                                 int posicionJugador);

    // Método para mostrar información completa de la conferencia
    virtual string toString() = 0; // ahora abstracta para forzar override

    // Método público para liberar recursos internos antes de borrar la conferencia
    void liberarRecursos();
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
    for (int i = 0; i < 15; ++i) equipos[i] = nullptr;
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
    for (int i = 0; i < 15; ++i) equipos[i] = nullptr;
}

/**
 * Método para liberar recursos internos (equipos)
 * Debe llamarse antes de borrar la conferencia con delete si se usó new.
 */
void Conference::liberarRecursos() {
    for (int i = 0; i < cantidadEquipos; ++i) {
        if (equipos[i] != nullptr) {
            // liberar recursos internos del equipo antes de borrarlo
            equipos[i]->liberarRecursos();
            delete equipos[i];
            equipos[i] = nullptr;
        }
    }
    cantidadEquipos = 0;
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
        // crear copia en heap y almacenar puntero
        equipos[cantidadEquipos] = new Team(t);
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
        // liberar recursos internos del equipo y borrar
        if (equipos[posicionEquipo] != nullptr) {
            equipos[posicionEquipo]->liberarRecursos();
            delete equipos[posicionEquipo];
            equipos[posicionEquipo] = nullptr;
        }
        // Se recorre el arreglo para compactar
        for (int i = posicionEquipo; i < cantidadEquipos - 1; i++) {
            equipos[i] = equipos[i + 1];
        }
        equipos[cantidadEquipos - 1] = nullptr;
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
        if (equipos[posicionEquipo] != nullptr) {
            return *equipos[posicionEquipo]; // devuelve copia por valor
        } else {
            return Team();
        }
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
 * @param jugador Objeto Person (Player o derivado) a agregar
 * @return
 */
void Conference::agregarJugadorEnEquipo(int posicionEquipo,
                                        const Person& jugador) {
    if (posicionEquipo >= 0 && posicionEquipo < cantidadEquipos) {
        if (equipos[posicionEquipo] != nullptr) {
            equipos[posicionEquipo]->agregarJugador(jugador);
        } else {
            cout << "Equipo nulo. No se agrego el jugador." << endl;
        }
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
        if (equipos[posicionEquipo] != nullptr) {
            equipos[posicionEquipo]->eliminarJugador(posicionJugador);
        } else {
            cout << "Equipo nulo. No se elimino el jugador." << endl;
        }
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
    // Implementación base reutilizable aunque la función es abstracta
    string info = "Conferencia: " + nombre +
                  " Region: " + region + "\n";
    if (cantidadEquipos == 0) {
        info += "No hay equipos registrados.\n";
    } else {
        info += "Equipos:\n";
        // Recorre todos los equipos y concatena su información
        for (int i = 0; i < cantidadEquipos; i++) {
            info += equipos[i]->toString() + "\n";
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
class EastConference : public Conference {
private:
    int idConferencia;
    int maxEquipos;
public:
    EastConference();
    EastConference(string n, string r, int id, int max);
    int getIdConferencia();
    void setIdConferencia(int id);
    int getMaxEquipos();
    void setMaxEquipos(int m);
    string toString() override;
};

EastConference::EastConference() : Conference() {
    idConferencia = 0;   // ID por defecto
    maxEquipos = 15;     // Máximo por defecto
}

EastConference::EastConference(string n, string r, int id, int max)
    : Conference(n, r) {
    if (id >= 0) {
        idConferencia = id;
    } else {
        idConferencia = 0;
    }
    if (max > 0) {
        maxEquipos = max;
    } else {
        maxEquipos = 15;
    }
}

int EastConference::getIdConferencia() {
    return idConferencia;
}

void EastConference::setIdConferencia(int id) {
    if (id >= 0) {
        idConferencia = id;
    } else {
        idConferencia = 0;
    }
}

int EastConference::getMaxEquipos() {
    return maxEquipos;
}

void EastConference::setMaxEquipos(int m) {
    if (m > 0) {
        maxEquipos = m;
    } else {
        maxEquipos = 15;
    }
}

string EastConference::toString() {
    string base = Conference::toString();
    return "EastConference: " + nombre + " Region: " + region + "\n" + base;
}

// WestConference

class WestConference : public Conference {
private:
    int idConferencia;
    int maxEquipos;
public:
    WestConference();
    WestConference(string n, string r, int id, int max);
    int getIdConferencia();
    void setIdConferencia(int id);
    int getMaxEquipos();
    void setMaxEquipos(int m);
    string toString() override;
};

WestConference::WestConference() : Conference() {
    idConferencia = 0;   // ID por defecto
    maxEquipos = 15;     // Máximo por defecto
}

WestConference::WestConference(string n, string r, int id, int max)
    : Conference(n, r) {
    if (id >= 0) {
        idConferencia = id;
    } else {
        idConferencia = 0;
    }
    if (max > 0) {
        maxEquipos = max;
    } else {
        maxEquipos = 15;
    }
}

int WestConference::getIdConferencia() {
    return idConferencia;
}

void WestConference::setIdConferencia(int id) {
    if (id >= 0) {
        idConferencia = id;
    } else {
        idConferencia = 0;
    }
}

int WestConference::getMaxEquipos() {
    return maxEquipos;
}

void WestConference::setMaxEquipos(int m) {
    if (m > 0) {
        maxEquipos = m;
    } else {
        maxEquipos = 15;
    }
}

string WestConference::toString() {
    string base = Conference::toString();
    return "WestConference: " + nombre + " Region: " + region + "\n" + base;
}

#endif // Cierra la protección contra múltiples inclusiones del archivo



