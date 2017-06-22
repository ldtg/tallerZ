#include <cereal/archives/binary.hpp>
#include <common/DataCommands/Unit/DataUnitMoveCommand.h>
#include <server/model/Commands/Unit/UnitMoveCommand.h>
#include <common/DataCommands/Unit/DataUnitAttackUnitCommand.h>
#include <server/model/Commands/Unit/UnitAttackUnitCommand.h>
#include <common/DataCommands/Unit/DataUnitAttackBuildCommand.h>
#include <server/model/Commands/Unit/UnitAttackBuildCommand.h>
#include <common/DataCommands/Unit/DataUnitAttackTOCommand.h>
#include <server/model/Commands/Unit/UnitAttackTerrainObjectCommand.h>
#include <common/DataCommands/Unit/DataUnitCaptureCommand.h>
#include <server/model/Commands/Unit/UnitCaptureCommand.h>
#include <common/DataCommands/Build/DataBuildChangeUnitCommand.h>
#include <server/model/Commands/Build/BuildChangeUnitCommand.h>
#include "CommandFactory.h"
Command *CommandFactory::createCommand(const CommandType &type,
                                                   std::stringstream &ss) {
  switch (type) {
    case U_MOVE_P: {
      cereal::BinaryInputArchive iarchive(ss);
      DataUnitMoveCommand data;
      iarchive(data);
      return new UnitMoveCommand(data);
    }
    case U_ATK_U: {
      cereal::BinaryInputArchive iarchive(ss);
      DataUnitAttackUnitCommand data;
      iarchive(data);
      return new UnitAttackUnitCommand(data);
    }
    case U_ATK_B: {
      cereal::BinaryInputArchive iarchive(ss);
      DataUnitAttackBuildCommand data;
      iarchive(data);
      return new UnitAttackBuildCommand(data);
    }
    case U_ATK_TO: {
      cereal::BinaryInputArchive iarchive(ss);
      DataUnitAttackTOCommand data;
      iarchive(data);
      return new UnitAttackTerrainObjectCommand(data);
    }
    case U_CAPT_C: {
      cereal::BinaryInputArchive iarchive(ss);
      DataUnitCaptureCommand data;
      iarchive(data);
      return new UnitCaptureCommand(data);
    }
    case B_CFAB_U: {
      cereal::BinaryInputArchive iarchive(ss);
      DataBuildChangeUnitCommand data;
      iarchive(data);
      return new BuildChangeUnitCommand(data);
    }
    default: {
      return nullptr;//Nunca deberia llegar porque se consideraron todos los casos
    }
  }
}
