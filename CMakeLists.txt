cmake_minimum_required (VERSION 3.12)

project (CPP-Template-Detect-If-Object-Contains-A-Function-Definition
        VERSION 0.0.1
        DESCRIPTION "Simple CMake Project by Pratik to demonstrate if a templated type can be used to detect if an object contains a function definition"
        LANGUAGES CXX)

# Add the Executable
add_executable (${PROJECT_NAME})

# Add the source files
target_sources(${PROJECT_NAME} PRIVATE main.cxx)