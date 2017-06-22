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
        src/common/DataEvents/Unit/DataUnitMoveEvent.cpp
        src/common/DataEvents/Unit/DataUnitMoveEvent.h
        src/server/model/Events/ServerEvent.cpp
        src/server/model/Events/ServerEvent.h
        src/server/model/Events/Unit/UnitAttackEvent.cpp
        src/server/model/Events/Unit/UnitAttackEvent.h
        src/common/DataEvents/Unit/DataUnitAttackEvent.cpp
        src/common/DataEvents/Unit/DataUnitAttackEvent.h
        src/server/model/Events/Unit/UnitMoveEvent.cpp
        src/server/model/Events/Unit/UnitMoveEvent.h
        src/common/DataEvents/Unit/DataUnitCreateEvent.cpp
        src/common/DataEvents/Unit/DataUnitCreateEvent.h
        src/server/model/Events/Unit/UnitCreateEvent.cpp
        src/server/model/Events/Unit/UnitCreateEvent.h
        src/common/DataEvents/Unit/DataUnitIDEvent.cpp
        src/common/DataEvents/Unit/DataUnitIDEvent.h
        src/server/model/Events/Unit/UnitDeathEvent.cpp
        src/server/model/Events/Unit/UnitDeathEvent.h
        src/server/model/Events/Unit/UnitStillEvent.cpp
        src/server/model/Events/Unit/UnitStillEvent.h
        src/common/DataEvents/Build/DataBuildUpdateEvent.cpp
        src/common/DataEvents/Build/DataBuildUpdateEvent.h
        src/server/model/Events/Build/BuildDamageEvent.cpp
        src/server/model/Events/Build/BuildDamageEvent.h
        src/common/DataEvents/Build/DataBuildIDEvent.cpp
        src/common/DataEvents/Build/DataBuildIDEvent.h
        src/server/model/Events/Build/BuildDestroyedEvent.cpp
        src/server/model/Events/Build/BuildDestroyedEvent.h
        src/common/DataEvents/Bullet/DataBulletNewEvent.cpp
        src/common/DataEvents/Bullet/DataBulletNewEvent.h
        src/server/model/Events/Bullet/BulletMoveEvent.cpp
        src/server/model/Events/Bullet/BulletMoveEvent.h
        src/server/model/Events/Bullet/BulletNewEvent.cpp
        src/server/model/Events/Bullet/BulletNewEvent.h
        src/common/DataEvents/Bullet/DataBulletMoveEvent.cpp
        src/common/DataEvents/Bullet/DataBulletMoveEvent.h
        src/common/DataEvents/Bullet/DataBulletHitEvent.cpp
        src/common/DataEvents/Bullet/DataBulletHitEvent.h
        src/server/model/Events/Bullet/BulletHitEvent.cpp
        src/server/model/Events/Bullet/BulletHitEvent.h
        src/common/DataEvents/Capturable/DataCaptureEvent.cpp
        src/common/DataEvents/Capturable/DataCaptureEvent.h
        src/server/model/Events/Capturable/CaptureEvent.cpp
        src/server/model/Events/Capturable/CaptureEvent.h
        src/common/DataEvents/TerrainObject/DataTerrainObjectIDEvent.cpp
        src/common/DataEvents/TerrainObject/DataTerrainObjectIDEvent.h
        src/server/model/Events/TerrainObject/TerrainObjectDestroyedEvent.cpp
        src/server/model/Events/TerrainObject/TerrainObjectDestroyedEvent.h
        src/common/DataEvents/Game/DataPlayerDefeatEvent.cpp
        src/common/DataEvents/Game/DataPlayerDefeatEvent.h
        src/server/model/Events/Game/GamePlayerDefeatedEvent.cpp
        src/server/model/Events/Game/GamePlayerDefeatedEvent.h
        src/common/DataEvents/Game/DataEndGameEvent.cpp
        src/common/DataEvents/Game/DataEndGameEvent.h
        src/server/model/Events/Game/GameEndGameEvent.cpp
        src/server/model/Events/Game/GameEndGameEvent.h
        src/common/DataCommands/CommandType.h
        src/common/DataCommands/Unit/DataUnitMoveCommand.cpp
        src/common/DataCommands/Unit/DataUnitMoveCommand.h
        src/server/model/Commands/Unit/UnitMoveCommand.cpp
        src/server/model/Commands/Unit/UnitMoveCommand.h
        src/server/model/Commands/Command.h
        src/server/model/Commands/CommandFactory.cpp
        src/server/model/Commands/CommandFactory.h
        src/common/DataCommands/Unit/DataUnitAttackUnitCommand.cpp
        src/common/DataCommands/Unit/DataUnitAttackUnitCommand.h
        src/server/model/Commands/Unit/UnitAttackUnitCommand.cpp
        src/server/model/Commands/Unit/UnitAttackUnitCommand.h
        src/common/DataCommands/Unit/DataUnitAttackBuildCommand.cpp
        src/common/DataCommands/Unit/DataUnitAttackBuildCommand.h
        src/server/model/Commands/Unit/UnitAttackBuildCommand.cpp
        src/server/model/Commands/Unit/UnitAttackBuildCommand.h
        src/common/DataCommands/Unit/DataUnitAttackTOCommand.cpp
        src/common/DataCommands/Unit/DataUnitAttackTOCommand.h
        src/server/model/Commands/Unit/UnitAttackTerrainObjectCommand.cpp
        src/server/model/Commands/Unit/UnitAttackTerrainObjectCommand.h
        src/common/DataCommands/Unit/DataUnitCaptureCommand.cpp
        src/common/DataCommands/Unit/DataUnitCaptureCommand.h
        src/server/model/Commands/Unit/UnitCaptureCommand.cpp
        src/server/model/Commands/Unit/UnitCaptureCommand.h
        src/common/DataCommands/Build/DataBuildChangeUnitCommand.cpp
        src/common/DataCommands/Build/DataBuildChangeUnitCommand.h
        src/server/model/Commands/Build/BuildChangeUnitCommand.cpp
        src/server/model/Commands/Build/BuildChangeUnitCommand.h
        src/server/CommandReceiver.cpp
        src/server/CommandReceiver.h
        src/common/Socket/Socket.cpp
        src/common/Socket/Socket.h
        src/common/Socket/SocketException.cpp
        src/common/Socket/SocketException.h
        src/common/Thread/Thread.cpp
        src/common/Thread/Thread.h
        src/server/model/RealGameController.cpp
        src/server/model/RealGameController.h
        src/server/model/ProtectedGameController.cpp
        src/server/model/ProtectedGameController.h
        src/server/GameController.h
        src/server/EventSender.cpp
        src/server/EventSender.h
        src/server/ServerMain.cpp
        src/server/PlayersManager.cpp
        src/server/PlayersManager.h
        src/common/DataClientServerMessages/DataClientConnectedMessage.cpp
        src/common/DataClientServerMessages/DataClientConnectedMessage.h
        src/common/DataClientServerMessages/DataServerClientAccepted.cpp
        src/common/DataClientServerMessages/DataServerClientAccepted.h
        src/common/Queue/Queue.h src/server/model/Events/Build/BuildUpdateTimeEvent.cpp src/server/model/Events/Build/BuildUpdateTimeEvent.h
        src/main.cpp src/tests/Data_to_json.cpp src/tests/Data_to_json.h src/tests/data_to_json_tests.cpp src/tests/Json_to_Data.cpp src/tests/Json_to_Data.h src/common/DataEvents/Unit/DataUnitStillEvent.cpp src/common/DataEvents/Unit/DataUnitStillEvent.h)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/src)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/src/server)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/src/client)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/src/common)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/src/storage)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/src/Exceptions)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/src/Utils)


#nota a futuro: la mayoria de esos flags del SDL2 vienen de ejecutar `sdl2-config --cflags --libs --static-libs` en la terminal (estan copipasteados). Habrá que ver como hacerlo bien a esto.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb -std=c++11 -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2 -pthread -Wl,--no-undefined -lm -ldl -lasound -lm -ldl -lpulse-simple -lpulse -lX11 -lXext -lXcursor -lXinerama -lXi -lXrandr -lXss -lXxf86vm -lwayland-egl -lwayland-client -lwayland-cursor -lxkbcommon -lrt")


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

# Download and unpack googletest at configure time
configure_file (CMakeLists.txt.in
        googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download)
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download)

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This adds
# the following targets: gtest, gtest_main, gmock
# and gmock_main
add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
        ${CMAKE_BINARY_DIR}/googletest-build)

# The gtest/gmock targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include"
            "${gmock_SOURCE_DIR}/include")
endif ()

# Now simply link your own targets against gtest, gmock,
# etc. as appropriate
include_directories(cmake-build-debug/googletest-src/googlemock/include)
include_directories(cmake-build-debug/googletest-src/googletest/include)
target_link_libraries(${PROJECT_NAME} gtest gtest_main)

target_link_libraries(${PROJECT_NAME})

