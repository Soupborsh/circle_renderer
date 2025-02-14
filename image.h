#include "types.h"

#define N_BYTES (((WIDTH + 7) / 8) * HEIGHT)

int write_to_pbm(const char *filename, BYTE *image);
