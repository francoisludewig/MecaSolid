cmake_minimum_required(VERSION 3.1.2)

set(SOURCES_FILES
        Source/Solid.cpp
        )

set(HEADER_FILES
        Include/Solid/Solid.h
        )


set(FILES
        ${SOURCES_FILES}
        ${HEADER_FILES}
        )


add_library(
        mecasolidSolid.libs STATIC
        ${FILES}
)

target_link_libraries(
        mecasolidSolid.libs
        mecasolidUtils.libs
        #jsoncpp
)

target_include_directories(
        mecasolidSolid.libs PUBLIC
        Include/
)


