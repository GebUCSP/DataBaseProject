#pragma once
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;

ref class HardDrive; // Adelanto de clase para evitar dependencia circular

public ref class QueryManager
{
private:
    HardDrive^ hd;

public:
    QueryManager(HardDrive^ hd);

    // Construye un árbol AVL directamente a partir del campo especificado del disco
    void ConstruirAVLPorCampo(String^ campo);
};
