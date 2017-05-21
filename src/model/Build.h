#ifndef TALLERZ_BUILD_H
#define TALLERZ_BUILD_H

#include "Attackable.h"
#include "BuildID.h"
#include "Player.h"
class Build : public Attackable{
 private:
  const BuildID id;
  const unsigned short techLevel;
  const unsigned short health;
  Player &owner;

};

#endif //TALLERZ_BUILD_H
