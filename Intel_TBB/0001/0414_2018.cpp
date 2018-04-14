
//
//									Hello World!
//------------------------------------------------------------------------------------------------
//
//						this is a cpp source file.
//
//						Lucius@LUCIUS-PC
//											--4/14/2018 09:31:42
//
//
//			Copyright (c) 2018 LuciusKyle@outlook.com. All rights reserved.
//
//------------------------------------------------------------------------------------------------
//									Goodbye World!
//

#include<tbb\tbb.h>

#include<iostream>
//#include<boost/random.hpp>
#include<random>
#include<ctime>
#include<boost/chrono.hpp>

using std::cout;
using std::endl;

constexpr size_t array_size = 0x10000000;

std::default_random_engine random_engine(time(nullptr));
std::uniform_real_distribution<double> distro(-100.0, 100.0);

void foo(double &d)
{
	d = sqrt(d);
}

void bar(double &d)
{
	d = distro(random_engine);
}

void ParallelApplyFoo(double a[], size_t n) {
	tbb::parallel_for(size_t(0), n, [&](size_t i) {
		foo(a[i]);
	});
}

void ParallelApplyBar(double a[], size_t n) {
	tbb::parallel_for(size_t(0), n, [&](size_t i) {
		bar(a[i]);
	});
}

int main(int argc, char *argv[])
{

	auto start = boost::chrono::system_clock::now();
	start = boost::chrono::system_clock::now();
	//do something.
	cout << "time: "
		<< boost::chrono::duration_cast<boost::chrono::milliseconds>(boost::chrono::system_clock::system_clock::now() - start).count()
		<< " ms"
		<< endl;

	start = boost::chrono::system_clock::now();
	double *d_arr = new double[array_size];
	cout << "time: "
		<< boost::chrono::duration_cast<boost::chrono::milliseconds>(boost::chrono::system_clock::system_clock::now() - start).count()
		<< " ms"
		<< endl;

	start = boost::chrono::system_clock::now();
	for (size_t i = 0; i < array_size; ++i) {
		d_arr[i] = distro(random_engine);
	}
	cout << "initialize array, time: "
		<< boost::chrono::duration_cast<boost::chrono::milliseconds>(boost::chrono::system_clock::system_clock::now() - start).count()
		<< " ms"
		<< endl;

	start = boost::chrono::system_clock::now();
	ParallelApplyBar(d_arr, array_size);
	cout << "parallel initialize array, time: "
		<< boost::chrono::duration_cast<boost::chrono::milliseconds>(boost::chrono::system_clock::system_clock::now() - start).count()
		<< " ms"
		<< endl;
	start = boost::chrono::system_clock::now();
	ParallelApplyFoo(d_arr, array_size);
	cout << "parallel square root, array, time: "
		<< boost::chrono::duration_cast<boost::chrono::milliseconds>(boost::chrono::system_clock::system_clock::now() - start).count()
		<< " ms"
		<< endl;

	delete[] d_arr;
	return 0;
}
