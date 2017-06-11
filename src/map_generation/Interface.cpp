//
// Created by darius on 11/06/17.
//

#include "Interface.h"
Parametros Interface::run() {
  interfaz_del_generador();
  return parametros;
}
void Interface::interfaz_del_generador() {
  std::cout << "Bienvenidos al generador de mapas.";
  std::cout << "\nIngrese el ancho del mapa: ";
  std::cin >> ingresado;
  parametros.ancho = dimension_validada();
  std::cout << "\nIngrese el largo del mapa: ";
  std::cin >> ingresado;
  parametros.largo = dimension_validada();
  std::cout << "\nIngrese la cantidad de territorios: ";
  std::cin >> ingresado;
  parametros.territorios = territorios_validados();
  std::cout << "\nIngrese la cantidad de jugadores: ";
  std::cin >> ingresado;
  parametros.jugadores = jugadores_validados();
  std::cout << "\nIngrese el tipo de mapa: 0: WINTER 1:SPRING 2:HUMID 3:DUSTY 4:HELL\n";
  std::cin >> ingresado;
  parametros.tipo_de_mapa = tipo_de_mapa_validado();
  std::cout << "\nIngrese la cantidad de vehiculos abandonados: ";
  std::cin >> ingresado;
  parametros.vehiculos_abandonados = vehiculos_validados();
  std::cout << "\nIngrese el nivel de tecnologia de las fabricas: ";
  std::cin >> ingresado;
  parametros.tecnologia = tecnologia_validada();
  std::cout << "\nIngrese el porcentaje de rios: ";
  std::cin >> ingresado;
  parametros.porcentaje_rios = rios_o_rocas_validado();
  std::cout << "\nIngrese el porcentaje de rocas: ";
  std::cin >> ingresado;
  parametros.porcentaje_rocas = rios_o_rocas_validado();
  std::cout << "\nIngrese el nombre del archivo a guardar: ";
  std::cin >> ingresado;
  parametros.nombre_archivo = nombre_validado();
}
std::string Interface::nombre_validado() {
  std::string nombre = ingresado + ".json";
  return nombre;
}
unsigned int Interface::rios_o_rocas_validado() {
  int _input;
  _input = std::atoi(ingresado.c_str());
  if (_input < 0){
    _input = 0;
  }
  if (_input > 100){
    _input = 100;
  }
  this->ingresado.erase();
  return (unsigned int)_input;
}
unsigned int Interface::tecnologia_validada() {
  int _input;
  _input = std::atoi(ingresado.c_str());
  if (_input < 1){
    _input = 1;
  }
  if (_input > 5){
    _input = 5;
  }
  this->ingresado.erase();
  return (unsigned int)_input;
}
unsigned int Interface::vehiculos_validados() {
  int _input;
  _input = std::atoi(ingresado.c_str());
  if (_input < 0){
    _input = 0;
  }
  if (_input > 30){
    _input = 30;
  }
  this->ingresado.erase();
  return (unsigned int)_input;
}
unsigned int Interface::tipo_de_mapa_validado() {
  int _input;
  _input = std::atoi(ingresado.c_str());
  if (_input < 0 || _input > 4){
    _input = 0;
  }
  this->ingresado.erase();
  return (unsigned int)_input;
}
unsigned int Interface::jugadores_validados() {
  int _input;
  _input = std::atoi(ingresado.c_str());
  if (_input < 2){
    _input = 2;
  }
  if (_input > 4){
    _input = 4;
  }
  this->ingresado.erase();
  return (unsigned int)_input;
}
unsigned int Interface::territorios_validados() {
  int _input;
  _input = std::atoi(ingresado.c_str());
  if (_input < 4){
    _input = 4;
  }
  if (_input > 9){
    _input = 9;
  }
  this->ingresado.erase();
  return (unsigned int)_input;
}
unsigned int Interface::dimension_validada() {
  int _input;
  _input = std::atoi(ingresado.c_str());
  if (_input < 12){
    _input = 12;
  }
  if (_input > 40){
    _input = 40;
  }
  this->ingresado.erase();
  return (unsigned int)_input;
}
