// HardDrive.h
#pragma once

public ref class HardDrive
{
private:
    int platters;
    int tracks;
    int sectors;
    int clusters;

public:
    HardDrive(int p, int t, int s, int c)
    {
        platters = p;
        tracks = t;
        sectors = s;
        clusters = c;
    }

    void ShowInfo()
    {
        System::Windows::Forms::MessageBox::Show(
            "Platters: " + platters + "\nTracks: " + tracks +
            "\nSectors: " + sectors + "\nClusters: " + clusters);
    }
};
