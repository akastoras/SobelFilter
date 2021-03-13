/*
 * Description: Functions for manipulating .pgm images
 * Author: Athanasios Kastoras | University of Thessaly
 * Email: akastoras@uth.gr
 */

#ifndef __PGM__H
#define __PGM__H

typedef struct pgm_image {
	int width;
	int height;
	int maxval;
	unsigned char *pixels;
} pgm_t;


/* Functions */
pgm_t *new_pgm_image(const int width, const int height, const int maxval);
pgm_t *load_pgm_image(const char *filename);
void store_pgm_image(pgm_t *image, char *filename);


#endif