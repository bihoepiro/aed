#include "iostream"
#include <queue>
using namespace std;

/*
Métodos de BST
- Insert // inserta nodos al BST
- Remove // remueve un nodo especifico en el BST
- Find // encuentra un nodo especifico en el BST
- Height // altura del árbol
- MinValue // encuentra el nodo de mínimo valor en el BST
- MaxValue // encuentra el nodo de máximo valor en el BST
- BFS // recorre el BST a través de BFS
- Successor // Indica el valor del nodo sucesor de cierto nodo en el BST
- Predeccessor // Indica el valor del nodo predecesor de cierto nodo en el BST
 - Clear // Limpia todo el BST
*/
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

    void clear(NodeBT* node) {
        if (node == nullptr) {
            return;
        }

        clear(node->left);
        clear(node->right);

        delete node;
    }

public:
    NodeBT *root;
    BSTree() : root(nullptr) {}
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

    NodeBT* findNode(NodeBT* node, T value) {
        if (node == nullptr || node->data == value) {
            return node;
        }

        if (value < node->data) {
            return findNode(node->left, value);
        } else {
            return findNode(node->right, value);
        }
    }

    T successor(T value) {
        NodeBT* node = findNode(root, value);
        if (node == nullptr) {
            throw logic_error("No está el valor en el árbol");
        }

        if (node->right != nullptr) {
            return minValue(node->right);
        }

        NodeBT* succ = nullptr;
        NodeBT* current = root;

        while (current != nullptr) {
            if (value < current->data) {
                succ = current;
                current = current->left;
            } else if (value > current->data) {
                current = current->right;
            } else {
                break;
            }
        }

        if (succ == nullptr) {
            throw logic_error("No hay sucesor");
        }

        return succ->data;
    }

    T predecessor(T value) {
        NodeBT* node = findNode(root, value);
        if (node == nullptr) {
            throw logic_error("No está el valor en el árbol");
        }

        if (node->left != nullptr) {
            return maxValue(node->left);
        }

        NodeBT* pred = nullptr;
        NodeBT* current = root;

        while (current != nullptr) {
            if (value > current->data) {
                pred = current;
                current = current->right;
            } else if (value < current->data) {
                current = current->left;
            } else {
                break;
            }
        }

        if (pred == nullptr) {
            throw logic_error("No hay precedor");
        }

        return pred->data;
    }

    void clear() {
        clear(root);
        root = nullptr;
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

    cout << "BFS traversal: ";
    bst.BFS();

    cout << "Tree height: " << bst.height(bst.root) << endl;

    cout << "Minimum value: " << bst.minValue(bst.root) << endl;
    cout << "Maximum value: " << bst.maxValue(bst.root) << endl;

    int valueToFind = 3;
    cout << "Is " << valueToFind << " in the tree? " << (bst.find(bst.root, valueToFind) ? "Yes" : "No") << endl;

    int valueToRemove = 5;
    cout << "Removing " << valueToRemove  << endl;
    bst.remove(valueToRemove);

    cout << "BFS traversal after removal: ";
    bst.BFS();

    int valS = 3;
    cout << "Successor of " << valS << ": " << bst.successor(valS) << endl;


    int valP = 3;
    cout << "Predecessor of " << valP << ": " << bst.predecessor(valP) << endl;


    return 0;
}
