#include "Storage.h"

template <class T>
Storage<T>::Storage(Storage<T>* father_, int container_size) {
	father = father_;
	container.resize(container_size);
}