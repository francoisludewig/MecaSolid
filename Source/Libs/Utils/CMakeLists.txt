cmake_minimum_required(VERSION 3.1.2)

set(SOURCES_FILES
	Source/Vector3D.cpp
	Source/Quaternion.cpp
	Source/Matrix3x3.cpp
	Source/Point.cpp
	Source/Segment.cpp
	Source/Line.cpp
	Source/Plan.cpp
	Source/Basis.cpp
	Source/Polygon.cpp
	Source/VectorsQuaternionConverter.cpp
)

set(HEADER_FILES
	Include/Utils/Vector3D.h
	Include/Utils/Quaternion.h
	Include/Utils/Matrix3x3.h	
	Include/Utils/Point.h	
	Include/Utils/Segment.h	
	Include/Utils/Line.h	
	Include/Utils/Plan.h	
	Include/Utils/Basis.h	
	Include/Utils/Polygon.h
	Include/Utils/VectorsQuaternionConverter.h	
)

set(FILES
    ${SOURCES_FILES}
    ${HEADER_FILES}
)

add_library(
	mecasolidUtils.libs STATIC
	${FILES}
)

target_include_directories(
	mecasolidUtils.libs PUBLIC
	Include/
)


