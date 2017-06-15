cmake_minimum_required(VERSION 3.7)
project(tallerZ_Servidor)

set(CMAKE_CXX_STANDARD 11)
include_directories(include)

set(SOURCE_FILES
        src/server/model/AStar.cpp
        src/server/model/AStar.h
        src/server/model/Node.cpp
        src/server/model/Node.h
        src/server/model/Unit.cpp
        src/server/model/Unit.h
        src/server/model/MovementState.h
        src/server/model/Weapon.cpp
        src/server/model/Weapon.h
        src/server/model/Attackable.h
        src/server/model/Data.cpp
        src/server/model/Data.h
        src/server/model/Robot.cpp
        src/server/model/Robot.h

        src/Exceptions/model_exceptions/UnitNotFoundException.cpp
        src/Exceptions/model_exceptions/UnitNotFoundException.h
        src/server/model/UnitData.h
        src/server/model/UnitFactory.cpp
        src/server/model/UnitFactory.h
        src/common/Map/TerrainData.h
        src/server/model/Vehicle.cpp
        src/server/model/Vehicle.h

        src/server/model/Bullet.cpp
        src/server/model/Bullet.h
        src/common/IDs/BulletID.cpp
        src/common/IDs/BulletID.h
        src/common/Map/Map.cpp
        src/common/Map/Map.h
        src/common/Map/Position.cpp
        src/common/Map/Position.h
        src/common/Map/Tile.cpp
        src/common/Map/Tile.h
        src/common/Types/TerrainType.h
        src/common/IDs/UnitID.cpp
        src/common/IDs/UnitID.h
        src/common/States/UnitState.cpp
        src/common/States/UnitState.h
        src/common/Types/UnitType.h
        src/common/Types/WeaponType.h
        src/common/States/BulletState.cpp
        src/common/States/BulletState.h
        src/server/model/Player.cpp
        src/server/model/Player.h
        src/server/model/Team.cpp
        src/server/model/Team.h
        src/common/IDs/PlayerID.cpp
        src/common/IDs/PlayerID.h
        src/server/model/Territory.cpp
        src/server/model/Territory.h
        src/server/model/Build.cpp
        src/server/model/Build.h
        src/server/model/BuildData.h
        src/common/Types/BuildType.h
        src/common/IDs/BuildID.cpp
        src/common/IDs/BuildID.h
        src/common/Types/BuildType.h
        src/common/States/BuildState.cpp src/common/States/BuildState.h
        src/common/IDs/TeamID.cpp src/common/IDs/TeamID.h
        src/server/model/TerrainObject.cpp
        src/server/model/TerrainObject.h
        src/common/Types/TerrainObjectType.h
        src/common/IDs/TerrainObjectID.cpp
        src/common/IDs/TerrainObjectID.h
        src/common/States/TerrainObjectState.cpp
        src/common/States/TerrainObjectState.h
        src/server/model/TerrainObjectData.h
        src/common/Types/PlayerColor.h
        src/server/model/GaiaPlayer.cpp
        src/server/model/GaiaPlayer.h

        src/common/IDs/CapturableID.cpp
        src/common/IDs/CapturableID.h
        src/common/States/CapturableState.h
        src/common/Types/CapturableType.h
        src/server/model/Capturable.cpp
        src/server/model/Capturable.h
        src/server/model/CapturableVehicle.cpp
        src/server/model/CapturableVehicle.h
        src/server/model/MapType.h
        src/common/Types/PlayerColor.h

        src/Exceptions/Sdl_Exceptions/Sdl_Exception.cpp
        src/Exceptions/Sdl_Exceptions/Sdl_Exception.h
        src/Exceptions/model_exceptions/UnableToFindAPathException.cpp
        src/Exceptions/model_exceptions/UnableToFindAPathException.h
        src/Exceptions/model_exceptions/UnableToBuildThatUnitException.cpp
        src/Exceptions/model_exceptions/UnableToBuildThatUnitException.h
        src/Exceptions/Storage_Exceptions/Storage_Exception.h
        src/Exceptions/Storage_Exceptions/Storage_Exception.cpp

        src/storage/Game_Loader.h
        src/storage/Game_Loader.cpp

        z_sounds/Sound_event.h
        z_sounds/Sound_event.cpp

        src/Exceptions/model_exceptions/BuildingNotFoundException.cpp
        src/Exceptions/model_exceptions/BuildingNotFoundException.h
        src/common/DataEvents/EventType.h
        src/common/DataEvents/dataEvent.cpp
        src/common/DataEvents/dataEvent.h
        src/common/DataEvents/Unit/dataUnitMoveEvent.cpp
        src/common/DataEvents/Unit/dataUnitMoveEvent.h
        src/server/model/Events/serverEvent.cpp
        src/server/model/Events/serverEvent.h
        src/server/model/Events/Unit/serverUAttackEvent.cpp
        src/server/model/Events/Unit/serverUAttackEvent.h
        src/common/DataEvents/Unit/dataUnitAttackEvent.cpp
        src/common/DataEvents/Unit/dataUnitAttackEvent.h
        src/server/model/Events/Unit/serverUMoveEvent.cpp
        src/server/model/Events/Unit/serverUMoveEvent.h
        src/common/DataEvents/Unit/dataUnitCreateEvent.cpp
        src/common/DataEvents/Unit/dataUnitCreateEvent.h
        src/server/model/Events/Unit/serverUCreateEvent.cpp
        src/server/model/Events/Unit/serverUCreateEvent.h
        src/common/DataEvents/Unit/dataUnitIDEvent.cpp
        src/common/DataEvents/Unit/dataUnitIDEvent.h
        src/server/model/Events/Unit/serverUDeathEvent.cpp
        src/server/model/Events/Unit/serverUDeathEvent.h
        src/server/model/Events/Unit/serverUStillEvent.cpp
        src/server/model/Events/Unit/serverUStillEvent.h
        src/common/DataEvents/Build/dataBuildUpdateEvent.cpp
        src/common/DataEvents/Build/dataBuildUpdateEvent.h
        src/server/model/Events/Build/serverBDamageEvent.cpp
        src/server/model/Events/Build/serverBDamageEvent.h
        src/common/DataEvents/Build/dataBuildIDEvent.cpp
        src/common/DataEvents/Build/dataBuildIDEvent.h
        src/server/model/Events/Build/serverBDestroyedEvent.cpp
        src/server/model/Events/Build/serverBDestroyedEvent.h
        src/common/DataEvents/Bullet/dataBulletNewEvent.cpp
        src/common/DataEvents/Bullet/dataBulletNewEvent.h
        src/server/model/Events/Bullet/serverBLTMoveEvent.cpp
        src/server/model/Events/Bullet/serverBLTMoveEvent.h
        src/server/model/Events/Bullet/serverBLTNewEvent.cpp
        src/server/model/Events/Bullet/serverBLTNewEvent.h
        src/common/DataEvents/Bullet/dataBulletMoveEvent.cpp
        src/common/DataEvents/Bullet/dataBulletMoveEvent.h
        src/common/DataEvents/Bullet/dataBulletHitEvent.cpp
        src/common/DataEvents/Bullet/dataBulletHitEvent.h
        src/server/model/Events/Bullet/serverBLTHitEvent.cpp
        src/server/model/Events/Bullet/serverBLTHitEvent.h
        src/common/DataEvents/Capturable/dataCaptureEvent.cpp
        src/common/DataEvents/Capturable/dataCaptureEvent.h
        src/server/model/Events/Capturable/serverCCaptureEvent.cpp
        src/server/model/Events/Capturable/serverCCaptureEvent.h
        src/common/DataEvents/TerrainObject/dataTerrainObjectIDEvent.cpp
        src/common/DataEvents/TerrainObject/dataTerrainObjectIDEvent.h
        src/server/model/Events/TerrainObject/serverTODestroyedEvent.cpp
        src/server/model/Events/TerrainObject/serverTODestroyedEvent.h
        src/common/DataEvents/Game/dataPlayerDefeatEvent.cpp
        src/common/DataEvents/Game/dataPlayerDefeatEvent.h
        src/server/model/Events/Game/serverGPlayerDefeatedEvent.cpp
        src/server/model/Events/Game/serverGPlayerDefeatedEvent.h
        src/common/DataEvents/Game/dataEndGameEvent.cpp
        src/common/DataEvents/Game/dataEndGameEvent.h
        src/server/model/Events/Game/serverGEndGameEvent.cpp
        src/server/model/Events/Game/serverGEndGameEvent.h
        src/common/DataCommands/CommandType.h
        src/common/DataCommands/Unit/dataUnitMoveCommand.cpp
        src/common/DataCommands/Unit/dataUnitMoveCommand.h
        src/server/model/Commands/Unit/serverUMoveCommand.cpp
        src/server/model/Commands/Unit/serverUMoveCommand.h
        src/server/model/Commands/serverCommand.cpp
        src/server/model/Commands/serverCommand.h
        src/server/model/Commands/serverCommandFactory.cpp
        src/server/model/Commands/serverCommandFactory.h
        src/common/DataCommands/Unit/dataUnitAttackUnitCommand.cpp
        src/common/DataCommands/Unit/dataUnitAttackUnitCommand.h
        src/server/model/Commands/Unit/serverUAttackUCommand.cpp
        src/server/model/Commands/Unit/serverUAttackUCommand.h
        src/common/DataCommands/Unit/dataUnitAttackBuildCommand.cpp
        src/common/DataCommands/Unit/dataUnitAttackBuildCommand.h
        src/server/model/Commands/Unit/serverUAttackBCommand.cpp
        src/server/model/Commands/Unit/serverUAttackBCommand.h
        src/common/DataCommands/Unit/dataUnitAttackTOCommand.cpp
        src/common/DataCommands/Unit/dataUnitAttackTOCommand.h
        src/server/model/Commands/Unit/serverUAttackTOCommand.cpp
        src/server/model/Commands/Unit/serverUAttackTOCommand.h
        src/common/DataCommands/Unit/dataUnitCaptureCommand.cpp
        src/common/DataCommands/Unit/dataUnitCaptureCommand.h
        src/server/model/Commands/Unit/serverUCaptureCommand.cpp
        src/server/model/Commands/Unit/serverUCaptureCommand.h
        src/common/DataCommands/Build/dataBuildChangeUnitCommand.cpp
        src/common/DataCommands/Build/dataBuildChangeUnitCommand.h
        src/server/model/Commands/Build/serverBChangeUCommand.cpp
        src/server/model/Commands/Build/serverBChangeUCommand.h
        src/server/serverCommandReceiver.cpp
        src/server/serverCommandReceiver.h
        src/common/Socket/Socket.cpp
        src/common/Socket/Socket.h
        src/common/Socket/SocketException.cpp
        src/common/Socket/SocketException.h
        src/common/Thread/Thread.cpp
        src/common/Thread/Thread.h
        src/server/model/realGameController.cpp
        src/server/model/realGameController.h
        src/server/model/protectedGameController.cpp
        src/server/model/protectedGameController.h
        src/server/serverGameController.cpp
        src/server/serverGameController.h
        src/server/serverEventSender.cpp
        src/server/serverEventSender.h
        src/server/serverMain.cpp
        src/server/serverPlayersManager.cpp
        src/server/serverPlayersManager.h
        src/common/DataClientServerMessages/dataClientConnectedMessage.cpp
        src/common/DataClientServerMessages/dataClientConnectedMessage.h
        src/common/DataClientServerMessages/dataServerClientAccepted.cpp
        src/common/DataClientServerMessages/dataServerClientAccepted.h
        src/common/Queue/Queue.h src/server/model/Events/Build/serverBUpdateTimeEvent.cpp src/server/model/Events/Build/serverBUpdateTimeEvent.h)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/src)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/src/server)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/src/client)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/src/common)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/src/storage)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/src/Exceptions)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/src/Utils)


#nota a futuro: la mayoria de esos flags del SDL2 vienen de ejecutar `sdl2-config --cflags --libs --static-libs` en la terminal (estan copipasteados). Habrá que ver como hacerlo bien a esto.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb -O0 -pg -std=c++11 -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2 -pthread -Wl,--no-undefined -lm -ldl -lasound -lm -ldl -lpulse-simple -lpulse -lX11 -lXext -lXcursor -lXinerama -lXi -lXrandr -lXss -lXxf86vm -lwayland-egl -lwayland-client -lwayland-cursor -lxkbcommon -lrt")


find_package(PkgConfig REQUIRED)

add_executable(tallerZ_Servidor ${SOURCE_FILES})

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
PKG_SEARCH_MODULE(SDL2MIXER REQUIRED SDL2_mixer>=2.0.0)
PKG_SEARCH_MODULE(SDL2TTF REQUIRED SDL2_ttf>=2.0.0)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS} ${SLD2MIXER_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} ${SDL2MIXER_LIBRARIES} ${SDL2TTF_LIBRARIES})
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/json/src)

target_link_libraries(${PROJECT_NAME})

