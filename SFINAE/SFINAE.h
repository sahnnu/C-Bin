#pragma once
class Hist;
class OPCUA;
template <typename T>
class DataSource
{

	T* serverHandle;
	public:
		DataSource(T* handle) : serverHandle(handle) {}
		T* getHandle() { return serverHandle; }
		
		typename std::enable_if_t<std::is_same<T, Hist>::value>
		void getSample()
		{

		std::cout<<"Getting sample from Hist data source"<<std::endl;
		
		}

		typename std::enable_if_t<std::is_same<T,OPCUA>::value>
		void setdata()
		{

		std::cout<<"Setting data to OPCUA data source"<<std::endl;
		
		}

};

