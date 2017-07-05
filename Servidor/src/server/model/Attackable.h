#ifndef TALLERZ_ATTACKABLE_H
#define TALLERZ_ATTACKABLE_H

#include "common/Map/Position.h"
#include "Weapon.h"
#include "common/IDs/PlayerID.h"
#include "Player.h"
//Interfaz necesaria para todos los objetos que sean atacables
class Attackable {
 public:
  //Retorna la posición en la cual el atacable tiene que ser atacado a partir de la posición del atacante
  virtual Position getAttackPosition(const Position &attacker) const = 0;
  //Retorna la posicion central del atacado
  virtual Position getCenterPosition() const = 0;
  //Retorna un puntero al player dueño del atacado
  virtual Player *getOwner() = 0;
  virtual bool isAlive() const = 0;
  virtual bool isMoving() const = 0;
  //Retorna la siguiente posición a la que se moverá el atacado
  virtual Position nextMovePosition() const = 0;
  //Recibe un ataque
  virtual void receiveAttack(const Weapon &weapon) = 0;
  virtual ~Attackable() {};
};

#endif //TALLERZ_ATTACKABLE_H
