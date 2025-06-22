#pragma once
#include <vector>

using namespace std;

template <class T>
class Storage
{
public:
	Storage(Storage<T>* father_ = nullptr, int container_size);
private:
	Storage<T>* father;
	vector<T*> container;
};

