cmake_minimum_required(VERSION 3.1.2)


include(FetchContent)
FetchContent_Declare(
        jsoncpp
        GIT_REPOSITORY https://github.com/open-source-parsers/jsoncpp
        GIT_TAG        1.9.5
)

FetchContent_GetProperties(jsoncpp)
if (NOT jsoncpp_POPULATED)
    FetchContent_Populate(jsoncpp)
    add_subdirectory(${jsoncpp_SOURCE_DIR} ${jsoncpp_BINARY_DIR})
endif ()

set(SOURCES_FILES
        Source/SolidRepository.cpp
        )

set(HEADER_FILES
        Include/SolidRepository.h
        )


set(FILES
        ${SOURCES_FILES}
        ${HEADER_FILES}
        Include/JsonConverter.h Source/JsonConverter.cpp)


add_library(
        mecasolidRepository.libs STATIC
        ${FILES}
)



target_link_libraries(
        mecasolidRepository.libs
        mecasolidSolid.libs
        mecasolidUtils.libs
        jsoncpp_lib
)

target_include_directories(
        mecasolidRepository.libs PUBLIC
        Include/
)




