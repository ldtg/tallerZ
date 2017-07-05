
#include <stdio.h>
#include <Generator.h>
#include <iostream>
#include <Interface.h>
#include <Store_map.h>
/*
 * 1: ancho
 * 2: largo
 * 3: cantidad de territorios
 * 4: cantidad de jugadores
 * 5: tipo de mapa
 * 6: cantidad de vehiculos abandonados
 * 7: nivel de tecnologia de las fabricas
 * 8: porcentaje de rios
 * 9: porcentaje de rocas
 * 10: nombre archivo de salida
 *
 * Generator(const unsigned& width
      , const unsigned& length
      , unsigned territories
      , const unsigned& players
      , MAP_TYPE map_type, int vehicles, int factories_level);
 */

int main(int argc, char *argv[]) {
  Interface gc_interface;
  Parametros parametros = gc_interface.run();

  //Parametros parametros = { 20, 20, 9, 2, 0, 9, 1, 20, 20, "invierno.json"};
  Generator generator(parametros.ancho,
                      parametros.largo,
                      parametros.territorios,
                      parametros.jugadores,
                      (MAP_TYPE )parametros.tipo_de_mapa,
                      parametros.vehiculos_abandonados,
                      parametros.tecnologia,
                      parametros.porcentaje_rios,
                      parametros.porcentaje_rocas);

  Store_map(parametros.nombre_archivo, generator)();

  return 0;
}


