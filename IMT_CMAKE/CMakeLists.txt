# CMakeList.txt : CMake project for IMT_CMAKE, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.7)












# Add source to this project's executable.
add_executable (IMT_CMAKE "main.c" "main.h" "binned_conv.c" "binned_conv.h" "conv.c" "conv.h" "emgpdf.c" "emgpdf.h" "gp_max.c" "gp_max.h" "imt_analysis.c" "imt_analysis.h" "loglikelihood.c" "loglikelihood.h" "mexWrap.c" "nn_conv.c" "nn_conv.h" "onestage.c" "onestage.h" "onestagepdf_lag.c" "onestagepdf_lag.h" "onestagepdf_prime.c" "onestagepdf_prime.h" "tailmass.c" "tailmass.h" "threestage.c" "threestage.h" "twostage.c" "twostage.h" "utility.c" "utility.h" "window_conv.c" "window_conv.h")

target_link_libraries(IMT_CMAKE GSL::gsl)


# TODO: Add tests and install targets if needed.




