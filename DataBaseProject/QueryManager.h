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

    AVLNode(String^ key_, List<ValueNode^>^ row_) {
        key = key_;
        row = row_;
        height = 1;
        left = nullptr;
        right = nullptr;
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
    AVLNode^ InsertNode(AVLNode^ node, String^ key, List<ValueNode^>^ row);
    AVLNode^ SearchNode(AVLNode^ node, String^ key);
    void InOrderSearch(AVLNode^ node, String^ field, String^ op, String^ val, List<List<ValueNode^>^>^ results);

public:
    AVLTree();
    void Insert(String^ key, List<ValueNode^>^ row);
    List<ValueNode^>^ Search(String^ key);
    List<List<ValueNode^>^>^ SearchByField(String^ field, String^ op, String^ val);
};

ref class QueryManager {
private:
    static AVLTree^ indexTree = gcnew AVLTree();
    static int keyIndex = 0;

public:
    static void InsertRow(array<String^>^ values);
    static void SelectWhere(String^ field, String^ op, String^ val);
    static void SetKeyField(String^ fieldName);
};
