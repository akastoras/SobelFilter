# SobelFilterHPC

The Sobel filter or Sobel Operator is a kernel convolution algorithm used for edge detection. It is based on convolving the image with a small filter vertically and horizontally, and then combining the two outputs using Eucledian distance.

In this project the main goal is to compare the excecution time of the Program when using OpenMP to parallelize the computation and when not.

The profiling was done using the comand:
```
$ perf stat ./sobel_filter images/img0001.pgm images/img0001_new.pgm
```

## Results
The results of the comparison are shown below:

![comparison](https://user-images.githubusercontent.com/57157508/111367493-783a3480-869d-11eb-9a47-1959bd08f246.png)

## Other Optimizations
Other optimizations include:
 * Using registers to store the most used variables
 * Combining the two outputs using Manhatan distance instead of Eucledian
