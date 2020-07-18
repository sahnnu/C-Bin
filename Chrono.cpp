#include <iostream>
#include <chrono>
#include <unistd.h>
using namespace std::chrono_literals;
using namespace std;
using namespace chrono;
// main function to measure elapsed time of a C++ program 
// using chrono library

std::chrono::duration<double, std::milli>pulse;

std::chrono::duration<double, std::milli> GetTime()
{
	return pulse;
}

void SetTime(std::chrono::duration<double, std::milli> p)
{
 pulse = p; 
}

int main()
{
time_point<steady_clock>start = chrono::steady_clock::now();

	// do some stuff here
	sleep(3);

	auto end = chrono::steady_clock::now();
duration<double,std::micro>d (end - start);
//duration<double>d (end - start); //conversion of  int type is not possible in duration,so use duration_cast //by default the unit is second because the ratio in time_point is std::ratio<1>
//auto d=duration_cast<std::chrono::nanoseconds>(end - start); //Duration_cast essential when we want the "Rep" of Duration class to be represented as  int type
cout <<"elapsed time"<<d.count()<<endl;

SetTime(1ms);
cout<<GetTime().count();

/*	cout << "Elapsed time in nanoseconds : " 
		<< chrono::duration_cast<chrono::nanoseconds>(end - start).count()
		<< " ns" << endl;

	cout << "Elapsed time in microseconds : " 
		<< chrono::duration_cast<chrono::microseconds>(end - start).count()
		<< " µs" << endl;

	cout << "Elapsed time in milliseconds : " 
		<< chrono::duration_cast<chrono::milliseconds>(end - start).count()
		<< " ms" << endl;

	cout << "Elapsed time in seconds : " 
		<< chrono::duration_cast<chrono::seconds>(end - start).count()
		<< " sec";
*/
	return 0;
}


