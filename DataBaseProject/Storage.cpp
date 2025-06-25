#include "Storage.h"

Cluster::Cluster(int size, int capacity) {
	max_capacity = capacity;
	used_capacity = 0;
	data = gcnew array<BaseClass^>(size);
}

Track::Track(int size) {
	clusters = gcnew array<Cluster^>(size);
}

Surface::Surface(int size) {
	tracks = gcnew array<Track^>(size);
}

Platter::Platter(int size) {
	surfaces = gcnew array<Surface^>(size);
}

Disk::Disk(HardDrive ^ hd){
	platters = gcnew array<Platter^>(hd->getPlatters());
	for each (Platter^ p in platters)
	{
		p = gcnew Platter(2);
		for each (Surface^ s in p->surfaces)
		{
			s = gcnew Surface(hd->getTracks());
			for each (Track^ t in s->tracks)
			{
				t = gcnew Track(hd->getTracks());
				for each (Cluster ^ c in t->clusters)
				{
					c = gcnew Cluster(hd->getClusterQuantity(), hd->getClusterCapacity());
				}
			}
		}
	}
}