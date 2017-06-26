#include "Production_Menu.h"
#include <client/model/Model.h>

/**
 * constructor
 * @param window : ventana sobre la que se renderiza
 * @param x : coordenada X del menu
 * @param y : coordenada Y del menu
 */
Production_Menu::Production_Menu(const BuildID buildID,
                                 const BuildState &buildState,
                                 MainWindow &window, Model &model,
                                 int x, int y)
    : buildID(buildID), window(window),
      model(model), buildState(buildState) {

  this->renderQuad = {x, y, width, length};
  this->background = new Texture(background_path.c_str(), &window);
  this->background->renderize(&window, &renderQuad);
  this->showing_unit_type = buildState.actualUnitFab;
  load_items();
}

/**
 * load_items
 */
void Production_Menu::load_items() {
  /******Labels*****/
  set_absolute_position(_time_rect, this->time_rect);
  this->time = new Label(window,
                         std::to_string(buildState.timeRemainingInSecs),
                         this->time_rect,
                         this->font);

  set_absolute_position(_unit_rect, this->unit_rect);
  this->unit =
      new Texture(get_label_path(showing_unit_type), &window, unit_rect);
  //this->unit->renderize(&window, &unit_rect);

  set_absolute_position(_health_rect, this->health_rect);
  this->health = new Label(window, std::to_string(buildState.health) + "%",
                           this->health_rect, this->font);

  set_absolute_position(_building_name_rect, this->building_name_rect);
  this->building_name = new Label(window, get_building_type(buildID.getType()),
                                  this->building_name_rect, this->font);

  set_absolute_position(_status_rect, this->status_rect);
  this->status = new Label(window, "Select", this->status_rect, this->font);

  /******Buttons*****/
  set_absolute_position(_build_b_rect, this->build_b_rect);
  this->build = new Build_Button(&window, &model, this, build_b_rect);

  set_absolute_position(_up_rect, this->up_rect);
  this->up = new Up_Button(&window, &model, this, up_rect);

  set_absolute_position(_down_rect, this->down_rect);
  this->down = new Down_Button(&window, &model, this, down_rect);
}

///**
// * displace_toXY : mueve el menu a las coordenadas x,y
// * @param x : coordenada x
// * @param y : coordenada y
// */
//void Production_Menu::displace_toXY(int x, int y) {
//  this->renderQuad.x = x;
//  this->renderQuad.y = y;
//  this->background->renderize(&window, &this->renderQuad);
//
//  this->set_absolute_position(_time_rect, time_rect);
//  this->time->set_rectangle(time_rect);
//  this->time->reload();
//
//  this->set_absolute_position(_status_rect, status_rect);
//  this->status->set_rectangle(status_rect);
//  this->status->reload();
//
//  this->set_absolute_position(_health_rect, health_rect);
//  this->health->set_rectangle(health_rect);
//  this->health->reload();
//
//  this->set_absolute_position(_unit_rect, unit_rect);
//  this->unit->set_rectangle(unit_rect);
//  this->unit->reload();
//
//  this->set_absolute_position(_building_name_rect, building_name_rect);
//  this->building_name->set_rectangle(building_name_rect);
//  this->building_name->reload();
//
//  this->set_absolute_position(_build_b_rect, build_b_rect);
//  this->build->set_rectangle(build_b_rect);
//  this->build->reload();
//
//  this->set_absolute_position(_up_rect, up_rect);
//  this->up->set_rectangle(up_rect);
//  this->up->reload();
//
//  this->set_absolute_position(_down_rect, down_rect);
//  this->down->set_rectangle(down_rect);
//  this->down->reload();
//}

/**
 * show_select_status: En lugar de Building pone Select
 */
void Production_Menu::show_select_status() {
  this->status->modify_text("Select");
}

/**
 * show_building_status: En lugar de Select pone Building
 */
void Production_Menu::show_building_status() {
  this->status->modify_text("Building");
}

/**
 * show_health_level
 * @param health : nivel de salud de la fabrica.
 */
void Production_Menu::show_health_level(int health) {
  this->health->modify_text(std::to_string(health) + "%");
}

/**
 * destructor
 */
Production_Menu::~Production_Menu() {
  if (this->time != NULL)
    delete this->time;
  if (this->status != NULL)
    delete this->status;
  if (this->health != NULL)
    delete this->health;
  if (this->unit != NULL)
    delete this->unit;
  if (this->building_name != NULL)
    delete this->building_name;
  if (this->build != NULL)
    delete this->build;
  if (this->up != NULL)
    delete this->up;
  if (this->down != NULL)
    delete this->down;
  if (this->background != NULL)
    delete this->background;
}

void Production_Menu::draw(SDL_Renderer *render, Camera &camera) {
  this->update_status();
  Menu::draw(render, camera);
  build->draw(render, camera);
  up->draw(render, camera);
  down->draw(render, camera);
  time->draw(render, camera);
  status->draw(render, camera);
  health->draw(render, camera);
  unit->draw(render, camera);
  building_name->draw(render, camera);
}
/*
void Production_Menu::add_to_panel(Panel &panel) {
  this->update_status();
  panel.add(this);
  panel.add(build);
  panel.add(up);
  panel.add(down);
  panel.add(time);
  panel.add(status);
  panel.add(health);
  panel.add(unit);
  panel.add(building_name);
}
*/
std::string Production_Menu::get_building_type(const BuildType &buildType) {
  switch (buildType) {
    case (BuildType::FORT):return "FORT";
    case (BuildType::VEHICLEF):return "V. FACTORY";
    case (BuildType::ROBOTF):return "R. FACTORY";
    default: return "FORT";
  }
}

std::string Production_Menu::get_unit_name(const UnitType &utype) {
  switch (utype) {
    case UnitType::R_GRUNT:return "grunt";
    case UnitType::R_TOUGH:return "tough";
    case UnitType::R_PSYCHO:return "psycho";
    case UnitType::R_PYRO:return "pyro";
    case UnitType::R_SNIPER:return "sniper";
    case UnitType::R_LASER:return "laser";
    case UnitType::V_JEEP:return "jeep";
    case UnitType::V_MTANK:return "medium";
    case UnitType::V_LTANK:return "light";
    case UnitType::V_HTANK:return "heavy";
    case UnitType::V_MML:return "missile_launcher";
    default :return "grunt";
  }
}

void Production_Menu::handle_click(int x, int y) {
  if (up->inRectangle(x, y)) {
    up->handle_event();
  }
  if (down->inRectangle(x, y)) {
    down->handle_event();
  }
  if (build->inRectangle(x, y)) {
    build->handle_event();
  }
}

void Production_Menu::show_previous_buildable_unit() {
  bool found = false;
  std::vector<UnitType>::const_iterator it;
  it = buildState.fabricableUnits.begin();
  while (!found) {
    if (*it == showing_unit_type) {
      found = true;
    } else {
      it++;
    }
  }
  if (it != buildState.fabricableUnits.begin()) {
    it--;
    showing_unit_type = *it;
  } else {
    showing_unit_type = *(buildState.fabricableUnits.end() - 1);
  }
  unit->load_texture(get_label_path(showing_unit_type), window.getWindow());
  unit->renderize(&window, &unit_rect);
}

void Production_Menu::show_next_buildable_unit() {
  bool found = false;
  auto it = buildState.fabricableUnits.begin();
  while (!found) {
    if (*it == showing_unit_type) {
      found = true;
    }
    it++;
  }
  if (it != buildState.fabricableUnits.end()) {
    showing_unit_type = *it;
  } else {
    showing_unit_type = *buildState.fabricableUnits.begin();
  }
  unit->load_texture(get_label_path(showing_unit_type), window.getWindow());
  unit->renderize(&window, &unit_rect);
}

void Production_Menu::update_unit_to_build() {
  BuildState bs = model.getMap().getBuildState(buildID);
  if (bs.owner == model.getPlayer()) {
    model.get_gameControllerProxy()->changeUnitFab(buildID, showing_unit_type);
    bs.actualUnitFab = showing_unit_type;
    model.getMap().updateBuild(buildID, bs);
  }
}
std::string Production_Menu::get_label_path(const UnitType &utype) {
  return (folder_path + get_unit_name(utype) + "_label.png");
}
void Production_Menu::update_status() {
  buildState = model.getMap().getBuildState(buildID);
  delete this->health;
  delete this->time;
  if (buildState.health > 0)
    this->time = new Label(window,
                           std::to_string(buildState.timeRemainingInSecs),
                           this->time_rect,
                           this->font);
  else
    this->time = new Label(window,
                           "-",
                           this->time_rect,
                           this->font);
  this->health = new Label(window, std::to_string(buildState.health),
                           this->health_rect, this->font);
}

