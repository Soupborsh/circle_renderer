#include "circles.h"

#define N_BITS (sizeof(BYTE) * 8)
#define BYTE_I (((y * WIDTH) + x) / 8)
#define BIT_I (7 - (((y * WIDTH) + x) % 8))
#define BOUNDARY(n, r) (((n) >= (r)) ? ((n) - (r)) : (0))
#define BOUNDARY_2_WIDTH(x, r)                                                 \
  ((((x) + (r)) < WIDTH) ? ((x) + (r)) : (WIDTH - 1))
#define BOUNDARY_2_HEIGHT(y, r)                                                \
  ((((y) + (r)) < HEIGHT) ? ((y) + (r)) : (HEIGHT - 1))

extern const UINT WIDTH;
extern const UINT HEIGHT;

void draw_xor_circle(BYTE *image, UINT a, UINT b, UINT r) {
  for (UINT y = BOUNDARY(b, r); y < BOUNDARY_2_HEIGHT(b, r); y++) {
    for (UINT x = BOUNDARY(a, r); x < BOUNDARY_2_WIDTH(a, r); x++) {
      if ((r * r) >= ((x - a) * (x - a) + (y - b) * (y - b))) {
        image[BYTE_I] ^= 1 << BIT_I;
      }
    }
  }
}

void draw_circle(BYTE *image, UINT a, UINT b, UINT r) {
  for (UINT y = BOUNDARY(b, r); y < BOUNDARY_2_HEIGHT(b, r); y++) {
    for (UINT x = BOUNDARY(a, r); x < BOUNDARY_2_WIDTH(a, r); x++) {
      if ((r * r) >= ((x - a) * (x - a) + (y - b) * (y - b))) {
        image[BYTE_I] |= 1 << BIT_I;
      }
    }
  }
}

void draw_hollow_circle(BYTE *image, UINT a, UINT b, UINT r, UINT thickness) {
  for (UINT y = BOUNDARY(b, r); y < BOUNDARY_2_HEIGHT(b, r); y++) {
    for (UINT x = BOUNDARY(a, r); x < BOUNDARY_2_WIDTH(a, r); x++) {
      if ((r * r) - ((x - a) * (x - a) + (y - b) * (y - b)) <=
          (r * 2 * thickness)) {
        image[BYTE_I] |= 1 << BIT_I;
      }
    }
  }
}
