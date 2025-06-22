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
    HardDrive(int p, int t, int s, int c);

    void ShowInfo();
};
