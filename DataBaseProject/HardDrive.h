#pragma once

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;

ref class BaseClass;

public ref class Cluster {
public:
    List<Object^>^ data;
    int max_capacity, used_capacity;

    Cluster(int capacity);
};

public ref class Track {
public:
    array<Cluster^>^ clusters;

    Track(int size);
};

public ref class Surface {
public:
    array<Track^>^ tracks;

    Surface(int size);
};

public ref class Platter {
public:
    array<Surface^>^ surfaces;

    Platter(int size);
};

public ref class HardDrive {
public:
    array<Platter^>^ platters;

public:
    static HardDrive^ instance = nullptr;
    int plattersQuantity, tracksQuantity, clusterCapacity, clusterQuantity;

    HardDrive(int plattersQuantity, int tracksQuantity, int clusterCapacity, int clusterQuantity);

    void ShowInfo();
    static void Create(int plattersQuantity_, int tracksQuantity_, int clusterCapacity_, int clusterQuantity_);

    void InsertRow(array<String^>^ values, List<Tuple<String^, String^, int, int, bool, bool>^>^ fieldMetadata);

    //NUEVA DECLARACIÓN: Mostrar todo el contenido del disco
    void ShowAllData();

    // Singleton instance getter
    static property HardDrive^ Instance {
        HardDrive^ get() {
            return instance;
        }
    }
};
