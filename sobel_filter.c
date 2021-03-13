#include "pgm.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv) {
	pgm_t *image = load_pgm_image(argv[1]);

	store_pgm_image(image, argv[2]);
}