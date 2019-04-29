# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.7)


option(GLM_TEST_ENABLE_FAST_MATH "Enable fast math optimizations" OFF)
if(GLM_TEST_ENABLE_FAST_MATH)
	if(NOT GLM_QUIET)
		message(STATUS "GLM: Build with fast math optimizations")
	endif()
	if((CMAKE_CXX_COMPILER_ID MATCHES "Clang") OR (CMAKE_CXX_COMPILER_ID MATCHES "GNU"))
		add_compile_options(-ffast-math)
	elseif(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
		add_compile_options(/fp:fast)
	endif()
else()
	if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
		add_compile_options(/fp:precise)
	endif()
endif()



option(HUNTER_STATUS_DEBUG "Print a lot of info" ON)
option(HUNTER_CONFIGURATION_TYPES Release)
option(CMAKE_CONFIGURATION_TYPES Release)


include("cmake/HunterGate.cmake")
HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.23.131.tar.gz"
    SHA1 "0512ea6392065c8ece808296fddd7d8664d30920"
	LOCAL 
)


project(download-gsl)
# download gtest
hunter_add_package(GSL)
# now gtest can be used
find_package(GSL CONFIG REQUIRED)


project ("IMT_CMAKE")

# Include sub-projects.
add_subdirectory ("IMT_CMAKE")


