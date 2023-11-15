cmake_minimum_required (VERSION 3.16)

if(WIN32)
	set(SDL2_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/halley/deps/include/SDL2)
	set(SDL2_LIBRARIES ${CMAKE_CURRENT_SOURCE_DIR}/halley/deps/lib64/SDL2.lib)
elseif(APPLE)
	set(SDL2_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/halley/deps/osx/include/SDL2)
	set(SDL2_LIBRARIES ${CMAKE_CURRENT_SOURCE_DIR}/halley/deps/osx/lib/libSDL2.a)
	set(ShaderConductor_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/halley/deps/osx/include/ShaderConductor)

	set(OPENSSL_CRYPTO_LIBRARY "-framework CoreFoundation")
	set(OPENSSL_SSL_LIBRARY "-framework Security")
elseif(UNIX)
	# CMAKE_INCLUDE_PATH is modified in HalleyProject.cmake, adding
	# ./halley/deps/include to the include path, which contains the Windows
	# versions of SDL2 headers. The CI build seems to pick this up first.
	set(SDL2_INCLUDE_DIR /usr/include/SDL2)
	set(SDL2_LIBRARIES /usr/lib/x86_64-linux-gnu/libSDL2.so)
endif()

project (halleyGame)
set(REQUIRE_WINDOWS_10 1)
set(HALLEY_PROJECT_EMBED 1)
set(HALLEY_PATH ${CMAKE_CURRENT_SOURCE_DIR}/halley)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${HALLEY_PATH}/cmake/")

include(HalleyProject)

if(NOT (DEFINED HALLEY_GAME_BIN_DIR))
	set(HALLEY_GAME_BIN_DIR "bin")
endif()

set (SOURCES
	"prec.cpp"
	"src/game.cpp"
	"src/game_stage.cpp"
	"src/editor/game_scene_editor.cpp"
	)

set (HEADERS
	"prec.h"
	"src/game.h"
	"src/game_stage.h"
	"src/editor/game_scene_editor.h"
	)

set (GEN_DEFINITIONS
	)

halleyProject(halleyGame "${SOURCES}" "${HEADERS}" "" "${GEN_DEFINITIONS}" ${CMAKE_CURRENT_SOURCE_DIR}/${HALLEY_GAME_BIN_DIR})
