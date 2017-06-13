cmake_minimum_required(VERSION 3.7)
project(tallerZ_Cliente)

set(CMAKE_CXX_STANDARD 11)
include_directories(include)

set(SOURCE_FILES

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
        src/client/model/Events/model/unit/UnitAttackEvent.cpp
        src/client/model/Events/model/unit/UnitAttackEvent.h
        src/Exceptions/model_exceptions/UnitNotFoundException.cpp
        src/Exceptions/model_exceptions/UnitNotFoundException.h
        src/common/Map/TerrainData.h
        src/client/model/Events/model/unit/UnitMoveEvent.cpp
        src/client/model/Events/model/unit/UnitMoveEvent.h
        src/client/model/Events/Event.cpp
        src/client/model/Events/Event.h
        src/client/model/Events/model/unit/UnitDamageReceiveEvent.cpp
        src/client/model/Events/model/unit/UnitDamageReceiveEvent.h
        src/client/model/Events/model/unit/UnitDeathEvent.cpp
        src/client/model/Events/model/unit/UnitDeathEvent.h
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
        src/client/model/Events/model/bullet/BulletNewEvent.cpp
        src/client/model/Events/model/bullet/BulletNewEvent.h
        src/common/IDs/BulletID.cpp
        src/common/IDs/BulletID.h
        src/client/model/Events/model/bullet/BulletHitEvent.cpp
        src/client/model/Events/model/bullet/BulletHitEvent.h
        src/common/States/BulletState.cpp
        src/common/States/BulletState.h
        src/common/IDs/PlayerID.cpp
        src/common/IDs/PlayerID.h
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
        src/common/Types/TerrainObjectType.h
        src/common/IDs/TerrainObjectID.cpp
        src/common/IDs/TerrainObjectID.h
        src/client/model/Events/model/terrainObject/TerrainObjectDestroyedEvent.cpp
        src/client/model/Events/model/terrainObject/TerrainObjectDestroyedEvent.h
        src/common/States/TerrainObjectState.cpp
        src/common/States/TerrainObjectState.h
        src/common/Types/PlayerColor.h

        src/client/model/Events/model/build/BuildDamageEvent.cpp
        src/client/model/Events/model/build/BuildDamageEvent.h
        src/client/model/Events/model/build/BuildDestroyedEvent.cpp
        src/client/model/Events/model/build/BuildDestroyedEvent.h
        src/client/model/Events/model/unit/UnitCreateEvent.cpp
        src/client/model/Events/model/unit/UnitCreateEvent.h
        src/client/model/Events/model/unit/UnitMoveStepEvent.cpp
        src/client/model/Events/model/unit/UnitMoveStepEvent.h
        src/client/model/Events/model/bullet/BulletMoveEvent.cpp
        src/client/model/Events/model/bullet/BulletMoveEvent.h
        src/client/model/Events/model/bullet/BulletMoveStepEvent.cpp
        src/client/model/Events/model/bullet/BulletMoveStepEvent.h
        src/client/model/Events/model/unit/UnitStillEvent.cpp
        src/client/model/Events/model/unit/UnitStillEvent.h
        src/common/IDs/CapturableID.cpp
        src/common/IDs/CapturableID.h
        src/common/States/CapturableState.h
        src/common/Types/CapturableType.h
        src/client/model/Events/model/capturable/CaptureEvent.cpp
        src/client/model/Events/model/capturable/CaptureEvent.h
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
        src/Exceptions/model_exceptions/UnableToFindAPathException.cpp
        src/Exceptions/model_exceptions/UnableToFindAPathException.h
        src/Exceptions/model_exceptions/UnableToBuildThatUnitException.cpp
        src/Exceptions/model_exceptions/UnableToBuildThatUnitException.h
        src/Exceptions/Storage_Exceptions/Storage_Exception.h
        src/Exceptions/Storage_Exceptions/Storage_Exception.cpp

        #src/Z_RUNNER.cpp
        #src/Z_RUNNER.h
        src/client/front_end/SDL_Interface/Menus/Production/Buttons/Retract_Button.cpp
        src/client/front_end/SDL_Interface/Menus/Production/Buttons/Retract_Button.h
        src/client/front_end/SDL_Interface/Menus/Production/Buttons/Build_Button.cpp
        src/client/front_end/SDL_Interface/Menus/Production/Buttons/Build_Button.h
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
        src/client/front_end/SDL_Interface/Menus/Quit/Quit_Menu.cpp
        src/client/front_end/SDL_Interface/Menus/Quit/Quit_Menu.h
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
        src/client/front_end/SDL_Interface/Buttons/Quit_Button.cpp
        src/client/front_end/SDL_Interface/Buttons/Quit_Button.h

        z_sounds/Sound_event.h
        z_sounds/Sound_event.cpp

        src/Exceptions/model_exceptions/BuildingNotFoundException.cpp
        src/Exceptions/model_exceptions/BuildingNotFoundException.h
        src/client/model/GameControllerProxy.cpp
        src/client/model/GameControllerProxy.h
        src/common/DataEvents/EventType.h
        src/common/DataEvents/dataEvent.cpp
        src/common/DataEvents/dataEvent.h
        src/common/DataEvents/Unit/dataUnitMoveEvent.cpp
        src/common/DataEvents/Unit/dataUnitMoveEvent.h
        src/client/model/Events/EventFactory.cpp
        src/client/model/Events/EventFactory.h
        src/common/DataEvents/Unit/dataUnitAttackEvent.cpp
        src/common/DataEvents/Unit/dataUnitAttackEvent.h
        src/common/DataEvents/Unit/dataUnitCreateEvent.cpp
        src/common/DataEvents/Unit/dataUnitCreateEvent.h
        src/common/DataEvents/Unit/dataUnitIDEvent.cpp
        src/common/DataEvents/Unit/dataUnitIDEvent.h
        src/common/DataEvents/Build/dataBuildDamageEvent.cpp
        src/common/DataEvents/Build/dataBuildDamageEvent.h
        src/common/DataEvents/Build/dataBuildIDEvent.cpp
        src/common/DataEvents/Build/dataBuildIDEvent.h
        src/common/DataEvents/Bullet/dataBulletNewEvent.cpp
        src/common/DataEvents/Bullet/dataBulletNewEvent.h
        src/common/DataEvents/Bullet/dataBulletMoveEvent.cpp
        src/common/DataEvents/Bullet/dataBulletMoveEvent.h
        src/common/DataEvents/Bullet/dataBulletHitEvent.cpp
        src/common/DataEvents/Bullet/dataBulletHitEvent.h
        src/common/DataEvents/Capturable/dataCaptureEvent.cpp
        src/common/DataEvents/Capturable/dataCaptureEvent.h
        src/common/DataEvents/TerrainObject/dataTerrainObjectIDEvent.cpp
        src/common/DataEvents/TerrainObject/dataTerrainObjectIDEvent.h
        src/common/DataEvents/Game/dataPlayerDefeatEvent.cpp
        src/common/DataEvents/Game/dataPlayerDefeatEvent.h
        src/common/DataEvents/Game/dataEndGameEvent.cpp
        src/common/DataEvents/Game/dataEndGameEvent.h

        src/common/DataCommands/CommandType.h
        src/common/DataCommands/Unit/dataUnitMoveCommand.cpp
        src/common/DataCommands/Unit/dataUnitMoveCommand.h
        src/client/model/Commands/clientCommand.cpp
        src/client/model/Commands/clientCommand.h
        src/client/model/Commands/Unit/clientUnitMoveCommand.cpp
        src/client/model/Commands/Unit/clientUnitMoveCommand.h
        src/common/DataCommands/Unit/dataUnitAttackUnitCommand.cpp
        src/common/DataCommands/Unit/dataUnitAttackUnitCommand.h
        src/client/model/Commands/Unit/clientUnitAttackUnitCommand.cpp
        src/client/model/Commands/Unit/clientUnitAttackUnitCommand.h
        src/common/DataCommands/Unit/dataUnitAttackBuildCommand.cpp
        src/common/DataCommands/Unit/dataUnitAttackBuildCommand.h
        src/client/model/Commands/Unit/clientUnitAttackBuildCommand.cpp
        src/client/model/Commands/Unit/clientUnitAttackBuildCommand.h
        src/common/DataCommands/Unit/dataUnitAttackTOCommand.cpp
        src/common/DataCommands/Unit/dataUnitAttackTOCommand.h
        src/client/model/Commands/Unit/clientUnitAttackTOCommand.cpp
        src/client/model/Commands/Unit/clientUnitAttackTOCommand.h
        src/common/DataCommands/Unit/dataUnitCaptureCommand.cpp
        src/common/DataCommands/Unit/dataUnitCaptureCommand.h
        src/client/model/Commands/Unit/clientUnitCaptureCommand.cpp
        src/client/model/Commands/Unit/clientUnitCaptureCommand.h
        src/common/DataCommands/Build/dataBuildChangeUnitCommand.cpp
        src/common/DataCommands/Build/dataBuildChangeUnitCommand.h
        src/client/model/Commands/Build/clientBuildChangeUnitCommand.cpp
        src/client/model/Commands/Build/clientBuildChangeUnitCommand.h
        src/common/Socket/Socket.cpp
        src/common/Socket/Socket.h
        src/common/Socket/SocketException.cpp
        src/common/Socket/SocketException.h
        src/common/Thread/Thread.cpp
        src/common/Thread/Thread.h
        src/client/clientEventReceiver.cpp
        src/client/clientEventReceiver.h
        src/client/clientCommandSender.cpp
        src/client/clientCommandSender.h
        src/client/clientMain.cpp
        src/common/DataClientServerMessages/dataClientConnectedMessage.cpp
        src/common/DataClientServerMessages/dataClientConnectedMessage.h
        src/common/DataClientServerMessages/dataServerClientAccepted.cpp
        src/common/DataClientServerMessages/dataServerClientAccepted.h
        src/client/clientRunner.cpp
        src/client/clientRunner.h
        src/common/Queue/Queue.h

        src/client/front_end/SDL_Interface/Menus/Quit/Buttons/Salir_Button.h
        src/client/front_end/SDL_Interface/Menus/Quit/Buttons/Salir_Button.cpp
        src/client/front_end/SDL_Interface/Menus/Quit/Quit_Menu.h
        src/client/front_end/SDL_Interface/Menus/Quit/Quit_Menu.cpp


        )

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/src)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/src/client)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/src/common)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/src/storage)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/src/Exceptions)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/src/Utils)


#nota a futuro: la mayoria de esos flags del SDL2 vienen de ejecutar `sdl2-config --cflags --libs --static-libs` en la terminal (estan copipasteados). Habrá que ver como hacerlo bien a esto.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb -O0 -pg -std=c++11 -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2 -pthread -Wl,--no-undefined -lm -ldl -lasound -lm -ldl -lpulse-simple -lpulse -lX11 -lXext -lXcursor -lXinerama -lXi -lXrandr -lXss -lXxf86vm -lwayland-egl -lwayland-client -lwayland-cursor -lxkbcommon -lpthread -lrt")


find_package(PkgConfig REQUIRED)

add_executable(tallerZ_Cliente ${SOURCE_FILES})

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
PKG_SEARCH_MODULE(SDL2MIXER REQUIRED SDL2_mixer>=2.0.0)
PKG_SEARCH_MODULE(SDL2TTF REQUIRED SDL2_ttf>=2.0.0)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS} ${SLD2MIXER_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} ${SDL2MIXER_LIBRARIES} ${SDL2TTF_LIBRARIES})
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/json/src)

target_link_libraries(${PROJECT_NAME})
