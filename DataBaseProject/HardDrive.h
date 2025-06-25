#pragma once

using namespace System;

public ref class HardDrive
{
private:
    int platters;
    int tracks;
    int clusterCapacity;
    int clusterQuantity;

public:
    HardDrive(int p, int t, int clusterCap, int c);
    int getPlatters();
    int getTracks();
    int getClusterCapacity();
    int getClusterQuantity();


    void ShowInfo();
};
