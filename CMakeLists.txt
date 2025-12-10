cmake_minimum_required(VERSION 3.15)
project(felix_backtester VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Optimization flags
if(MSVC)
    add_compile_options(/O2 /Oi /Ot /Oy /GL)
else()
    add_compile_options(-O3 -march=native -flto)
endif()

# Find Python and PyBind11
find_package(Python 3.8 COMPONENTS Interpreter Development REQUIRED)
find_package(pybind11 REQUIRED)

# Include directories
include_directories(engine/include)

# Define source files
set(ENGINE_SOURCES
    engine/src/core/datastream.cpp
    engine/src/core/event_loop.cpp
    engine/src/core/portfolio.cpp
    engine/src/matching/order_book.cpp
    engine/src/matching/matching.cpp
    engine/src/risk/risk_engine.cpp
    engine/src/data/tick_record.cpp
)

# Create the pybind11 module
pybind11_add_module(felix_engine MODULE
    engine/src/bindings/pybind_module.cpp
    ${ENGINE_SOURCES}
)

# Output directory for the extension to be importable directly (optional but helpful)
set_target_properties(felix_engine PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}")


# Link directories (if needed later)
target_link_libraries(felix_engine PRIVATE pybind11::module)

# Testing
enable_testing()
add_executable(test_datastream tests/cpp/test_datastream.cpp ${ENGINE_SOURCES})
target_include_directories(test_datastream PRIVATE engine/include)

add_executable(test_matching tests/cpp/test_matching.cpp ${ENGINE_SOURCES})
target_include_directories(test_matching PRIVATE engine/include)


