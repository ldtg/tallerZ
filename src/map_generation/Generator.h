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
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <random>
#include <server/model/Position.h>
#include <server/model/MapType.h>
#include <server/model/TerrainType.h>
#include <server/model/BuildType.h>
#include <server/model/TerrainObjectType.h>

/**@struct Delegation: utilizado unicamente en el algoritmo de distribucion de
 * territorios. */
struct Delegation{
  int x;
  int y;
  int tiles_left;
};

/**
 * @struct Position_Data: guarda toda la informacion de lo que tiene
 * el mapa en las coordenadas X e Y
 */
struct Position_Data{
  bool flag;
  bool fort;
  bool robot_factory;
  bool rock;
  bool bridge;
  TerrainType terrain_type;
  int territory;
  bool vehicle;
  bool vehicle_factory;
  int x;
  int y;
};

class Store_map;

class Generator {
  friend class Store_map;
 public: //Para el test
  MAP_TYPE map_type;
  TerrainType base_terrain;
  TerrainType river_type;
  TerrainObjectType rock_type;
  TerrainType road_type;
  TerrainType bridge_type;

  const unsigned tile_amount;
  const unsigned territories;
  const unsigned map_length;
  const unsigned map_width;
  const unsigned players;
  unsigned tiles_per_territory;
  unsigned frame; //encuadrado
  Position_Data * map_positions;
  std::vector<Position_Data> vertices;

  int partial_lava_water_percentage = 80;
  int total_lava_water_percentage = 10;
  int partial_rock_percentage = 80;
  int total_rock_percentage = 10;

  int abandoned_vehicles_amount;
  int max_units = 150;
  int factories_level;

 public:
  Generator(const unsigned& width
      , const unsigned& length
      , unsigned territories
      , const unsigned& players
      , MAP_TYPE map_type, int vehicles, int factories_level);

  ~Generator();

  /**
   * set_max_units: modifica el parametro que indica la cantidad
   * de unidades maximas posibles en el mapa.
   * @param max_units
   */
  void set_max_units(int max_units);
  /**
   * set_geography
   * En funcion del tipo de mapa setea el tipo de terreno y el tipo de rio
   * por defecto: tierra, pradera o nieve.
   */
  void set_geography();

  /**
   * calc_distance: calcula la distancia manhattan que hay entre dos vertices
   * @param v1 : vertice 1
   * @param v2 : vertice 2
   * @return : distancia entre los vértices
   */
  unsigned int
  calc_distance(const Position_Data& v1, const Position_Data& v2) const;

  /**
   * Dibuja una ruta entre dos vertices (fuertes o fabricas)
   * @param start : posicion de incio del trazado
   * @param end : posicion final del trazado
   * @param terrain_type : tipo de terreno (ruta, agua, lava...)
   * @return cantidad de tiles marcadas de determinado terreno.
   */
  int draw_line(const Position_Data &start, const Position_Data &end,
                TerrainType terrain_type);
  /**
   * trace_paths: determina y dibuja rutas en el mapa
   */
  void trace_paths();
  /**
   * set_water_lava_percentages
   * La cantidad de agua o lava en un territorio se calcula segun un
   * porcentaje (parcial) sobre otro porcentaje (absoluto representando el
   * maximo porcentaje posible de tiles de agua o lava por mapa)
   * @param total_percentage
   * @param partial_percentage
   */
  void
  set_water_lava_percentages(int total_percentage, int partial_percentage);
  /**
   * set_rocks_percentages
   * La cantidad de roca o hielo en un territorio se calcula segun un
   * porcentaje (parcial) sobre otro porcentaje (absoluto representando el
   * maximo porcentaje posible de tiles con roca o hielo por mapa)
   * @param total_percentage
   * @param partial_percentage
   */
  void set_rocks_percentages(int total_percentage, int partial_percentage);
  /**
   * calc_tile_amount: calcula la cantidad de tiles que pueden ser de agua,
   * lava, roca o hielo a distribuir por el mapa. Se calcula un
   * porcentaje (parcial) sobre otro porcentaje (absoluto representando el
   * maximo porcentaje posible de tiles de agua, lava o roca/hielo por mapa)
   * @param total_percentage
   * @param partial_percentage
   * @return cantidad total de tiles de agua, lava, roca o hielo a distribuir
   * por el mapa
   */
  int
  calc_tile_amount(int total_percentage, int partial_percentage);
  /**
   * trace_rivers
   * Dibuja rios de agua o de lava.
   */
  void trace_rivers();
  /**
   * may_overlap_road
   * Los caminos se dibujan antes de los rios. Este metodo previene que un rio
   * se acople sobre un camino ya dibujado.
   * @param start : posicion de inicio del rio candidato
   * @param end : posicion final del rio candidato
   * @return : true si las coordenadas de start y end se ubican sobre la misma
   * fila o columna de alguno de los vertices (edificios).
   */
  bool may_overlap_road(const Position_Data& start, const Position_Data& end) const;
  /**
   * set_terrain: indica el tipo de terreno de la posicion x y.
   * Si se tiene que colocar agua o lava sobre un terreno que
   * previamente tenia configurado que debia ser camino, se coloca un puente.
   * @param x : coordenada X
   * @param y : coordenada Y
   * @param terrain_type
   */
  void set_terrain(int x, int y, TerrainType terrain_type);

  /**
   * can_put_rock_on_position: verifica si no hay nada que obstaculice la
   * colocacion de una roca o hielo.
   * @param position :posicion candidata
   * @return : true si se puede colocar una roca ahi o false en caso contrario
   */
  bool can_put_rock_or_vehicle_on_position(const Position_Data &position);

  /**
   * put_rocks: coloca rocas (o hielo) por el mapa hasta alcanzar una cierta
   * cantidad determinada por los porcentajes totales y parciales indicados
   * como atributos.
   */
  void put_rocks();

  /**
   * put_vehicles
   * distribuye aleatoriamente los vehiculos por el mapa en donde se pueda.
   */
  void put_vehicles();
  /**
   * put_building_random_in_territory
   * Posiciona fabricas y fuertes en una posicion aleatoria adentro del
   * territorio pasado por parametro. Además la bandera de un territorio
   * se posiciona de forma aleatoria alrededor de la fabrica.
   * @param territory : territorio sobre el que posicionar el edificio
   * @param building : fuerte o fabrica
   */
  void put_building_random_in_territory(const unsigned& territory, BuildType building);

  /**
   * belongs_to_territory
   * @param pos : posicion a analizar
   * @param territory : territorio al que deberia pertenecer la posicion
   * @return : devuelve si la posicion pertenece al territorio pasado por
   * parametro.
   */
  bool belongs_to_territory(const Position& pos, const unsigned& territory);

  /**
   * belongs_to_map: determina si una posicion esta adentro o no del mapa
   * @param pos : posicion a analizar
   * @return : si pertenece o no al mapa la posicion.
   */
  bool belongs_to_map(const Position& pos);

  /**
   * can_put_flag_on_position: verifica que la posicion no este afuera del mapa
   * ni que la posicion pertenezca a un territorio distinto
   * @param pos : posicion candidata a tener la bandera
   * @param territory : territorio de la bandera
   * @return : true si puede y false si no.
   */
  bool can_put_flag_on_position(const Position& pos, const unsigned& territory);

  /**
   * put_flag_around_factory: posiciona una bandera en una de las posiciones
   * vecinas (pertenecientes al mismo territorio) a una fabrica
   * @param position : posicion de la fabrica
   * @param territory : numero de territorio.
   */
  void put_flag_around_factory(Position_Data& position, const unsigned& territory);

  /**
   * building_distribution_algorithm
   * Distribuye fuertes y fabricas por los territorios.
   * En donde hay fabricas se posiciona una bandera al lado.
   */
  void building_distribution_algorithm();

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
   * building_is_not_in_border
   * @param x : posicion x
   * @param y : posicion y
   * @return : si el edificio se situa o no en un borde del mapa
   */
  bool building_is_not_in_border(int x, int y);
  /****PRIVATE****/
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
   * calculate_tiles_per_territory: calcula el valor discreto de tiles
   * que han de tener uniformemente los territorios.
   */
  void calculate_tiles_per_territory();
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
