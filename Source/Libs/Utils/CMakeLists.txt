cmake_minimum_required(VERSION 3.1.2)

set(SOURCES_FILES
	Source/Vector.cpp
	Source/Quaternion.cpp
	Source/Matrix.cpp
	Source/Point.cpp
	Source/Segment.cpp
	Source/Line.cpp
	Source/Plan.cpp
	Source/Basis.cpp
	Source/BasisId.cpp
	Source/Polygon.cpp
	Source/VectorsQuaternionConverter.cpp	
	Source/BasisChangerImplementation.cpp
	Source/BasisChanger.cpp
	Source/BasisChangerFromGlobalToBasis.cpp
	Source/BasisChangerFromBasisToBasis.cpp
	Source/BasisChangerFromBasisToGlobal.cpp
)

set(HEADER_FILES
	Include/Utils/Vector.h
	Include/Utils/Quaternion.h
	Include/Utils/Matrix.h	
	Include/Utils/Point.h	
	Include/Utils/Segment.h	
	Include/Utils/Line.h	
	Include/Utils/Plan.h	
	Include/Utils/Basis.h		
	Include/Utils/BasisId.h	
	Include/Utils/Polygon.h
	Include/Utils/VectorsQuaternionConverter.h	
	Include/Utils/BasisChanger.h
	Include/Utils/BasisChangerImplementation.h
	Include/Utils/BasisChangerFromGlobalToBasis.h
	Include/Utils/BasisChangerFromBasisToBasis.h
	Include/Utils/BasisChangerFromBasisToGlobal.h
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


