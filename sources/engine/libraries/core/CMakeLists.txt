add_library(core)

set_target_properties(core PROPERTIES LINKER_LANGUAGE CPP)

target_sources(core PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/includes/Prometheus.Core.Array.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/includes/Prometheus.Core.CriticalSection.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/includes/Prometheus.Core.Pointer.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/includes/Prometheus.Core.Reference.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/includes/Prometheus.Core.ScopedLock.hpp
)
