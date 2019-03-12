#include "main.h"

extern void window_conv(const distType z[], const distType y[], distType C[], double h, int size_xyz);

extern void get_window(const distType z[], const distType y[], long * firstIdx, long * lastIdx, long * firstYIdx, long * lastYIdx, distType threshold, unsigned long size_xyz);