cmake_minimum_required(VERSION 3.16)

project(Prometheus.Core.Project VERSION 1.0.0 LANGUAGES CXX)

get_directory_property(IS_SUBPROJECT PARENT_DIRECTORY)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/Options.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/CompilerOptions.cmake)

add_library(Prometheus.Core INTERFACE)

target_include_directories(Prometheus.Core INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/includes>
    $<INSTALL_INTERFACE:includes>
)

target_compile_features(Prometheus.Core INTERFACE cxx_std_17)
add_library(Prometheus::Core ALIAS Prometheus.Core)

install(DIRECTORY includes/Prometheus.Core DESTINATION includes)

install(TARGETS Prometheus.Core EXPORT Prometheus.Core.Config)
install(EXPORT Prometheus.Core.Config NAMESPACE Prometheus:: DESTINATION share/Prometheus.Core/cmake)

include(CMakePackageConfigHelpers)
write_basic_package_version_file("${PROJECT_BINARY_DIR}/Prometheus.Core.Version.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)
install(FILES "${PROJECT_BINARY_DIR}/Prometheus.Core.Version.cmake" DESTINATION share/Prometheus.Core/cmake)

if(NOT Prometheus.Core.Testing)
    message(STATUS "Тестирование проекта Prometheus.Core выключено")
elseif(IS_SUBPROJECT)
    message(STATUS "Prometheus.Core не тестируется в режиме подмодуля")
else()
    add_subdirectory(unit_tests)
endif()

if(NOT IS_SUBPROJECT)
    add_subdirectory(doc)
endif()