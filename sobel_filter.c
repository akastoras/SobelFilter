/*
 * Description: Implementation of Sobel Filter for detecting
 * edges on .pgm images.
 * Author: Athanasios Kastoras | University of Thessaly
 * Email: akastoras@uth.gr
 */

#include "pgm.h"
#include <stdio.h>

int main(int argc, char **argv) {
	pgm_t *image = load_pgm_image(argv[1]);

	store_pgm_image(image, argv[2]);
}