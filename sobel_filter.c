/*
 * Description: Implementation of Sobel Filter for detecting
 * edges on .pgm images.
 * Author: Athanasios Kastoras | University of Thessaly
 * Email: akastoras@uth.gr
 */

#include "pgm.h"
#include <stdio.h>
#include <math.h>

#define MAX(a,b) ((a < b)? b: a)


// https://en.wikipedia.org/wiki/Sobel_operator
pgm_t *sobel_filter(const pgm_t *image)
{	
	const int x_kernel[3][3] = {
		{-1, 0, 1},
		{-2, 0, 2},
		{-1, 0, 1}
	};
	const int y_kernel[3][3] = {
		{-1,-2,-1},
		{0, 0, 0},
		{1, 2, 1}
	};
	int x_sum, y_sum;
	int diff = 1;
	const int height = image->height, width = image->width, maxval = image->maxval;
	pgm_t *new_image = new_pgm_image(width, height, image->maxval);


	for (int x = 1; x < height - 1; ++x) {
		for (int y = 1; y < width - 1; ++y) {
			
			x_sum = y_sum = 0;
			for (int i = -1 * diff; i < diff; ++i) {
				for (int j = -1 * diff; j < diff; ++j) {
					x_sum += image->pixels[(x+i) * image->width + (y+j)] * x_kernel[i][j];
					y_sum += image->pixels[(x+i) * image->width + (y+j)] * y_kernel[i][j];
				}
			}
			new_image->pixels[x * image->width + y] = MAX( sqrt(x_sum*x_sum + y_sum*y_sum), maxval);
		}
	}
	return new_image;
}

int main(int argc, char **argv) {
	pgm_t *image = load_pgm_image(argv[1]);

	pgm_t *new_image = sobel_filter(image);

	store_pgm_image(new_image, argv[2]);
}

