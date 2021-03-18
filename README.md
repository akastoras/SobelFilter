# SobelFilterHPC

The Sobel filter or Sobel Operator is a kernel convolution algorithm used for edge detection. It is based on convolving the image with a small filter vertically and horizontally, and then combining the two outputs using Eucledian distance.
For more information on [Kernel Convolution](https://en.wikipedia.org/wiki/Kernel_(image_processing)) or [Sobel Operator](https://en.wikipedia.org/wiki/Sobel_operator)

In this project the main goal is to compare the excecution time of the Program when using OpenMP to parallelize the computation and when not.

The profiling was done using the comand on a Linux machine with a Intel(R) Core(TM) i5-8265U CPU @ 1.60GHz:
```
$ perf stat ./sobel_filter images/img0001.pgm images/img0001_new.pgm
```

## Results
The results of the comparison are shown below:

![comparison](https://user-images.githubusercontent.com/57157508/111672954-24595800-8823-11eb-9209-382be901311d.png)

## Other Optimizations
Other optimizations include:
 * Using registers to store the most used variables
 * Combining the two outputs using Manhatan distance instead of Eucledian
 * Instead of multiplying with 2, shifting by 1
 * Removing unnesessary commands, such as `a * 1`, or `a + b * 0`
