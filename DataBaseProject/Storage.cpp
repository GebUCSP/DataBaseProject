#include "Storage.h"

Disk::Disk(HardDrive ^ hd){
	data = gcnew array<Platter^>(hd->getPlatters());
}