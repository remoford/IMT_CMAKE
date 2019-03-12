# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.7)



include("cmake/HunterGate.cmake")
HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.23.131.tar.gz"
    SHA1 "0512ea6392065c8ece808296fddd7d8664d30920"
	LOCAL #
)


project(download-gsl)


# download gtest
hunter_add_package(GSL)

# now gtest can be used
find_package(GSL CONFIG REQUIRED)



project ("IMT_CMAKE")

# Include sub-projects.
add_subdirectory ("IMT_CMAKE")


