cmake_minimum_required(VERSION 3.20)

project(skyblock_pricing_desktop CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

FetchContent_Declare(
    skyblock_pricing 
    GIT_REPOSITORY https://github.com/Anderson-Lai/skyblock-pricing.git
    GIT_TAG master
)
FetchContent_MakeAvailable(skyblock_pricing)

find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})

add_executable(${PROJECT_NAME} WIN32
    "${CMAKE_CURRENT_SOURCE_DIR}/src/app.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/mainframe.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/getflips.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/clipboard.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/events.cpp"
)

target_include_directories(${PROJECT_NAME}
    PRIVATE 
        "${CMAKE_CURRENT_SOURCE_DIR}/include/"
         ${wxWidgets_INCLUDE_DIRS}
)

if (MSVC) 
    target_compile_options(${PROJECT_NAME} PUBLIC
        $<$<CONFIG:Debug>:/MDd>
        $<$<CONFIG:Release>:/MD /DNDEBUG /O2>
    )
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(${PROJECT_NAME} PUBLIC 
        $<$<CONFIG:Debug>:-ggdb -pthread -Wall -Wpedantic -Wextra -fsanitize=address>
        $<$<CONFIG:Release>:-O3 -s -pthread -DNDEBUG>
    )
    target_link_options(${PROJECT_NAME} PUBLIC
        $<$<CONFIG:Debug>:-ggdb -pthread -Wall -Wpedantic -Wextra -fsanitize=address>
        $<$<CONFIG:Release>:-O3 -s -pthread -DNDEBUG>
    )
else ()
    message(FATAL_ERROR "Your compiler is not supported")
endif ()

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        skyblock_pricing 
        ${wxWidgets_LIBRARIES}
)
