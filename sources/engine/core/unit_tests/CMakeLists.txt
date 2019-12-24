find_package(doctest 2.3.3 REQUIRED)

add_executable(core-unit-tests ${CMAKE_CURRENT_SOURCE_DIR}/sources/core_unit_tests_main.cpp)

target_sources(core-unit-tests PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/sources/core_feature.cpp
)

target_link_libraries(core-unit-tests PRIVATE
        Prometheus::Core
        doctest::doctest
)

add_custom_target(check ALL COMMAND core-unit-tests)

find_program(GCOVR_EXECUTABLE gcovr)
if(Prometheus.Core.Coverage AND GCOVR_EXECUTABLE)
    message(STATUS "Измерение покрытия кода тестами включено")

    target_compile_options(core-unit-tests PRIVATE --coverage)
    target_link_libraries(core-unit-tests PRIVATE gcov)

    add_custom_target(coverage
        COMMAND
            ${GCOVR_EXECUTABLE}
                --root=${CMAKE_CURRENT_SOURCE_DIR}/includes/
                --object-directory=${CMAKE_CURRENT_BINARY_DIR}
            DEPENDS
                check
    )
elseif(Prometheus.Core.Coverage AND NOT GCOVR_EXECUTABLE)
    set(Prometheus.Core.Coverage OFF)
    message(WARNING "Для замеров покрытия кода тестами требуется программа gcovr")
endif()