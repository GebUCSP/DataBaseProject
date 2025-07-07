#include "HardDrive.h"
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;

Cluster::Cluster(int capacity) {
    max_capacity = capacity;
    used_capacity = 0;
    data = gcnew List<Object^>();
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

void HardDrive::ShowInfo()
{
    MessageBox::Show(
        "Platters: " + plattersQuantity + "\nTracks: " + tracksQuantity +
        "\nClusters: " + clusterQuantity + "\nCluster Capacity: " + clusterCapacity);
}

void HardDrive::Create(int plattersQuantity_, int tracksQuantity_, int clusterCapacity_, int clusterQuantity_)
{
    if (instance == nullptr)
        instance = gcnew HardDrive(plattersQuantity_, tracksQuantity_, clusterCapacity_, clusterQuantity_);
}

// Insertar fila validada desde ReadManager al disco
void HardDrive::InsertRow(array<String^>^ values, List<Tuple<String^, String^, int, int, bool, bool>^>^ fieldMetadata)
{
    for (int p = 0; p < platters->Length; ++p)
    {
        for (int s = 0; s < platters[p]->surfaces->Length; ++s)
        {
            for (int t = 0; t < platters[p]->surfaces[s]->tracks->Length; ++t)
            {
                for (int c = 0; c < platters[p]->surfaces[s]->tracks[t]->clusters->Length; ++c)
                {
                    Cluster^ cluster = platters[p]->surfaces[s]->tracks[t]->clusters[c];

                    if (cluster->used_capacity < cluster->max_capacity)
                    {
                        Dictionary<String^, String^>^ row = gcnew Dictionary<String^, String^>();

                        for (int i = 0; i < values->Length; ++i)
                        {
                            String^ fieldName = fieldMetadata[i]->Item1;
                            String^ value = values[i];
                            row[fieldName] = value;
                        }

                        cluster->data->Add(row);
                        cluster->used_capacity++;
                        return;
                    }
                }
            }
        }
    }

    MessageBox::Show("Disco lleno. No hay espacio disponible para insertar más datos.");
}

// NUEVA FUNCIÓN: Mostrar todo lo almacenado en el disco
void HardDrive::ShowAllData()
{
    String^ output = "";

    for (int p = 0; p < platters->Length; ++p)
    {
        for (int s = 0; s < platters[p]->surfaces->Length; ++s)
        {
            for (int t = 0; t < platters[p]->surfaces[s]->tracks->Length; ++t)
            {
                for (int c = 0; c < platters[p]->surfaces[s]->tracks[t]->clusters->Length; ++c)
                {
                    Cluster^ cluster = platters[p]->surfaces[s]->tracks[t]->clusters[c];

                    if (cluster->data->Count > 0)
                    {
                        output += "--- P" + p + " S" + s + " T" + t + " C" + c + " ---\n";

                        for each (Dictionary<String^, String^> ^ row in cluster->data)
                        {
                            for each (String ^ key in row->Keys)
                            {
                                output += key + ": " + row[key] + " | ";
                            }
                            output += "\n";
                        }

                        output += "\n";
                    }
                }
            }
        }
    }

    if (output->Length == 0)
        output = "No hay datos almacenados en el disco.";

    MessageBox::Show(output, "Datos en el Disco");
}
