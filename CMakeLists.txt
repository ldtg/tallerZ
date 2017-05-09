cmake_minimum_required(VERSION 3.7)
project(tallerZ)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        src/model/main.cpp
        src/model/Map.cpp
        src/model/Map.h
        src/model/Position.cpp
        src/model/Position.h
        src/model/AStar.cpp
        src/model/AStar.h
        src/model/Node.cpp
        src/model/Node.h
        src/model/Sound_event.cpp
        src/model/Sound_event.h
        src/model/Unit.cpp
        src/model/Unit.h
        src/model/Tile.cpp
        src/model/Tile.h
        src/model/TerrainType.h
        src/model/Movement.h
        src/model/GameCotroller.cpp
        src/model/GameCotroller.h
        src/model/IdUnit.cpp
        src/model/IdUnit.h src/storage/Store_settings.cpp src/storage/Store_settings.h src/storage/Store_map.cpp src/storage/Store_map.h src/Z_tests/Base_tests/TestBase.h)

#nota a futuro: la mayoria de esos flags del SDL2 vienen de ejecutar `sdl2-config --cflags --libs --static-libs` en la terminal (estan copipasteados). Habrá que ver como hacerlo bien a esto.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2 -lpthread -Wl,--no-undefined -lm -ldl -lasound -lm -ldl -lpthread -lpulse-simple -lpulse -lX11 -lXext -lXcursor -lXinerama -lXi -lXrandr -lXss -lXxf86vm -lwayland-egl -lwayland-client -lwayland-cursor -lxkbcommon -lts -lpthread -lrt")

add_executable(tallerZ ${SOURCE_FILES})

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
PKG_SEARCH_MODULE(SDL2MIXER REQUIRED SDL2_mixer>=2.0.0)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS} ${SLD2MIXER_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} ${SDL2MIXER_LIBRARIES})
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/json/src)
