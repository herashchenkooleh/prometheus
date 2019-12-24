cmake_minimum_required(VERSION 3.16)

project(Prometheus.Engine.Math.Project VERSION 1.0.0 LANGUAGES CXX)

get_directory_property(IS_SUBPROJECT PARENT_DIRECTORY)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/Options.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/CompilerOptions.cmake)

add_library(Prometheus.Engine.Math INTERFACE)

target_include_directories(Prometheus.Engine.Math INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/includes>
    $<INSTALL_INTERFACE:includes>
)

target_compile_features(Prometheus.Engine.Math INTERFACE cxx_std_17)
add_library(Prometheus::Math ALIAS Prometheus.Engine.Math)

install(DIRECTORY includes/Prometheus.Engine.Math DESTINATION includes)

install(TARGETS Prometheus.Engine.Math EXPORT Prometheus.Engine.Math.Config)
install(EXPORT Prometheus.Engine.Math.Config NAMESPACE Prometheus:: DESTINATION share/Prometheus.Engine.Math/cmake)

include(CMakePackageConfigHelpers)
write_basic_package_version_file("${PROJECT_BINARY_DIR}/Prometheus.Engine.Math.Version.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)
install(FILES "${PROJECT_BINARY_DIR}/Prometheus.Engine.Math.Version.cmake" DESTINATION share/Prometheus.Engine.Math/cmake)

if(NOT Prometheus.Engine.Math.Testing)
    message(STATUS "Тестирование проекта Prometheus.Engine.Math выключено")
elseif(IS_SUBPROJECT)
    message(STATUS "Prometheus.Engine.Math не тестируется в режиме подмодуля")
else()
    add_subdirectory(unit_tests)
endif()

if(NOT IS_SUBPROJECT)
    add_subdirectory(doc)
endif()