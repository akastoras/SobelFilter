#include "pgm.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

/* Create a new empty image with the given characteristics */
pgm_t *new_pgm_image(const int width, const int height, const int maxval)
{
	pgm_t *image = malloc(sizeof(pgm_t));
	assert(image);

	image->width = width;
	image->height = height;
	image->maxval = maxval;
	image->pixels = (unsigned char *) calloc(width * height, sizeof(unsigned char));
	assert(image->pixels);

	return image;
}

/* Fill an image with random pixels. width, height
 and maxval fields should be initialized properly */
void rand_pgm_image(pgm_t *image)
{
	for (int i = 0; i < image->width; i++) {
		for (int j = 0; j < image->height; j++) {
			image->pixels[i*image->width + j] = (unsigned char) rand() % image->maxval;
		}
	}
}


/* Check if comments exist where the fp is, if so move past them */
void skip_comments(FILE *file)
{
	char c;

	fscanf(file, " %c", &c);
	if (c == '#') {
		while (fgetc(file) != '\n');
	}
	else {
		fseek(file, -1, SEEK_CUR);
	}
}


/* Load an image from a file */
pgm_t *load_pgm_image(const char *filename)
{
	FILE *file = fopen(filename, "rb");
	assert(file);
	char width_string[6], height_string[6], maxval_string[6];
	int width, height, maxval;
	char m1, m2;

	
	/* Read image metadata */
	skip_comments(file);
	fscanf(file, "%c%c", &m1, &m2);
	assert(m1 == 'P' && m2 == '5'); // Possible change: if m2 == 2: read ascii format

	skip_comments(file);
	fscanf(file, " %s", width_string);
	width = atoi(width_string);

	skip_comments(file);
	fscanf(file, " %s", height_string);
	height = atoi(height_string);
	
	skip_comments(file);
	fscanf(file, " %s", maxval_string);
	maxval = atoi(maxval_string);

	
	/* Create empty image */
	pgm_t *image = new_pgm_image(width, height, maxval);


	/* Read image content, ignore comments */
	skip_comments(file);
	fread(image->pixels, image->width * image->height, 1, file);

	fclose(file);
	return image;
}


/* Store an image to a file */
void store_pgm_image(const pgm_t *image, const char *filename)
{
	/* Open File */
	assert(image && image->pixels);
	FILE *file = fopen(filename, "wb");
	assert(file);

	/* Write metadata */
	fprintf(file, "P5\n");
	fprintf(file, "%d %d\n%d\n", image->width, image->height, image->maxval);

	/* Store the image content */
	fwrite(image->pixels, image->width * image->height, 1, file);

	fclose(file);
}

/* Create a white square at the center of the image */
void fill_pgm_image(pgm_t *image)
{
	for (int i = 0; i < image->height; i++) {
		for (int j = 0; j < image->width; j++) {
			if (i > image->height/4 && i < image->height*3/4
				&& j > image->width/4 && j < image->width*3/4) 
			{
				image->pixels[i*image->width + j] = image->maxval;
			}
			else {
				image->pixels[i*image->width + j] = 0;
			}
		}
	}
}

/* Check to see if the filtered image is 
an empty sqare at the center of the image*/
bool check_pgm_image(pgm_t *image)
{
	for (int i = 0; i < image->height; i++) {
		for (int j = 0; j < image->width; j++) {

			bool is_in_square_i = (i == image->height/4 || i == image->height/4 + 1
			 			|| i == image->height*3/4 || i == image->height*3/4 - 1)
						&& (j >= image->width/4 && j <= image->width*3/4);

			bool is_in_square_j = (j == image->height/4 || j == image->height/4 + 1
			 			|| j == image->height*3/4 || j == image->height*3/4 - 1)
						&& (i >= image->height/4 && i <= image->height*3/4);
			
			if (is_in_square_i || is_in_square_j) {
				printf("In square: %d %d -> %d\n", i, j, image->pixels[i*image->width + j]);
				if (image->pixels[i*image->width + j] == 0) {
					return false;
				}
			}
			else {
				printf("Out of square: %d %d -> %d\n", i, j, image->pixels[i*image->width + j]);
				if (image->pixels[i*image->width + j] != 0) {
					return false;
				}
			}
		}
	}

	return true;
}
