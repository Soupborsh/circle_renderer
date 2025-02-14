#include "circles.h"
#include "image.h"
#include <string.h>

// 512 x 512 by default
const UINT WIDTH = POWER_OF_2(9);
const UINT HEIGHT = POWER_OF_2(9);

int main(void) {
  // image buffer
  BYTE image[N_BYTES];
  memset(image, 0, N_BYTES);

  // functions that draw to image buffer
  draw_circle(image, WIDTH / 2 - WIDTH / 8, HEIGHT / 2 - HEIGHT / 8, WIDTH / 4);
  draw_hollow_circle(image, WIDTH / 2 + WIDTH / 8, HEIGHT / 2 - HEIGHT / 8,
                     WIDTH / 4, WIDTH / 16);
  draw_xor_circle(image, WIDTH / 2, HEIGHT / 2 + HEIGHT / 8, WIDTH / 4);

  // Old example image:
  // draw_xor_circle(image, WIDTH / 2 - WIDTH / 8, HEIGHT / 2, WIDTH / 4);
  // draw_xor_circle(image, WIDTH / 2 + WIDTH / 8, HEIGHT / 2, WIDTH / 4);
  // draw_xor_circle(image, WIDTH / 2, HEIGHT / 2 + HEIGHT / 8, WIDTH / 4);
  // draw_xor_circle(image, WIDTH / 2, HEIGHT / 2 - HEIGHT / 8, WIDTH / 4);
  write_to_pbm("image.pbm", image);
  return 0;
}
