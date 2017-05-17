cmake_minimum_required(VERSION 3.7)
project(tallerZ)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        src/main.cpp
        src/model/Map.cpp
        src/model/Map.h
        src/model/Position.cpp
        src/model/Position.h
        src/model/Tile.cpp
        src/model/Tile.h
        src/model/TerrainType.h
        src/model/Movement.h
        src/model/UnitID.cpp
        src/model/UnitID.h
        src/model/UnitState.cpp
        src/model/UnitState.h
        src/model/AStar.cpp
        src/model/AStar.h
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
        z_tests/tests_model/Tile_test.cpp
        z_tests/tests_model/Map_test.cpp
        src/model/Robot.cpp
        src/model/Robot.h
        z_tests/tests_model/Robot_test.cpp
        z_tests/tests_model/AStar_test.cpp
        #[[
        src/model/GameCotroller.cpp
        src/model/GameCotroller.h
        src/model/MovementEvent.cpp
        src/model/MovementEvent.h
        src/model/UnitAttackEvent.cpp
        src/model/UnitAttackEvent.h
        src/model/Build.cpp
        src/model/Build.h
        src/model/BuildID.cpp
        src/model/BuildID.h
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
        src/vista/Sprite.cpp
        src/vista/Sprite.h
        src/model/ObjectMap.cpp
        src/model/ObjectMap.h
        src/model/Land.cpp
        src/model/Land.h
        src/vista/Vista.cpp
        src/vista/Vista.h
        src/model/MapBuilder.cpp
        src/model/MapBuilder.h
        src/model/Grunt.cpp
        src/model/Grunt.h]]

        src/vista/Window.cpp
        src/vista/Window.h
        src/vista/Panel.cpp
        src/vista/Panel.h
        src/vista/Image.cpp
        src/vista/Image.h
        src/vista/ObjectMapaVista.cpp
        src/vista/ObjectMapaVista.h

        z_tests/tests_model/Vista_test.cpp)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/src/model)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/src/storage)

#nota a futuro: la mayoria de esos flags del SDL2 vienen de ejecutar `sdl2-config --cflags --libs --static-libs` en la terminal (estan copipasteados). Habrá que ver como hacerlo bien a esto.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2 -lpthread -Wl,--no-undefined -lm -ldl -lasound -lm -ldl -lpthread -lpulse-simple -lpulse -lX11 -lXext -lXcursor -lXinerama -lXi -lXrandr -lXss -lXxf86vm -lwayland-egl -lwayland-client -lwayland-cursor -lxkbcommon -lpthread -lrt")

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
