file(GLOB SOURCES "*.h" "*.cpp")
add_library(visitor ${SOURCES})
target_link_libraries(visitor db server ast entity type util parser)
