#pragma once
#include "HardDrive.h"

ref class BaseClass;


public ref class Cluster {
public:
	array<BaseClass^>^ data;
	int max_capacity, used_capacity;
	Cluster(int size, int capacity);
};

public ref class Track {
public:
	array<Cluster^>^ clusters;
	Track(int size);
};

public ref class Surface {
public:
	array<Track^>^ tracks;
	Surface(int size);
};

public ref class Platter {
public:
	array<Surface^>^ surfaces;
	Platter(int size);
};

public ref class Disk {
private:
	array<Platter^>^ platters;
public:
	Disk(HardDrive^ hd);
};