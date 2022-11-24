cmake_minimum_required(VERSION 3.1.2)

set(SOURCES_FILES
        Source/SolidRepository.cpp
        )

set(HEADER_FILES
        Include/SolidRepository.h
        )


set(FILES
        ${SOURCES_FILES}
        ${HEADER_FILES}
        ../../../Tests/Repository/TestSolidReposiroty.cpp Include/JsonConverter.h Source/JsonConverter.cpp)


add_library(
        mecasolidRepository.libs STATIC
        ${FILES}
)

target_link_libraries(
        mecasolidRepository.libs
        mecasolidSolid.libs
        mecasolidUtils.libs
        jsoncpp
)

target_include_directories(
        mecasolidRepository.libs PUBLIC
        Include/
)


