BUILD INSTRUCTIONS

Building with cmake is supported on both *nix and windows. The first step, configure, downloads and compiles the GSL library and sets up the build system. The second step, building, can happen on the command line or in your favorite IDE. Several compilers are supported. These include GCC, MSVC, ICC and LLVM. The Intel C++ Compiler works for compiling IMT but not the GSL library. Tested build systems include Makefiles, Eclipse CDT projects, Ninja and Visual Studio. Some IDEs such as VSCode can build cmake projects directly.



Here are some examples of building on linux (in this case windows subsystem for linux):

MAKEFILE GCC
jrf2m@DESKTOP-TQ8AHR0:/mnt/c/Users/remof/source/repos/IMT_CMAKE$ cmake -H. -B_wsl_gcc_builds
jrf2m@DESKTOP-TQ8AHR0:/mnt/c/Users/remof/source/repos/IMT_CMAKE$ cmake --build _wsl_gcc_builds --config Release

MAKEFILE LLVM
jrf2m@DESKTOP-TQ8AHR0:/mnt/c/Users/remof/source/repos/IMT_CMAKE$ cmake -H. -B_wsl_llvm_builds -DCMAKE_C_COMPILER:PATH="/usr/bin/clang"
jrf2m@DESKTOP-TQ8AHR0:/mnt/c/Users/remof/source/repos/IMT_CMAKE$ cmake --build _wsl_llvm_builds --config Release

MAKEFILE INTEL
root@DESKTOP-TQ8AHR0:/mnt/c/Users/remof/source/repos/IMT_CMAKE# cmake . -B_wsl_intel_builds -DCMAKE_C_COMPILER:PATH="/opt/intel/bin/icc" -DCMAKE_CXX_COMPILER:PATH="/opt/intel/bin/icc"
root@DESKTOP-TQ8AHR0:/mnt/c/Users/remof/source/repos/IMT_CMAKE# cmake --build _wsl_intel_builds --config Release

NINJA INTEL
root@DESKTOP-TQ8AHR0:/mnt/c/Users/remof/source/repos/IMT_CMAKE# cmake . -B_wsl_ninja_intel_builds -G Ninja -DCMAKE_C_COMPILER:PATH="/opt/intel/bin/icc" -DCMAKE_CXX_COMPILER:PATH="/opt/intel/bin/icc"
root@DESKTOP-TQ8AHR0:/mnt/c/Users/remof/source/repos/IMT_CMAKE# cmake --build _wsl_ninja_intel_builds --config Release

NINJA GCC
jrf2m@DESKTOP-TQ8AHR0:/mnt/c/Users/remof/source/repos/IMT_CMAKE$ cmake . -B_wsl_ninja_gcc -G Ninja
jrf2m@DESKTOP-TQ8AHR0:/mnt/c/Users/remof/source/repos/IMT_CMAKE$ cmake --build _wsl_ninja_gcc --config Release

NINJA LLVM
jrf2m@DESKTOP-TQ8AHR0:/mnt/c/Users/remof/source/repos/IMT_CMAKE$ cmake . -B_wsl_ninja_llvm -G Ninja -DCMAKE_C_COMPILER:PATH="/usr/bin/clang"
jrf2m@DESKTOP-TQ8AHR0:/mnt/c/Users/remof/source/repos/IMT_CMAKE$ cmake --build _wsl_ninja_llvm --config Release



For windows, it is best to use the x64 Native Tools Command Prompt for VS 2017 which takes care of several enviroment variables for you.

If you want to compile from the command line:

NINJA GCC
c:\Users\remof\source\repos\IMT_CMAKE>cmake -B_ninja_gcc_builds -G Ninja
c:\Users\remof\source\repos\IMT_CMAKE>cmake --build _ninja_gcc_builds --config Release

NINJA LLVM
c:\Users\remof\source\repos\IMT_CMAKE>cmake -B_ninja_llvm_builds -G Ninja -DCMAKE_C_COMPILER:PATH="C:\Program Files\LLVM\bin\clang-cl.exe" -DCMAKE_CXX_COMPILER:PATH="C:\Program Files\LLVM\bin\clang-cl.exe"
c:\Users\remof\source\repos\IMT_CMAKE>cmake --build _ninja_llvm_builds --config Release

NINJA MSVC
c:\Users\remof\source\repos\IMT_CMAKE>cmake -G Ninja -B _ninja_builds -DCMAKE_C_COMPILER:PATH="C:/Program Files (x86)/Microsoft Visual Studio/2017/Enterprise/VC/Tools/MSVC/14.16.27023/bin/Hostx64/x64/cl.exe" -DCMAKE_CXX_COMPILER:PATH="C:/Program Files (x86)/Microsoft Visual Studio/2017/Enterprise/VC/Tools/MSVC/14.16.27023/bin/Hostx64/x64/cl.exe"
c:\Users\remof\source\repos\IMT_CMAKE>cmake --build _ninja_builds --config Release



If you want to compile from an IDE:

CDT GCC
c:\Users\remof\source\repos\IMT_CMAKE>cmake -B_cdt_gcc_builds -G "Eclipse CDT4 - Ninja"
Open _cdt_gcc_builds using open projects from filesystem and build all

VSCode Ninja GCC
With cmake and cmake tools extensions installed, VSCode can configure and build in an integrated fashion. On my windows machine, the GCC for mingw32 8.2.0 toolkit builds using Makefiles and the Visual Studio Enterprise 2017 - amd64 toolkit works via Ninja. VSCode also works well on OSX.

Note, while Visual Studio has a cmake open directory functionality, this doesn't work with this project. For some reason it tries to include lib.m when MSVC doesn't want math linked explicitly. Surely this is fixable... However, we can generate native .sln files!

Visual Studio MSVC
c:\Users\remof\source\repos\IMT_CMAKE>cmake -B_vs_msvc_builds -G "Visual Studio 15 2017 Win64"
Open generated .sln in visual studio and build

Visual Studio LLVM
c:\Users\remof\source\repos\IMT_CMAKE>cmake -B_vs_msvc_builds -G "Visual Studio 15 2017 Win64" -T LLVM
Open generated .sln in visual studio and build

Visual Studio INTEL
Use cmake to generate .sln with either MSVC or LLVM then change the toolset directly inside visual studio. For some reason, Intel can't compile GSL but it can link the previously compiled GSL object files. This seems to be a reasonable compromise for the moment.

doesnt work: c:\Users\remof\source\repos\IMT_CMAKE>cmake -G "Visual Studio 15 2017 Win64" -B _vs_intel_builds -T "Intel C++ Compiler 19.0"
doesnt work: c:\Users\remof\source\repos\IMT_CMAKE>cmake -G "Visual Studio 15 2017 Win64" -B _vs_intel_builds -DCMAKE_C_COMPILER:PATH="C:\Program Files (x86)\IntelSWTools\compilers_and_libraries\windows\bin\intel64\icl.exe" -DCMAKE_CXX_COMPILER:PATH="C:\Program Files (x86)\IntelSWTools\compilers_and_libraries\windows\bin\intel64\icl.exe"
doest work: c:\Users\remof\source\repos\IMT_CMAKE>cmake -G Ninja -B _ninja_intel_builds -DCMAKE_C_COMPILER:PATH="C:\Program Files (x86)\IntelSWTools\compilers_and_libraries\windows\bin\intel64\icl.exe" -DCMAKE_CXX_COMPILER:PATH="C:\Program Files (x86)\IntelSWTools\compilers_and_libraries\windows\bin\intel64\icl.exe"



MATLAB MEX - work in progress

jrf2m@DESKTOP-TQ8AHR0:/mnt/c/Users/remof/source/repos/IMT_CMAKE$ cmake --build _wsl_ninja_gcc --config Release
[1/1] Linking C shared library IMT_CMAKE/IMT_MEX.mexa64
FAILED: IMT_CMAKE/IMT_MEX.mexa64
: && /usr/bin/cc -fPIC    -shared -Wl,-soname,IMT_MEX.mexa64 -o IMT_CMAKE/IMT_MEX.mexa64 IMT_CMAKE/CMakeFiles/IMT_MEX.dir/main.c.o IMT_CMAKE/CMakeFiles/IMT_MEX.dir/binned_conv.c.o IMT_CMAKE/CMakeFiles/IMT_MEX.dir/conv.c.o IMT_CMAKE/CMakeFiles/IMT_MEX.dir/emgpdf.c.o IMT_CMAKE/CMakeFiles/IMT_MEX.dir/gp_max.c.o IMT_CMAKE/CMakeFiles/IMT_MEX.dir/imt_analysis.c.o IMT_CMAKE/CMakeFiles/IMT_MEX.dir/loglikelihood.c.o IMT_CMAKE/CMakeFiles/IMT_MEX.dir/mexWrap.c.o IMT_CMAKE/CMakeFiles/IMT_MEX.dir/nn_conv.c.o IMT_CMAKE/CMakeFiles/IMT_MEX.dir/onestage.c.o IMT_CMAKE/CMakeFiles/IMT_MEX.dir/onestagepdf_lag.c.o IMT_CMAKE/CMakeFiles/IMT_MEX.dir/onestagepdf_prime.c.o IMT_CMAKE/CMakeFiles/IMT_MEX.dir/tailmass.c.o IMT_CMAKE/CMakeFiles/IMT_MEX.dir/threestage.c.o IMT_CMAKE/CMakeFiles/IMT_MEX.dir/twostage.c.o IMT_CMAKE/CMakeFiles/IMT_MEX.dir/utility.c.o IMT_CMAKE/CMakeFiles/IMT_MEX.dir/window_conv.c.o -L/usr/local/MATLAB/R2019a/bin/glnxa64 -Wl,-rpath,/usr/local/MATLAB/R2019a/bin/glnxa64 -lmex /home/jrf2m/.hunter/_Base/0512ea6/d1541bf/f172cd0/Install/lib/libgsl-OFF.a -lR2018a /home/jrf2m/.hunter/_Base/0512ea6/d1541bf/f172cd0/Install/lib/libgsl-OFF.a /home/jrf2m/.hunter/_Base/0512ea6/d1541bf/f172cd0/Install/lib/libgslcblas-OFF.a -lm && :
/usr/bin/ld: cannot find -lR2018a
collect2: error: ld returned 1 exit status
ninja: build stopped: subcommand failed.
jrf2m@DESKTOP-TQ8AHR0:/mnt/c/Users/remof/source/repos/IMT_CMAKE$

jrf2m@DESKTOP-TQ8AHR0:/mnt/c/Users/remof/source/repos/IMT_CMAKE/_wsl_ninja_gcc$ /usr/bin/cc -fPIC    -shared -Wl,-soname,IMT_MEX.mexa64 -o IMT_CMAKE/IMT_MEX.mexa64 IMT_CMAKE/CMakeFiles/IMT_MEX.dir/main.c.o IMT_CMAKE/CMakeFiles/IMT_MEX.dir/binned_conv.c.o IMT_CMAKE/CMakeFiles/IMT_MEX.dir/conv.c.o IMT_CMAKE/CMakeFiles/IMT_MEX.dir/emgpdf.c.o IMT_CMAKE/CMakeFiles/IMT_MEX.dir/gp_max.c.o IMT_CMAKE/CMakeFiles/IMT_MEX.dir/imt_analysis.c.o IMT_CMAKE/CMakeFiles/IMT_MEX.dir/loglikelihood.c.o IMT_CMAKE/CMakeFiles/IMT_MEX.dir/mexWrap.c.o IMT_CMAKE/CMakeFiles/IMT_MEX.dir/nn_conv.c.o IMT_CMAKE/CMakeFiles/IMT_MEX.dir/onestage.c.o IMT_CMAKE/CMakeFiles/IMT_MEX.dir/onestagepdf_lag.c.o IMT_CMAKE/CMakeFiles/IMT_MEX.dir/onestagepdf_prime.c.o IMT_CMAKE/CMakeFiles/IMT_MEX.dir/tailmass.c.o IMT_CMAKE/CMakeFiles/IMT_MEX.dir/threestage.c.o IMT_CMAKE/CMakeFiles/IMT_MEX.dir/twostage.c.o IMT_CMAKE/CMakeFiles/IMT_MEX.dir/utility.c.o IMT_CMAKE/CMakeFiles/IMT_MEX.dir/window_conv.c.o -L/usr/local/MATLAB/R2019a/bin/glnxa64 -Wl,-rpath,/usr/local/MATLAB/R2019a/bin/glnxa64 -lmex /home/jrf2m/.hunter/_Base/0512ea6/d1541bf/f172cd0/Install/lib/libgsl-OFF.a  /home/jrf2m/.hunt
er/_Base/0512ea6/d1541bf/f172cd0/Install/lib/libgsl-OFF.a /home/jrf2m/.hunter/_Base/0512ea6/d1541bf/f172cd0/Install
/lib/libgslcblas-OFF.a -lm
/usr/bin/ld: /home/jrf2m/.hunter/_Base/0512ea6/d1541bf/f172cd0/Install/lib/libgsl-OFF.a(init.c.o): relocation R_X86_64_PC32 against symbol `gsl_vector_complex_long_double_alloc' can not be used when making a shared object; recompile with -fPIC
/usr/bin/ld: final link failed: Bad value
collect2: error: ld returned 1 exit status