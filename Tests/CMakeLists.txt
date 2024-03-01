cmake_minimum_required(VERSION 3.1.2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest
        GIT_TAG v1.14.0
)

FetchContent_GetProperties(googletest)

if (NOT googletest_POPULATED)
    FetchContent_Populate(googletest)
    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BUILD_DIR} [EXCLUDE_FROM_ALL])
endif()

set(SOURCES_FILES
        main.cpp

        Resource/DoublePrecision.h

        Basis/TestVector.cpp
        Basis/TestQuaternion.cpp
        Basis/TestBasis.cpp
        Basis/TestBasisId.cpp
        Basis/TestMatrix.cpp
        Basis/TestVectorsQuaternionConverter.cpp

        Solid/TestSolid.cpp

        GeometryConcepts/TestPoint.cpp
        GeometryConcepts/TestSegment.cpp
        GeometryConcepts/TestLine.cpp

        BasisChanger/TestBasisChangerGlobalToBasis.cpp
        BasisChanger/TestBasisChangerBasisToGlobal.cpp
        BasisChanger/TestBasisChangerBasisToBasis.cpp
        BasisChanger/TestBasisChanger.cpp

        Interception/TestInterceptorLines.cpp
        Interception/TestInterceptorPlans.cpp
        Interception/TestInterceptorSegments.cpp

        Repository/TestSolidRepository.cpp)

add_executable(
        mecasolid.Tests
        ${SOURCES_FILES}
)

target_link_libraries(
        mecasolid.Tests
        mecasolidUtils.libs
        mecasolidSolid.libs
        mecasolidRepository.libs
        gtest_main
        gmock_main
)