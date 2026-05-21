# Proyecto programación orientada a objetos

## Liga de Basketball en c++
Este proyecto consiste en el desarrollo de un sistema de gestión de una liga de basketball utilizando Programación Orientada a Objetos en C++. El sistema fue diseñado a partir de un diagrama de clases UML que representa la estructura de una liga deportiva real, incluyendo conferencias, equipos, jugadores, entrenadores y balones.

El objetivo principal del proyecto es aplicar conceptos de POO como herencia, encapsulamiento y agregación, además de modelar correctamente un problema real mediante clases y relaciones entre objetos.

##  ¿Para qué sirve?
- Simula una liga de baloncesto con conferencias (Este y Oeste), equipos y jugadores.
- Permite crear conferencias con nombre, región y tipo (Este/Oeste).
- Permite agregar equipos con ciudad, entrenador y balón asociado.
- Permite agregar jugadores con nombre, edad, posición y número de camiseta.
- Ofrece menús interactivos para mostrar la liga completa, una conferencia o un equipo específico.
- Permite eliminar conferencias, equipos o jugadores de forma controlada.
- Incluye validaciones de entrada para evitar datos vacíos, negativos o índices inválidos.

##  ¿Para qué no sirve?
- No simula partidos ni calcula estadísticas deportivas.
- No guarda datos en archivos ni en bases de datos (la información se pierde al cerrar el programa).
- No tiene interfaz gráfica: funciona únicamente en consola.
- No está diseñado para uso profesional en gestión de ligas deportivas, solo como proyecto académico.

## Cómo se usa
1. Compilar el proyecto con un compilador C++.  
2. Ejecutar el programa.  
3. Usar el menú principal para:
   - Agregar conferencias (máximo 2).  
   - Agregar equipos a una conferencia (máximo 15 por conferencia).  
   - Agregar jugadores a un equipo (máximo 10 por equipo).  
   - Mostrar información de la liga, conferencias o equipos.  
   - Eliminar conferencias, equipos o jugadores según sea necesario.  
4. Salir con la opción 9.

## Identificación de clases
Para resolver el problema se identificaron las siguientes clases principales:
1. League administra toda la liga y las conferencias.
2. Conference representa una conferencia que contiene equipos.
3. EastConference y WestConference especializaciones de Conference.
4. Team representa un equipo de basketball.
5. Person clase base para personas dentro del sistema.
6. Player representa a un jugador.
7. Coach representa a un entrenador.
8. Ball representa el balón utilizado por un equipo.

Estas clases fueron seleccionadas porque representan directamente los elementos necesarios para modelar una liga deportiva y permiten dividir correctamente las responsabilidades del sistema.

## Relación entre el UML y el problema
El diagrama UML representa cómo interactúan los distintos elementos de una liga de basketball real.

La clase League contiene conferencias, ya que una liga puede estar formada por varias conferencias. A su vez, cada Conference administra distintos equipos (Team).

Cada equipo cuenta con lo siguiente, varios jugadores, un entrenador y un balón.

La herencia entre Person, Player y Coach permite reutilizar atributos comunes como nombre y edad. Además, las clases EastConference y WestConference permiten especializar las conferencias dependiendo de la región.

Gracias a esta estructura, el diagrama UML se relaciona directamente con el problema planteado y facilita la organización del sistema de manera clara y modular.

## Casos que podrían hacer fallar el proyecto
Durante el desarrollo se identificaron algunos casos que podrían provocar errores o un funcionamiento incorrecto del sistema.
1. Intentar agregar más jugadores de los permitidos en un equipo.
2. Intentar agregar más equipos de los permitidos en una conferencia.
3. Eliminar posiciones inexistentes dentro de arreglos.
4. Acceder a jugadores o equipos que no existen.
5. No validar correctamente índices o posiciones.
6. Sobrescribir objetos dentro de arreglos estáticos.
7. Problemas de memoria si se implementa manejo dinámico incorrectamente.

Para evitar estos problemas se deben implementar validaciones en cada método que agregue, elimine o modifique información.

## Ejecución del programa
Para compilar y ejecutar el programa desde la terminal, siga estos pasos:
1. Ubíquese en la carpeta donde se encuentra main.cpp junto con todos los archivos .h.
2. Posteriormente, ejecute el siguiente comando:
  g++ main.cpp -o programa
  Esto genera el archivo ejecutable programa.exe.
3. Ejecución
   Ejecute el siguiente comando:
   .\programa.exe

## Diagrama de clases
Para visualizar el diagrama de clases, da clic aquí:
[Diagrama de clases](./Diagrama%20de%20clases.pdf)
