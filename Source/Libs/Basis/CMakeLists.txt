cmake_minimum_required(VERSION 3.1.2)

set(SOURCES_FILES
	Source/Vector3D.cpp
	Source/Quaternion.cpp
	Source/Basis.cpp
)

set(HEADER_FILES
	Include/Basis/Vector3D.h
	Include/Basis/Quaternion.h
	Include/Basis/Basis.h	
)


set(FILES
    ${SOURCES_FILES}
    ${HEADER_FILES}
)


add_library(
	mecasolidBasis.libs STATIC
	${FILES}
)


target_include_directories(
	mecasolidBasis.libs PUBLIC
	Include/
)


