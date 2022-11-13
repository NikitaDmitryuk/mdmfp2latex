set(LIBRARY ${CMAKE_PROJECT_NAME})

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true "*.hpp" "*.cpp")

add_library(${LIBRARY} ${SOURCES})

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC include)
