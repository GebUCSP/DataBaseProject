#include "QueryManager.h"
#include "HardDrive.h"

using namespace System;
using namespace System::Collections::Generic;

ref class AVLNode {
public:
    String^ key;
    AVLNode^ left;
    AVLNode^ right;
    int height;

    AVLNode(String^ val) {
        key = val;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

ref class AVLTree {
private:
    AVLNode^ root;

    int Height(AVLNode^ n) {
        return n ? n->height : 0;
    }

    int BalanceFactor(AVLNode^ n) {
        return n ? Height(n->left) - Height(n->right) : 0;
    }

    void UpdateHeight(AVLNode^ n) {
        n->height = 1 + Math::Max(Height(n->left), Height(n->right));
    }

    AVLNode^ RotateRight(AVLNode^ y) {
        AVLNode^ x = y->left;
        AVLNode^ T2 = x->right;

        x->right = y;
        y->left = T2;

        UpdateHeight(y);
        UpdateHeight(x);
        return x;
    }

    AVLNode^ RotateLeft(AVLNode^ x) {
        AVLNode^ y = x->right;
        AVLNode^ T2 = y->left;

        y->left = x;
        x->right = T2;

        UpdateHeight(x);
        UpdateHeight(y);
        return y;
    }

    AVLNode^ Insert(AVLNode^ node, String^ key) {
        if (node == nullptr)
            return gcnew AVLNode(key);

        if (String::Compare(key, node->key) < 0)
            node->left = Insert(node->left, key);
        else if (String::Compare(key, node->key) > 0)
            node->right = Insert(node->right, key);
        else
            return node; // evitar duplicados

        UpdateHeight(node);
        int balance = BalanceFactor(node);

        if (balance > 1 && String::Compare(key, node->left->key) < 0)
            return RotateRight(node);
        if (balance < -1 && String::Compare(key, node->right->key) > 0)
            return RotateLeft(node);
        if (balance > 1 && String::Compare(key, node->left->key) > 0) {
            node->left = RotateLeft(node->left);
            return RotateRight(node);
        }
        if (balance < -1 && String::Compare(key, node->right->key) < 0) {
            node->right = RotateRight(node->right);
            return RotateLeft(node);
        }

        return node;
    }

    void InOrder(AVLNode^ node) {
        if (node != nullptr) {
            InOrder(node->left);
            Console::WriteLine(node->key);
            InOrder(node->right);
        }
    }

public:
    AVLTree() {
        root = nullptr;
    }

    void Insert(String^ key) {
        root = Insert(root, key);
    }

    void PrintInOrder() {
        InOrder(root);
    }
};

// -------------------
QueryManager::QueryManager(HardDrive^ hd) {
    this->hd = hd;
}

void QueryManager::ConstruirAVLPorCampo(String^ campo) {
    AVLTree^ tree = gcnew AVLTree();

    for (int p = 0; p < hd->platters->Length; ++p) {
        for (int s = 0; s < hd->platters[p]->surfaces->Length; ++s) {
            for (int t = 0; t < hd->platters[p]->surfaces[s]->tracks->Length; ++t) {
                for (int c = 0; c < hd->platters[p]->surfaces[s]->tracks[t]->clusters->Length; ++c) {
                    Cluster^ cluster = hd->platters[p]->surfaces[s]->tracks[t]->clusters[c];

                    for each (Dictionary<String^, String^> ^ row in cluster->data) {
                        if (row->ContainsKey(campo)) {
                            String^ valor = row[campo];
                            tree->Insert(valor); // Inserta al AVL directamente
                        }
                    }
                }
            }
        }
    }

    Console::WriteLine("AVL In-Order para campo: " + campo);
    tree->PrintInOrder();
}
