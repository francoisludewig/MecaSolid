cmake_minimum_required(VERSION 3.1.2)

set(SOURCES_FILES
	Basis/Source/Vector3D.cpp
	Basis/Source/UnitQuaternion.cpp
	Basis/Source/Basis.cpp
)

set(HEADER_FILES
	Basis/Include/Basis/Vector3D.h
	Basis/Include/Basis/UnitQuaternion.h
	Basis/Include/Basis/Basis.h	
)


set(FILES
    ${SOURCES_FILES}
    ${HEADER_FILES}
)


add_library(
	mecasolid.libs STATIC
	${FILES}
)


target_include_directories(
	mecasolid.libs PUBLIC
	Basis/Include/
)


