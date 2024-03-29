cmake_minimum_required(VERSION 3.1.2)

project(MecaSolid VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "$<0:>${CMAKE_BINARY_DIR}/bin") # .exe and .dll
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "$<0:>${CMAKE_BINARY_DIR}/lib") # .so and .dylib
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "$<0:>${CMAKE_BINARY_DIR}/lib") # .lib and .a

# Exists in jsoncpp lib
add_compile_options(-Wno-unknown-pragmas)


set(SOURCES_FILES
	Source/main.cpp
)

set(FILES
    ${SOURCES_FILES}
       # Source/Libs/Repository/Include/SolidRepository.h Source/Libs/Repository/Source/SolidRepository.cpp
		)

add_executable(mecasolid
	${FILES}
)

target_link_libraries(
	mecasolid
	mecasolidUtils.libs
	mecasolidSolid.libs
)


add_subdirectory("Tests")
add_subdirectory("Source/Libs")