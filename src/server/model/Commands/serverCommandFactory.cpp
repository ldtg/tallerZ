#include <cereal/archives/binary.hpp>
#include <common/DataCommands/Unit/dataUnitMoveCommand.h>
#include <server/model/Commands/Unit/serverUMoveCommand.h>
#include <common/DataCommands/Unit/dataUnitAttackUnitCommand.h>
#include <server/model/Commands/Unit/serverUAttackUCommand.h>
#include <common/DataCommands/Unit/dataUnitAttackBuildCommand.h>
#include <server/model/Commands/Unit/serverUAttackBCommand.h>
#include <common/DataCommands/Unit/dataUnitAttackTOCommand.h>
#include <server/model/Commands/Unit/serverUAttackTOCommand.h>
#include <common/DataCommands/Unit/dataUnitCaptureCommand.h>
#include <server/model/Commands/Unit/serverUCaptureCommand.h>
#include <common/DataCommands/Build/dataBuildChangeUnitCommand.h>
#include <server/model/Commands/Build/serverBChangeUCommand.h>
#include "serverCommandFactory.h"
serverCommand *serverCommandFactory::createCommand(const CommandType &type,
                                                   std::stringstream &ss) {
  switch (type) {
    case U_MOVE_P: {
      cereal::BinaryInputArchive iarchive(ss);
      dataUnitMoveCommand data;
      iarchive(data);
      return new serverUMoveCommand(data);
    }
    case U_ATK_U: {
      cereal::BinaryInputArchive iarchive(ss);
      dataUnitAttackUnitCommand data;
      iarchive(data);
      return new serverUAttackUCommand(data);
    }
    case U_ATK_B: {
      cereal::BinaryInputArchive iarchive(ss);
      dataUnitAttackBuildCommand data;
      iarchive(data);
      return new serverUAttackBCommand(data);
    }
    case U_ATK_TO: {
      cereal::BinaryInputArchive iarchive(ss);
      dataUnitAttackTOCommand data;
      iarchive(data);
      return new serverUAttackTOCommand(data);
    }
    case U_CAPT_C: {
      cereal::BinaryInputArchive iarchive(ss);
      dataUnitCaptureCommand data;
      iarchive(data);
      return new serverUCaptureCommand(data);
    }
    case B_CFAB_U: {
      cereal::BinaryInputArchive iarchive(ss);
      dataBuildChangeUnitCommand data;
      iarchive(data);
      return new serverBChangeUCommand(data);
    }
    default: {
      return nullptr;//Nunca deberia llegar porque se consideraron todos los casos
    }
  }
}
