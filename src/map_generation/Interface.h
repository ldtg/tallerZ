//
// Created by darius on 11/06/17.
//

#ifndef TALLERZ_GENERADOR_INTERFACE_H
#define TALLERZ_GENERADOR_INTERFACE_H

#include <string>
#include <iostream>

struct Parametros{
  unsigned int ancho;
  unsigned int largo;
  unsigned int territorios;
  unsigned int jugadores;
  unsigned int tipo_de_mapa;
  unsigned int vehiculos_abandonados;
  unsigned int tecnologia;
  unsigned int porcentaje_rios;
  unsigned int porcentaje_rocas;
  std::string nombre_archivo;
};

class Interface {
 private:

  std::string ingresado;
  Parametros parametros;
 public:
  Parametros run();
  
  void interfaz_del_generador();

 private:
  std::string nombre_validado();

  unsigned int rios_o_rocas_validado();
  
  unsigned int tecnologia_validada();
  
  unsigned int vehiculos_validados();
  
  unsigned int tipo_de_mapa_validado();
  
  unsigned int jugadores_validados();
  
  unsigned int territorios_validados();
  
  unsigned int dimension_validada();
};

#endif //TALLERZ_GENERADOR_INTERFACE_H
