#pragma once
#include <algorithm>

using namespace System;
using namespace System::Collections::Generic;

public ref class ValueNode {
public:
	String^ field;
	String^ value;
	int size;
	String^ type;
	ValueNode^ next;
	ValueNode^ nextValueNode;
	ValueNode^ previousValueNode;
	Tuple<int, int, int, int>^ ubicacion;
	ValueNode(String^ field_, String^ type_, String^ value_, int size_);
};


public ref class Cluster {
public:
	ValueNode^ head;
	ValueNode^ tail;
	int max_capacity, used_capacity;
	Cluster(int capacity);
	void InsertValueNode(ValueNode^ node);
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

	HardDrive(int plattersQuantity, int tracksQuantity, int clusterCapacity, int clusterQuantity);
public:
	static HardDrive^ instance = nullptr;
	array<int>^ usedCapacityClusters;
	array<Tuple<String^, String^, int>^>^ headers = nullptr;

	int plattersQuantity, tracksQuantity, clusterCapacity, clusterQuantity;

	static void Create(int plattersQuantity_, int tracksQuantity_, int clusterCapacity_, int clusterQuantity_);
	void InsertRow(array<String^>^ values);

	void setHeaders(List<Tuple<String^, String^, int, int, bool, bool>^>^ container);

    void ShowInfo();

	static property HardDrive^ Instance {
		HardDrive^ get() {
			return instance;
		}
	}
};
