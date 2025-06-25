#pragma once

using namespace System;

ref class BaseClass;

public ref class Cluster {
public:
	//modificar a BaseClass
	array<int^>^ data;
	int max_capacity, used_capacity;
	Cluster(int capacity);
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

public ref class HardDrive
{
private:
	array<Platter^>^ platters;

public:
    HardDrive(int plattersQuantity, int tracksQuantity, int clusterCapacity, int clusterQuantity);
	int plattersQuantity, tracksQuantity, clusterCapacity, clusterQuantity;
    void ShowInfo();
};
