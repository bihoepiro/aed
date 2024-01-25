#include "iostream"
#include <queue>
using namespace std;

template <typename T>
class BSTree {
private:
    struct NodeBT {
        T data;
        NodeBT *left;
        NodeBT *right;

        NodeBT(T value) : data(value), left(nullptr), right(nullptr) {}
    };

    NodeBT* insert(NodeBT* root,T value){
        if (root == nullptr) {
            return new NodeBT(value);
        }

        if (value < root->data) {
            root->left = insert(root->left, value);
        } else if (value > root->data) {
            root->right = insert(root->right, value);
        }

        return root;
    }

    NodeBT* remove(NodeBT* root, T value){
        if (root == nullptr) {
            return root;
        }

        if (value < root->data) {
            root->left = remove(root->left, value);
        } else if (value > root->data) {
            root->right = remove(root->right, value);
        } else {
            if (root->left == nullptr) {
                NodeBT* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                NodeBT* temp = root->left;
                delete root;
                return temp;
            }

            root->data = minValue(root->right);

            root->right = remove(root->right, root->data);
        }
        return root;
    }

public:
    NodeBT *root= nullptr;
    void insert(T value) {
        root = insert(root, value);
    }

    void remove(T value) {
        root = remove(root, value);
    }

    int height(NodeBT* root) {
        if (root == nullptr) {
            return 0;
        }
        int lh = height(root->left);
        int rh = height(root->right);
        return 1 + max(lh, rh);
    }

    T minValue(NodeBT* root) {
        while (root->left != nullptr) {
            root = root->left;
        }
        return root->data;
    }

    T maxValue(NodeBT* root) {
        while (root->right != nullptr) {
            root = root->right;
        }
        return root->data;
    }

    bool find(NodeBT* node, T value){
        if(node == nullptr)
            return false;
        else if(value < node->data)
            return find(node->left, value);
        else if(value > node->data)
            return find(node->right, value);
        else return true;
    }

    void BFS() const {
        if (root == nullptr) {
            return;
        }

        queue<NodeBT*> q;
        q.push(root);

        while (!q.empty()) {
            NodeBT* current = q.front();
            cout << current->data << " ";

            if (current->left != nullptr) {
                q.push(current->left);
            }

            if (current->right != nullptr) {
                q.push(current->right);
            }

            q.pop();
        }
        cout << endl;
    }

};

int main() {
    BSTree<int> bst;


    // Insertar elementos
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert( 2);
    bst.insert( 4);

    // Mostrar el recorrido en anchura (BFS)
    cout << "BFS traversal: ";
    bst.BFS();

    // Obtener altura del árbol
    cout << "Tree height: " << bst.height(bst.root) << endl;

    // Encontrar el valor mínimo y máximo
    cout << "Minimum value: " << bst.minValue(bst.root) << endl;
    cout << "Maximum value: " << bst.maxValue(bst.root) << endl;

    // Verificar si un valor existe en el árbol
    int valueToFind = 3;
    cout << "Is " << valueToFind << " in the tree? " << (bst.find(bst.root, valueToFind) ? "Yes" : "No") << endl;

    // Eliminar un nodo
    int valueToRemove = 5;
    cout << "Removing " << valueToRemove << " from the tree." << endl;
    bst.remove(valueToRemove);

    // Mostrar el recorrido en anchura después de la eliminación
    cout << "BFS traversal after removal: ";
    bst.BFS();

    return 0;
}
