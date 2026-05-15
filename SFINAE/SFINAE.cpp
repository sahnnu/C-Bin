#pragma once



#include<type_traits>
#include<iostream>
using namespace std;
class Hist {};

class OPCUA {};
template <typename T>
class DataSource
{

	T* serverHandle;
public:
	DataSource(T* handle) : serverHandle(handle) {}
	T* getHandle() { return serverHandle; }

	template <typename U = T ,typename std::enable_if_t<std::is_same_v<U, Hist>,bool> = true >
		void getSample() const
	{

		std::cout << "Getting sample from Hist data source" << std::endl;

	}
		template <typename U = T, typename std::enable_if_t<std::is_same_v<U, OPCUA>, bool> = true >
		void getSample(int a = 10)
		{

			std::cout << "Getting sample from generic data source" << std::endl;

		}

	
	template < typename U = T ,typename std::enable_if_t<std::is_same_v<U, OPCUA>,bool> = true >
		void setdata()
	{

		std::cout << "Setting data to OPCUA data source" << std::endl;

	}

};

int main()
{
	Hist hist;
	OPCUA opcua;
	DataSource<Hist > histDataSource(&hist);
	histDataSource.getSample();

	
	DataSource<OPCUA> opcuaDataSource(&opcua);
	opcuaDataSource.setdata();

	return 0;
}

