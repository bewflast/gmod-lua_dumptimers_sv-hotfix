cmake_minimum_required(VERSION 3.18)
project(dumptimers_fix LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CONFIGURATION_TYPES Release Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin/release)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin/debug)
set(CMAKE_RUNTIME_LIBRARY_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin/release)
set(CMAKE_RUNTIME_LIBRARY_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin/debug)

if(UNIX)
        set(CMAKE_CXX_FLAGS "-m32")
endif()

function(set_gmod_suffix_prefix library)
        SET_TARGET_PROPERTIES(${library} PROPERTIES PREFIX "gmsv_")
        if(UNIX)
                SET_TARGET_PROPERTIES(${library} PROPERTIES SUFFIX "_linux.dll")
        elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
                SET_TARGET_PROPERTIES(${library} PROPERTIES SUFFIX "_win32.dll")
	elseif(CMAKE_SIZEOF_VOID_P EQUAL 8)
		SET_TARGET_PROPERTIES(${library} PROPERTIES SUFFIX "_win64.dll")
        endif()
endfunction()

add_subdirectory(gmod-interfaces-book)

set(    SOURCES
                source/main.cpp
                source/SDK/icvar.cpp
)

add_library(dumptimers_fix SHARED ${SOURCES})
target_include_directories(dumptimers_fix PRIVATE include)
target_link_libraries(dumptimers_fix ifacesbook)

set_gmod_suffix_prefix(dumptimers_fix)
