#include "ReadManager.h"
#include "FieldValidator.h"
#include "HardDrive.h"


#include <fstream>

using namespace System;
using namespace System::IO;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;
using namespace System::Text::RegularExpressions;

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

void ReadManager::ReadStructTable()
{
    if (String::IsNullOrEmpty(LastImportedStructPath))
    {
        MessageBox::Show("No se seleccionó un archivo válido");
        return;
    }

    try
    {
        array<String^>^ lines = File::ReadAllLines(LastImportedStructPath);
        if (lines->Length == 0)
        {
            MessageBox::Show("El archivo .txt está vacío.");
            return;
        }

        fields->Clear();

        Regex^ rx = gcnew Regex(
            "^\\s*(\\w+)\\s+([A-Z]+(?:\\([0-9]+(?:\\s*,\\s*[0-9]+)?\\))?)\\s*(.*?)(?:,)?\\s*$",
            RegexOptions::IgnoreCase);

        for each (String ^ rawLine in lines)
        {
            String^ line = rawLine->Trim();
            if (line->Length == 0 ||
                line->StartsWith("CREATE TABLE", StringComparison::OrdinalIgnoreCase) ||
                line->StartsWith(")", StringComparison::Ordinal))
                continue;

            Match^ m = rx->Match(line);
            if (!m->Success)
            {
                MessageBox::Show("Error de sintaxis: " + line);
                continue;
            }

            String^ name = m->Groups[1]->Value;
            String^ typeSpec = m->Groups[2]->Value->ToUpper();
            String^ rest = m->Groups[3]->Value->Trim()->ToUpper();
            String^ type;
            int size = 0;
            int scale = 0;

            int p1 = typeSpec->IndexOf('(');
            if (p1 > -1)                       
            {
                type = typeSpec->Substring(0, p1);         
                int p2 = typeSpec->LastIndexOf(')');
                String^ inside = typeSpec->Substring(p1 + 1, p2 - p1 - 1)->Replace(" ", "");
                array<String^>^ nums = inside->Split(',');
                size = Int32::Parse(nums[0]);
                if (nums->Length == 2)
                    scale = Int32::Parse(nums[1]);
            }
            else
            {
                type = typeSpec;
                if (type == "INTEGER") size = 10;
            }

            bool isPrimaryKey = rest->Contains("PRIMARY KEY");
            bool isNotNull = rest->Contains("NOT NULL");

            fields->Add(gcnew Tuple<String^, String^, int, int, bool, bool>(
                name, type, size, scale, isPrimaryKey, isNotNull));
        }
    }
    catch (Exception^ ex)
    {
        MessageBox::Show("Error al leer el archivo de estructura: " + ex->Message);
    }
}

void ReadManager::ReadCSV()
{
    if (String::IsNullOrEmpty(LastImportedFilePath))
    {
        MessageBox::Show("No hay archivo CSV importado.");
        return;
    }

    try
    {
        array<String^>^ lines = File::ReadAllLines(LastImportedFilePath);

        if (lines->Length < 2)
        {
            MessageBox::Show("El archivo debe tener encabezado y al menos una fila de datos.");
            return;
        }

        array<String^>^ headers = SplitCSVLine(lines[0]);
        List<Tuple<String^, String^, int, int, bool, bool>^>^ FieldsOrdered =
            gcnew List<Tuple<String^, String^, int, int, bool, bool>^>();

        for each (String ^ rawHeader in headers)
        {
            String^ header = rawHeader->Trim();
            bool found = false;

            for each (auto field in fields)
            {
                String^ nameNormalized = field->Item1->Trim()->ToUpper();
                String^ headerNormalized = header->ToUpper();

                if (nameNormalized == headerNormalized)
                {
                    FieldsOrdered->Add(field);
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                MessageBox::Show("Columna no reconocida: " + header);
                return;
            }
        }

        for (int i = 1; i < lines->Length; ++i)
        {
            array<String^>^ values = SplitCSVLine(lines[i]);
            if (values->Length != FieldsOrdered->Count)
            {
                MessageBox::Show("Fila inválida, cantidad incorrecta de columnas");
                return;
            }

            bool isValidRow = true;
            for (int j = 0; j < values->Length; ++j)
            {
                String^ value = values[j];
                auto field = FieldsOrdered[j];

                if (!ValidateValue(value, field)) {
                    isValidRow = false;
                    String^ fieldName = field->Item1;
                    MessageBox::Show("Valor inválido en fila " + i + ", columna '" + fieldName +
                        "': \"" + value + "\"");
                    break;
                }

            }

            if (isValidRow) HardDrive::Instance->InsertRow(values, FieldsOrdered); 
        }

        MessageBox::Show("Lectura y validación del archivo CSV completadas correctamente.");
    }
    catch (Exception^ ex)
    {
        MessageBox::Show("Error al leer el archivo: " + ex->Message);
    }
}



bool ReadManager::ValidateValue(String^ value, Tuple<String^, String^, int, int, bool, bool>^ field) {
    bool isNotNull = field->Item6;

    if (isNotNull && String::IsNullOrWhiteSpace(value)) return 0;

    String^ type = field->Item2;
    int scale = field->Item4;
    int size = field->Item3;

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
