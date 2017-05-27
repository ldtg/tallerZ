//
// Created by darius on 25/05/17.
//

#ifndef TALLERZ_GENERATOR_H
#define TALLERZ_GENERATOR_H

/**
 * Generador de mapa
Los mapas pueden ser generados de forma automática a través de una aplicación adicional. Debe recibir por
parámetro
- El tamaño del mapa. -> Unidad: Tiles, cantidad de tiles a lo largo y a lo ancho
- La cantidad de territorios. -> los territorios han de ser mas o menos uniformes en cuanto a tamaño,
 una grilla a lo largo del mapa no estaría mal
- El o los niveles de tecnología de las fábricas que existirán, los tipos (de robots y de vehículos) y la
cantidad.
- Porcentaje de territorios de agua/pantano y lava. Estos deben formar rios.
- Se debe garantizar que todos los fuertes y fábricas de vehículos tengan un camino (por tierra o por
puentes) hacia el resto de los territorios. En otras palabras, un fuerte o fábricas de vehículos no
puede estar en una isla, aislado del resto del mapa.
- Porcentaje de variedad de terrenos.
- Cantidad de vehículos abandonados.

 Planificacion: https://docs.google.com/document/d/1qMFwzIKMDrgpU6Doa4D05HIGJ60ew4fEgWMWcgSogjc/edit

 */
#include <cmath>
#include <exception>
#include <Exceptions/Map_Generator_Exceptions/Generator_Exception.h>
#include <iostream>

struct territory_coords{
  int x;
  int y;
  int territory;
};

struct Delegation{
  int x;
  int y;
  int tiles_left;
};

class Generator {
 public: //Para el test
  const unsigned tile_amount;
  const unsigned territories;
  const unsigned map_length;
  const unsigned map_width;
  unsigned tiles_per_territory;
  unsigned frame; //encuadrado
  territory_coords * map_territories;

 public:
  Generator(const unsigned& width, const unsigned& length, unsigned territories);

  ~Generator();

  /**
   * get_position : extrapola una posición matricial a la de un array
   * @param x : coordenada X
   * @param y : coordenada Y
   * @return : la posicion correspondiente al array lineal que representa
   * la matriz
   */
  unsigned int get_position(unsigned x, unsigned y);

  /**
   * esta_encuadrado: verifica si el tile de posicion x,y se ubica adentro
   * del marco especificado por frame_number
   * @param frame_number : numero de marco (contando desde cero)
   * @param x : posicion X del tile
   * @param y : posicion Y del tile
   * @return : true si la tile pertenece al marco o false en caso contrario
   */
  bool esta_encuadrado(int frame_number, int x, int y);

  /**
   * fill_territory: asigna hasta tile_amount tiles a un territorio.
   * @param territory: territorio en cuestion
   * @param tile_amount: cantidad de tiles deseada para asignar a un territorio
   * @param frame : "marco" o cantidad de filas que componen un marco
   * @param frame_number: numero de marco (contando desde cero)
   * @param x : posicion x de partida
   * @param y : posicion y de partida
   * @return : devuelve 0 en caso de completar un territorio o devuelve
   * un numero entero positivo representando la cantidad de tiles faltantes
   * para completar el numero de tile_amount (tiles por territorio) y también
   * la posicion en la que se tiene que retomar.
   * Esa situación se da cuando se alcanza un borde lateral del mapa.
   */
  Delegation fill_territory(int territory, int tile_amount, int x, int y, int frame_number);

  /**
   * fill_territory_backwards: asigna hasta tile_amount tiles a un territorio
   * en sentido inverso en el marco.
   * @param territory: territorio en cuestion
   * @param tile_amount: cantidad de tiles deseada para asignar a un territorio
   * @param frame_number: numero de marco (contando desde cero)
   * @param x : posicion x de partida
   * @param y : posicion y de partida
   * @return : devuelve 0 en caso de completar un territorio o devuelve
   * un numero entero positivo representando la cantidad de tiles faltantes
   * para completar el numero de tile_amount (tiles por territorio) y también
   * la posicion en la que se tiene que retomar.
   * Esa situación se da cuando se alcanza un borde lateral del mapa.
   */
  Delegation fill_territory_backwards(int territory, int tile_amount, int x, int y, int frame_number);

  /**
   * fill_remnants: etapa final del algoritmo de distribución de territorios
   * los tiles remanentes que quedaron sin asignar a un territorio son asignados
   * al ultimo territorio.
   * @param x : coordenada X de inicio
   * @param y : coordenada Y de inicio
   * @param forwards : si el algoritmo se realiza de izquierda a derecha
   * @param remnants : cantidad de tiles sin asignar
   * @param frame_number : numero de marco
   */
  void fill_remnants(int x, int y, bool forwards, int remnants, int frame_number);

  /**
   * territory_distribution_algorithm
   * En funcion de los parametros de ancho y largo de mapa, así como de la
   * cantidad de territorios a generar, este algoritmo de distribución de
   * territorios se encarga distribuir territorios de manera que estos sean
   * jugables (es decir con una distribución pareja en cuanto a la superficie
   * de los territorios) y no de manera aleatoria (ver documentación).
   */
  void territory_distribution_algorithm();

  /**
   * calculate_tiles_per_territory: calcula el valor discreto de tiles
   * que han de tener uniformemente los territorios.
   */
  void calculate_tiles_per_territory(){
    this->tiles_per_territory = (tile_amount/territories);
  }

  /**
   * calculate_frame (calcular marco): el algoritmo de distribución de
   * territorios internamente procura que los territorios se encuadren
   * en lo que llamamos frames o marcos que son nada más que un conjunto
   * acoplado y determinado de filas (mas detalles en la documentacion).
   * calculate_frame calcula el numero de filas que componen el marco.
   */
  void calculate_frame();
};

#endif //TALLERZ_GENERATOR_H
