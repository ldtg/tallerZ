cmake_minimum_required(VERSION 3.7)
project(tallerZ)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        src/main.cpp
        src/model/Map.cpp
        src/model/Map.h
        z_tests/tests_model/Map_test.cpp
        src/model/Position.cpp
        src/model/Position.h
        src/model/Tile.cpp
        src/model/Tile.h
        z_tests/tests_model/Tile_test.cpp
        src/model/TerrainType.h
        src/model/UnitID.cpp
        src/model/UnitID.h
        src/model/UnitState.cpp
        src/model/UnitState.h
        src/model/AStar.cpp
        src/model/AStar.h
        z_tests/tests_model/AStar_test.cpp
        src/model/Node.cpp
        src/model/Node.h
        src/model/Unit.cpp
        src/model/Unit.h
        src/model/MovementState.h
        src/model/Weapon.cpp
        src/model/Weapon.h
        src/model/Attackable.h
        src/model/UnitType.h
        src/model/WeaponType.h
        src/model/Data.cpp
        src/model/Data.h
        src/model/Robot.cpp
        src/model/Robot.h
        z_tests/tests_model/Robot_test.cpp
        z_tests/tests_model/AStar_test.cpp
        src/model/GameController.cpp
        src/model/GameController.h
        src/model/UnitAttackEvent.cpp
        src/model/UnitAttackEvent.h
        src/model/Build.cpp
        src/model/Build.h
        src/model/BuildID.cpp
        src/model/BuildID.h
        src/model/BuildType.h
        src/model/UnitNotFoundException.cpp
        src/model/UnitNotFoundException.h
        src/model/UnitData.h
        src/model/UnitFactory.cpp
        src/model/UnitFactory.h
        src/model/TerrainData.h
        src/model/UnitMoveEvent.cpp
        src/model/UnitMoveEvent.h
        src/model/Event.cpp
        src/model/Event.h
        src/model/UnitDamageReceiveEvent.cpp
        src/model/UnitDamageReceiveEvent.h
        z_tests/tests_model/GameController_test.cpp
        src/model/UnitDeathEvent.cpp
        src/model/UnitDeathEvent.h
        src/model/Vehicle.cpp
        src/model/Vehicle.h
        #[[
        src/model/BuildAttackEvent.cpp
        src/model/BuildAttackEvent.h
        z_sounds/Sound_event.cpp
        z_sounds/Sound_event.h
        src/storage/Store_settings.cpp
        src/storage/Store_settings.h
        src/storage/Store_map.cpp
        src/storage/Store_map.h
        z_tests/tests_sounds/basic_test.cpp
        z_tests/tests_storage/store_map_tests.cpp
        src/storage/Store_settings.cpp
        src/storage/Store_settings.h
        src/storage/Store_map.cpp
        src/storage/Store_map.h
        z_tests/tests_sounds/basic_test.cpp
        z_tests/tests_storage/store_map_tests.cpp
        ]]
        src/vista/Window.cpp
        src/vista/Window.h
        src/vista/Panel.cpp
        src/vista/Panel.h
        src/vista/Image.cpp
        src/vista/Image.h
        src/vista/ObjectMapaVista.cpp
        src/vista/ObjectMapaVista.h
        z_tests/tests_model/Vista_test.cpp
        src/vista/Vista.cpp
        src/vista/Vista.h
        src/vista/Sprite.cpp
        src/vista/Sprite.h


        src/front_end/Timer.h
        src/front_end/Timer.cpp
        ############
        src/Exceptions/Front_end_exceptions/Front_end_exception.h
        src/Exceptions/Front_end_exceptions/Front_end_exception.cpp
        ############
        z_tests/tests_model/Vista_test.cpp
        z_tests/tests_model/GameController_test.cpp
        src/model/UnitData.h
        #src/model/RobotFactory.cpp
        #src/model/RobotFactory.h
        src/model/TerrainData.h
        src/model/UnitMoveEvent.cpp
        src/model/UnitMoveEvent.h
        src/model/Event.cpp
        src/model/Event.h
        src/model/UnitAttackEvent.cpp
        src/model/UnitAttackEvent.h
        src/model/UnitDamageReceiveEvent.cpp
        src/model/UnitDamageReceiveEvent.h
        src/model/UnitDeathEvent.cpp
        src/model/UnitDeathEvent.h
        src/model/Vehicle.cpp
        src/model/Vehicle.h z_tests/tests_front_end/FEnd_test.cpp src/header_for_tests.h src/front_end/SDL_Interface/Weapon_Img.cpp src/front_end/SDL_Interface/Weapon_Img.h src/front_end/SDL_Interface/Main_Window.cpp src/front_end/SDL_Interface/Main_Window.h src/SDL_START.cpp src/SDL_START.h src/Exceptions/Sdl_Exceptions/Sdl_Exception.cpp src/Exceptions/Sdl_Exceptions/Sdl_Exception.h src/front_end/SDL_Interface/Side_Board.cpp src/front_end/SDL_Interface/Side_Board.h src/Utils/Sdl_Utils.cpp src/Utils/Sdl_Utils.h)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/src)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/src/model)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/src/storage)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/src/Exceptions)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/src/Utils)


#nota a futuro: la mayoria de esos flags del SDL2 vienen de ejecutar `sdl2-config --cflags --libs --static-libs` en la terminal (estan copipasteados). Habrá que ver como hacerlo bien a esto.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2 -lpthread -Wl,--no-undefined -lm -ldl -lasound -lm -ldl -lpthread -lpulse-simple -lpulse -lX11 -lXext -lXcursor -lXinerama -lXi -lXrandr -lXss -lXxf86vm -lwayland-egl -lwayland-client -lwayland-cursor -lxkbcommon -lpthread -lrt")

#gtkmm-3.0
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread -I/usr/include/gtkmm-3.0 -I/usr/lib/x86_64-linux-gnu/gtkmm-3.0/include -I/usr/include/atkmm-1.6 -I/usr/include/giomm-2.4 -I/usr/lib/x86_64-linux-gnu/giomm-2.4/include -I/usr/include/pangomm-1.4 -I/usr/lib/x86_64-linux-gnu/pangomm-1.4/include -I/usr/include/gtk-3.0 -I/usr/include/cairomm-1.0 -I/usr/lib/x86_64-linux-gnu/cairomm-1.0/include -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/gtk-3.0/unix-print -I/usr/include/gdkmm-3.0 -I/usr/lib/x86_64-linux-gnu/gdkmm-3.0/include -I/usr/include/atk-1.0 -I/usr/include/glibmm-2.4 -I/usr/lib/x86_64-linux-gnu/glibmm-2.4/include -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/sigc++-2.0 -I/usr/lib/x86_64-linux-gnu/sigc++-2.0/include -I/usr/include/pango-1.0 -I/usr/include/cairo -I/usr/include/pixman-1 -I/usr/include/freetype2 -I/usr/include/libpng12 -I/usr/include/at-spi2-atk/2.0 -I/usr/include/gio-unix-2.0/ -I/usr/include/harfbuzz -lgtkmm-3.0 -latkmm-1.6 -lgdkmm-3.0 -lgiomm-2.4 -lpangomm-1.4 -lgtk-3 -lglibmm-2.4 -lcairomm-1.0 -lgdk-3 -latk-1.0 -lgio-2.0 -lpangocairo-1.0 -lgdk_pixbuf-2.0 -lcairo-gobject -lpango-1.0 -lcairo -lsigc-2.0 -lgobject-2.0 -lglib-2.0")

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
pkg_check_modules(GTKMM gtkmm-3.0)

include_directories(${GTK3_INCLUDE_DIRS}
        ${GTKMM_INCLUDE_DIRS})

link_directories(${GTK3_LIBRARY_DIRS}
        ${GTKMM_LIBRARY_DIRS})

add_definitions(${GTK3_CFLAGS_OTHER})

add_executable(tallerZ ${SOURCE_FILES})

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
PKG_SEARCH_MODULE(SDL2MIXER REQUIRED SDL2_mixer>=2.0.0)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS} ${SLD2MIXER_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} ${SDL2MIXER_LIBRARIES})
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/json/src)

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in
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
target_link_libraries(${PROJECT_NAME} ${GTK3_LIBRARIES} ${GTKMM_LIBRARIES})
