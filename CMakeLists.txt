cmake_minimum_required (VERSION 3.25)

set(VCPKG_INSTALLED_DIR "${CMAKE_CURRENT_BINARY_DIR}/vcpkg_installed")
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake"
  CACHE STRING "Vcpkg toolchain file")

project (CPP-Template-Detect-If-Object-Contains-A-Function-Definition
        VERSION 0.0.1
        DESCRIPTION "Simple CMake Project by Pratik to demonstrate if a templated type can be used to detect if an object contains a function definition"
        LANGUAGES CXX)

find_package(Boost REQUIRED)

# Add the Executable
add_executable (${PROJECT_NAME})

# Add the source files
target_sources(${PROJECT_NAME} PRIVATE main.cxx)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

target_link_libraries(
        ${PROJECT_NAME}
                PRIVATE
                        Boost::boost
)
