/*
 * Description: Implementation of Sobel Filter for detecting
 * edges on .pgm images.
 * Author: Athanasios Kastoras | University of Thessaly
 * Email: akastoras@uth.gr
 */

#include "pgm.h"
#include <stdio.h>
#include <math.h>

#define TRHESHOLD(a,max) ((a > max)? max: 0)


// https://en.wikipedia.org/wiki/Sobel_operator
pgm_t *sobel_filter(const pgm_t *image)
{	
	const int x_kernel[3][3] = {
		{-1, 0, 1},
		{-5, 0, 5},
		{-1, 0, 1}
	};
	const int y_kernel[3][3] = {
		{-1,-5,-1},
		{0, 0, 0},
		{1, 5, 1}
	};
	int x_sum, y_sum;
	const int height = image->height, width = image->width, maxval = image->maxval;
	pgm_t *new_image = new_pgm_image(width, height, image->maxval);


	for (int x = 1; x < height - 1; ++x) {
		for (int y = 1; y < width - 1; ++y) {
			x_sum = (
				(x_kernel[0][0] * image->pixels[(x - 1)*width + (y - 1)]) +
				(x_kernel[0][1] * image->pixels[(x)*width + (y - 1)]) +
				(x_kernel[0][2] * image->pixels[(x + 1)*width + (y - 1)]) +
				(x_kernel[1][0] * image->pixels[(x - 1)*width + (y)]) +
				(x_kernel[1][1] * image->pixels[(x)*width + (y)]) +
				(x_kernel[1][2] * image->pixels[(x + 1)*width + (y)]) +
				(x_kernel[2][0] * image->pixels[(x - 1)*width + (y + 1)]) +
				(x_kernel[2][1] * image->pixels[(x)*width + (y + 1)]) +
				(x_kernel[2][2] * image->pixels[(x + 1)*width + (y + 1)])
        	);
			y_sum = (
				(y_kernel[0][0] * image->pixels[(x - 1)*width + (y - 1)]) +
				(y_kernel[0][1] * image->pixels[(x)*width + (y - 1)]) +
				(y_kernel[0][2] * image->pixels[(x + 1)*width + (y - 1)]) +
				(y_kernel[1][0] * image->pixels[(x - 1)*width + (y)]) +
				(y_kernel[1][1] * image->pixels[(x)*width + (y)]) +
				(y_kernel[1][2] * image->pixels[(x + 1)*width + (y)]) +
				(y_kernel[2][0] * image->pixels[(x - 1)*width + (y + 1)]) +
				(y_kernel[2][1] * image->pixels[(x)*width + (y + 1)]) +
				(y_kernel[2][2] * image->pixels[(x + 1)*width + (y + 1)])
        	);

			new_image->pixels[x * image->width + y] = TRHESHOLD( sqrt(x_sum*x_sum + y_sum*y_sum), maxval);
		}
	}
	return new_image;
}

int main(int argc, char **argv) {
	pgm_t *image = load_pgm_image(argv[1]);

	pgm_t *new_image = sobel_filter(image);

	store_pgm_image(new_image, argv[2]);
}

