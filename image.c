#include "image.h"
#include <stdio.h>
extern const UINT WIDTH;
extern const UINT HEIGHT;

int write_to_pbm(const char *filename, BYTE *image) {
    FILE *fptr = fopen(filename, "wb");
    if (fptr == NULL) {
        fprintf(stderr,"ERROR while opening file image.pbm\n");
        return -1;
    }
    // write pbm file header
    fprintf(fptr, "P4\n%u %u\n", WIDTH, HEIGHT);
    // write image buffer to file
    fwrite(image, sizeof(BYTE), N_BYTES, fptr);
    fclose(fptr);
    return 0;
}
