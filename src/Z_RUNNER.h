//
// Created by darius on 22/05/17.
//

#ifndef TALLERZ_RUN_H
#define TALLERZ_RUN_H

#include <controller/Controller.h>
#include <front_end/SDL_Interface/Main_Window.h>
#include <model/Data.h>
#include <model/UnitFactory.h>
#include <storage/Game_Loader.h>
#include "view/View.h"
#include <model/CapturableVehicle.h>
#include <model/UnitFactory.h>
#include <model/Territory.h>
/**
 * @class Z_RUNNER
 * ejecutora del juego que conecta los distintos componentes
 * realizados hasta ahora
 */
class Z_RUNNER {
 public:
  Z_RUNNER();

  void run();

  ~Z_RUNNER();

};

#endif //TALLERZ_RUN_H
