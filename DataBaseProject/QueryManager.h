#pragma once
#include "HardDrive.h"

using namespace System;
using namespace System::Collections::Generic;

ref class AVLNode {
public:
    String^ key;
    List<ValueNode^>^ row;
    int height;
    AVLNode^ left;
    AVLNode^ right;

    AVLNode(String^ key_, ValueNode^ v) {
        key = key_;
        row = gcnew List<ValueNode^>();
        row->Add(v);
        left = right = nullptr;
        height = 1;
    }
};

ref class AVLTree {
private:
    AVLNode^ root;

    int Height(AVLNode^ node);
    int BalanceFactor(AVLNode^ node);
    AVLNode^ RotateRight(AVLNode^ y);
    AVLNode^ RotateLeft(AVLNode^ x);
    AVLNode^ Balance(AVLNode^ node);
    AVLNode^ InsertNode(AVLNode^ node, String^ key, ValueNode^ row);
    AVLNode^ SearchNode(AVLNode^ node, String^ key);
    void InOrderSearch(AVLNode^ node, String^ field, String^ op, String^ val, List<ValueNode^>^ results);
    bool CompareValues(String^ type, String^ a, String^ b, String^ op);

public:
    AVLTree();
    void Insert(String^ key, ValueNode^ row);
    List<ValueNode^>^ Search(String^ key);
    List<ValueNode^>^ SearchByField(String^ field, String^ op, String^ val);
};

ref class QueryManager {
private:
    static AVLTree^ indexTree = nullptr;
    static String^ currentField = "";

    static int keyIndex = 0;

public:
    static void InsertRow(array<String^>^ values);
    static void SelectWhere(String^ field, String^ op, String^ val);
    static void SetKeyField(String^ fieldName);
    static void BuildIndex(String^ field);
    static void AND(String^ field, String^ op, String^ val, String^ additionalField, String^ additionalOp, String^ additionalVal);
    static void OR(String^ field, String^ op, String^ val, String^ additionalField, String^ additionalOp, String^ additionalVal);
};
