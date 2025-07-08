#include "QueryManager.h"

int AVLTree::Height(AVLNode^ node) {
    return node ? node->height : 0;
}

int AVLTree::BalanceFactor(AVLNode^ node) {
    return node ? Height(node->left) - Height(node->right) : 0;
}

AVLNode^ AVLTree::RotateRight(AVLNode^ y) {
    AVLNode^ x = y->left;
    AVLNode^ T2 = x->right;
    x->right = y;
    y->left = T2;

    y->height = Math::Max(Height(y->left), Height(y->right)) + 1;
    x->height = Math::Max(Height(x->left), Height(x->right)) + 1;

    return x;
}

AVLNode^ AVLTree::RotateLeft(AVLNode^ x) {
    AVLNode^ y = x->right;
    AVLNode^ T2 = y->left;
    y->left = x;
    x->right = T2;

    x->height = Math::Max(Height(x->left), Height(x->right)) + 1;
    y->height = Math::Max(Height(y->left), Height(y->right)) + 1;

    return y;
}

AVLNode^ AVLTree::Balance(AVLNode^ node) {
    node->height = Math::Max(Height(node->left), Height(node->right)) + 1;
    int balance = BalanceFactor(node);

    if (balance > 1) {
        if (BalanceFactor(node->left) < 0)
            node->left = RotateLeft(node->left);
        return RotateRight(node);
    }
    if (balance < -1) {
        if (BalanceFactor(node->right) > 0)
            node->right = RotateRight(node->right);
        return RotateLeft(node);
    }

    return node;
}

AVLNode^ AVLTree::InsertNode(AVLNode^ node, String^ key, ValueNode^ row) {
    if (!node) return gcnew AVLNode(key, row);

    String^ type = row->type;
    int cmp = 0;
 
    if (CompareValues(type, key, node->key, "<")) cmp = -1;
    else if (CompareValues(type, key, node->key, ">")) cmp = 1;


    if (cmp < 0)
        node->left = InsertNode(node->left, key, row);
    else if (cmp > 0)
        node->right = InsertNode(node->right, key, row);
    else
        node->row->Add(row);

    return Balance(node);
}

AVLNode^ AVLTree::SearchNode(AVLNode^ node, String^ key) {
    if (!node) return nullptr;
    String^ type = node->row[0]->type;
    int cmp = 0;

    if (CompareValues(type, key, node->key, "<")) cmp = -1;
    else if (CompareValues(type, key, node->key, ">")) cmp = 1;


    if (cmp == 0) return node;
    if (cmp < 0) return SearchNode(node->left, key);
    return SearchNode(node->right, key);
}

void AVLTree::InOrderSearch(AVLNode^ node, String^ field, String^ op, String^ val, List<ValueNode^>^ results) {
    if (!node) return;
    InOrderSearch(node->left, field, op, val, results);

    for each (ValueNode^ n in node->row) {
        if (n->field == field && CompareValues(n->type, n->value, val, op)) {
            results->Add(n);
        }
    }

    InOrderSearch(node->right, field, op, val, results);
}

AVLTree::AVLTree() {
    root = nullptr;
}

void AVLTree::Insert(String^ key, ValueNode^ row) {
    root = InsertNode(root, key, row);
}

List<ValueNode^>^ AVLTree::Search(String^ key) {
    AVLNode^ node = SearchNode(root, key);
    return node ? node->row : nullptr;
}

List<ValueNode^>^ AVLTree::SearchByField(String^ field, String^ op, String^ val) {
    List<ValueNode^>^ results = gcnew List<ValueNode^>();
    InOrderSearch(root, field, op, val, results);
    return results;
}

void QueryManager::InsertRow(array<String^>^ values) {
    HardDrive::instance->InsertRow(values);

    List<ValueNode^>^ row = gcnew List<ValueNode^>();
    ValueNode^ head = HardDrive::instance->GetLastInsertedRow(); //mentar esto en HardDrive
    while (head != nullptr) {
        row->Add(head);
        head = head->nextValueNode;
    }

    String^ key = row[keyIndex]->value;
    //indexTree->Insert(key, row);
}


void QueryManager::SelectWhere(String^ field, String^ op, String^ val) {
    if (indexTree == nullptr || currentField != field)
        BuildIndex(field);
    
    List<ValueNode^>^ results = indexTree->SearchByField(field, op, val);

    if (results == nullptr || results->Count == 0) {
        MessageBox::Show("Sin resultados.");
        return;
    }

    HardDrive::instance->getRowByListNodes(results);
}

void QueryManager::SetKeyField(String^ fieldName) {
    for (int i = 0; i < HardDrive::instance->headers->Length; i++) {
        if (HardDrive::instance->headers[i]->Item1 == fieldName) {
            keyIndex = i;
            return;
        }
    }
    MessageBox::Show("Campo clave no encontrado");
}

bool AVLTree::CompareValues(String^ type, String^ a, String^ b, String^ op) {
    try {
        if (op == "Begin") return a->StartsWith(b);
        if (op == "End") return a->EndsWith(b);
        if (op == "Include") return a->Contains(b);
        if (type == "INTEGER") {
            int valA = Int32::Parse(a);
            int valB = Int32::Parse(b);
            if (op == "=") return valA == valB;
            if (op == "!=") return valA != valB;
            if (op == "<") return valA < valB;
            if (op == ">") return valA > valB;
            if (op == "<=") return valA <= valB;
            if (op == ">=") return valA >= valB;
        }
        else if (type == "DECIMAL") {
            double valA = Double::Parse(a);
            double valB = Double::Parse(b);
            if (op == "=") return valA == valB;
            if (op == "!=") return valA != valB;
            if (op == "<") return valA < valB;
            if (op == ">") return valA > valB;
            if (op == "<=") return valA <= valB;
            if (op == ">=") return valA >= valB;
        }
        else {
            if (op == "=") return a == b;
            if (op == "!=") return a != b;

        }
    }
    catch (FormatException^) {
        return false;
    }
    return false;
}

void QueryManager::BuildIndex(String^ field) {
    indexTree = gcnew AVLTree();
    currentField = field;

    List<ValueNode^>^ nodes = HardDrive::instance->getListByField(field);

    if (nodes == nullptr || nodes->Count == 0) {
        MessageBox::Show("No hay datos para indexar en ese campo.");
        return;
    }

    for each (ValueNode^ n in nodes) {
        indexTree->Insert(n->value, n);
    }
}

void QueryManager::AND(String^ field, String^ op, String^ val, String^ additionalField, String^ additionalOp, String^ additionalVal)
{
    if (indexTree == nullptr || currentField != field)
        BuildIndex(field);
    List<ValueNode^>^ resultsA = indexTree->SearchByField(field, op, val);

    indexTree = nullptr;

    if (indexTree == nullptr)
        BuildIndex(additionalField);
    List<ValueNode^>^ resultsB = indexTree->SearchByField(additionalField, additionalOp, additionalVal);

    List<ValueNode^>^ minList = nullptr;
    List<ValueNode^>^ maxList = nullptr;

    int size = 0;

    if (resultsA->Count < resultsB->Count) {
        size = resultsA->Count;
        minList = resultsA;
        maxList = resultsB;
    }
    else {
        size = resultsB->Count;
        minList = resultsB;
        maxList = resultsA;
    }

    List<ValueNode^>^ results = gcnew List<ValueNode^>();

    for (int i = 0; i < minList->Count; i++) {
        ValueNode^ p = HardDrive::Instance->getNodeByField(minList[i], maxList[i]->field);
        if (maxList->Contains(p))
            results->Add(p);
    }

    if (results == nullptr || results->Count == 0) {
        MessageBox::Show("Sin resultados.");
        return;
    }

    HardDrive::instance->getRowByListNodes(results);
}

void QueryManager::OR(String^ field, String^ op, String^ val, String^ additionalField, String^ additionalOp, String^ additionalVal)
{
    if (indexTree == nullptr || currentField != field)
        BuildIndex(field);
    List<ValueNode^>^ resultsA = indexTree->SearchByField(field, op, val);

    indexTree = nullptr;

    if (indexTree == nullptr)
        BuildIndex(additionalField);
    List<ValueNode^>^ resultsB = indexTree->SearchByField(additionalField, additionalOp, additionalVal);

    List<ValueNode^>^ minList = nullptr;
    List<ValueNode^>^ maxList = nullptr;


    if (resultsA->Count < resultsB->Count) {
        minList = resultsA;
        maxList = resultsB;
    }
    else {
        minList = resultsB;
        maxList = resultsA;
    }

    List<ValueNode^>^ results = gcnew List<ValueNode^>();

    for (int i = 0; i < maxList->Count; i++) {
        results->Add(maxList[i]);
    }

    for (int i = 0; i < minList->Count; i++) {
        ValueNode^ p = HardDrive::Instance->getNodeByField(minList[i], maxList[i]->field);
        if (!results->Contains(p))
            results->Add(p);
    }

    if (results == nullptr || results->Count == 0) {
        MessageBox::Show("Sin resultados.");
        return;
    }

    HardDrive::instance->getRowByListNodes(results);
}