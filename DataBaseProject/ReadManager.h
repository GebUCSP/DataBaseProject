#pragma once

using namespace System;
using namespace System::Collections::Generic;

public ref class ReadManager {
private:
    static String^ _lastImportedFilePath = nullptr;
    static String^ _lastImportedStructPath = nullptr;

public:
    static property String^ LastImportedFilePath {
        String^ get() { return _lastImportedFilePath; }
        void set(String^ value) { _lastImportedFilePath = value; }
    };
    static property String^ LastImportedStructPath {
        String^ get() { return _lastImportedStructPath; }
        void set(String^ value) { _lastImportedStructPath = value; }
    };

    static List<Tuple<String^, String^, int, int, bool, bool>^>^ fields = gcnew List<Tuple<String^, String^, int, int, bool, bool>^>();
    //static List<BaseData^>^>^ Rows = gcnew List<BaseData^>();
    static void ReadStructTable();
    static void ReadCSV();
    static bool ValidateValue(String^ value, Tuple<String^, String^, int, int, bool, bool>^ field);
};