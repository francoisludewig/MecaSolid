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


add_subdirectory("Tests")
add_subdirectory("Source/Libs")
