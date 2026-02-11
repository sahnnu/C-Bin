// ThreadSafeLRU.cpp : Defines the entry point for the application.
//

#include "ThreadSafeLRU.h"

#include<map>
#include<list>

using namespace std;

class LRUCache
{
	using CacheList = std::list<pair<int, int>>;
	using CacheIter = CacheList::iterator;
	int m_capacity;

	CacheList m_cacheList; //list to store the key-value pairs in order of usage (most recently used at the front)
	std::map<int , CacheIter > m_cache;


public:
	LRUCache(int Capacity) : m_capacity(Capacity) {
		
	};
	LRUCache(const LRUCache&) = delete;
	LRUCache& operator=(const LRUCache&) = delete;

	[[nodiscard]]
		int get(int key)
	{
		if (m_cache.find(key) != m_cache.end())
		{
			CacheIter it = m_cache[key];
			m_cacheList.splice(m_cacheList.begin(), m_cacheList, it); //Where before to insert in the list , Source List , Iterator (because the map stores the key and list iterator)
			it->second; //return the value
		}
		else
		{
			return -1;
		}

	}
		[[noreturn]]
		void put(int key, int value)
		{
			if (m_cache.contains(key))
			{
				CacheIter it = m_cache[key];
				it->second = value; //update the value
				//m_cacheList.splice(m_cacheList.begin(), m_cacheList, it);
			}
			else {
				if (m_cacheList.size() == m_capacity)
				{
					int keytpRemove = m_cache[key]->first;
					
					m_cacheList.erase( std::prev(m_cacheList.end()));
					m_cache.erase(keytpRemove); //remove the key from the map
				}

				m_cacheList.emplace_front(std::make_pair(key, value));
				m_cache[key] = m_cacheList.begin(); //store the iterator in the map

			}
		}

		void printAll() {

			for(auto& pair : m_cacheList)
			{
				cout << "Key: " << pair.first << ", Value: " << pair.second << endl;
			}
		}
	

};
int main()
{
	LRUCache cache(100); // Cache capacity of 2
	cache.put(1, 1);
	cache.put(2, 2);
	int value =cache.get(1);       // returns 1
	cache.put(3, 3);    // evicts key 2
	cache.printAll();
	return 0;
}
