cmake_minimum_required(VERSION 3.16)

project(Prometheus.Editor.Project VERSION 1.0.0 LANGUAGES CXX)

add_executable(Prometheus.Editor)

target_sources(Prometheus.Editor PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/sources/Prometheus.Editor.Main.Windows.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/sources/Prometheus.Editor.Application.Windows.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/includes/Prometheus.Editor.Application.hpp
)

target_include_directories(Prometheus.Editor PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/includes
)

target_compile_features(Prometheus.Editor PRIVATE cxx_std_17)