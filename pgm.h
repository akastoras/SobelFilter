/*
 * Description: Functions for manipulating .pgm images
 * Author: Athanasios Kastoras | University of Thessaly
 * Email: akastoras@uth.gr
 */

#ifndef __PGM_H_
#define __PGM_H_

#include <stdbool.h>

typedef struct pgm_image {
	int width;
	int height;
	int maxval;
	unsigned char *pixels; // Each Pixel is represented by a value from 0 (black) to maxval (white)
} pgm_t;


/* Functions */
pgm_t *new_pgm_image(const int width, const int height, const int maxval);
pgm_t *load_pgm_image(const char *filename);
void store_pgm_image(const pgm_t *image, const char *filename);
void rand_pgm_image(pgm_t *image);
void fill_pgm_image(pgm_t *image);
bool check_pgm_image(pgm_t *image);

#endif