cmake_minimum_required(VERSION 3.23)
project(lexer)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(
        lexer
        src/main.cpp
        src/lib/io/IReader.hpp
        src/lib/io/CBufferedReader.hpp
        src/lib/io/CBufferedReader.cpp
)

add_executable(
        lexer_unit_test
        src/lib/io/IReader.hpp
        src/lib/io/CBufferedReader.hpp

        test/lib/io/CBufferedReaderTest.cpp
        src/lib/io/CBufferedReader.cpp
)

target_link_libraries(lexer_unit_test gtest gtest_main gmock)