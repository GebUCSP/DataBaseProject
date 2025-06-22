#include "ReadManager.h"
#include <fstream>

using namespace System;
using namespace System::IO;
using namespace System::Windows::Forms;

void ReadManager::ReadCSV() {
    if (LastImportedFilePath == nullptr || LastImportedFilePath->Length == 0) {
        MessageBox::Show("No hay archivo CSV importado.");
        return;
    }

    try {
        array<String^>^ lines = File::ReadAllLines(LastImportedFilePath);

        if (lines->Length == 0) {
            MessageBox::Show("El archivo está vacío.");
            return;
        }

        for each (String ^ line in lines) {
            array<String^>^ values = line->Split(',');

            for each (String ^ val in values) {
                Console::Write(val + "\t");
            }
            Console::WriteLine("");
        }

        MessageBox::Show("Lectura del archivo CSV completada correctamente.");
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error al leer el archivo: " + ex->Message);
    }
}
