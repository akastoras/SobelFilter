# define compiler
CC       = gcc
# define compiler flags
CFLAGS   = -Wall -g -fopenmp
# define the object files that this project needs
OBJFILES = pgm.o sobel_filter.o
# define the executable file's name
MAIN     = sobel_filter

all: $(MAIN)

$(MAIN): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJFILES) -lm
	
%.o: %.c %.h
	$(CC) $(CFLAGS) -c -o $@ $<
clean:
	rm *.o images/*_new.pgm

std:
	./sobel_filter --std-test images/square_filled.pgm images/square_empty.pgm 

run_img01:
	./sobel_filter images/img0001.pgm images/img0001_new.pgm

run_img02:
	./sobel_filter images/img0002.pgm images/img0002_new.pgm

run_img03:
	./sobel_filter images/img0003.pgm images/img0003_new.pgm

run_img04:
	./sobel_filter images/img0004.pgm images/img0004_new.pgm

run_img05:
	./sobel_filter images/img0005.pgm images/img0005_new.pgm

run_img06:
	./sobel_filter images/img0006.pgm images/img0006_new.pgm

run_img07:
	./sobel_filter images/img0007.pgm images/img0007_new.pgm

run_img08:
	./sobel_filter images/img0008.pgm images/img0008_new.pgm

run_img09:
	./sobel_filter images/img0009.pgm images/img0009_new.pgm

run_img10:
	./sobel_filter images/img0010.pgm images/img0010_new.pgm

run_img11:
	./sobel_filter images/img0011.pgm images/img0011_new.pgm

run_img12:
	./sobel_filter images/img0012.pgm images/img0012_new.pgm

run: run_img01 run_img02 run_img03 run_img04 run_img05 run_img06 run_img07 run_img08 run_img09 run_img10 run_img11 run_img12
