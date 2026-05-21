// Librería estándar para entrada/salida (cin, cout)
#include <iostream>
// Librería para hacer uso de strings
#include <string>
// Incluye la clase League y sus dependencias
#include "League.h"

// Permite usar cout, cin, string sin prefijo std::
using namespace std;

int main() {
    // Se crea una liga llamada "NBA" del año 2025
    League liga("NBA", 2025);

    // Control del menú principal; se repetirá hasta ser 9 (Salir)
    int opcion = 0;

    // Bucle principal: muestra menú y procesa opciones hasta que el usuario salga
    while (opcion != 9) {
        // Impresión del menú principal para el usuario
        cout << "\nMENU PRINCIPAL\n";
        cout << "1. Agregar conferencia\n";
        cout << "2. Agregar equipo a conferencia\n";
        cout << "3. Agregar jugador a equipo\n";
        cout << "4. Mostrar liga completa\n";
        cout << "5. Mostrar conferencia\n";
        cout << "6. Mostrar equipo\n";
        cout << "7. Eliminar conferencia\n";
        cout << "8. Eliminar equipo/jugador\n";
        cout << "9. Salir\n";
        cout << "Selecciona una opcion (1-9): ";
        cin >> opcion;
        while (opcion < 1 || opcion > 9) {
            cout << "Opcion invalida. Intenta de nuevo (1-9): ";
            cin >> opcion;
        }

        // OPCIÓN 1: Agregar conferencia
        if (opcion == 1) {
            string nombre, region;
            int tipo;

            cout << "\nAgregar Conferencia\n";
            cout << "Introduce el nombre de la conferencia (ejemplo: "
                    "Conferencia1, Conferencia2): ";
            cin >> nombre;
            while (nombre == "") {
                cout << "Opcion invalida. Introduce un nombre valido: ";
                cin >> nombre;
            }
            cout << "Introduce la region (ejemplo: Norte, Sur): ";
            cin >> region;
            while (region == "") {
                cout << "Opcion invalida. Introduce una region valida: ";
                cin >> region;
            }
            cout << "Introduce el tipo (1 = Este, 2 = Oeste): ";
            cin >> tipo;
            while (tipo != 1 && tipo != 2) {
                cout << "Opcion invalida. Introduce 1 (Este) o 2 (Oeste): ";
                cin >> tipo;
            }

            // Creación de un objeto según el tipo indicado (Este u Oeste)
            if (tipo == 1) {
                EastConference conf(nombre, region, 1, 15);
                liga.agregarConferencia(conf);
            } else {
                WestConference conf(nombre, region, 2, 15);
                liga.agregarConferencia(conf);
            }
        }

        // OPCIÓN 2: Agregar equipo
        else if (opcion == 2) {
            // Validación: requiere al menos una conferencia creada
            if (liga.getCantidadConferencias() == 0) {
                cout << "Primero debes agregar una conferencia.\n";
            } else {
                int posConf;
                cout << "\nAgregar Equipo\n";
                cout << "Selecciona conferencia (0-"
                     << liga.getCantidadConferencias() - 1 << "): ";
                cin >> posConf;
                while (posConf < 0 || posConf >= liga.getCantidadConferencias()) {
                    cout << "Opcion invalida. Selecciona conferencia (0-"
                         << liga.getCantidadConferencias() - 1 << "): ";
                    cin >> posConf;
                }

                // Datos básicos del equipo
                string nombreEquipo, ciudad;
                cout << "Introduce el nombre del equipo (ejemplo: Lakers, Bulls): ";
                cin >> nombreEquipo;
                while (nombreEquipo == "") {
                    cout << "Opcion invalida. Introduce un nombre valido: ";
                    cin >> nombreEquipo;
                }
                cout << "Introduce la ciudad (ejemplo: LosAngeles, Chicago): ";
                cin >> ciudad;
                while (ciudad == "") {
                    cout << "Opcion invalida. Introduce una ciudad valida: ";
                    cin >> ciudad;
                }

                // Datos del entrenador del equipo
                string nombreCoach, especialidad;
                int edadCoach, experiencia;
                cout << "Introduce el nombre del entrenador: ";
                cin >> nombreCoach;
                while (nombreCoach == "") {
                    cout << "Opcion invalida. Introduce un nombre valido: ";
                    cin >> nombreCoach;
                }
                cout << "Introduce la edad del entrenador: ";
                cin >> edadCoach;
                while (edadCoach <= 0) {
                    cout << "Opcion invalida. Introduce una edad valida (>0): ";
                    cin >> edadCoach;
                }
                cout << "Introduce los años de experiencia del entrenador: ";
                cin >> experiencia;
                while (experiencia < 0) {
                    cout << "Opcion invalida. Introduce experiencia valida (>=0): ";
                    cin >> experiencia;
                }
                cout << "Introduce la especialidad del entrenador (ejemplo: "
                        "Ofensiva, Defensiva): ";
                cin >> especialidad;
                while (especialidad == "") {
                    cout << "Opcion invalida. Introduce una especialidad valida: ";
                    cin >> especialidad;
                }
                Coach coach(nombreCoach, edadCoach, experiencia, especialidad);


                // Datos del balón del equipo
                string marcaBalon;
                float tamanoBalon;
                cout << "Introduce la marca del balon (ejemplo: Spalding): ";
                cin >> marcaBalon;
                while (marcaBalon == "") {
                    cout << "Opcion invalida. Introduce una marca valida: ";
                    cin >> marcaBalon;
                }
                cout << "Introduce el tamaño del balon (ejemplo: 7.5): ";
                cin >> tamanoBalon;
                while (tamanoBalon <= 0) {
                    cout << "Opcion invalida. Introduce un tamaño valido (>0): ";
                    cin >> tamanoBalon;
                }
                Ball balon(marcaBalon, tamanoBalon);

                // Se instancia el equipo con nombre, ciudad, coach y balón
                Team equipo(nombreEquipo, ciudad, coach, balon);

                // Se agrega el equipo a la conferencia seleccionada
                liga.agregarEquipoEnConferencia(posConf, equipo);
            }
        }

        // OPCIÓN 3: Agregar jugador
        else if (opcion == 3) {
            // Validación: requiere al menos una conferencia creada
            if (liga.getCantidadConferencias() == 0) {
                cout << "Primero debes agregar una conferencia.\n";
            } else {
                int posConf;
                cout << "\nAgregar Jugador\n";
                cout << "Selecciona conferencia (0-"
                     << liga.getCantidadConferencias() - 1 << "): ";
                cin >> posConf;
                while (posConf < 0 || posConf >= liga.getCantidadConferencias()) {
                    cout << "Opcion invalida. Selecciona conferencia (0-"
                         << liga.getCantidadConferencias() - 1 << "): ";
                    cin >> posConf;
                }

                // Validación: la conferencia debe tener equipos
                if (liga.getConferencia(posConf).getCantidadEquipos() == 0) {
                    cout << "Primero debes agregar un equipo.\n";
                } else {
                    int posEquipo;
                    cout << "Selecciona equipo (0-"
                         << liga.getConferencia(posConf).getCantidadEquipos() - 1
                         << "): ";
                    cin >> posEquipo;
                    while (posEquipo < 0 ||
                           posEquipo >= liga.getConferencia(posConf).getCantidadEquipos()) {
                        cout << "Opcion invalida. Selecciona equipo (0-"
                             << liga.getConferencia(posConf).getCantidadEquipos() - 1
                             << "): ";
                        cin >> posEquipo;
                    }

                    // Datos del jugador a agregar al equipo
                    string nombre, posicion;
                    int edad, numero;
                    cout << "Introduce el nombre del jugador (ejemplo: Jordan, "
                            "LeBron): ";
                    cin >> nombre;
                    while (nombre == "") {
                        cout << "Opcion invalida. Introduce un nombre valido: ";
                        cin >> nombre;
                    }
                    cout << "Introduce la edad del jugador (ejemplo: 25): ";
                    cin >> edad;
                    while (edad <= 0) {
                        cout << "Opcion invalida. Introduce una edad valida (>0): ";
                        cin >> edad;
                    }
                    cout << "Introduce la posicion (ejemplo: Base, Alero, Pivot): ";
                    cin >> posicion;
                    while (posicion == "") {
                        cout << "Opcion invalida. Introduce una posicion valida: ";
                        cin >> posicion;
                    }
                    cout << "Introduce el numero de camiseta (ejemplo: 23): ";
                    cin >> numero;
                    while (numero <= 0) {
                        cout << "Opcion invalida. Introduce un numero valido (>0): ";
                        cin >> numero;
                    }

                    // Se crea el objeto Player con los datos y se agrega al equipo
                    Player jugador(nombre, edad, posicion, numero);
                    liga.agregarJugadorEnEquipo(posConf, posEquipo, jugador);
                }
            }
        }

        // OPCIÓN 4: Mostrar liga completa
        else if (opcion == 4) {
            cout << "\nMostrar Liga\n";
            cout << liga.toString() << endl;
        }

        // OPCIÓN 5: Mostrar conferencia
        else if (opcion == 5) {
            if (liga.getCantidadConferencias() == 0) {
                cout << "No hay conferencias registradas.\n";
            } else {
                int posConf;
                cout << "\nMostrar Conferencia\n";
                cout << "Selecciona conferencia (0-"
                     << liga.getCantidadConferencias() - 1 << "): ";
                cin >> posConf;
                while (posConf < 0 ||
                       posConf >= liga.getCantidadConferencias()) {
                    cout << "Opcion invalida. Selecciona conferencia (0-"
                         << liga.getCantidadConferencias() - 1 << "): ";
                    cin >> posConf;
                }
                cout << liga.getConferencia(posConf).toString() << endl;
                // Impresión de la conferencia seleccionada
            }
        }

        // OPCIÓN 6: Mostrar equipo
        else if (opcion == 6) {
            if (liga.getCantidadConferencias() == 0) {
                cout << "No hay conferencias registradas.\n";
            } else {
                int posConf;
                cout << "Selecciona conferencia (0-"
                     << liga.getCantidadConferencias() - 1 << "): ";
                cin >> posConf;
                while (posConf < 0 ||
                       posConf >= liga.getCantidadConferencias()) {
                    cout << "Opcion invalida. Selecciona conferencia (0-"
                         << liga.getCantidadConferencias() - 1 << "): ";
                    cin >> posConf;
                }

                if (liga.getConferencia(posConf).getCantidadEquipos() == 0) {
                    cout << "No hay equipos en esta conferencia.\n";
                } else {
                    int posEquipo;
                    cout << "Selecciona equipo (0-"
                         << liga.getConferencia(posConf).getCantidadEquipos() - 1
                         << "): ";
                    cin >> posEquipo;
                    while (posEquipo < 0 ||
                           posEquipo >= liga.getConferencia(posConf).getCantidadEquipos()) {
                        cout << "Opcion invalida. Selecciona equipo (0-"
                             << liga.getConferencia(posConf).getCantidadEquipos() - 1
                             << "): ";
                        cin >> posEquipo;
                    }
                    cout << liga.getConferencia(posConf)
                                   .getEquipo(posEquipo).toString()
                         << endl;
                }
            }
        }


        // OPCIÓN 7: Eliminar conferencia
        else if (opcion == 7) {
            int cantidad = liga.getCantidadConferencias();
            if (cantidad == 0) {
                cout << "No hay conferencias para eliminar.\n";
            } else {
                int posConf;
                cout << "\nEliminar Conferencia\n";
                cout << "Selecciona conferencia (0-" << cantidad - 1 << "): ";
                cin >> posConf;
                while (posConf < 0 || posConf >= cantidad) {
                    cout << "Opcion invalida. Selecciona conferencia (0-"
                         << cantidad - 1 << "): ";
                    cin >> posConf;
                }
                liga.eliminarConferencia(posConf);
            }
        }

                // OPCIÓN 8: Eliminar equipo o jugador
        else if (opcion == 8) {
            if (liga.getCantidadConferencias() == 0) {
                cout << "No hay conferencias registradas.\n";
            } else {
                int subopcion;
                cout << "\nEliminar\n";
                cout << "1. Eliminar equipo\n";
                cout << "2. Eliminar jugador\n";
                cout << "Selecciona: ";
                cin >> subopcion;
                while (subopcion != 1 && subopcion != 2) {
                    cout << "Opcion invalida. Selecciona 1 (equipo) o 2 (jugador): ";
                    cin >> subopcion;
                }

                // Rama para eliminar un equipo completo dentro de una conferencia
                if (subopcion == 1) {
                    int posConf;
                    cout << "Selecciona conferencia (0-"
                         << liga.getCantidadConferencias() - 1 << "): ";
                    cin >> posConf;
                    while (posConf < 0 ||
                           posConf >= liga.getCantidadConferencias()) {
                        cout << "Opcion invalida. Selecciona conferencia (0-"
                             << liga.getCantidadConferencias() - 1 << "): ";
                        cin >> posConf;
                    }

                    if (liga.getConferencia(posConf).getCantidadEquipos() == 0) {
                        cout << "No hay equipos en esta conferencia.\n";
                    } else {
                        int posEquipo;
                        cout << "Selecciona equipo (0-"
                             << liga.getConferencia(posConf).getCantidadEquipos() - 1
                             << "): ";
                        cin >> posEquipo;
                        while (posEquipo < 0 ||
                               posEquipo >= liga.getConferencia(posConf)
                                                 .getCantidadEquipos()) {
                            cout << "Opcion invalida. Selecciona equipo (0-"
                                 << liga.getConferencia(posConf).getCantidadEquipos() - 1
                                 << "): ";
                            cin >> posEquipo;
                        }
                        liga.eliminarEquipoEnConferencia(posConf, posEquipo);
                    }
                } else {
                    // Rama para eliminar un jugador específico de un equipo
                    int posConf;
                    cout << "Selecciona conferencia (0-"
                         << liga.getCantidadConferencias() - 1 << "): ";
                    cin >> posConf;
                    while (posConf < 0 ||
                           posConf >= liga.getCantidadConferencias()) {
                        cout << "Opcion invalida. Selecciona conferencia (0-"
                             << liga.getCantidadConferencias() - 1 << "): ";
                        cin >> posConf;
                    }

                    if (liga.getConferencia(posConf).getCantidadEquipos() == 0) {
                        cout << "No hay equipos en esta conferencia.\n";
                    } else {
                        int posEquipo;
                        cout << "Selecciona equipo (0-"
                             << liga.getConferencia(posConf).getCantidadEquipos() - 1
                             << "): ";
                        cin >> posEquipo;
                        while (posEquipo < 0 ||
                               posEquipo >= liga.getConferencia(posConf)
                                                 .getCantidadEquipos()) {
                            cout << "Opcion invalida. Selecciona equipo (0-"
                                 << liga.getConferencia(posConf).getCantidadEquipos() - 1
                                 << "): ";
                            cin >> posEquipo;
                        }

                        if (liga.getConferencia(posConf)
                                .getEquipo(posEquipo).getCantidadJugadores() == 0) {
                            cout << "No hay jugadores en este equipo.\n";
                        } else {
                            int posJugador;
                            cout << "Selecciona jugador (0-"
                                 << liga.getConferencia(posConf)
                                        .getEquipo(posEquipo)
                                        .getCantidadJugadores() - 1 << "): ";
                            cin >> posJugador;
                            while (posJugador < 0 ||
                                   posJugador >= liga.getConferencia(posConf)
                                                      .getEquipo(posEquipo)
                                                      .getCantidadJugadores()) {
                                cout << "Opcion invalida. Selecciona jugador (0-"
                                     << liga.getConferencia(posConf)
                                            .getEquipo(posEquipo)
                                            .getCantidadJugadores() - 1 << "): ";
                                cin >> posJugador;
                            }
                            liga.eliminarJugadorEnEquipo(posConf, posEquipo, posJugador);
                        }
                    }
                }
            }
        }


        // OPCIÓN 9: Salir
        else if (opcion == 9) {
            cout << "Saliendo del programa\n";
            // El while terminará en la siguiente evaluación (opcion == 9)
        }

        // Opción inválida
        else {
            cout << "Opcion invalida.\n";
            // Se continúa el bucle para volver a mostrar el menú
        }
    } // Fin del while(opcion != 9)

    // Terminación normal del programa
    return 0;
} // Fin de main()
