cmake_minimum_required(VERSION 3.16)

project(Prometheus.Engine.Core.Project VERSION 1.0.0 LANGUAGES CXX)

get_directory_property(IS_SUBPROJECT PARENT_DIRECTORY)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/Options.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/CompilerOptions.cmake)

add_library(Prometheus.Engine.Core INTERFACE)

target_include_directories(Prometheus.Engine.Core INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/includes>
    $<INSTALL_INTERFACE:includes>
)

target_compile_features(Prometheus.Engine.Core INTERFACE cxx_std_17)
add_library(Prometheus::Core ALIAS Prometheus.Engine.Core)

install(DIRECTORY includes/Prometheus.Engine.Core DESTINATION includes)

install(TARGETS Prometheus.Engine.Core EXPORT Prometheus.Engine.Core.Config)
install(EXPORT Prometheus.Engine.Core.Config NAMESPACE Prometheus:: DESTINATION share/Prometheus.Engine.Core/cmake)

include(CMakePackageConfigHelpers)
write_basic_package_version_file("${PROJECT_BINARY_DIR}/Prometheus.Engine.Core.Version.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)
install(FILES "${PROJECT_BINARY_DIR}/Prometheus.Engine.Core.Version.cmake" DESTINATION share/Prometheus.Engine.Core/cmake)

if(NOT Prometheus.Engine.Core.Testing)
    message(STATUS "Тестирование проекта Prometheus.Engine.Core выключено")
elseif(IS_SUBPROJECT)
    message(STATUS "Prometheus.Engine.Core не тестируется в режиме подмодуля")
else()
    add_subdirectory(unit_tests)
endif()

if(NOT IS_SUBPROJECT)
    add_subdirectory(doc)
endif()