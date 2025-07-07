#include "HardDrive.h"
using namespace System::Windows::Forms;

ValueNode::ValueNode(String^ field_, String^ type_, String^ value_, int size_) {
    field = field_;
    type = type_;
    value = value_;
    size = size_;
    next = nullptr;
    previousValueNode = nullptr;
    nextValueNode = nullptr;
    ubicacion = nullptr;
}

void Cluster::InsertValueNode(ValueNode^ node) {
    if (!tail) {
        head = node;
        tail = head;
    }
    else {
        tail->next = node;
    }
    used_capacity += node->size;
 
}

Cluster::Cluster(int capacity) {
	max_capacity = capacity;
	used_capacity = 0;
    head = nullptr;
    tail = nullptr;
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

    usedCapacityClusters = gcnew array<int>(clusterQuantity_);

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
	if (instance == nullptr) instance = gcnew HardDrive(plattersQuantity_, tracksQuantity_, clusterCapacity_, clusterQuantity_);
}

void HardDrive::InsertRow(array<String^>^ values)
{
    ValueNode^ head = gcnew ValueNode(headers[0]->Item1, headers[0]->Item2, values[0], headers[0]->Item3);
    ValueNode^ prev = head;
    for (int i = 1; i < values->Length; ++i) {
        ValueNode^ current = gcnew ValueNode(headers[i]->Item1, headers[i]->Item2,values[i], headers[i]->Item3);
        prev->nextValueNode = current;
        current->previousValueNode = prev;
        prev = current;
    }

    List < Tuple < List<ValueNode^>^, Cluster^, int, int, int, int > ^ > ^ simulacion = gcnew List<Tuple<List<ValueNode^>^, Cluster^, int, int, int, int>^>();
    ValueNode^ current = head;
    bool exito = false;

    for (int p = 0; p < plattersQuantity && current; ++p) {
        for (int s = 0; s < platters[p]->surfaces->Length && current; ++s) {
            for (int t = 0; t < platters[p]->surfaces[s]->tracks->Length && current; ++t) {
                for (int cl = 0; cl < platters[p]->surfaces[s]->tracks[t]->clusters->Length && current; ++cl) {

                    Cluster^ cluster = platters[p]->surfaces[s]->tracks[t]->clusters[cl];
                    int capacityAvailable = clusterCapacity - cluster->used_capacity;

                    List<ValueNode^>^ group = gcnew List<ValueNode^>();
                    ValueNode^ iterator = current;
                    int sizeSum = 0;

                    while (iterator && sizeSum + iterator->size <= capacityAvailable) {
                        group->Add(iterator);
                        sizeSum += iterator->size;
                        iterator = iterator->nextValueNode;
                    }
                    if (group->Count > 0) {
                        simulacion->Add(gcnew Tuple<List<ValueNode^>^, Cluster^, int, int, int, int>(group, cluster, p,s,t,cl));
                        current = iterator;
                    }
                }
            }
        }
    }

    if (current != nullptr) {
        MessageBox::Show("No hay espacio suficiente para insertar la fila.");
        return;
    }

    for each (Tuple<List<ValueNode^>^, Cluster^, int, int,int,int> ^ t in simulacion) {
        List<ValueNode^>^ group = t->Item1;
        Cluster^ cluster = t->Item2;

        for each (ValueNode ^ n in group) {
            n->ubicacion = gcnew Tuple<int, int, int, int>(t->Item3, t->Item4, t->Item5, t->Item6);
            cluster->InsertValueNode(n);
            usedCapacityClusters[t->Item6] += n->size;
        }      
    }

    MessageBox::Show("Fila insertada con éxito.");
}

void HardDrive::setHeaders(List<Tuple<String^, String^, int, int, bool, bool>^>^ container)
{
    headers = gcnew array<Tuple<String^, String^, int>^>(container->Count);
    for (int i = 0; i < container->Count; i++) {
        headers[i] = gcnew Tuple<String^, String^, int>(container[i]->Item1, container[i]->Item2, container[i]->Item3);
    }
}
