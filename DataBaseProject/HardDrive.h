#pragma once

using namespace System;
using namespace System::Collections::Generic;

public ref class Cluster {
public:
	List<Object^>^ data;
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
	HardDrive(int plattersQuantity_, int tracksQuantity_, int clusterCapacity_, int clusterQuantity_);
public:
	static property HardDrive^ Instance {
		HardDrive^ get();
	}
	static HardDrive^ instance = nullptr;
	static void Create(int plattersQuantity_, int tracksQuantity_, int clusterCapacity_, int clusterQuantity_);
	int plattersQuantity;
	int tracksQuantity;
	int clusterCapacity;
	int clusterQuantity;
	int capacity;
    void ShowInfo();
	void InsertRow(array<String^>^ row, List<Tuple<String^, String^, int, int, bool, bool>^>^ fields);
};
