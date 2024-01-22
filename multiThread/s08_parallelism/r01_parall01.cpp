// Packaged task example
// Executes the task in a new thread
#include <iostream>
#include <future>
#include <chrono>
#include <numeric>
#include <vector>
#include <random>
#include <future>
#include<algorithm>
#include <execution>

// namespace se=std::execution;
// std::vector<int> a{9,8,5,7,6,2,1,4,22,33};


// using namespace std::literals;

// static std::mt19937 mt;
// std::uniform_real_distribution<double> dist(0, 100);

// inline double accum(double *beg, double *end) { return std::accumulate(beg, end, 0.0); }

// double add_parallel(std::vector<double> &vec)
// {
// 	auto v0 = &vec[0];

// 	auto vsize = vec.size();

// 	auto f1 = std::async(std::launch::async, accum, v0, v0 + vsize / 4);
// 	auto f2 = std::async(std::launch::async, accum, v0 + vsize / 4, v0 + 2 * vsize / 4);
// 	auto f3 = std::async(std::launch::async, accum, v0 + 2 * vsize / 4, v0 + 3 * vsize / 4);
// 	auto f4 = std::async(std::launch::async, accum, v0 + 3 * vsize / 4, v0 + vsize);

// 	return f1.get() + f2.get() + f3.get() + f4.get();
// }
// double add_parallelPT(std::vector<double> &vec)
// {
// 	auto v0 = &vec[0];

// 	auto vsize = vec.size();

// 	auto f1 = std::async(std::launch::async, accum, v0, v0 + vsize / 4);
// 	auto f2 = std::async(std::launch::async, accum, v0 + vsize / 4, v0 + 2 * vsize / 4);
// 	auto f3 = std::async(std::launch::async, accum, v0 + 2 * vsize / 4, v0 + 3 * vsize / 4);
// 	auto f4 = std::async(std::launch::async, accum, v0 + 3 * vsize / 4, v0 + vsize);

// 	return f1.get() + f2.get() + f3.get() + f4.get();
// }
int main()
{
	
	std::vector<int> a{9,8,5,7,6,2,1,4,22,33};	
	for(auto b:a)
	std::cout<<b<<' ';
	std::cout<<std::endl;
	std::sort(std::execution::par_unseq,a.begin(), a.end(), [](int a, int b)->bool{return a<b;});
	for(auto b:a)
	std::cout<<b<<' ';
	std::cout<<std::endl;
	std::sort(a.begin(), a.end(), [](int a, int b)->bool{return a>b;});
	for(auto b:a)
	std::cout<<b<<' ';
	std::cout<<std::endl;
	
	return 1;
	// std::vector<double> vec(16);
	// std::iota(vec.begin(), vec.end(), 1.0);
	// std::vector<double> vr(10000);
	// std::generate(vr.begin(), vr.end(), [&vr](){return dist(mt);});


	// std::cout<< "Sum of first 16 int: " << add_parallel(vec) << '\n';
	// std::cout<< "Sum of 10 000 randoms: " << add_parallel(vr) << '\n';

	// return 0;
}