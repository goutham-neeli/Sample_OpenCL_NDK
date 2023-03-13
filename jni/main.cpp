#include <iostream>
#include <chrono>
#include <random>

#include "refNR.h"
#include "openCLNR.h"

int main() {

	int width = 1024, height = 1024, channels = 4;
	int buffer_size = width * height * channels;

	int shape[2] = {width, height};

	unsigned char* in_p = new unsigned char[buffer_size]; 
	unsigned char* out_p = new unsigned char[buffer_size];

	for (int i = 0; i < buffer_size; i++) {
		in_p[i] = rand() % 256;
	}

	auto start = std::chrono::high_resolution_clock::now();

	refNR(in_p, out_p, &shape[0]);

	auto stop = std::chrono::high_resolution_clock::now();
	auto int_us = std::chrono::duration_cast<std::chrono::microseconds>(stop - start); 
	std::chrono::duration<long, std::micro> int_usec = int_us;
	printf("Execution Time-Ref: %ld microseconds\n", int_usec.count());


	auto start_ = std::chrono::high_resolution_clock::now();

	openCLNR(in_p, out_p, &shape[0]);

	auto stop_ = std::chrono::high_resolution_clock::now();
	auto int_us_ = std::chrono::duration_cast<std::chrono::microseconds>(stop_ - start_);
	std::chrono::duration<long, std::micro> int_usec_ = int_us_;
	printf("Execution Time-OpenCL: %ld microseconds\n", int_usec_.count());

	printf("Performance : %f\n",((float)int_usec.count() / (float)int_usec_.count()));

	return 0;

}