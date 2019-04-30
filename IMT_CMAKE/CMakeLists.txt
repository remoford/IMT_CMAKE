# CMakeList.txt : CMake project for IMT_CMAKE, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.7)

# Add source to this project's executable.
add_executable (IMT_CMAKE "main.c" "main.h" "binned_conv.c" "binned_conv.h" "conv.c" "conv.h" "emgpdf.c" "emgpdf.h" "gp_max.c" "gp_max.h" "imt_analysis.c" "imt_analysis.h" "loglikelihood.c" "loglikelihood.h" "mexWrap.c" "nn_conv.c" "nn_conv.h" "onestage.c" "onestage.h" "onestagepdf_lag.c" "onestagepdf_lag.h" "onestagepdf_prime.c" "onestagepdf_prime.h" "tailmass.c" "tailmass.h" "threestage.c" "threestage.h" "twostage.c" "twostage.h" "utility.c" "utility.h" "window_conv.c" "window_conv.h")


message("\n\n\nHEYO TIME FOR LINKING-O\n\n\n")

target_link_libraries(IMT_CMAKE GSL::gsl)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
target_link_libraries(IMT_CMAKE m)
endif()
#message( ${CMAKE_EXE_LINKER_FLAGS})


message("\n\n\nHEYO DONE WITH THE LINKING-O\n\n\n")

find_package(Matlab)
matlab_add_mex(NAME IMT_MEX SRC "main.c" "main.h" "binned_conv.c" "binned_conv.h" "conv.c" "conv.h" "emgpdf.c" "emgpdf.h" "gp_max.c" "gp_max.h" "imt_analysis.c" "imt_analysis.h" "loglikelihood.c" "loglikelihood.h" "mexWrap.c" "nn_conv.c" "nn_conv.h" "onestage.c" "onestage.h" "onestagepdf_lag.c" "onestagepdf_lag.h" "onestagepdf_prime.c" "onestagepdf_prime.h" "tailmass.c" "tailmass.h" "threestage.c" "threestage.h" "twostage.c" "twostage.h" "utility.c" "utility.h" "window_conv.c" "window_conv.h" LINK_TO GSL::gsl R2018a)
target_link_libraries(IMT_MEX GSL::gsl)
set_target_properties(IMT_MEX PROPERTIES COMPILE_FLAGS "-fvisibility=default")

# TODO: Add tests and install targets if needed.




