#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include <chrono> 


bool odd(int i)
{
	if(i%2 != 0)
	return true;
	else 
	return false;
}

int main()
{
	vector<int>v;
	v.reserve(100000);
	for(long i=0;i<100000;i++)
	{
	v.push_back(i);
	
	}

	auto start = std::chrono::high_resolution_clock::now();
	//start
	auto it = v.erase(std::remove_if(v.begin(),v.end(),odd),v.end());
	//end
	auto finish = std::chrono::high_resolution_clock::now();
	
	std::chrono::duration<double> elapsed = finish - start;
//	std::chrono::duration elapsed = finish - start;
	cout<<"Time elaspsed "<<elapsed.count()<<endl;
	
	
}



