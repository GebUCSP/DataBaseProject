#include "ReadManager.h"
#include "FieldValidator.h"
#include "HardDrive.h"


#include <fstream>

using namespace System;
using namespace System::IO;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;

array<String^>^ SplitCSVLine(String^ line) {
    List<String^>^ values = gcnew List<String^>();
    String^ currentField = "";
    bool inQuotes = 0;

    for each (Char c in line) {
        if (c == '"') inQuotes = !inQuotes;
        else if (c == ',' && !inQuotes) {
            values->Add(currentField->Trim());
            currentField = "";
        }
        else currentField += c;
    }
    
    values->Add(currentField->Trim());

    for (int i = 0; i < values->Count; i++) {
        String^ value = values[i];
        if (value->StartsWith("\"") && value->EndsWith("\""))
            values[i] = value->Substring(1, value->Length - 2);
    }
    return values->ToArray();
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
        fields->Clear();

        for each (String ^ line in lines) {
            line = line->Trim();

            if (line->StartsWith("CREATE TABLE") || line == ");")
                continue;
            if (line->EndsWith(",")) line = line->Substring(0, line->Length - 1);

            array<String^>^ values = line->Split(' ');

            if (values->Length < 2) {
                MessageBox::Show("Error de sintaxis");
                continue;
            }
            String^ name = values[0];
            String^ typeTemp = values[1];
            String^ type;
            int size = 0, scale = 0;

            int i1 = typeTemp->IndexOf('(');
            int i2 = typeTemp->IndexOf(')');

            if (i1 > -1 && i2 > i1) {
                type = typeTemp->Substring(0, i1)->ToUpper();
                String^ Cadsizes = typeTemp->Substring(i1 + 1, i2 - i1 - 1);
                array<String^>^ sizes = Cadsizes->Split(',');
                   
                size = Int32::Parse(sizes[0]);
                if (sizes->Length == 2) {
                    scale = Int32::Parse(sizes[1]);
                }

            }
            else {
                type = typeTemp->ToUpper();
                if (type == "INTEGER") size = 10;
                else if (type != "BOOLEAN") {
                    MessageBox::Show("Se requiere un tamaño específico.");
                    continue;
                }
            }
            String^ constraint = String::Join(" ", values, 2, values->Length - 2)->ToUpper();
            bool isPrimaryKey = constraint->Contains("PRIMARY KEY");
            bool isNotNull = constraint->Contains("NOT NULL");
            
            fields->Add(gcnew Tuple<String^, String^, int, int, bool, bool > (
                name, type, size, scale, isPrimaryKey, isNotNull
            ));
        }
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error al leer el archivo de estructura; " + ex->Message);
    }
}

void ReadManager::ReadCSV() {
    //Leer archivo CSV con los datos de la tabla
    if (LastImportedFilePath == nullptr || LastImportedFilePath->Length == 0) {
        MessageBox::Show("No hay archivo CSV importado.");
        return;
    }

    try {
        array<String^>^ lines = File::ReadAllLines(LastImportedFilePath);

        if (lines->Length < 2) {
            MessageBox::Show("El archivo debe tener encabezado y al menos una fila de datos.");
            return;
        }

        array<String^>^ headers = SplitCSVLine(lines[0]);

        List<Tuple<String^, String^, int, int, bool, bool>^>^ FieldsOrdered = gcnew List<Tuple< String^, String^, int, int, bool, bool>^>();
        
        for each (String ^ header in headers) {
            bool found = 0;
            for each (auto field in fields) {
                if (field->Item1 == header) {
                    FieldsOrdered->Add(field);
                    found = true;
                    break;
                }
            }
            if (!found) {
                MessageBox::Show("Columna no reconocida: " + header);
                return;
            }
        }

        for (int i = 1; i < lines->Length; i++) {
            array<String^>^ values = SplitCSVLine(lines[i]);

            if (values->Length != FieldsOrdered->Count) {
                MessageBox::Show("Fila inválida, cantidad incorrecta de columnas");
                return;
            }

            bool isValidRow = 1;
            //List<BaseData^>^ row = gcnew List<BaseData^>();
            for (int j = 0; j < values->Length; j++) {
                String^ value = values[j];
                auto field = FieldsOrdered[j];

                if (!ValidateValue(value, field)) {
                    isValidRow = 0;
                    MessageBox::Show("Valor inválido");
                    break;
                }
                //BaseData^ value = CreateValue(value, field->Item2, field->Item3, field->Item4);
                //row->Add();
                //Ya no iria -> if (isValidRow) HardDrive::InsertRow(values);
            }
        }
        MessageBox::Show("Lectura y validacion del archivo CSV completadas correctamente.");
    }
    catch (Exception^ ex) {
        MessageBox::Show("Error al leer el archivo: " + ex->Message);
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

