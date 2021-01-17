cmake_minimum_required(VERSION 3.5)

# set the project name and version
project(raytracer VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

message("# Setting Source Directories...")
# Set Source Directories
set(SRC_DIR src/)
set(CAMERA_SRC_DIR ${SRC_DIR}/camera)
set(CANVAS_SRC_DIR ${SRC_DIR}/canvas)
set(INTERFACE_SRC_DIR ${SRC_DIR}/interface)
set(OBJECT_SRC_DIR ${SRC_DIR}/object)
set(OPERATION_SRC_DIR ${SRC_DIR}/operation)
set(SCENE_SRC_DIR ${SRC_DIR}/scene)
set(UTILS_SRC_DIR ${SRC_DIR}/utils)
message("# Setting Source Directories completed")

message("# Setting Include Directories...")
# Set Include Directories
set(INC_DIR inc/)
set(CAMERA_INC_DIR ${INC_DIR}/camera)
set(CANVAS_INC_DIR ${INC_DIR}/canvas)
set(INTERFACE_INC_DIR ${INC_DIR}/interface)
set(OBJECT_INC_DIR ${INC_DIR}/object)
set(OPERATION_INC_DIR ${INC_DIR}/operation)
set(SCENE_INC_DIR ${INC_DIR}/scene)
set(UTILS_INC_DIR ${INC_DIR}/utils)
message("# Setting Include Directories completed")

message("# Setting Source Files...")
# Set Source Files
set(CAMERA_SOURCES
	${CAMERA_SRC_DIR}/camera.cpp
)

set(CANVAS_SOURCES
	${CANVAS_SRC_DIR}/canvas.cpp
)

set(INTERFACE_SOURCES
	${INTERFACE_SRC_DIR}/raytracer.cpp
)

set(OBJECT_SOURCES
    ${OBJECT_SRC_DIR}/object.cpp
    ${OBJECT_SRC_DIR}/plane.cpp
    ${OBJECT_SRC_DIR}/sphere.cpp
    ${OBJECT_SRC_DIR}/triangle.cpp
)

set(OPERATION_SOURCES
    ${OPERATION_SRC_DIR}/renderer.cpp
)

set(SCENE_SOURCES
	${SCENE_SRC_DIR}/scene.cpp
)

set(UTILS_SOURCES
	${UTILS_SRC_DIR}/color.cpp
    ${UTILS_SRC_DIR}/light.cpp
    ${UTILS_SRC_DIR}/lighting.cpp
    ${UTILS_SRC_DIR}/ray.cpp
    ${UTILS_SRC_DIR}/vector3.cpp
)

message("# Setting Source Files completed")

message("# Combining all source files...")
# combine all source files
set(SOURCES ${CAMERA_SOURCES} 
			${CANVAS_SOURCES} 
			${INTERFACE_SOURCES}
			${OBJECT_SOURCES}
			${OPERATION_SOURCES}
            ${SCENE_SOURCES}
            ${UTILS_SOURCES}
)
message("# Combining all source files completed")

# create executable with target raytracer
add_library(raytracer STATIC ${SOURCES})

message("# Including include directories...")
target_include_directories(raytracer
    PUBLIC
        ${INC_DIR}
)

message("# Including include directories completed")


