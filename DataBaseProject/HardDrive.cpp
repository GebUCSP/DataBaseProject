#include "HardDrive.h"
using namespace System::Windows::Forms;

HardDrive::HardDrive(int p, int t, int clusterCap, int c)
{
    platters = p;
    tracks = t;
    clusterCapacity = clusterCap;
    clusterQuantity = c;
}

void HardDrive::ShowInfo()
{
    MessageBox::Show(
        "Platters: " + platters + "\nTracks: " + tracks +
        "\nClusters: " + clusterQuantity + "\nCluster Capacity: " + clusterCapacity);
}
