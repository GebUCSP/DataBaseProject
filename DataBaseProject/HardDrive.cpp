#include "HardDrive.h"

HardDrive::HardDrive(int p, int t, int s, int c) {
    platters = p;
    tracks = t;
    sectors = s;
    clusters = c;
}

void HardDrive::ShowInfo(){
    System::Windows::Forms::MessageBox::Show(
        "Platters: " + platters + "\nTracks: " + tracks +
        "\nSectors: " + sectors + "\nClusters: " + clusters);
}