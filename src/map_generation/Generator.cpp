
#include "Generator.h"

Generator::Generator(const unsigned &width, const unsigned &length, unsigned territories) :
    map_width(width),
    map_length(length),
    tile_amount(width*length),
    territories(territories) {

  calculate_tiles_per_territory();
  calculate_frame();
  this->map_territories = new territory_coords[tile_amount];
}

Delegation Generator::fill_territory(int territory, int tile_amount, int x, int y, int frame_number) {
  int _tile_amount;
  int pos;
  bool fin_columnas, fin_tiles, encuadrado;
  _tile_amount = tile_amount;
  //el marco y la tile pasada inicialmente no coinciden
  if (!esta_encuadrado(frame_number, x, y)) {
    throw Generator_Exception(
        "Error en fill_territory: los valores x e y se esperaba "
            "que estuvieran encuadrados adentro del frame especificado "
            "pero no lo están.\n");
  }
  fin_columnas = false;
  fin_tiles = false;
  while (!fin_columnas && !fin_tiles) {
    encuadrado = true;
    while (encuadrado && !fin_tiles) {
      pos = get_position(x, y);
      map_territories[pos].x = x;
      map_territories[pos].y = y;
      map_territories[pos].territory = territory;
      _tile_amount--;
      if (_tile_amount == 0) {
        fin_tiles = true;
      }
      y++;
      encuadrado = esta_encuadrado(frame_number, x, y);
    }
    if(!fin_tiles || !encuadrado) {
      x++;
      y = frame * frame_number;
    }
    if(x == map_width){ fin_columnas = true; }
  }
  Delegation d = {x,y,_tile_amount};
  return d;
}

Delegation Generator::fill_territory_backwards(int territory, int tile_amount, int x, int y, int frame_number) {
  int _tile_amount;
  int pos;
  bool fin_columnas, fin_tiles, encuadrado;
  _tile_amount = tile_amount;
  //el marco y la tile pasada inicialmente no coinciden
  if (!esta_encuadrado(frame_number, x, y)) {
    throw Generator_Exception(
        "Error en fill_territory: los valores x e y se esperaba "
            "que estuvieran encuadrados adentro del frame especificado "
            "pero no lo están.\n");
  }
  fin_columnas = false;
  fin_tiles = false;
  while (!fin_columnas && !fin_tiles) {
    encuadrado = true;
    while (encuadrado && !fin_tiles) {
      pos = get_position(x, y);
      map_territories[pos].x = x;
      map_territories[pos].y = y;
      map_territories[pos].territory = territory;
      _tile_amount--;
      if (_tile_amount == 0) {
        fin_tiles = true;
      }
      y++;
      encuadrado = esta_encuadrado(frame_number, x, y);
    }
    if(!fin_tiles || !encuadrado) {
      x--;
      y = frame * frame_number;
    }
    if(x < 0){ fin_columnas = true; }
  }
  Delegation d = {x,y,_tile_amount};
  return d;
}
bool Generator::esta_encuadrado(int frame_number, int x, int y) {
  return ((((frame*frame_number) <= y)
      && ( y < (frame*(frame_number+1))))
      && (x >= 0 && x < map_width) && ( y < this->map_length));
}
unsigned int Generator::get_position(unsigned x, unsigned y) {
  return (y * map_width + x);
}
void Generator::fill_remnants(int x, int y, bool forwards, int remnants, int frame_number) {
  if (forwards){
    fill_territory(territories-1,remnants,x,y,frame_number);
  }
  else {
    fill_territory_backwards(territories-1,remnants,x,y,frame_number);
  }
}
void Generator::territory_distribution_algorithm() {
  int x,y,territory,frame_number, remnants;
  bool fill_remnants_forward;
  bool territories_filled = false;
  bool end_frame = false;
  Delegation delegation;
  delegation.x = 0;
  delegation.y = 0;
  delegation.tiles_left = this->tiles_per_territory;
  frame_number = 0;
  territory = 0;
  while (!territories_filled){
    while (!end_frame && !territories_filled){
      delegation = fill_territory(territory,
                                  delegation.tiles_left,
                                  delegation.x,delegation.y,
                                  frame_number);
      if(delegation.x == map_width){
        end_frame = true;
        frame_number++;
        delegation.x = map_width-1;
        delegation.y = frame*frame_number;
      }
      if (delegation.tiles_left == 0){
        delegation.tiles_left = this->tiles_per_territory;
        territory++;
      }
      if (territory == territories){
        territories_filled = true;
        fill_remnants_forward = true;
      }
    }
    end_frame = false;
    while (!end_frame && !territories_filled){
      delegation = fill_territory_backwards(territory,
                                            delegation.tiles_left,
                                            delegation.x, delegation.y,
                                            frame_number);
      if(delegation.x < 0){
        end_frame = true;
        frame_number++;
        delegation.x = 0;
        delegation.y = frame*frame_number;
      }
      if (delegation.tiles_left == 0){
        delegation.tiles_left = this->tiles_per_territory;
        territory++;
      }
      if (territory == territories){
        territories_filled = true;
        fill_remnants_forward = false;
      }
    }
    end_frame = false;
  }
  remnants = tile_amount - tiles_per_territory*territories;
  if (remnants != 0){
    fill_remnants(delegation.x,delegation.y,fill_remnants_forward,remnants,frame_number);
  }
}
void Generator::calculate_frame() {
  unsigned i = 1;
  bool surpassed = false;
  while(!surpassed){
    if (i*i > tiles_per_territory){
      surpassed = true;
      frame = i-1;
    }
    i++;
  }
}
Generator::~Generator() {
  delete this->map_territories;
}
