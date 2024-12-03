CMAKE_MINIMUM_REQUIRED(VERSION 3.10.0)
# ---------------------------------------------------------------------------------
# C++ Standard
# ---------------------------------------------------------------------------------
SET(CMAKE_CXX_STANDARD 20)


# ---------------------------------------------------------------------------------
# SELECT THE ENGINE TYPE
# ---------------------------------------------------------------------------------
ADD_DEFINITIONS(-DOPENGL_API)

#EXECUTE_PROCESS(COMMAND python ../../../scripts/archetypes_generator.py)
# ---------------------------------------------------------------------------------
# CMake Projects
# ---------------------------------------------------------------------------------
PROJECT(1_2DGeometryShapes)
PROJECT(2_3DGeometryShapes)
# ---------------------------------------------------------------------------------
# CMake Modules
# ---------------------------------------------------------------------------------
INCLUDE(EngineLibraries.cmake)
INCLUDE(Upgine.cmake)

# ---------------------------------------------------------------------------------
# CMake MainProject Config
# ---------------------------------------------------------------------------------
OPTION(BUILD_RELEASE "Build Release version" OFF)
IF(BUILD_RELEASE)
    SET(CMAKE_BUILD_TYPE Release)
    SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -march=native -flto -j8 -fwhole-program-vtables")
ELSE()
    SET(CMAKE_BUILD_TYPE Debug)
ENDIF()

# ---------------------------------------------------------------------------------
# CMake Includes
# ---------------------------------------------------------------------------------
INCLUDE_DIRECTORIES("../../deps/include" "../../include")
# ---------------------------------------------------------------------------------
# CMake Main CPP
# ---------------------------------------------------------------------------------
SET(1_2D_Geometry_Shapes "../../src/application/1_2d_geometry_shapes.cpp" "../../include/application/1_2d_geometry_shapes.h" ../../include/upgine/graphics/draw/draw_clear.h ../../include/upgine/core/services/draw_service.h ../../include/upgine/core/types/math_types.h ../../include/upgine/ecs/systems/transform_system.h ../../src/upgine/ecs/system/renderer_system.cpp)
SET(2_3D_Geometry_Shapes "../../src/application/2_3d_geometry_shapes.cpp" "../../include/application/2_3d_geometry_shapes.h")

# ---------------------------------------------------------------------------------
# CMake Filters
# ---------------------------------------------------------------------------------

# ---------------------------------------------------------------------------------
# CMake Output config
# ---------------------------------------------------------------------------------


MESSAGE([status] "Welcome Upgine Project")


SET_PROPERTY(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT 1_2DGeometryShapes)
SET_PROPERTY(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT 2_3DGeometryShapes)

ADD_EXECUTABLE(1_2DGeometryShapes ${1_2D_Geometry_Shapes})
ADD_EXECUTABLE(2_3DGeometryShapes ${2_3D_Geometry_Shapes})

IF(WIN32)
SET_TARGET_PROPERTIES(
    1_2DGeometryShapes PROPERTIES
    VS_DEBUGGER_WORKING_DIRECTORY "../../../bin/1_2DGeometryShapes"
    RUNTIME_OUTPUT_DIRECTORY "../../../bin/1_2DGeometryShapes"
)
SET_TARGET_PROPERTIES(
    2_3DGeometryShapes PROPERTIES
    VS_DEBUGGER_WORKING_DIRECTORY "../../../bin/2_3DGeometryShapes"
    RUNTIME_OUTPUT_DIRECTORY "../../../bin/2_3DGeometryShapes"
)
ENDIF(WIN32)

IF(UNIX)
ADD_CUSTOM_TARGET(
    TARGET 1_2DGeometryShapes
    POST_BUILD
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR} )
ADD_CUSTOM_TARGET(
    TARGET 2_3DGeometryShapes
    POST_BUILD
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR} )
ENDIF(UNIX)

# ---------------------------------------------------------------------------------
# CMake Libraries config
# ---------------------------------------------------------------------------------
TARGET_LINK_LIBRARIES(1_2DGeometryShapes Upgine)
TARGET_LINK_LIBRARIES(2_3DGeometryShapes Upgine)


TARGET_COMPILE_FEATURES(1_2DGeometryShapes PRIVATE cxx_std_17)
TARGET_COMPILE_FEATURES(2_3DGeometryShapes PRIVATE cxx_std_17)