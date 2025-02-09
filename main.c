#include <stdio.h>

#define BYTE unsigned char
#define N_BITS (sizeof(BYTE) * 8)
#define N_BYTES (((WIDTH + 7) / 8) * HEIGHT)
#define BYTE_I (i / 8)
#define BIT_I (7 - (i % 8))
#define UINT unsigned int
#define WIDTH 256
#define HEIGHT 256

int main(void) {
  FILE *fptr = fopen("image.pbm", "wb");
  if (fptr == NULL) {
    printf("ERROR while opening file\n");
    return -1;
  }

  fprintf(fptr, "P4\n%u %u\n", WIDTH, HEIGHT);

  BYTE image[N_BYTES] = {0};

  UINT a = WIDTH / 2, b = HEIGHT / 2, r = WIDTH / 2;
  for (UINT y = 0, i = 0; y < HEIGHT; y++) {
    for (UINT x = 0; x < WIDTH; x++, i++) {
      if (r * r >= (x - a) * (x - a) + (y - b) * (y - b)) {
        image[BYTE_I] |= 1 << BIT_I;
      }
    }
  }
  fwrite(image, sizeof(BYTE), N_BYTES, fptr);
  fclose(fptr);
  return 0;
}
