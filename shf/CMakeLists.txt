
cmake_minimum_required (VERSION 3.8)

project (SHF)

#find_package(Boost 1.79.0 COMPONENTS filesystem REQUIRED )
set(CMAKE_BUILD_TYPE Debug)

# 하위 프로젝트를 포함합니다.

set(SHF_TITLE SHF)
set(SHF_DESCRIPTION "Standard Head Functions of WGS")

set(SHF_VERSION_MAJOR 0)
set(SHF_VERSION_MINOR 0)
set(SHF_VERSION_MICRO 1)

configure_file (
	${PROJECT_SOURCE_DIR}/config.h.in
	${PROJECT_BINARY_DIR}/config.h
)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c17")

# set(Boost_DIR C:/local/boost_1_79_0)
# SET(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "C:/boost/include/boost-1_79")
# SET(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "C:/boost/lib")
SET(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "C:/local/boost_1_79_0/boost")
SET(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "C:/local/boost_1_79_0/stage/lib")
# set(BOOST_ROOT C:/local/boost_1_79_0)
# set(Boost_DIR C:/local/boost_1_79_0)
# set(Boost_LIBRARY_DIRS C:/local/boost_1_79_0/lib64-msvc-14.3)
set (Boost_DETAILED_FAILURE_MSG ON)
set (Boost_THREADAPI win32)
# set (BOOST_DIR "C/boost/include/boost-1_79")
# set (BOOST_ROOT "C:/boost/include/boost-1_79")
# set (Boost_LIBRARY_DIR  "C:/boost/lib")
set (BOOST_DIR "C:/local/boost_1_79_0")
set (BOOST_ROOT "C:/local/boost_1_79_0")
set (Boost_LIBRARY_DIR  "C:/local/boost_1_79_0/stage/lib")
set (Boost_COMPILER "-vc")
set (Boost_USE_STATIC_RUNTIME ON)  
set (Boost_DEBUG ON)  #<---------- Real life saver
message(STATUS "Boost include dirs: ( ${Boost_INCLUDE_DIRS} )")
message(STATUS "Boost root dirs: ( ${Boost_ROOT} )")

find_package(Boost REQUIRED)
# find_package(Boost REQUIRED COMPONENTS  filesystem)
# find_package(OPENCV REQUIRED)
include_directories(
	${CMAKE_CURRENT_BINARY_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}
	${Boost_INCLUDE_DIRS}
)

#===============================================================================
#= Release flags
#-------------------------------------------------------------------------------
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
add_compile_options(-O3)

#boost
if(Boost_FOUND)
	message(STATUS "Boost library status:")
	message(STATUS "    version: ${Boost_VERSION}")
	message(STATUS "    Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
	message(STATUS "    Boost_LIBRARY_DIRS: ${Boost_LIBRARY_DIRS}")
	
			set(BOOST_LIBRARIES 
		${Boost_LIBRARY_DIR_DEBUG}/libboost_filesystem-mgw11-mt-x64-1_79.a
			)
			include_directories(${Boost_INCLUDE_DIRS})
endif()


set(SHF_SOURCES
  main.cpp
)
set(SHF_HEADERS
	test.h
)

set(SHF_LINK_LIBS
	${BOOST_LIBRARIES}
)

add_executable(
	${PROJECT_NAME}
	${SHF_HEADERS}
	${SHF_SOURCES}
)
target_include_directories(${PROJECT_NAME}
	PUBLIC ${Boost_INCLUDE_DIR}
)

target_link_libraries(${PROJECT_NAME} ${SHF_LINK_LIBS})
target_link_libraries(${PROJECT_NAME} ${Boost_FILESYSTEM_LIBRARY}  ${Boost_SYSTEM_LIBRARY})
# TODO: 필요한 경우 테스트를 추가하고 대상을 설치합니다.
