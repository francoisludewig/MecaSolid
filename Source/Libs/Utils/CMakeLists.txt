cmake_minimum_required(VERSION 3.1.2)

set(Basis_Sources_files
	Basis/Basis.cpp
	Basis/BasisId.cpp
	Basis/Matrix.cpp
	Basis/Quaternion.cpp
	Basis/Vector.cpp
	Basis/VectorsQuaternionConverter.cpp
)

set(Basis_Header_files
	Basis/DoubleComparison.h
	Basis/Basis.h
	Basis/BasisId.h
	Basis/Matrix.h
	Basis/Quaternion.h
	Basis/Vector.h
	Basis/VectorsQuaternionConverter.h
)

set(BasisChanger_Sources_files
	BasisChanger/BasisChanger.cpp
	BasisChanger/BasisChangerFromBasisToBasis.cpp
	BasisChanger/BasisChangerFromBasisToGlobal.cpp
	BasisChanger/BasisChangerFromGlobalToBasis.cpp
	BasisChanger/BasisChangerImplementation.cpp
)

set(BasisChanger_Header_files
	BasisChanger/BasisChanger.h
	BasisChanger/BasisChangerFromBasisToBasis.h
	BasisChanger/BasisChangerFromBasisToGlobal.h
	BasisChanger/BasisChangerFromGlobalToBasis.h
	BasisChanger/BasisChangerImplementation.h
)

set(GeometryConcepts_Sources_files
	GeometryConcepts/Line.cpp
	GeometryConcepts/Plan.cpp
	GeometryConcepts/Point.cpp
	GeometryConcepts/Segment.cpp
	GeometryConcepts/Polygon.cpp
)

set(GeometryConcepts_Header_files
	GeometryConcepts/Line.h
	GeometryConcepts/Plan.h
	GeometryConcepts/Point.h
	GeometryConcepts/Segment.h
	GeometryConcepts/Polygon.h
)


set(Interception_Sources_files
	Interception/InterceptorLines.cpp
	Interception/InterceptorPlans.cpp
	Interception/InterceptorSegments.cpp
	Interception/InterceptorLineSegment.cpp
	Interception/InterceptorPlanLine.cpp
	Interception/Interception.cpp
)

set(Interception_Header_files
	Interception/InterceptorLines.h
	Interception/InterceptorPlans.h
	Interception/InterceptorSegments.h
	Interception/InterceptorLineSegment.h
	Interception/InterceptorPlanLine.h
	Interception/Interception.h
)

set(SOURCES_FILES
	${Basis_Sources_files}
	${BasisChanger_Sources_files}
	${GeometryConcepts_Sources_files}
	${Interception_Sources_files}
)

set(HEADER_FILES
	${Basis_Header_files}
	${BasisChanger_Header_files}
	${GeometryConcepts_Header_files}
	${Interception_Sources_files}
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
	Basis/
	BasisChanger/
	GeometryConcepts/
	Exceptions/
	Interception/
)


