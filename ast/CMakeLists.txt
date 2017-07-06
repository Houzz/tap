set(CMAKE_CXX_STANDARD 11)

#add_subdirectory(expression)
#add_subdirectory(statement)

file(GLOB SOURCES "*.h" "*.cpp")
#add_library(ast statement expression ${SOURCES})
add_library(ast ${SOURCES})
#target_link_libraries(ast db server entity type visitor util parser)
