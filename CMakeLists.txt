# CMake entry point
cmake_minimum_required (VERSION 2.6)
project (SHFW)

OPTION(MAKE_WORKSPACE "Make SHFW testgame application" ON)

find_package(OpenGL REQUIRED)

add_subdirectory (extLibs)

include_directories(
	${CMAKE_SOURCE_DIR}/extLibs/glfw-3.2.1/include/GLFW
	${CMAKE_SOURCE_DIR}/extLibs/glm-0.9.8.4
	${CMAKE_SOURCE_DIR}/extLibs/SOIL2/${HEADERS}
	${CMAKE_SOURCE_DIR}/extLibs
	
	${CMAKE_SOURCE_DIR}/SHFW
	${CMAKE_SOURCE_DIR}/.
)

link_directories(
	${CMAKE_SOURCE_DIR}/extLibs/glfw-3.2.1/src
	${CMAKE_SOURCE_DIR}/SHFW
)

set(ALL_GRAPHICS_LIBS
	${OPENGL_LIBRARY}
	SHFW
	glfw
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
	SHFW/Camera.cpp
	SHFW/Camera.h
	SHFW/Canvas.cpp
	SHFW/Canvas.h
	SHFW/Color.h
	SHFW/Core.cpp
	SHFW/Core.h
	SHFW/Entity.cpp
	SHFW/Entity.h
	SHFW/InputManager.cpp
	SHFW/InputManager.h
	SHFW/Line.cpp
	SHFW/Line.h
	SHFW/Mesh.cpp
	SHFW/Mesh.h
	SHFW/Noise.cpp
	SHFW/Noise.h
	SHFW/PointT.h
	SHFW/Renderer.cpp
	SHFW/Renderer.h
	SHFW/ResourceManager.cpp
	SHFW/ResourceManager.h
	SHFW/SHFWconfig.h
	SHFW/Scene.cpp
	SHFW/Scene.h
	SHFW/Shader.cpp
	SHFW/Shader.h
	SHFW/Sprite.cpp
	SHFW/Sprite.h
	SHFW/Text.cpp
	SHFW/Text.h
	SHFW/Texture.cpp
	SHFW/Texture.h
	SHFW/Timer.cpp
	SHFW/Timer.h
	SHFW/Util.c
	SHFW/Util.h
	SHFW/SHTime.cpp
	SHFW/SHTime.h
	SHFW/VectorT.h
#	SHFW/SHEvents.h
#	SHFW/SHEventHandler.cpp
#	SHFW/SHEventHandler.h
#	SHFW/SHEventListener.cpp
#	SHFW/SHEventListener.h
#	SHFW/SHEvent.cpp
#	SHFW/SHEvent.h
#	SHFW/WindowResizeEvent.cpp
#	SHFW/WindowResizeEvent.h
#	SHFW/ScrollEvent.cpp
#	SHFW/ScrollEvent.h
	SHFW/glad.c
	SHFW/StandardAssets.h
	SHFW/SHMath.h
	SHFW/EmptyObject.cpp
	SHFW/EmptyObject.h
	SHFW/Slider.cpp
	SHFW/Slider.h
)

file(
	COPY ${CMAKE_SOURCE_DIR}/SHFW/shaders
	DESTINATION ${CMAKE_BINARY_DIR}
)

file(
	COPY ${CMAKE_SOURCE_DIR}/SHFW/assets
	DESTINATION ${CMAKE_BINARY_DIR}
)

IF(MAKE_WORKSPACE)
	add_executable(Workspace
		Workspace/main.cpp
		Workspace/PreviewScene.cpp
		Workspace/PreviewScene.h
		Workspace/TargetTexture.cpp
		Workspace/TargetTexture.h
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

