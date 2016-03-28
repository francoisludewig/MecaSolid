cmake_minimum_required(VERSION 3.1.2)

project(MecaSolid VERSION 1.0.0)

set(SOURCES_FILES
	Source/main.cpp
)

set(FILES
    ${SOURCES_FILES}
)

add_executable(mecasolid
	${FILES}
)

target_link_libraries(
	mecasolid
	mecasolid.libs
)

include_directories(${CMAKE_SOURCE_DIR}/Source/Libs/Basis/Include)

add_subdirectory("Tests")
add_subdirectory("Source/Libs")
