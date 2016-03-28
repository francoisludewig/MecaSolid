cmake_minimum_required(VERSION 3.1.2)

set(SOURCES_FILES
	Basis/Source/Vector3D.cpp
)

set(HEADER_FILES
	Basis/Include/Basis/Vector3D.h
)

set(FILES
    ${SOURCES_FILES}
    ${HEADER_FILES}
)

add_library(
	mecasolid.libs 
	${FILES}
)


