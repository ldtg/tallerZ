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
        src/client/model/Events/model/bullet/BulletMoveEvent.cpp
        src/client/model/Events/model/bullet/BulletMoveEvent.h
        src/client/model/Events/model/unit/UnitStillEvent.cpp
        src/client/model/Events/model/unit/UnitStillEvent.h
        src/common/IDs/CapturableID.cpp
        src/common/IDs/CapturableID.h
        src/common/States/CapturableState.h
        src/common/Types/CapturableType.h
        src/client/model/Events/model/capturable/CaptureEvent.cpp
        src/client/model/Events/model/capturable/CaptureEvent.h
        src/common/Types/PlayerColor.h

        src/client/view/Texture.cpp
        src/client/view/Texture.h
        src/client/view/Window.cpp
        src/client/view/Window.h
        src/client/view/Image.cpp
        src/client/view/Image.h
        src/client/view/ObjectView.cpp
        src/client/view/ObjectView.h
        src/client/view/View.cpp
        src/client/view/View.h
        src/client/view/Sprite.cpp
        src/client/view/Sprite.h
        src/client/view/ViewFactory.cpp
        src/client/view/ViewFactory.h
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

        src/client/front_end/SDL_Interface/Menus/Production/Buttons/Build_Button.cpp
        src/client/front_end/SDL_Interface/Menus/Production/Buttons/Build_Button.h
        src/client/front_end/SDL_Interface/Menus/Production/Buttons/Down_Button.h
        src/client/front_end/SDL_Interface/Menus/Production/Buttons/Down_Button.cpp
        src/client/front_end/SDL_Interface/Menus/Production/Buttons/Up_Button.cpp
        src/client/front_end/SDL_Interface/Menus/Production/Buttons/Up_Button.h

        src/client/front_end/SDL_Interface/Side_Board.cpp
        src/client/front_end/SDL_Interface/Side_Board.h
        src/client/front_end/SDL_Interface/Menus/Quit/Quit_Menu.cpp
        src/client/front_end/SDL_Interface/Menus/Quit/Quit_Menu.h
        src/client/front_end/SDL_Interface/Menus/Production/Production_Menu.cpp
        src/client/front_end/SDL_Interface/Menus/Production/Production_Menu.h
        src/client/front_end/SDL_Interface/Menus/Menu.cpp
        src/client/front_end/SDL_Interface/Menus/Menu.h
        src/client/front_end/SDL_Interface/Menus/Result/Victory.h
        src/client/front_end/SDL_Interface/Menus/Result/Victory.cpp
        src/client/front_end/SDL_Interface/Labels/Label.cpp
        src/client/front_end/SDL_Interface/Labels/Label.h
        src/client/front_end/SDL_Interface/Cursor.h
        src/client/front_end/SDL_Interface/Cursor.cpp
        src/client/front_end/SDL_Interface/Buttons/Button.cpp
        src/client/front_end/SDL_Interface/Buttons/Button.h
        src/client/front_end/SDL_Interface/Buttons/Quit_Button.cpp
        src/client/front_end/SDL_Interface/Buttons/Quit_Button.h

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
        src/common/DataEvents/Build/dataBuildUpdateEvent.cpp
        src/common/DataEvents/Build/dataBuildUpdateEvent.h
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
        src/common/Queue/Queue.h

        src/client/front_end/SDL_Interface/Menus/Quit/Buttons/Salir_Button.h
        src/client/front_end/SDL_Interface/Menus/Quit/Buttons/Salir_Button.cpp
        src/client/front_end/SDL_Interface/Menus/Quit/Quit_Menu.h
        src/client/front_end/SDL_Interface/Menus/Quit/Quit_Menu.cpp

        src/client/view/unit/UnitView.cpp src/client/view/unit/UnitView.h
        src/client/model/Events/model/build/BuildUpdateEvent.cpp
        src/client/model/Events/model/build/BuildUpdateEvent.h
        src/client/view/ObjectViewMove.cpp src/client/view/ObjectViewMove.h
        src/client/view/bullet/BulletView.cpp src/client/view/bullet/BulletView.h
        src/client/view/sounds/Sound.cpp src/client/view/sounds/Sound.h
        src/client/view/sounds/SoundPlayer.cpp src/client/view/sounds/SoundPlayer.h
        src/client/view/sounds/SoundsFactory.cpp src/client/view/sounds/SoundsFactory.h
        src/common/Thread/Lock.h
        src/client/view/unit/VehicleView.cpp src/client/view/unit/VehicleView.h

        src/client/view/unit/UnitView.cpp src/client/view/unit/UnitView.h
        src/client/view/ViewPosition.cpp
        src/client/view/ViewPosition.h
        src/client/view/unit/UnitView.cpp
        src/client/view/unit/UnitView.h
        src/client/model/Events/model/build/BuildUpdateEvent.cpp
        src/client/model/Events/model/build/BuildUpdateEvent.h
        src/client/view/ObjectViewMove.cpp
        src/client/view/ObjectViewMove.h
        src/client/view/bullet/BulletView.cpp
        src/client/view/bullet/BulletView.h
        src/client/view/sounds/Sound.cpp
        src/client/view/sounds/Sound.h
        src/client/view/sounds/SoundPlayer.cpp
        src/client/view/sounds/SoundPlayer.h
        src/client/view/sounds/SoundsFactory.cpp
        src/client/view/sounds/SoundsFactory.h
        src/common/Thread/Lock.h
        src/client/front_end/SDL_Interface/Menus/Result/Defeat.cpp
        src/client/front_end/SDL_Interface/Menus/Result/Defeat.h
        src/client/front_end/SDL_Interface/Menus/Result/Buttons/Ok_Button.cpp

        src/client/front_end/SDL_Interface/Menus/Result/Buttons/Ok_Button.h
        src/client/lobby/clientLobby.h
        src/client/lobby/clientLobby.cpp
        src/Exceptions/lobby_exceptions/Close_Exception.h
        src/Exceptions/lobby_exceptions/Close_Exception.cpp
        src/client/front_end/SDL_Interface/Menus/Result/Buttons/Ok_Button.h
        src/common/DataEvents/Unit/dataUnitStillEvent.cpp
        src/common/DataEvents/Unit/dataUnitStillEvent.h
        src/client/model/MovementState.h
        src/client/view/unit/RobotView.cpp src/client/view/unit/RobotView.h src/client/view/explosion/ExplosionView.h src/client/view/explosion/RocketHitView.cpp src/client/view/explosion/RocketHitView.h src/client/view/explosion/HCBulletHitView.cpp src/client/view/explosion/HCBulletHitView.h src/client/view/explosion/FireHitView.cpp src/client/view/explosion/FireHitView.h src/client/view/explosion/LaserHitView.cpp src/client/view/explosion/LaserHitView.h src/client/view/explosion/UnitDeathView.cpp src/client/view/explosion/UnitDeathView.h src/client/view/building/BuildingView.h src/client/view/building/FortView.cpp src/client/view/building/FortView.h src/client/view/building/RobotFView.cpp src/client/view/building/RobotFView.h src/client/view/building/VehicleFView.cpp src/client/view/building/VehicleFView.h src/client/view/building/BuildingEffectType.h src/client/view/building/BuildingView.cpp)



INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/src)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/src/client)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/src/common)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/src/storage)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/src/Exceptions)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/src/Utils)

#nota a futuro: la mayoria de esos flags del SDL2 vienen de ejecutar `sdl2-config --cflags --libs --static-libs` en la terminal (estan copipasteados). Habrá que ver como hacerlo bien a esto.

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb -std=c++11 -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2 -pthread -Wl,--no-undefined -lm -ldl -lasound -lm -ldl -lpulse-simple -lpulse -lX11 -lXext -lXcursor -lXinerama -lXi -lXrandr -lXss -lXxf86vm -lwayland-egl -lwayland-client -lwayland-cursor -lxkbcommon -lrt")

#gtkmm-3.0
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread -I/usr/include/gtkmm-3.0 -I/usr/lib/x86_64-linux-gnu/gtkmm-3.0/include -I/usr/include/atkmm-1.6 -I/usr/include/giomm-2.4 -I/usr/lib/x86_64-linux-gnu/giomm-2.4/include -I/usr/include/pangomm-1.4 -I/usr/lib/x86_64-linux-gnu/pangomm-1.4/include -I/usr/include/gtk-3.0 -I/usr/include/cairomm-1.0 -I/usr/lib/x86_64-linux-gnu/cairomm-1.0/include -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/gtk-3.0/unix-print -I/usr/include/gdkmm-3.0 -I/usr/lib/x86_64-linux-gnu/gdkmm-3.0/include -I/usr/include/atk-1.0 -I/usr/include/glibmm-2.4 -I/usr/lib/x86_64-linux-gnu/glibmm-2.4/include -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/sigc++-2.0 -I/usr/lib/x86_64-linux-gnu/sigc++-2.0/include -I/usr/include/pango-1.0 -I/usr/include/cairo -I/usr/include/pixman-1 -I/usr/include/freetype2 -I/usr/include/libpng12 -I/usr/include/at-spi2-atk/2.0 -I/usr/include/gio-unix-2.0/ -I/usr/include/harfbuzz -lgtkmm-3.0 -latkmm-1.6 -lgdkmm-3.0 -lgiomm-2.4 -lpangomm-1.4 -lgtk-3 -lglibmm-2.4 -lcairomm-1.0 -lgdk-3 -latk-1.0 -lgio-2.0 -lpangocairo-1.0 -lgdk_pixbuf-2.0 -lcairo-gobject -lpango-1.0 -lcairo -lsigc-2.0 -lgobject-2.0 -lglib-2.0")

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
pkg_check_modules(GTKMM gtkmm-3.0)

include_directories(${GTK3_INCLUDE_DIRS}
        ${GTKMM_INCLUDE_DIRS})

link_directories(${GTK3_LIBRARY_DIRS}
        ${GTKMM_LIBRARY_DIRS})

add_definitions(${GTK3_CFLAGS_OTHER})


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
target_link_libraries(${PROJECT_NAME} ${GTK3_LIBRARIES} ${GTKMM_LIBRARIES})

target_link_libraries(${PROJECT_NAME})
