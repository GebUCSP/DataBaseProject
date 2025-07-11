#include "HardDrive.h"
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;

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
        tail = tail->next;
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

HardDrive::HardDrive(int plattersQuantity_, int tracksQuantity_, int clusterQuantity_, int sectorsQuantity_, int sectorCapacity_)
{
    plattersQuantity = plattersQuantity_;
    tracksQuantity = tracksQuantity_;
    clusterQuantity = clusterQuantity_;
    sectorsQuantity = sectorsQuantity_;
    sectorCapacity = sectorCapacity_;
    clusterCapacity = (plattersQuantity * 2 * tracksQuantity * sectorsQuantity * sectorCapacity) / clusterQuantity;


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
        "\nClusters: " + clusterQuantity + "\nCluster Capacity: " + clusterCapacity +
        "\nSectors: " + sectorsQuantity + "\nSector Capacity: " + sectorCapacity);
}

void HardDrive::Create(int plattersQuantity_, int tracksQuantity_, int clusterQuantity_, int sectorsQuantity_, int sectorCapacity_)
{
    if (instance == nullptr) instance = gcnew HardDrive(plattersQuantity_, tracksQuantity_, clusterQuantity_, sectorsQuantity_, sectorCapacity_);
}

void HardDrive::InsertRow(array<String^>^ values)
{
    ValueNode^ head = gcnew ValueNode(headers[0]->Item1, headers[0]->Item2, values[0], headers[0]->Item3);
    lastInsertedHead = head;
    ValueNode^ prev = head;
    for (int i = 1; i < values->Length; ++i) {
        ValueNode^ current = gcnew ValueNode(headers[i]->Item1, headers[i]->Item2, values[i], headers[i]->Item3);
        prev->nextValueNode = current;
        current->previousValueNode = prev;
        prev = current;
    }

    List < Tuple < List<ValueNode^>^, Cluster^, int, int, int, int >^ >^ simulacion = gcnew List<Tuple<List<ValueNode^>^, Cluster^, int, int, int, int>^>();
    ValueNode^ current = head;

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
                        group->Sort(gcnew ValueNodeComparerDesc());
                        simulacion->Add(gcnew Tuple<List<ValueNode^>^, Cluster^, int, int, int, int>(group, cluster, p, s, t, cl));
                        current = iterator;
                    }
                }
            }
        }
    }

    if (current != nullptr) {
        MessageBox::Show("No hay espacio suficiente para insertar una fila ");
        return;
    }

    for each (Tuple<List<ValueNode^>^, Cluster^, int, int, int, int> ^ t in simulacion) {
        List<ValueNode^>^ group = t->Item1;
        Cluster^ cluster = t->Item2;

        for each (ValueNode ^ n in group) {
            int sectorsPerCluster = sectorsQuantity / clusterQuantity;
            int clusterStartSector = sectorsPerCluster * t->Item6;
            int sectorOffsetWithinCluster = cluster->used_capacity / sectorCapacity;
            int initialSector = clusterStartSector + sectorOffsetWithinCluster;
            int sectorsNeeded = (n->size + sectorCapacity - 1) / sectorCapacity;
            int finalSector = initialSector + sectorsNeeded - 1;


            n->ubicacion = gcnew Tuple<int, int, int, int, Tuple<int, int>^>(t->Item3, t->Item4, t->Item5, t->Item6, gcnew Tuple<int, int>(initialSector, finalSector));
            cluster->InsertValueNode(n);
            usedCapacityClusters[t->Item6] += n->size;
        }
    }
}

List<ValueNode^>^ HardDrive::getListByField(String^ field) {
    List<ValueNode^>^ returnList = gcnew List<ValueNode^>();

    for (int p = 0; p < platters->Length; ++p) {
        for (int s = 0; s < platters[p]->surfaces->Length; ++s) {
            for (int t = 0; t < platters[p]->surfaces[s]->tracks->Length; ++t) {
                for (int c = 0; c < platters[p]->surfaces[s]->tracks[t]->clusters->Length; ++c) {
                    Cluster^ cluster = platters[p]->surfaces[s]->tracks[t]->clusters[c];
                    ValueNode^ current = cluster->head;
                    while (current) {
                        if (current->field == field) {
                            returnList->Add(current);
                        }
                        current = current->next;
                    }
                }
            }
        }
    }
    return returnList;
}

List<String^>^ HardDrive::getRowByNode(ValueNode^ node) {
    List<String^>^ output = gcnew List<String^>();
    ValueNode^ currentNode = node;
    while (currentNode->previousValueNode) {
        currentNode = currentNode->previousValueNode;
    }
    while (currentNode) {
        output->Add(currentNode->value + String::Format("\nLocation: (P:{0}, S:{1}, T:{2}, C:{3}, S:({4},{5}))",
            currentNode->ubicacion->Item1,
            currentNode->ubicacion->Item2,
            currentNode->ubicacion->Item3,
            currentNode->ubicacion->Item4,
            currentNode->ubicacion->Item5->Item1,
            currentNode->ubicacion->Item5->Item2
        ));
        currentNode = currentNode->nextValueNode;
    }
    return output;
}

void HardDrive::getRowByListNodes(List<ValueNode^>^ lista) {
    List<List<String^>^>^ output = gcnew List<List<String^>^>();
    for each (ValueNode ^ n in lista) {
        output->Add(getRowByNode(n));
    }

    if (output->Count == 0) {
        MessageBox::Show("No hay coincidencias.");
        return;
    }

    // Crear la ventana y tabla
    Form^ form = gcnew Form();
    form->Text = "Tabla de Registros del Disco";
    form->Size = System::Drawing::Size(1000, 400);
    form->StartPosition = FormStartPosition::CenterScreen;

    DataGridView^ dgv = gcnew DataGridView();
    dgv->Dock = System::Windows::Forms::DockStyle::Fill;
    dgv->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
    dgv->AllowUserToAddRows = false;
    dgv->ReadOnly = true;
    dgv->ScrollBars = ScrollBars::Both;
    dgv->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
    dgv->DefaultCellStyle->WrapMode = DataGridViewTriState::True;
    dgv->AutoSizeRowsMode = DataGridViewAutoSizeRowsMode::AllCells;

    // Agregar columnas de headers
    for (int i = 0; i < headers->Length; ++i) {
        dgv->Columns->Add("col" + i.ToString(), headers[i]->Item1);
    }

    // Agregar filas
    for each(List<String^> ^ rowList in output) {
        array<String^>^ row = gcnew array<String^>(headers->Length + 1);

        for (int i = 0; i < rowList->Count && i < headers->Length; ++i) {
            row[i] = rowList[i];
        }

        dgv->Rows->Add(row);
    }


    form->Controls->Add(dgv);
    form->Show();
}

ValueNode^ HardDrive::getNodeByField(ValueNode^ node, String^ field){
    ValueNode^ currentNode = node;
    while (currentNode->previousValueNode) {
        currentNode = currentNode->previousValueNode;
    }

    while (currentNode) {
        if (currentNode->field == field) return currentNode;
        currentNode = currentNode->nextValueNode;
    }
    return currentNode;
}

void HardDrive::ShowAllData() {
    String^ output = "";

    for (int p = 0; p < platters->Length; ++p) {
        for (int s = 0; s < platters[p]->surfaces->Length; ++s) {
            for (int t = 0; t < platters[p]->surfaces[s]->tracks->Length; ++t) {
                for (int c = 0; c < platters[p]->surfaces[s]->tracks[t]->clusters->Length; ++c) {
                    Cluster^ cluster = platters[p]->surfaces[s]->tracks[t]->clusters[c];

                    if (cluster->head) {
                        output += "--- P" + p + " S" + s + " T" + t + " C" + c + " ---\n";
                        ValueNode^ current = cluster->head;
                        while (current) {
                            output += current->field + ": " + current->value + " | ";
                            current = current->next;
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

void HardDrive::ShowDataAsTable() {
    List<List<String^>^>^ allRows = gcnew List<List<String^>^>();

    for (int p = 0; p < platters->Length; ++p) {
        for (int s = 0; s < platters[p]->surfaces->Length; ++s) {
            for (int t = 0; t < platters[p]->surfaces[s]->tracks->Length; ++t) {
                for (int c = 0; c < platters[p]->surfaces[s]->tracks[t]->clusters->Length; ++c) {
                    Cluster^ cluster = platters[p]->surfaces[s]->tracks[t]->clusters[c];
                    ValueNode^ current = cluster->head;

                    while (current) {
                        if (current->previousValueNode == nullptr) {
                            List<String^>^ row = gcnew List<String^>();
                            ValueNode^ rowCurrent = current;
                            while (rowCurrent) {
                                row->Add(rowCurrent->value);
                                rowCurrent = rowCurrent->nextValueNode;
                            }
                            allRows->Add(row);
                        }
                        current = current->next;
                    }
                }
            }
        }
    }

    if (allRows->Count == 0) {
        MessageBox::Show("No hay datos almacenados.", "Tabla del Disco");
        return;
    }

    // Crear la ventana y tabla
    Form^ form = gcnew Form();
    form->Text = "Tabla de Registros del Disco";
    form->Size = System::Drawing::Size(1000, 400);
    form->StartPosition = FormStartPosition::CenterScreen;

    DataGridView^ dgv = gcnew DataGridView();
    dgv->Dock = System::Windows::Forms::DockStyle::Fill;
    dgv->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
    dgv->AllowUserToAddRows = false;
    dgv->ReadOnly = true;
    dgv->ScrollBars = ScrollBars::Both;
    dgv->SelectionMode = DataGridViewSelectionMode::FullRowSelect;

    // Agregar columnas de headers
    for (int i = 0; i < headers->Length; ++i) {
        dgv->Columns->Add("col" + i.ToString(), headers[i]->Item1);
    }

    // Agregar filas
    for each (List<String^> ^ rowList in allRows) {
        // Crear nuevo array con espacio para la columna "Ubicación" + datos
        array<String^>^ row = gcnew array<String^>(headers->Length + 1);

        // Asignar la ubicación (opcional: puedes omitir esto si no tienes ese dato)
        row[0] = "Ubicación no disponible"; // o puedes quitar esta columna si no la necesitas

        for (int i = 0; i < rowList->Count && i < headers->Length; ++i) {
            row[i] = rowList[i];
        }

        dgv->Rows->Add(row);
    }


    form->Controls->Add(dgv);
    form->Show();
}




void HardDrive::setHeaders(List<Tuple<String^, String^, int, int, bool, bool>^>^ container)
{
    headers = gcnew array<Tuple<String^, String^, int>^>(container->Count);
    for (int i = 0; i < container->Count; i++) {
        headers[i] = gcnew Tuple<String^, String^, int>(container[i]->Item1, container[i]->Item2, container[i]->Item3);
    }
}

ValueNode^ HardDrive::GetLastInsertedRow() {
    return lastInsertedHead;
}