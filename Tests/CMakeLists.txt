cmake_minimum_required(VERSION 3.1.2)

set(SOURCES_FILES
	main.cpp
	Resource/DoublePrecision.h
	TestVector3D.cpp
	TestUnitQuaternion.cpp
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
	mecasolid.libs
	gtest
)

