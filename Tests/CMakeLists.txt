cmake_minimum_required(VERSION 3.1.2)

set(SOURCES_FILES
	main.cpp
	Resource/DoublePrecision.h
	TestVector.cpp
	TestQuaternion.cpp
	TestBasis.cpp
	TestBasisId.cpp
	TestMatrix.cpp
	TestSolid.cpp
	TestPoint.cpp
	TestSegment.cpp
	TestLine.cpp
	TestVectorsQuaternionConverter.cpp
	TestBasisChangerGlobalToBasis.cpp
	TestBasisChangerBasisToGlobal.cpp
	TestBasisChangerBasisToBasis.cpp
	TestBasisChanger.cpp
)

set(FILES
    ${SOURCES_FILES}
)

add_executable(
	mecasolid.Tests 
	${FILES}
	${tests_files}
)

target_link_libraries(
	mecasolid.Tests
	mecasolidUtils.libs
	mecasolidSolid.libs
	gtest
)

