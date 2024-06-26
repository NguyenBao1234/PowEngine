project (PowEngine VERSION 0.1)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/PowEngine/*.cpp CMAKE_CONFIGURE_DEPENDS)
add_library(${PROJECT_NAME} STATIC ${SRC_FILES} "PowEngine/pch.h" "PowEngine/Core/Logger/Logger.h" "PowEngine/Window/Window.h" "PowEngine/Window/GLFWPlatformWindow.cpp" "PowEngine/Window/WindowPlatform.h" "PowEngine/Window/WindowPlatform.cpp" "PowEngine/Core/Event/EventContext.h" "PowEngine/Core/Event/EventAction.h" "PowEngine/Core/Event/EventDispatcher.h" "PowEngine/Core/Event/EventDispatcher.cpp")

target_compile_definitions(${PROJECT_NAME} PUBLIC ON_POW_ENGINE DYNAMIC_LIB=0 DYNAMIC_BUILD=0)

target_include_directories(${PROJECT_NAME} PUBLIC 
	${CMAKE_CURRENT_SOURCE_DIR}/PowEngine
	${CMAKE_SOURCE_DIR}/Vendors/include
	${CMAKE_SOURCE_DIR}/Vendors/glfw/include
)

target_link_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/Vendors/bin)
target_link_libraries(${PROJECT_NAME} PUBLIC spdlogd glfw)

target_precompile_headers(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/PowEngine/pch.h ${CMAKE_SOURCE_DIR}/Vendors/include/glad/gl.h)
