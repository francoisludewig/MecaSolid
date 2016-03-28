cmake_minimum_required(VERSION 3.1.2)

set(SOURCES_FILES
	Basis/Vector3D.cpp
	Basis/Vector3D.h
)

set(FILES
    ${SOURCES_FILES}
)

add_library(
	mecasolid.libs
	${FILES}
)


