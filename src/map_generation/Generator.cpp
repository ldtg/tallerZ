
#include <algorithm>
#include "Generator.h"

Generator::Generator(const unsigned &width, const unsigned &length, unsigned territories, const unsigned& teams, MAP_TYPE map_type, int vehicles, int factories_level) :
    map_width(width),
    map_length(length),
    tile_amount(width*length),
    territories(territories), teams(teams), map_type(map_type),
    abandoned_vehicles_amount(vehicles), factories_level(factories_level){

  calculate_tiles_per_territory();
  calculate_frame();
  this->map_positions = new territory_coords[tile_amount];
  memset(this->map_positions,0,sizeof(territory_coords)*tile_amount);
  set_geography();
}

Delegation Generator::fill_territory(int territory, int tile_amount, int x, int y, int frame_number) {
  int _tile_amount;
  int pos;
  bool fin_columnas, fin_tiles, encuadrado;
  _tile_amount = tile_amount;
  //si el marco y la tile pasada inicialmente no coinciden
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
      map_positions[pos].x = x;
      map_positions[pos].y = y;
      map_positions[pos].territory = territory;
      map_positions[pos].terrain = base_terrain;
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
      map_positions[pos].x = x;
      map_positions[pos].y = y;
      map_positions[pos].territory = territory;
      map_positions[pos].terrain = base_terrain;
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
  delete this->map_positions;
}
void Generator::put_flag_around_factory(territory_coords &position,
                                        const unsigned &territory) {
  unsigned long int i;
  Position pos(position.x, position.y);
  std::vector<Position> neighbors = pos.getNeighbors();

  std::vector<Position> avalible_neighbors;

  std::vector<Position>::iterator it;
  for (it = neighbors.begin(); it != neighbors.end(); it++){
    if (can_put_flag_on_position(*it,territory)){
      avalible_neighbors.push_back(*it);
    }
  }
  i = rand() % avalible_neighbors.size();
  unsigned int m = get_position(avalible_neighbors[i].getX(),avalible_neighbors[i].getY());
  map_positions[m].flag = true;
}
bool Generator::can_put_flag_on_position(const Position &pos, const unsigned &territory) {
  return (belongs_to_map(pos) && belongs_to_territory(pos,territory));
}
bool Generator::belongs_to_map(const Position &pos) {
  return (pos.getX() >= 0 && pos.getX() < map_width
      && pos.getY() >= 0 && pos.getY() < map_length);
}
bool Generator::belongs_to_territory(const Position &pos, const unsigned &territory) {
  return (map_positions[get_position(pos.getX(),pos.getY())].territory ==
      territory);
}
void Generator::trace_paths() {
  bool empty_vector;
  unsigned int min_distance, distance;
  std::vector<territory_coords> _vertices = this->vertices;
  std::vector<territory_coords>::iterator it, jt;
  territory_coords closest_vertex;

  empty_vector = false;
  it = _vertices.begin();
  while (!empty_vector){
    min_distance = 99999;
    for (jt = _vertices.begin()+1; jt != _vertices.end(); jt++){
      distance = calc_distance(*it,*jt);
      if (distance < min_distance){
        min_distance = distance;
        closest_vertex = *jt;
      }
    }
    draw_line(*it, closest_vertex, TERRAIN_TYPE::ROAD);
    it = _vertices.erase(it);
    if (it == _vertices.end()){
      empty_vector = true;
    }
  }
}
void Generator::set_terrain(int x, int y, TERRAIN_TYPE terrain_type) {
  unsigned int pos = get_position(x,y);
  if ((this->map_positions[pos].terrain == ROAD) && (terrain_type == SWAMP
      || terrain_type == WATER || terrain_type == LAVA)){
    this->map_positions[pos].terrain = BRIDGE;
  } else {
    this->map_positions[pos].terrain = terrain_type;
  }
}
int Generator::draw_line(const territory_coords &start, const territory_coords &end, TERRAIN_TYPE terrain_type) {
  int xdiff;
  int ydiff;
  int marked_tiles = 0;
  xdiff = end.x - start.x;
  if (xdiff > 0){
    for (int i = 0; i < xdiff; i++){
      //this->map_positions[get_position(start.x+i,start.y)].terrain = terrain_type;
      set_terrain((start.x + i), start.y, terrain_type);
      marked_tiles++;
    }
  }
  if (xdiff < 0){
    for (int i = 0; i < abs(xdiff); i++){
      //this->map_positions[get_position(start.x-i,start.y)].terrain = terrain_type;
      set_terrain((start.x-i), start.y, terrain_type);
      marked_tiles++;
    }
  }

  ydiff = end.y - start.y;
  if ( ydiff > 0){
    for (int i = 0; i < ydiff; i++){
      //this->map_positions[get_position(end.x,start.y+i)].terrain = terrain_type;
      set_terrain(end.x, start.y + i, terrain_type);
      marked_tiles++;
    }
  }
  if (ydiff < 0){
    for (int i = 0; i < abs(ydiff); i++){
      //this->map_positions[get_position(end.x,start.y-i)].terrain = terrain_type;
      set_terrain(end.x, start.y - i, terrain_type);
      marked_tiles++;
    }
  }
  return marked_tiles;
}
void Generator::put_building_random_in_territory(const unsigned &territory, BUILDING building) {
  bool tile_found;
  srand(time(NULL));
  int random_tile = rand() % tiles_per_territory;
  int i = -1;
  int j = -1;
  tile_found = false;
  while(!tile_found){
    i++;
    if (map_positions[i].territory == territory){
      j++;
    }
    if (j == random_tile){
      tile_found = true;
    }
  }
  this->vertices.push_back(map_positions[i]);
  switch (building){
    case FORT:
      map_positions[i].fort = true;
      break;
    case FACTORY:
      map_positions[i].factory = true;
      put_flag_around_factory(map_positions[i],
                              territory);
      break;
  }
}
void Generator::building_distribution_algorithm() {
  int j;
  int frecuency;
  std::vector<int> territories_with_forts;
  std::vector<int> territories_with_flags_and_factories;
  frecuency = territories/teams;

  j = 0;
  for (int i = 0; i < territories; i++){
    if (i % frecuency == 0 && j < teams){
      territories_with_forts.push_back(i);
      j++;
    } else {
      territories_with_flags_and_factories.push_back(i);
    }
  }

  for (const auto& i : territories_with_forts){
    put_building_random_in_territory(i,FORT);
  }
  for (const auto& i : territories_with_flags_and_factories){
    put_building_random_in_territory(i,FACTORY);
  }
}
unsigned int Generator::calc_distance(const territory_coords &v1, const territory_coords &v2) const {
  Position p1(v1.x, v1.y);
  Position p2(v2.x, v2.y);
  return p1.manhattanDistance(p2);
}
int Generator::calc_tile_amount(int total_percentage, int partial_percentage) {
  double max_amount_of_water_or_lava_possible;
  max_amount_of_water_or_lava_possible =
      (this->tile_amount * total_percentage ) / 100;
  return (int)(
      (max_amount_of_water_or_lava_possible * partial_percentage )/ 100);
}

void Generator::trace_rivers() {
  int tiles_marked;
  territory_coords start, end;
  bool filled;

  int lava_water_tile_amount = calc_tile_amount(
      total_lava_water_percentage, partial_lava_water_percentage);

  filled = false;
  tiles_marked = 0;
  while (!filled){
    start = map_positions[get_position(rand() % map_width, rand() % map_length)];
    end = map_positions[get_position(rand() % map_width, rand() % map_length)];
    if (!may_overlap_road(start,end)){
      tiles_marked += draw_line(start,end,river_type);
      if (tiles_marked >= lava_water_tile_amount){
        filled = true;
      }
    }
  }
}
void Generator::set_water_lava_percentages(int total_percentage, int partial_percentage) {
  this->total_lava_water_percentage = total_percentage;
  this->partial_lava_water_percentage = partial_percentage;
}
void Generator::set_geography() {
  switch( this->map_type){
    case WINTER:
      this->base_terrain = SNOW;
      this->river_type = WATER;
      this->rock_type = ICE;
      break;
    case DUSTY:
      this->base_terrain = LAND;
      this->river_type = WATER;
      this->rock_type = ROCK;
      break;
    case SPRING:
      this->base_terrain = PRAIRIE;
      this->river_type = WATER;
      this->rock_type = ROCK;
      break;
    case HUMID:
      this->base_terrain = PRAIRIE;
      this->river_type = SWAMP;
      this->rock_type = ROCK;
      break;
    case HELL:
      this->base_terrain = LAND;
      this->river_type = LAVA;
      this->rock_type = ROCK;
      break;
  }
}
bool Generator::may_overlap_road(const territory_coords &start, const territory_coords &end) const {
  bool may_overlap = false;
  for (const auto& i: this->vertices){
    if (i.x == start.x || i.x == end.x || i.y == start.y || i.y == end.y ){
      may_overlap = true;
      break;
    }
  }
  return may_overlap;
}
void Generator::calculate_tiles_per_territory() {
  this->tiles_per_territory = (tile_amount/territories);
}
void Generator::set_rocks_percentages(int total_percentage, int partial_percentage) {
  this->total_rock_percentage = total_percentage;
  this->partial_rock_percentage = partial_percentage;
}
bool Generator::can_put_rock_or_vehicle_on_position(const territory_coords &position) {
  return (!position.flag && !position.factory && !position.fort
      && !position.rock && (position.terrain == SNOW
      || position.terrain == LAND || position.terrain == PRAIRIE));
}
void Generator::put_rocks() {
  int rocks = 0;
  bool map_filled = false;
  int tile_amount = calc_tile_amount(this->total_rock_percentage, this->partial_rock_percentage);
  unsigned int rand_pos;
  while(!map_filled){
    rand_pos = get_position(rand() % map_width, rand() % map_length);
    if (can_put_rock_or_vehicle_on_position(map_positions[rand_pos])){
      map_positions[rand_pos].rock = true;
      rocks++;
    }
    map_filled = (rocks >= tile_amount);
  }
}
void Generator::put_vehicles() {
  int position;
  int vehicles = 0;
  bool vehicles_filled = false;
  while (!vehicles_filled){
    position = get_position(rand() % map_width, rand() % map_length);
    if (can_put_rock_or_vehicle_on_position(map_positions[position])){
      map_positions[position].vehicle = true;
      vehicles++;
    }
    vehicles_filled = (vehicles >= abandoned_vehicles_amount);
  }
}
