#pragma once
#include "HardDrive.h"

ref class BaseClass;


public ref class Clusters {
private:
	array<BaseClass^>^ data;
};

public ref class Track {
private:
	array<Clusters^>^ data;
};

public ref class Surface {
private:
	array<Track^>^ data;
};

public ref class Platter {
private:
	array<Surface^>^ data;
};

public ref class Disk {
private:
	array<Platter^>^ data;
public:
	Disk(HardDrive^ hd);
};