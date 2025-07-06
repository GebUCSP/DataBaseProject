#include "HardDrive.h"
using namespace System::Windows::Forms;

Cluster::Cluster(int capacity) {
	max_capacity = capacity;
	used_capacity = 0;

	data = gcnew List<Object^>(capacity);
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
	capacity = plattersQuantity * 2 * tracksQuantity * clusterQuantity * clusterCapacity ;

	platters = gcnew array<Platter^>(plattersQuantity);
    for (int i = 0; i < plattersQuantity; ++i)
    {
        platters[i] = gcnew Platter(2);
        for (int j = 0; j < platters[i]->surfaces->Length; ++j)
        {
            platters[i]->surfaces[j] = gcnew Surface(tracksQuantity);
            for (int k = 0; k < platters[i]->surfaces[j]->tracks->Length; ++k)
            {
                platters[i]->surfaces[j]->tracks[k] = gcnew Track(clusterQuantity);
                for (int l = 0; l < platters[i]->surfaces[j]->tracks[k]->clusters->Length; ++l)
                {
                    platters[i]->surfaces[j]->tracks[k]->clusters[l] = gcnew Cluster(clusterCapacity);
                }
            }
        }
    }

}

void HardDrive::Create(int plattersQuantity_, int tracksQuantity_, int clusterCapacity_, int clusterQuantity_)
{
    if (instance == nullptr) instance = gcnew HardDrive(plattersQuantity_, tracksQuantity_, clusterCapacity_, clusterQuantity_);
}

HardDrive^ HardDrive::Instance::get() {
    return instance;
}

void HardDrive::ShowInfo()
{
    MessageBox::Show(
        "Platters: " + plattersQuantity + "\nTracks: " + tracksQuantity +
        "\nClusters: " + clusterQuantity + "\nCluster Capacity: " + clusterCapacity);
}

void HardDrive::InsertRow(array<String^>^ row, List<Tuple<String^, String^, int, int, bool, bool>^>^ fields)
{
    throw gcnew System::NotImplementedException();
}
