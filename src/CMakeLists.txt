set(BINARY ${CMAKE_PROJECT_NAME})
set(LIBRARY ${CMAKE_PROJECT_NAME}_lib)

FIND_PACKAGE( Boost 1.40 COMPONENTS program_options REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

file(GLOB SOURCES LIST_DIRECTORIES false "*.hpp" "*.cpp")

add_subdirectory(${LIBRARY})

add_executable(${BINARY} ${SOURCES})
target_link_libraries(${BINARY} LINK_PUBLIC ${Boost_LIBRARIES} ${LIBRARY})
