cmake_minimum_required(VERSION 3.1.2)

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

        Repository/TestSolidReposiroty.cpp
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
        mecasolidRepository.libs
        gtest
)

