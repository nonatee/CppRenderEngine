cmake_minimum_required(VERSION 3.15)
project(CppRenderEngine LANGUAGES CXX)

# Collect all .cpp files in src/
file(GLOB_RECURSE SOURCES
    ${PROJECT_SOURCE_DIR}/src/*.cpp
)

# Optionally, collect headers for IDE visibility
file(GLOB_RECURSE HEADERS
    ${PROJECT_SOURCE_DIR}/include/*.h
    ${PROJECT_SOURCE_DIR}/include/*.hpp
)

# Find SDL2 before using its variables
find_package(SDL2 REQUIRED)

# Create executable
add_executable(CppRenderEngine ${SOURCES} ${HEADERS})

# Use modern C++ for this target
target_compile_features(CppRenderEngine PRIVATE cxx_std_17)

# Include directories scoped to target
target_include_directories(CppRenderEngine PRIVATE
    ${PROJECT_SOURCE_DIR}/include
    ${SDL2_INCLUDE_DIRS}
)

# Link SDL2 libraries
target_link_libraries(CppRenderEngine PRIVATE ${SDL2_LIBRARIES})
