#include "ReadManager.h"
#include "FieldValidator.h"

#include <fstream>

using namespace System;
using namespace System::IO;
using namespace System::Windows::Forms;

void ReadManager::ReadCSV() {
    //Leer archivo CSV con los datos de la tabla
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

void ReadManager::ReadStructTable() {
    //Leer archivo txt con la estructura de la tabla
    if (LastImportedStructPath == nullptr || LastImportedStructPath->Length == 0) {
        MessageBox::Show("No se selecciono un archivo válido");
        return;
    }
    try {
        array<String^>^ lines = File::ReadAllLines(LastImportedStructPath);
        if (lines->Length == 0) {
            MessageBox::Show("El archivo .txt está vacío.");
            return;
        }

        for each (String ^ line in lines) {
            line = line->Trim();

            if (line->StartsWith("CREATE TABLE") || line == ");")
                continue;
        }
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error al leer el archivo de estructura; " + ex->Message);
    }
}

bool ReadManager::ValidateValue(String^ value, Tuple<String^, String^, int, int, bool, bool>^ field) {
    String^ type = field->Item2;
    int size = field->Item3;
    int scale = field->Item4;
    if (type == "INTEGER")
        return FieldValidator::ValidateInteger(value, size);
    else if (type == "DECIMAL")
        return FieldValidator::ValidateDecimal(value, size, scale);
    else if (type == "VARCHAR")
        return FieldValidator::ValidateVarchar(value, size);
    else if (type == "CHAR")
        return FieldValidator::ValidateChar(value, size);
    else if (type == "BOOLEAN")
        return FieldValidator::ValidateBoolean(value);

    return 0;
}

