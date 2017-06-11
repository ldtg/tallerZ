cmake_minimum_required(VERSION 3.7)
project(tallerZ)

set(CMAKE_CXX_STANDARD 11)
include_directories(include)

set(SOURCE_FILES
        src/main.cpp
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
        src/common/Types/UnitType.h
        src/common/Types/WeaponType.h
        src/server/model/Data.cpp
        src/server/model/Data.h
        src/server/model/Robot.cpp
        src/server/model/Robot.h
        src/client/model/Events/model/unit/UnitAttackEvent.cpp
        src/client/model/Events/model/unit/UnitAttackEvent.h
        src/Exceptions/model_exceptions/UnitNotFoundException.cpp
        src/Exceptions/model_exceptions/UnitNotFoundException.h
        src/server/model/UnitData.h
        src/server/model/UnitFactory.cpp
        src/server/model/UnitFactory.h
        src/common/Map/TerrainData.h
        src/client/model/Events/model/unit/UnitMoveEvent.cpp
        src/client/model/Events/model/unit/UnitMoveEvent.h
        src/client/model/Events/Event.cpp
        src/client/model/Events/Event.h
        src/client/model/Events/model/unit/UnitDamageReceiveEvent.cpp
        src/client/model/Events/model/unit/UnitDamageReceiveEvent.h
        src/client/model/Events/model/unit/UnitDeathEvent.cpp
        src/client/model/Events/model/unit/UnitDeathEvent.h
        src/server/model/Vehicle.cpp
        src/server/model/Vehicle.h
        src/client/model/Events/Pointer/LeftClickEvent.cpp
        src/client/model/Events/Pointer/LeftClickEvent.h
        src/client/model/Events/EventHandler.cpp
        src/client/model/Events/EventHandler.h
        src/client/model/Events/view/QuitEvent.cpp
        src/client/model/Events/view/QuitEvent.h
        src/client/model/Events/view/CameraMove.cpp
        src/client/model/Events/view/CameraMove.h
        src/client/model/Events/Pointer/RightClickEvent.cpp
        src/client/model/Events/Pointer/RightClickEvent.h
        src/client/model/Model.cpp
        src/client/model/Model.h
        src/server/model/GameController.h
        src/server/model/GameController.cpp
        src/server/model/Bullet.cpp
        src/server/model/Bullet.h
        src/client/model/Events/model/bullet/BulletNewEvent.cpp
        src/client/model/Events/model/bullet/BulletNewEvent.h
        src/common/IDs/BulletID.cpp
        src/common/IDs/BulletID.h
        src/client/model/Events/model/bullet/BulletHitEvent.cpp
        src/client/model/Events/model/bullet/BulletHitEvent.h
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
        src/client/model/Events/model/game/PlayerDefeatedEvent.cpp
        src/client/model/Events/model/game/PlayerDefeatedEvent.h
        src/common/IDs/TeamID.cpp src/common/IDs/TeamID.h
        src/client/model/Events/model/game/EndGameEvent.cpp
        src/client/model/Events/model/game/EndGameEvent.h
        src/server/model/TerrainObject.cpp
        src/server/model/TerrainObject.h
        src/common/Types/TerrainObjectType.h
        src/common/IDs/TerrainObjectID.cpp
        src/common/IDs/TerrainObjectID.h
        src/client/model/Events/model/terrainObject/TerrainObjectDestroyedEvent.cpp
        src/client/model/Events/model/terrainObject/TerrainObjectDestroyedEvent.h
        src/common/States/TerrainObjectState.cpp
        src/common/States/TerrainObjectState.h
        src/server/model/TerrainObjectData.h
        src/common/Types/PlayerColor.h
        src/server/model/GaiaPlayer.cpp
        src/server/model/GaiaPlayer.h

        src/client/model/Events/model/build/BuildDamageEvent.cpp
        src/client/model/Events/model/build/BuildDamageEvent.h
        src/client/model/Events/model/build/BuildDestroyedEvent.cpp
        src/client/model/Events/model/build/BuildDestroyedEvent.h
        src/client/model/Events/model/unit/UnitCreateEvent.cpp
        src/client/model/Events/model/unit/UnitCreateEvent.h
        z_tests/tests_model/GameController_build_test.cpp
        src/client/model/Events/model/unit/UnitMoveStepEvent.cpp
        src/client/model/Events/model/unit/UnitMoveStepEvent.h
        src/client/model/Events/model/bullet/BulletMoveEvent.cpp
        src/client/model/Events/model/bullet/BulletMoveEvent.h
        src/client/model/Events/model/bullet/BulletMoveStepEvent.cpp
        src/client/model/Events/model/bullet/BulletMoveStepEvent.h
        src/client/model/Events/model/unit/UnitStillEvent.cpp
        src/client/model/Events/model/unit/UnitStillEvent.h
        z_tests/tests_model/GameController_objects_test.cpp
        z_tests/tests_model/GameController_win_test.cpp
        src/common/IDs/CapturableID.cpp
        src/common/IDs/CapturableID.h
        src/common/States/CapturableState.h
        src/common/Types/CapturableType.h
        src/server/model/Capturable.cpp
        src/server/model/Capturable.h
        src/client/model/Events/model/capturable/CaptureEvent.cpp
        src/client/model/Events/model/capturable/CaptureEvent.h
        src/server/model/CapturableVehicle.cpp
        src/server/model/CapturableVehicle.h
        src/server/model/MapType.h
        z_tests/tests_model/GameControllerCapturables_test.cpp
        src/common/Types/PlayerColor.h
        src/client/model/Events/view/CameraMoveStepEvent.cpp
        src/client/model/Events/view/CameraMoveStepEvent.h

        src/client/view/Texture.cpp
        src/client/view/Texture.h
        src/client/view/Window.cpp
        src/client/view/Window.h
        src/client/view/Panel.cpp
        src/client/view/Panel.h
        src/client/view/Image.cpp
        src/client/view/Image.h
        src/client/view/ObjectMapaVista.cpp
        src/client/view/ObjectMapaVista.h
        src/client/view/View.cpp
        src/client/view/View.h
        src/client/view/Sprite.cpp
        src/client/view/Sprite.h
        src/client/view/VistasFactory.cpp
        src/client/view/VistasFactory.h
        src/client/view/Camera.cpp
        src/client/view/Camera.h
        src/client/view/EffectType.h

        src/client/controller/Controller.cpp
        src/client/controller/Controller.h
        src/client/controller/Handler.h
        src/client/controller/HandlerFactory.cpp
        src/client/controller/HandlerFactory.h
        src/client/controller/MouseButtonLeft.cpp
        src/client/controller/MouseButtonLeft.h
        src/client/controller/NullHandler.cpp
        src/client/controller/NullHandler.h
        src/client/controller/Quit.cpp
        src/client/controller/Quit.h
        src/client/controller/MouseButtonRight.cpp
        src/client/controller/MouseButtonRight.h
        src/client/controller/MouseMotion.cpp
        src/client/controller/MouseMotion.h
        src/client/controller/MouseState.cpp
        src/client/controller/MouseState.h

        src/Exceptions/Sdl_Exceptions/Sdl_Exception.cpp
        src/Exceptions/Sdl_Exceptions/Sdl_Exception.h
        src/Exceptions/Front_end_exceptions/Generator_Exception.h
        src/Exceptions/Front_end_exceptions/Front_end_exception.cpp
        src/Exceptions/Map_Generator_Exceptions/Generator_Exception.h
        src/Exceptions/Map_Generator_Exceptions/Generator_Exception.cpp
        src/Exceptions/model_exceptions/UnableToFindAPathException.cpp
        src/Exceptions/model_exceptions/UnableToFindAPathException.h
        src/Exceptions/model_exceptions/UnableToBuildThatUnitException.cpp
        src/Exceptions/model_exceptions/UnableToBuildThatUnitException.h
        src/Exceptions/Map_Generator_Exceptions/Generator_Exception.h
        src/Exceptions/Map_Generator_Exceptions/Generator_Exception.cpp
        src/Exceptions/Storage_Exceptions/Storage_Exception.h
        src/Exceptions/Storage_Exceptions/Storage_Exception.cpp

        src/header_for_tests.h
        #z_tests/tests_front_end/FEnd_test.cpp
        z_tests/tests_model/GameController_test.cpp
        z_tests/tests_model/Map_test.cpp
        z_tests/tests_view/Vista_test.cpp
        z_tests/tests_model/Tile_test.cpp
        z_tests/tests_model/Robot_test.cpp
        z_tests/tests_model/AStar_test.cpp
        z_tests/tests_view/Window_test.cpp
        z_tests/tests_generator/Generator_test.cpp
        z_tests/tests_storage/store_map_tests.cpp

        src/SDL_START.cpp
        src/SDL_START.h

        #src/Z_RUNNER.cpp
        #src/Z_RUNNER.h
        src/client/front_end/SDL_Interface/Menus/Production/Buttons/Retract_Button.cpp
        src/client/front_end/SDL_Interface/Menus/Production/Buttons/Retract_Button.h
        src/client/front_end/SDL_Interface/Menus/Production/Buttons/Cancel_Button.cpp
        src/client/front_end/SDL_Interface/Menus/Production/Buttons/Cancel_Button.h
        src/client/front_end/SDL_Interface/Menus/Production/Buttons/Ok_Button.cpp
        src/client/front_end/SDL_Interface/Menus/Production/Buttons/Ok_Button.h
        src/client/front_end/SDL_Interface/Menus/Production/Buttons/Add_Button.cpp
        src/client/front_end/SDL_Interface/Menus/Production/Buttons/Add_Button.h
        src/client/front_end/SDL_Interface/Menus/Production/Buttons/Down_Button.h
        src/client/front_end/SDL_Interface/Menus/Production/Buttons/Down_Button.cpp
        src/client/front_end/SDL_Interface/Menus/Production/Buttons/Up_Button.cpp
        src/client/front_end/SDL_Interface/Menus/Production/Buttons/Up_Button.h

        src/client/front_end/SDL_Interface/Side_Board.cpp
        src/client/front_end/SDL_Interface/Side_Board.h
        src/client/front_end/SDL_Interface/Weapon_Img.cpp
        src/client/front_end/SDL_Interface/Weapon_Img.h
        src/client/front_end/SDL_Interface/Robot_Face.cpp
        src/client/front_end/SDL_Interface/Robot_Face.h
        src/client/front_end/SDL_Interface/Main_Window.cpp
        src/client/front_end/SDL_Interface/Main_Window.h
        src/client/front_end/SDL_Interface/Menus/Main/main_menu.cpp
        src/client/front_end/SDL_Interface/Menus/Main/main_menu.h
        src/client/front_end/SDL_Interface/Menus/Production/Production_Menu.cpp
        src/client/front_end/SDL_Interface/Menus/Production/Production_Menu.h
        src/client/front_end/SDL_Interface/Menus/Menu.cpp
        src/client/front_end/SDL_Interface/Menus/Menu.h
        src/client/front_end/SDL_Interface/Labels/Label.cpp
        src/client/front_end/SDL_Interface/Labels/Label.h
        src/client/front_end/SDL_Interface/Cursor.h
        src/client/front_end/SDL_Interface/Cursor.cpp
        src/client/front_end/SDL_Interface/Buttons/Button.cpp
        src/client/front_end/SDL_Interface/Buttons/Button.h
        src/client/front_end/SDL_Interface/Buttons/Menu_Button.cpp
        src/client/front_end/SDL_Interface/Buttons/Menu_Button.h

        src/map_generation/Generator.cpp
        src/map_generation/Generator.h

        src/storage/Game_Loader.h
        src/storage/Game_Loader.cpp
        src/storage/Store_map.cpp
        src/storage/Store_map.h

        z_sounds/Sound_event.h
        z_sounds/Sound_event.cpp

        z_tests/tests_storage/load_map_tests.cpp
        src/Exceptions/model_exceptions/BuildingNotFoundException.cpp
        src/Exceptions/model_exceptions/BuildingNotFoundException.h
        z_tests/tests_storage/load_map_tests.cpp
        src/client/model/GameControllerProxy.cpp
        src/client/model/GameControllerProxy.h
        src/common/DataEvents/EventType.h
        z_tests/test_server/serialize_Events_test.cpp
        src/common/DataEvents/dataEvent.cpp
        src/common/DataEvents/dataEvent.h
        src/common/DataEvents/Unit/dataUnitMoveEvent.cpp
        src/common/DataEvents/Unit/dataUnitMoveEvent.h
        src/server/model/Events/serverEvent.cpp
        src/server/model/Events/serverEvent.h
        src/client/model/Events/EventFactory.cpp
        src/client/model/Events/EventFactory.h
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
        src/common/DataEvents/Build/dataBuildDamageEvent.cpp
        src/common/DataEvents/Build/dataBuildDamageEvent.h
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
        src/server/model/Events/Game/serverGEndGameEvent.h src/common/DataCommands/CommandType.h src/common/DataCommands/Unit/dataUnitMoveCommand.cpp src/common/DataCommands/Unit/dataUnitMoveCommand.h src/server/model/Commands/Unit/serverUMoveCommand.cpp src/server/model/Commands/Unit/serverUMoveCommand.h src/server/model/Commands/serverCommand.cpp src/server/model/Commands/serverCommand.h src/client/model/Commands/clientCommand.cpp src/client/model/Commands/clientCommand.h src/client/model/Commands/Unit/clientUnitMoveCommand.cpp src/client/model/Commands/Unit/clientUnitMoveCommand.h src/server/model/Commands/serverCommandFactory.cpp src/server/model/Commands/serverCommandFactory.h src/common/DataCommands/Unit/dataUnitAttackUnitCommand.cpp src/common/DataCommands/Unit/dataUnitAttackUnitCommand.h src/client/model/Commands/Unit/clientUnitAttackUnitCommand.cpp src/client/model/Commands/Unit/clientUnitAttackUnitCommand.h src/server/model/Commands/Unit/serverUAttackUCommand.cpp src/server/model/Commands/Unit/serverUAttackUCommand.h src/common/DataCommands/Unit/dataUnitAttackBuildCommand.cpp src/common/DataCommands/Unit/dataUnitAttackBuildCommand.h src/client/model/Commands/Unit/clientUnitAttackBuildCommand.cpp src/client/model/Commands/Unit/clientUnitAttackBuildCommand.h src/server/model/Commands/Unit/serverUAttackBCommand.cpp src/server/model/Commands/Unit/serverUAttackBCommand.h src/common/DataCommands/Unit/dataUnitAttackTOCommand.cpp src/common/DataCommands/Unit/dataUnitAttackTOCommand.h src/client/model/Commands/Unit/clientUnitAttackTOCommand.cpp src/client/model/Commands/Unit/clientUnitAttackTOCommand.h src/server/model/Commands/Unit/serverUAttackTOCommand.cpp src/server/model/Commands/Unit/serverUAttackTOCommand.h src/common/DataCommands/Unit/dataUnitCaptureCommand.cpp src/common/DataCommands/Unit/dataUnitCaptureCommand.h src/client/model/Commands/Unit/clientUnitCaptureCommand.cpp src/client/model/Commands/Unit/clientUnitCaptureCommand.h src/server/model/Commands/Unit/serverUCaptureCommand.cpp src/server/model/Commands/Unit/serverUCaptureCommand.h src/common/DataCommands/Build/dataBuildChangeUnitCommand.cpp src/common/DataCommands/Build/dataBuildChangeUnitCommand.h src/client/model/Commands/Build/clientBuildChangeUnitCommand.cpp src/client/model/Commands/Build/clientBuildChangeUnitCommand.h src/server/model/Commands/Build/serverBChangeUCommand.cpp src/server/model/Commands/Build/serverBChangeUCommand.h)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/src)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/src/server)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/src/client)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/src/common)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/src/storage)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/src/Exceptions)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/src/Utils)


#nota a futuro: la mayoria de esos flags del SDL2 vienen de ejecutar `sdl2-config --cflags --libs --static-libs` en la terminal (estan copipasteados). Habrá que ver como hacerlo bien a esto.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb -O0 -pg -std=c++11 -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2 -lpthread -Wl,--no-undefined -lm -ldl -lasound -lm -ldl -lpthread -lpulse-simple -lpulse -lX11 -lXext -lXcursor -lXinerama -lXi -lXrandr -lXss -lXxf86vm -lwayland-egl -lwayland-client -lwayland-cursor -lxkbcommon -lpthread -lrt")


find_package(PkgConfig REQUIRED)

add_executable(tallerZ ${SOURCE_FILES})

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
#target_link_libraries(${PROJECT_NAME} ${GTK3_LIBRARIES} ${GTKMM_LIBRARIES})
target_link_libraries(${PROJECT_NAME})

