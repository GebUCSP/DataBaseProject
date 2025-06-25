// HardDrive.h
#pragma once

public ref class HardDrive
{
private:
    int platters;
    int tracks;
    int clusterCapacity;
    int clusterQuantity;

public:
    HardDrive(int p, int t, int clusterCap, int c)
    {
        platters = p;
        tracks = t;
        clusterCapacity = clusterCap;
        clusterQuantity = c;
    }

    void ShowInfo()
    {
        System::Windows::Forms::MessageBox::Show(
            "Platters: " + platters + "\nTracks: " + tracks +
            "\nClusters: " + clusterQuantity + "\nCluster Capacity: " + clusterCapacity);
    }
};
