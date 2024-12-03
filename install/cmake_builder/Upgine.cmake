# ---------------------------------------------------------------------------------
# Upgine                                                               
# ---------------------------------------------------------------------------------


# ---------------------------------------------------------------------------------
# CMake Prepare Libraries
# ---------------------------------------------------------------------------------
FIND_PACKAGE(OpenGL REQUIRED)
INCLUDE_DIRECTORIES(${OPENGL_INCLUDE_DIRS})

# ---------------------------------------------------------------------------------
# Upgine Setup                                                                  
# ---------------------------------------------------------------------------------

SET(APPLICATION_SRC ../../src/upgine/application/application_base.cpp)
SOURCE_GROUP("Source Files\\Application" FILES ${APPLICATION_SRC})
SET(SOURCE_FILES ${APPLICATION_SRC})

SET(APPLICATION_INC
        ../../include/upgine/application/application_interface.h
        ../../include/upgine/application/application_abstract.h ../../include/upgine/application/application_base.h)
SOURCE_GROUP("Header Files\\Application" FILES ${APPLICATION_INC})
SET(SOURCE_FILES ${APPLICATION_INC})

#---------------------------------------------------------------------------------

SET(GRAPHICS_SRC   )
SOURCE_GROUP("Source Files\\Graphics" FILES ${GRAPHICS_SRC})
SET(SOURCE_FILES ${GRAPHICS_SRC})

SET(GRAPHICS_INC  )
SOURCE_GROUP("Header Files\\Graphics" FILES ${GRAPHICS_INC})
SET(SOURCE_FILES ${GRAPHICS_INC})

#---------------------------------------------------------------------------------

SET(GRAPHICS_DRAW_SRC ../../src/upgine/graphics/draw/draw_element.cpp ../../src/upgine/graphics/draw/draw_list.cpp ../../src/upgine/graphics/draw/draw_clear.cpp ../../src/upgine/graphics/draw/draw_uniform_float.cpp ../../src/upgine/graphics/draw/draw_uniform_base.cpp ../../src/upgine/graphics/draw/draw_uniform_texture.cpp ../../src/upgine/graphics/draw/draw_material.cpp ../../src/upgine/graphics/draw/draw_uniform_matrix4.cpp)
SOURCE_GROUP("Source Files\\Graphics\\Draw" FILES ${GRAPHICS_DRAW_SRC})
SET(SOURCE_FILES ${GRAPHICS_DRAW_SRC})

SET(GRAPHICS_DRAW_INC
        ../../include/upgine/graphics/draw/draw_list.h
        ../../include/upgine/graphics/draw/draw_command_interface.h
        ../../include/upgine/graphics/draw/draw_element.h ../../include/upgine/graphics/draw/draw_clear.h ../../include/upgine/graphics/draw/draw_uniform_float.h ../../include/upgine/graphics/draw/draw_uniform_texture.h ../../include/upgine/graphics/draw/draw_uniform_base.h ../../include/upgine/graphics/draw/draw_material.h ../../include/upgine/graphics/draw/draw_uniform_matrix4.h)
SOURCE_GROUP("Header Files\\Graphics\\Draw" FILES ${GRAPHICS_DRAW_INC})
SET(SOURCE_FILES ${GRAPHICS_DRAW_INC})

#---------------------------------------------------------------------------------

SET(GRAPHICS_RESOURCES_SRC
		../../src/upgine/graphics/resources/shader.cpp
		../../src/upgine/graphics/resources/material.cpp
		../../src/upgine/graphics/resources/vertex_buffer.cpp
        ../../src/upgine/graphics/resources/buffer.cpp
        ../../src/upgine/graphics/resources/texture.cpp)
SOURCE_GROUP("Source Files\\Graphics\\Resources" FILES ${GRAPHICS_RESOURCES_SRC})
SET(SOURCE_FILES ${GRAPHICS_RESOURCES_SRC})

SET(GRAPHICS_RESOURCES_INC
		../../include/upgine/graphics/resources/resources_interface.h
		../../include/upgine/graphics/resources/shader.h
		../../include/upgine/graphics/resources/material.h
		../../include/upgine/graphics/resources/vertex_buffer.h ../../include/upgine/graphics/resources/texture.h ../../include/upgine/graphics/resources/constants.h)
SOURCE_GROUP("Header Files\\Graphics\\Resources" FILES ${GRAPHICS_RESOURCES_INC})
SET(SOURCE_FILES ${GRAPHICS_RESOURCES_INC})

#---------------------------------------------------------------------------------


SET(GRAPHICS_GPU_SRC
        ../../src/upgine/graphics/gpu/opengl_gpu.cpp
        )
SOURCE_GROUP("Source Files\\Graphics\\GPU" FILES ${GRAPHICS_GPU_SRC})
SET(SOURCE_FILES ${GRAPHICS_GPU_SRC})

SET(GRAPHICS_GPU_INC
        ../../include/upgine/graphics/gpu/gpu_interface.h
        ../../include/upgine/graphics/gpu/opengl_api.h
        )
SOURCE_GROUP("Header Files\\Graphics\\GPU" FILES ${GRAPHICS_GPU_INC})
SET(SOURCE_FILES ${GRAPHICS_GPU_INC})

#---------------------------------------------------------------------------------

SET(MEMORY_SMART_POINTER_SRC )
SOURCE_GROUP("Source Files\\Memory\\SmartPointer" FILES ${MEMORY_SMART_POINTER_SRC})
SET(SOURCE_FILES ${MEMORY_SMART_POINTER_SRC})

SET(MEMORY_SMART_POINTER_INC
		../../include/upgine/memory/smart_pointer/vector.h
        ../../include/upgine/memory/smart_pointer/reference.h
        ../../include/upgine/memory/smart_pointer/reference_container.h
        )
SOURCE_GROUP("Header Files\\Memory\\SmartPointer" FILES ${MEMORY_SMART_POINTER_INC})
SET(SOURCE_FILES ${MEMORY_SMART_POINTER_INC})

#---------------------------------------------------------------------------------


SET(CORE_SERVICES_SRC
		../../src/upgine/core/services/window_service.cpp
		../../src/upgine/core/services/input_service.cpp
        ../../src/upgine/core/services/profiler_service.cpp ../../src/upgine/core/services/graphics_resources_service.cpp ../../src/upgine/core/services/draw_service.cpp ../../src/upgine/core/services/camera_service.cpp ../../src/upgine/core/services/time_service.cpp)
SOURCE_GROUP("Source Files\\Core\\Services" FILES ${CORE_SERVICES_SRC})
SET(SOURCE_FILES ${CORE_SERVICES_SRC})

SET(CORE_SERVICES_INC
		../../include/upgine/core/services/service_interface.h
		../../include/upgine/core/services/input_service.h
		../../include/upgine/core/services/platform_service.h
		../../include/upgine/core/services/window_service.h
        ../../include/upgine/core/services/profiler_service.h ../../include/upgine/core/services/graphics_resources_service.h ../../include/upgine/core/services/draw_service.h ../../include/upgine/core/services/camera_service.h ../../include/upgine/core/services/time_service.h)
SOURCE_GROUP("Header Files\\Core\\Services" FILES ${CORE_SERVICES_INC})
SET(SOURCE_FILES ${CORE_SERVICES_INC})

SET(CORE_SERVICES_DTO_INC ../../include/upgine/core/services/dto/draw_service_dto.h)
SOURCE_GROUP("Header Files\\Core\\Services\\DTO" FILES ${CORE_SERVICES_DTO_INC})
SET(SOURCE_FILES ${CORE_SERVICES_DTO_INC})

#---------------------------------------------------------------------------------

SET(CORE_MANAGERS_SRC
		../../src/upgine/core/managers/services_manager.cpp
        ../../src/upgine/core/services/platform_service.cpp ../../src/upgine/core/managers/gpu_manager.cpp)
SOURCE_GROUP("Source Files\\Core\\Managers" FILES ${CORE_MANAGERS_SRC})
SET(SOURCE_FILES ${CORE_MANAGERS_SRC})

SET(CORE_MANAGERS_INC
		../../include/upgine/core/managers/services_manager.h
		../../include/upgine/core/managers/gpu_manager.h)
SOURCE_GROUP("Header Files\\Core\\Managers" FILES ${CORE_MANAGERS_INC})
SET(SOURCE_FILES ${CORE_MANAGERS_INC})

#---------------------------------------------------------------------------------

SET(CORE_MATH_INC ../../include/upgine/core/math/math_operations.h)
SOURCE_GROUP("Header Files\\Core\\Math" FILES ${CORE_MATH_INC})
SET(SOURCE_FILES ${CORE_MATH_INC})

SET(CORE_OBSERVER_INC ../../include/upgine/core/observer/observer.h)
SOURCE_GROUP("Header Files\\Core\\Observer" FILES ${CORE_OBSERVER_INC})
SET(SOURCE_FILES ${CORE_OBSERVER_INC})

#---------------------------------------------------------------------------------

#---------------------------------------------------------------------------------

SET(CORE_TYPES_INC
		../../include/upgine/core/types/basic_types.h
		../../src/upgine/graphics/resources/material.cpp ../../include/upgine/core/types/math_types.h)
SOURCE_GROUP("Header Files\\Core\\Types" FILES ${CORE_TYPES_INC})
SET(SOURCE_FILES ${CORE_TYPES_INC})


#---------------------------------------------------------------------------------

SET(MACRO_INC
        ../../include/upgine/macros/dependency_injector.h ../../include/upgine/macros/memory_alignment.h ../../include/upgine/macros/archetype_generator.h)
SOURCE_GROUP("Header Files\\Macros" FILES ${MACRO_INC})
SET(SOURCE_FILES ${MACRO_INC})
#---------------------------------------------------------------------------------

SET(ECS_ARCHETYPES_SRC   )
SOURCE_GROUP("Source Files\\ECS\\Archetypes" FILES ${ECS_ARCHETYPES_SRC})
SET(SOURCE_FILES ${ECS_ARCHETYPES_SRC})

SET(ECS_ARCHETYPES_INC ../../include/upgine/ecs/archetypes/archetypes_declaration.h )
SOURCE_GROUP("Header Files\\ECS\\Archetypes" FILES ${ECS_ARCHETYPES_INC})
SET(SOURCE_FILES ${ECS_ARCHETYPES_INC})

#---------------------------------------------------------------------------------

SET(ECS_COMPONENTS_SRC   )
SOURCE_GROUP("Source Files\\ECS\\Components" FILES ${ECS_COMPONENTS_SRC})
SET(SOURCE_FILES ${ECS_COMPONENTS_SRC})

SET(ECS_COMPONENTS_INC ../../include/upgine/ecs/components/transform_component.h ../../include/upgine/ecs/components/renderer_component.h ../../include/upgine/ecs/components/component_interface.h)
SOURCE_GROUP("Header Files\\ECS\\Components" FILES ${ECS_COMPONENTS_INC})
SET(SOURCE_FILES ${ECS_COMPONENTS_INC})

#---------------------------------------------------------------------------------

SET(ECS_SYSTEM_SRC )
SOURCE_GROUP("Source Files\\ECS\\System" FILES ${ECS_SYSTEM_SRC})
SET(SOURCE_FILES ${ECS_SYSTEM_SRC})

SET(ECS_SYSTEM_INC )
SOURCE_GROUP("Header Files\\ECS\\System" FILES ${ECS_SYSTEM_INC})
SET(SOURCE_FILES ${ECS_SYSTEM_INC})

#---------------------------------------------------------------------------------

SET(OBJECTS_SRC )
SOURCE_GROUP("Source Files\\Objects" FILES ${OBJECTS_SRC})
SET(SOURCE_FILES ${OBJECTS_SRC})

SET(OBJECT_INC ../../include/upgine/objects/game_object.h ../../include/upgine/objects/camera_object.h)
SOURCE_GROUP("Header Files\\Objects" FILES ${OBJECT_INC})
SET(SOURCE_FILES ${OBJECT_INC})

#---------------------------------------------------------------------------------
SET(ECS_MEMORY_SRC )
SOURCE_GROUP("Source Files\\ECS\\Memory" FILES ${ECS_MEMORY_SRC})
SET(SOURCE_FILES ${ECS_MEMORY_SRC})

SET(ECS_MEMORY_INC ../../include/upgine/ecs/memory/memory_chunk.h ../../include/upgine/ecs/memory/memory_chunks.h)
SOURCE_GROUP("Header Files\\ECS\\Memory" FILES ${ECS_MEMORY_INC})
SET(SOURCE_FILES ${ECS_MEMORY_INC})

SET(ECS_ENTITY_INC ../../include/upgine/ecs/entity/entity.h)
SOURCE_GROUP("Header Files\\ECS\\Entity" FILES ${ECS_ENTITY_INC})
SET(SOURCE_FILES ${ECS_ENTITY_INC})

SET(ECS_SYSTEM_SRC ../../src/upgine/ecs/system/renderer_system.cpp ../../src/upgine/ecs/system/transform_system.cpp)
SOURCE_GROUP("Source Files\\ECS\\System" FILES ${ECS_SYSTEM_SRC})
SET(SOURCE_FILES ${ECS_SYSTEM_SRC})

SET(ECS_SYSTEM_INC ../../include/upgine/ecs/systems/system_interface.h ../../include/upgine/ecs/systems/transform_system.h ../../include/upgine/ecs/systems/transform_system.h ../../include/upgine/ecs/systems/transform_system.h ../../include/upgine/ecs/systems/renderer_system.h)
SOURCE_GROUP("Header Files\\ECS\\System" FILES ${ECS_SYSTEM_INC})
SET(SOURCE_FILES ${ECS_SYSTEM_INC})

SET(ECS_DTO_INC ../../include/upgine/ecs/dto/component_dto.h)
SOURCE_GROUP("Header Files\\ECS\\DTO" FILES ${ECS_DTO_INC})
SET(SOURCE_FILES ${ECS_DTO_INC})

SET(LIBRARY_OUTPUT_PATH "../../../deps/library")

# ---------------------------------------------------------------------------------
# Upgine                                                                  
# ---------------------------------------------------------------------------------

MESSAGE( " ")
MESSAGE( "---------------------------")
MESSAGE( "-------   Vulkan    -------")
MESSAGE( "---------------------------")
MESSAGE(STATUS "Using module to find Vulkan")
FIND_PACKAGE(Vulkan)
IF(WIN32)
	IF (NOT Vulkan_FOUND)
		IF(CMAKE_SIZEOF_VOID_P EQUAL 8)
		  FIND_LIBRARY(Vulkan_LIBRARY NAMES vulkan-1 vulkan PATHS ../../deps/library/precompile/vulkan/windows/x64)
		ELSEIF(CMAKE_SIZEOF_VOID_P EQUAL 4)
		  FIND_LIBRARY(Vulkan_LIBRARY NAMES vulkan-1 vulkan PATHS ../../deps/library/precompile/vulkan/windows/x86)
		ENDIF()
		IF (Vulkan_LIBRARY)
			SET(Vulkan_FOUND ON)
			MESSAGE(STATUS "Using bundled Vulkan library version")
		ENDIF(Vulkan_LIBRARY)
	ENDIF()
ELSE(WIN32)
	IF (NOT Vulkan_FOUND)
		FIND_LIBRARY(Vulkan_LIBRARY NAMES vulkan HINTS "$ENV{VULKAN_SDK}/lib" "../../deps/library/precompile/vulkan/linux" REQUIRED)
		IF (Vulkan_LIBRARY)
			SET(Vulkan_FOUND ON)
			MESSAGE(STATUS "Using bundled Vulkan library version")
		ENDIF()
	ENDIF()
ENDIF(WIN32)

MESSAGE( " ")
EXECUTE_PROCESS(COMMAND python ../../../scripts/chunk_service_generator.py)
EXECUTE_PROCESS(COMMAND python ../../../scripts/system_service_generator.py)

SET(AUTO_GENERATED_FILES_INC ../../include/upgine/auto_generate/chunk_service.h ../../include/upgine/auto_generate/system_service.h)
SOURCE_GROUP("Source Files\\AutoGenerate" FILES ${AUTO_GENERATED_FILES_INC})
SET(SOURCE_FILES ${AUTO_GENERATED_FILES_INC})

SET(AUTO_GENERATED_FILES_SRC ../../src/upgine/auto_generate/chunk_service.cpp ../../src/upgine/auto_generate/system_service.cpp)
SOURCE_GROUP("Header Files\\AutoGenerate" FILES ${AUTO_GENERATED_FILES_SRC})
SET(SOURCE_FILES ${AUTO_GENERATED_FILES_SRC})

ADD_LIBRARY(Upgine
        ${APPLICATION_SRC} ${APPLICATION_INC}
		${AUTO_GENERATED_FILES_INC} ${AUTO_GENERATED_FILES_SRC}
		${CORE_SERVICES_SRC} ${CORE_SERVICES_INC} ${CORE_SERVICES_DTO_INC}
		${CORE_MANAGERS_SRC} ${CORE_MANAGERS_INC}
		${CORE_MATH_INC}
		${CORE_TYPES_INC}
		${GRAPHICS_SRC} ${GRAPHICS_INC}
		${GRAPHICS_RESOURCES_SRC} ${GRAPHICS_RESOURCES_INC}
		${GRAPHICS_GPU_SRC} ${GRAPHICS_GPU_INC}
        ${GRAPHICS_DRAW_SRC} ${GRAPHICS_DRAW_INC}
		${MEMORY_SMART_POINTER_SRC} ${MEMORY_SMART_POINTER_INC}
        ${MACRO_INC}
        ${ECS_ARCHETYPES_SRC} ${ECS_ARCHETYPES_INC}
        ${ECS_COMPONENTS_SRC} ${ECS_COMPONENTS_INC}
        ${ECS_SYSTEM_SRC} ${ECS_SYSTEM_INC}
        ${OBJECTS_SRC} ${OBJECT_INC}
        ${ECS_MEMORY_SRC} ${ECS_MEMORY_INC}
		${ECS_ENTITY_INC}
		${ECS_SYSTEM_SRC} ${ECS_SYSTEM_INC}
		${ECS_DTO_INC}
		${CORE_OBSERVER_INC}
		)
ADD_CUSTOM_TARGET(ChunkService
		COMMAND python ../../../scripts/chunk_service_generator.py
		COMMAND python ../../../scripts/system_service_generator.py
		DEPENDS ../../../scripts/chunk_service_generator.py
		COMMENT "Generating ChunkService..."
		)

add_dependencies(Upgine ChunkService)


if (MSVC)
		if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
		TARGET_COMPILE_DEFINITIONS(ExternalLibraries PRIVATE CLANG_MVC)
		TARGET_COMPILE_DEFINITIONS(Upgine PRIVATE CLANG_MVC)
		TARGET_COMPILE_OPTIONS(Upgine PRIVATE /MP /Wall /WX -Wno-c++98-compat)
		endif()
endif()


IF (Vulkan_LIBRARY)
	TARGET_LINK_LIBRARIES(Upgine ExternalLibraries ${Vulkan_LIBRARY} ${OPENGL_LIBRARIES})
ELSE()
	TARGET_LINK_LIBRARIES(Upgine ExternalLibraries ${OPENGL_LIBRARIES})
ENDIF(Vulkan_LIBRARY)