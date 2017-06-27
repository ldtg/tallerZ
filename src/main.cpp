
#include <stdio.h>
#include <Generator.h>
#include <iostream>
#include <Interface.h>
#include <Store_map.h>


int main(int argc, char *argv[]) {
  Interface gc_interface;
  Parametros parametros = gc_interface.run();

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


