#include "HardDrive.h"
using namespace System::Windows::Forms;

Cluster::Cluster(int capacity) {
	max_capacity = capacity;
	used_capacity = 0;
	//modificar a BaseClass
	data = gcnew array<int^>(capacity);
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

HardDrive::HardDrive(int plattersQuantity_, int tracksQuantity_, int clusterCapacity_, int clusterQuantity_)
{
	plattersQuantity = plattersQuantity_;
	tracksQuantity = tracksQuantity_;
	clusterCapacity = clusterCapacity_;
	clusterQuantity = clusterQuantity_;

	platters = gcnew array<Platter^>(plattersQuantity);
	for each (Platter ^ p in platters)
	{
		p = gcnew Platter(2);
		for each (Surface ^ s in p->surfaces)
		{
			s = gcnew Surface(tracksQuantity);
			for each (Track ^ t in s->tracks)
			{
				t = gcnew Track(clusterQuantity);
				for each (Cluster ^ c in t->clusters)
				{
					c = gcnew Cluster(clusterCapacity);
				}
			}
		}
	}
}

void HardDrive::ShowInfo()
{
    MessageBox::Show(
        "Platters: " + plattersQuantity + "\nTracks: " + tracksQuantity +
        "\nClusters: " + clusterQuantity + "\nCluster Capacity: " + clusterCapacity);
}
