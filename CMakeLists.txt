cmake_minimum_required(VERSION 3.17)
project(cli_game_engine)

set(CMAKE_CXX_STANDARD 14)

add_executable(cli_game_engine main.cpp engine/core/collider.cpp engine/core/collider.h engine/core/position.cpp engine/core/position.h engine/core/game_object.cpp engine/core/game_object.h engine/core/rect.cpp engine/core/rect.h engine/core/transform.cpp engine/core/transform.h engine/scene/camera.cpp engine/scene/camera.h engine/scene/renderer.cpp engine/scene/renderer.h engine/logger.cpp engine/logger.h engine/scene/obj_converter.cpp engine/scene/obj_converter.h engine/core/rigid_body.cpp engine/core/rigid_body.h)