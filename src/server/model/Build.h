#ifndef TALLERZ_BUILD_H
#define TALLERZ_BUILD_H

#include "Attackable.h"
#include "common/IDs/BuildID.h"
#include "Player.h"
#include "common/Types/UnitType.h"
#include "BuildData.h"
#include "common/States/BuildState.h"
#include "Unit.h"

class Build : public Attackable {
 private:
  BuildID id;
  Player *owner;
  Team team;
  Position centerPosition;
  //distancia desde el centro a los bordes
  unsigned short size;
  unsigned short techLevel;
  std::vector<UnitType> fabricableUnits;
  std::vector<unsigned short> damagesToReceive;
  unsigned short health;
  UnitType actualUnitFab;
  unsigned long ticksBeforeCreate;
  unsigned long actualTicksBeforeCreateBase;
  bool timeToBuild;

  unsigned long getSpeedRate() const;
 public:
  Build(const BuildData &data,
        const Position &centerPosition,
        Player &owner, const Team &team,
        const unsigned short techLevel);
  //Le informa al edificio que el modelo avanzó un paso
  void tick();
  //Cambia la unidad a fabricar si no es posible fabricarla no hace nada
  void changeFabUnit(const UnitType &type);
  //Cambi el jugador y el equipo dueño del edificio
  void changePlayer(Player *player, const Team &team);
  //Aplica los daños de su lista de daños recibidos
  virtual void receiveDamages();
  //Recibe un daño y lo agrega a su lista
  virtual void receiveAttack(const Weapon &weapon) override;
  //Crea unidades a partir de la posicion buildpos y las retorna en un vector.
  std::vector<Unit *> fabricateUnits(const Position &buildPos);
  virtual Position getCenterPosition() const override;
  virtual Player *getOwner() override;
  //Para que cuando lo ataquen, ataquen la posicion mas cercana al atacante (solo las esquinas)
  virtual Position getAttackPosition(const Position &attackerPosition) const override;
  virtual Position nextMovePosition() const override;
  BuildID getId() const;
  BuildState getBuildState() const;
  virtual bool hasDamagesToReceive() const;
  virtual bool isAlive() const override;
  virtual bool isMoving() const override;
  bool hasToBuild() const;
  ~Build();
};

#endif //TALLERZ_BUILD_H
