#include <stdio.h>

// 512 x 512 by default
#define WIDTH POWER_OF_2(9)
#define HEIGHT POWER_OF_2(9)

#define BYTE unsigned char
#define N_BITS (sizeof(BYTE) * 8)
#define N_BYTES (((WIDTH + 7) / 8) * HEIGHT)
#define BYTE_I (i / 8)
#define BIT_I (7 - (i % 8))
#define POWER_OF_2(x) (1 << (x))
#define UINT unsigned int

void draw_circle(BYTE *image, UINT a, UINT b, UINT r);
void draw_xor_circle(BYTE *image, UINT a, UINT b, UINT r);
void draw_hollow_circle(BYTE *image, UINT a, UINT b, UINT r, UINT thickness);

int main(void) {
  FILE *fptr = fopen("image.pbm", "wb");
  if (fptr == NULL) {
    printf("ERROR while opening file image.pbm\n");
    return -1;
  }
  // image buffer
  BYTE image[N_BYTES] = {0};

  // functions that draw to image buffer
  // FIX: currently there is some layering bug,
  // however, it produces cool images
  // draw_xor_circle(image, WIDTH / 2 - WIDTH / 8, HEIGHT / 2 - HEIGHT / 8,
  //                 WIDTH / 4);
  // draw_xor_circle(image, WIDTH / 2 + WIDTH / 8, HEIGHT / 2 - HEIGHT / 8,
  //                 WIDTH / 4);
  // draw_xor_circle(image, WIDTH / 2, HEIGHT / 2 + HEIGHT / 8, WIDTH / 4);

  draw_xor_circle(image, WIDTH / 2 - WIDTH / 8, HEIGHT / 2, WIDTH / 4);
  draw_xor_circle(image, WIDTH / 2 + WIDTH / 8, HEIGHT / 2, WIDTH / 4);
  draw_xor_circle(image, WIDTH / 2, HEIGHT / 2 + HEIGHT / 8, WIDTH / 4);
  draw_xor_circle(image, WIDTH / 2, HEIGHT / 2 - HEIGHT / 8, WIDTH / 4);

  // draw_circle(image, WIDTH / 2 + WIDTH / 8, HEIGHT / 2, WIDTH / 4);
  // draw_hollow_circle(image, WIDTH / 2, HEIGHT / 2, WIDTH / 3, 16);

  // write image buffer to file
  fprintf(fptr, "P4\n%u %u\n", WIDTH, HEIGHT);
  fwrite(image, sizeof(BYTE), N_BYTES, fptr);
  fclose(fptr);
  return 0;
}

void draw_xor_circle(BYTE *image, UINT a, UINT b, UINT r) {
  for (UINT y = 0, i = 0; y < HEIGHT; y++) {
    for (UINT x = 0; x < WIDTH; x++, i++) {
      if ((r * r) <= ((x - a) * (x - a) + (y - b) * (y - b))) {
        image[BYTE_I] ^= 1 << BIT_I;
      }
    }
  }
}

void draw_circle(BYTE *image, UINT a, UINT b, UINT r) {
  for (UINT y = 0, i = 0; y < HEIGHT; y++) {
    for (UINT x = 0; x < WIDTH; x++, i++) {
      if ((r * r) <= ((x - a) * (x - a) + (y - b) * (y - b))) {
        image[BYTE_I] |= 1 << BIT_I;
      }
    }
  }
}

void draw_hollow_circle(BYTE *image, UINT a, UINT b, UINT r, UINT thickness) {
  for (UINT y = 0, i = 0; y < HEIGHT; y++) {
    for (UINT x = 0; x < WIDTH; x++, i++) {
      if ((r * r) - ((x - a) * (x - a) + (y - b) * (y - b)) >=
          (r * 2 * thickness)) {
        image[BYTE_I] |= 1 << BIT_I;
      }
    }
  }
}
