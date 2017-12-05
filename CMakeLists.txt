# CMake entry point
cmake_minimum_required (VERSION 2.6)
project (SHFW)

OPTION(MAKE_WORKSPACE "Make SHFW testgame application" ON)

find_package(OpenGL REQUIRED)

add_subdirectory (extLibs)

include_directories(
	${CMAKE_SOURCE_DIR}/extLibs/glfw-3.2.1/include/GLFW
	${CMAKE_SOURCE_DIR}/extLibs/glm-0.9.8.4
	${CMAKE_SOURCE_DIR}/extLibs/glew-2.1.0/include
	${CMAKE_SOURCE_DIR}/extLibs
	${CMAKE_SOURCE_DIR}/SHFW/assets
	${CMAKE_SOURCE_DIR}/SHFW
	${CMAKE_SOURCE_DIR}/.
)

link_directories(
	${CMAKE_SOURCE_DIR}/extLibs/glfw-3.2.1/src
	${CMAKE_SOURCE_DIR}/extLibs/glew-2.1.0
	${CMAKE_SOURCE_DIR}/extLibs
	${CMAKE_SOURCE_DIR}/SHFW/assets
	${CMAKE_SOURCE_DIR}/SHFW
)

set(ALL_GRAPHICS_LIBS
	${OPENGL_LIBRARY}
	SHFW
	glfw
	GLEW_210
)

add_definitions(
	-DTW_STATIC
	-DTW_NO_LIB_PRAGMA
	-DTW_NO_DIRECT3D
	-DGLEW_STATIC
	-D_CRT_SECURE_NO_WARNINGS
)

####################################################################
# libshfw.a                                                        #
####################################################################

add_library(SHFW
	SHFW/Core.cpp
	SHFW/Core.h
	SHFW/RenderManager.cpp
	SHFW/RenderManager.h
	SHFW/InputKeycodes.h
	SHFW/InputManager.cpp
	SHFW/InputManager.h
	SHFW/Time.cpp
	SHFW/Time.h
	SHFW/Entity.cpp
	SHFW/Entity.h
	SHFW/Scene.cpp
	SHFW/Scene.h
)

IF(MAKE_WORKSPACE)
	add_executable(Workspace
		Workspace/main.cpp
	)
	target_link_libraries(Workspace
		${ALL_GRAPHICS_LIBS}
	)
	# Copy assets to the build directory
	file(
		COPY Workspace/assets
		DESTINATION ${CMAKE_BINARY_DIR}
	)
ENDIF()

