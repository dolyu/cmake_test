# CMakeList.txt : 최상위 CMake 프로젝트 파일, 전역 구성을 수행하고
# 여기에 하위 프로젝트를 포함합니다.
#
cmake_minimum_required (VERSION 3.8)

project (SHF)

#find_package(Boost 1.79.0 COMPONENTS filesystem REQUIRED )
set(CMAKE_BUILD_TYPE Debug)

# 하위 프로젝트를 포함합니다.
add_subdirectory ("shf")
