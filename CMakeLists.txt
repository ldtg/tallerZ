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
        src/model/Robot.cpp
        src/model/Robot.h
        src/model/UnitAttackEvent.cpp
        src/model/UnitAttackEvent.h
        src/model/UnitNotFoundException.cpp
        src/model/UnitNotFoundException.h
        src/model/UnitData.h
        src/model/UnitFactory.cpp
        src/model/UnitFactory.h
        src/model/TerrainData.h
        src/model/UnitMoveEvent.cpp
        src/model/UnitMoveEvent.h
        src/model/Events/Event.cpp
        src/model/Events/Event.h
        src/model/UnitDamageReceiveEvent.cpp
        src/model/UnitDamageReceiveEvent.h
        src/model/UnitDeathEvent.cpp
        src/model/UnitDeathEvent.h
        src/model/Vehicle.cpp
        src/model/Vehicle.h
        src/model/Events/Pointer/ClickEvent.cpp
        src/model/Events/Pointer/ClickEvent.h
        src/model/Events/EventHandler.cpp
        src/model/Events/EventHandler.h
        src/model/Events/QuitEvent.cpp
        src/model/Events/QuitEvent.h
        src/model/Model.cpp
        src/model/Model.h
        src/model/GameController.h
        src/model/GameController.cpp

        src/view/Texture.cpp
        src/view/Texture.h
        src/view/Window.cpp
        src/view/Window.h
        src/view/Panel.cpp
        src/view/Panel.h
        src/view/Image.cpp
        src/view/Image.h
        src/view/ObjectMapaVista.cpp
        src/view/ObjectMapaVista.h
        src/view/View.cpp
        src/view/View.h
        src/view/Sprite.cpp
        src/view/Sprite.h

        src/controller/Controller.cpp
        src/controller/Controller.h
        src/controller/Handler.h
        src/controller/Handler.cpp
        src/controller/HandlerFactory.cpp
        src/controller/HandlerFactory.h
        src/controller/Mouse.cpp
        src/controller/Mouse.h
        src/controller/NullHandler.cpp
        src/controller/NullHandler.h
        src/controller/Quit.cpp
        src/controller/Quit.h

        src/front_end/SDL_Interface/Map_View.cpp
        src/front_end/SDL_Interface/Map_View.h
        src/front_end/SDL_Interface/Side_Board.cpp
        src/front_end/SDL_Interface/Side_Board.h
        src/front_end/SDL_Interface/Weapon_Img.cpp
        src/front_end/SDL_Interface/Weapon_Img.h
        src/front_end/SDL_Interface/Robot_Face.cpp
        src/front_end/SDL_Interface/Robot_Face.h
        src/front_end/SDL_Interface/Main_Window.cpp
        src/front_end/SDL_Interface/Main_Window.h
        src/front_end/SDL_Interface/Menus/Main/main_menu.cpp
        src/front_end/SDL_Interface/Menus/Main/main_menu.h
        src/front_end/SDL_Interface/Menus/Production/Production_Menu_1.cpp
        src/front_end/SDL_Interface/Menus/Production/Production_Menu_1.h
        src/front_end/SDL_Interface/Menus/Production/Production_Menu_2.cpp
        src/front_end/SDL_Interface/Menus/Production/Production_Menu_2.h
        src/front_end/SDL_Interface/Menus/Production/Units_Queue.h
        src/front_end/SDL_Interface/Menus/Production/Units_Queue.cpp
        src/front_end/SDL_Interface/Menus/Menu.cpp
        src/front_end/SDL_Interface/Menus/Menu.h
        src/front_end/SDL_Interface/Labels/Label.cpp
        src/front_end/SDL_Interface/Labels/Label.h
        src/front_end/SDL_Interface/Cursor.h
        src/front_end/SDL_Interface/Cursor.cpp
        src/front_end/SDL_Interface/Buttons/Button.cpp
        src/front_end/SDL_Interface/Buttons/Button.h
        src/front_end/SDL_Interface/Buttons/Menu_Button.cpp
        src/front_end/SDL_Interface/Buttons/Menu_Button.h

        src/Exceptions/Sdl_Exceptions/Sdl_Exception.cpp
        src/Exceptions/Sdl_Exceptions/Sdl_Exception.h
        src/Exceptions/Front_end_exceptions/Generator_Exception.h
        src/Exceptions/Front_end_exceptions/Front_end_exception.cpp
        src/Exceptions/Map_Generator_Exceptions/Generator_Exception.h
        src/Exceptions/Map_Generator_Exceptions/Generator_Exception.cpp

        src/header_for_tests.h
        z_tests/tests_front_end/FEnd_test.cpp
        z_tests/tests_model/GameController_test.cpp
        z_tests/tests_model/Map_test.cpp
        z_tests/tests_model/Vista_test.cpp
        z_tests/tests_model/Tile_test.cpp
        z_tests/tests_model/Robot_test.cpp
        z_tests/tests_model/AStar_test.cpp

        src/SDL_START.cpp
        src/SDL_START.h
        src/Z_RUNNER.cpp
        src/Z_RUNNER.h
        src/front_end/SDL_Interface/Menus/Production/Buttons/Expand_Button.cpp
        src/front_end/SDL_Interface/Menus/Production/Buttons/Expand_Button.h
        src/front_end/SDL_Interface/Menus/Production/Buttons/Retract_Button.cpp
        src/front_end/SDL_Interface/Menus/Production/Buttons/Retract_Button.h
        src/front_end/SDL_Interface/Menus/Production/Buttons/Cancel_Button.cpp
        src/front_end/SDL_Interface/Menus/Production/Buttons/Cancel_Button.h
        src/front_end/SDL_Interface/Menus/Production/Buttons/Ok_Button.cpp
        src/front_end/SDL_Interface/Menus/Production/Buttons/Ok_Button.h
        src/front_end/SDL_Interface/Menus/Production/Production_Menu_2.cpp
        src/front_end/SDL_Interface/Menus/Production/Production_Menu_2.h
        src/front_end/SDL_Interface/Menus/Production/Buttons/Add_Button.cpp
        src/front_end/SDL_Interface/Menus/Production/Buttons/Add_Button.h
        src/front_end/SDL_Interface/Menus/Production/Buttons/Down_Button.h
        src/front_end/SDL_Interface/Menus/Production/Buttons/Down_Button.cpp
        src/front_end/SDL_Interface/Menus/Production/Buttons/Up_Button.cpp
        src/front_end/SDL_Interface/Menus/Production/Buttons/Up_Button.h

        src/map_generation/Generator.cpp
        src/map_generation/Generator.h z_tests/tests_generator/Generator_test.cpp)

#src/model/GameController.cpp
#src/model/GameController.h
#z_tests/tests_model/GameController_test.cpp

#[[
  src/model/Build.cpp
  src/model/Build.h
  src/model/BuildID.cpp
  src/model/BuildID.h
  src/model/BuildType.h
  src/model/BuildData.h

  src/model/Player.cpp
  src/model/Player.h
  src/model/Team.cpp
  src/model/Team.h
  src/model/PlayerID.cpp
  src/model/PlayerID.h
  src/model/Territory.cpp
  src/model/Territory.h
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

        INCLUDE_DIRECTORIES (${CMAKE_CURRENT_SOURCE_DIR}/src)
        INCLUDE_DIRECTORIES (${CMAKE_CURRENT_SOURCE_DIR}/src/model)
        INCLUDE_DIRECTORIES (${CMAKE_CURRENT_SOURCE_DIR}/src/storage)
        INCLUDE_DIRECTORIES (${CMAKE_CURRENT_SOURCE_DIR}/src/Exceptions)
        INCLUDE_DIRECTORIES (${CMAKE_CURRENT_SOURCE_DIR}/src/Utils)


        #nota a futuro: la mayoria de esos flags del SDL2 vienen de ejecutar `sdl2-config --cflags --libs --static-libs` en la terminal (estan copipasteados). Habrá que ver como hacerlo bien a esto.
        set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb -std=c++11 -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2 -lpthread -Wl,--no-undefined -lm -ldl -lasound -lm -ldl -lpthread -lpulse-simple -lpulse -lX11 -lXext -lXcursor -lXinerama -lXi -lXrandr -lXss -lXxf86vm -lwayland-egl -lwayland-client -lwayland-cursor -lxkbcommon -lpthread -lrt")


        add_executable (tallerZ ${SOURCE_FILES})

        INCLUDE (FindPkgConfig)

        PKG_SEARCH_MODULE (SDL2 REQUIRED sdl2)
        PKG_SEARCH_MODULE (SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
        PKG_SEARCH_MODULE (SDL2MIXER REQUIRED SDL2_mixer>=2.0.0)
        PKG_SEARCH_MODULE (SDL2TTF REQUIRED SDL2_ttf>=2.0.0)

        INCLUDE_DIRECTORIES (${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS} ${SLD2MIXER_INCLUDE_DIRS})
        TARGET_LINK_LIBRARIES (${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} ${SDL2MIXER_LIBRARIES} ${SDL2TTF_LIBRARIES})
        INCLUDE_DIRECTORIES (${CMAKE_CURRENT_SOURCE_DIR}/json/src)

        # Download and unpack googletest at configure time
        configure_file (CMakeLists.txt.in
        googletest-download/CMakeLists.txt)
        execute_process (COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download)
        execute_process (COMMAND ${CMAKE_COMMAND} --build .
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download)

        # Prevent GoogleTest from overriding our compiler/linker options
        # when building with Visual Studio
        set (gtest_force_shared_crt ON CACHE BOOL "" FORCE)

        # Add googletest directly to our build. This adds
        # the following targets: gtest, gtest_main, gmock
        # and gmock_main
        add_subdirectory (${CMAKE_BINARY_DIR}/googletest-src
        ${CMAKE_BINARY_DIR}/googletest-build)

        # The gtest/gmock targets carry header search path
        # dependencies automatically when using CMake 2.8.11 or
        # later. Otherwise we have to add them here ourselves.
        if (CMAKE_VERSION VERSION_LESS 2.8.11)
        include_directories ("${gtest_SOURCE_DIR}/include"
        "${gmock_SOURCE_DIR}/include")
        endif ()

        # Now simply link your own targets against gtest, gmock,
        # etc. as appropriate
        include_directories (cmake-build-debug/googletest-src/googlemock/include)
        include_directories (cmake-build-debug/googletest-src/googletest/include)
        target_link_libraries (${PROJECT_NAME} gtest gtest_main)
        #target_link_libraries(${PROJECT_NAME} ${GTK3_LIBRARIES} ${GTKMM_LIBRARIES})
        target_link_libraries (${PROJECT_NAME})

