#pragma once

using namespace System;

public ref class ReadManager {
private:
    static String^ _lastImportedFilePath = nullptr;

public:
    static property String^ LastImportedFilePath {
        String^ get() { return _lastImportedFilePath; }
        void set(String^ value) { _lastImportedFilePath = value; }
    };

    static void ReadCSV();
};
