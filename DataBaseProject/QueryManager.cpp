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

AVLNode^ AVLTree::InsertNode(AVLNode^ node, String^ key, List<ValueNode^>^ row) {
    if (!node) return gcnew AVLNode(key, row);
    if (String::Compare(key, node->key) < 0)
        node->left = InsertNode(node->left, key, row);
    else
        node->right = InsertNode(node->right, key, row);
    return Balance(node);
}

AVLNode^ AVLTree::SearchNode(AVLNode^ node, String^ key) {
    if (!node) return nullptr;
    int cmp = String::Compare(key, node->key);
    if (cmp == 0) return node;
    if (cmp < 0) return SearchNode(node->left, key);
    return SearchNode(node->right, key);
}

void AVLTree::InOrderSearch(AVLNode^ node, String^ field, String^ op, String^ val, List<List<ValueNode^>^>^ results) {
    if (!node) return;
    InOrderSearch(node->left, field, op, val, results);

    for each (ValueNode ^ n in node->row) {
        if (n->field == field) {
            bool condition = false;
            if (op == "=") condition = n->value == val;
            else if (op == ">") condition = Int32::Parse(n->value) > Int32::Parse(val);
            else if (op == "<") condition = Int32::Parse(n->value) < Int32::Parse(val);

            if (condition) results->Add(node->row);
        }
    }

    InOrderSearch(node->right, field, op, val, results);
}

AVLTree::AVLTree() {
    root = nullptr;
}

void AVLTree::Insert(String^ key, List<ValueNode^>^ row) {
    root = InsertNode(root, key, row);
}

List<ValueNode^>^ AVLTree::Search(String^ key) {
    AVLNode^ node = SearchNode(root, key);
    return node ? node->row : nullptr;
}

List<List<ValueNode^>^>^ AVLTree::SearchByField(String^ field, String^ op, String^ val) {
    List<List<ValueNode^>^>^ results = gcnew List<List<ValueNode^>^>();
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
    indexTree->Insert(key, row);
}

void QueryManager::SelectWhere(String^ field, String^ op, String^ val) {
    List<List<ValueNode^>^>^ results = indexTree->SearchByField(field, op, val);
    String^ output = "";

    for each (List<ValueNode^> ^ row in results) {
        for each (ValueNode ^ v in row)
            output += v->field + ": " + v->value + " | ";
        output += "\n";
    }

    MessageBox::Show(output == "" ? "Sin resultados." : output);
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
