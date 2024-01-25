#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definición de la estructura del nodo del árbol binario
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    // Constructor para facilitar la creación de nodos
    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

// Función para realizar el recorrido por niveles en el árbol binario
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;

    // Verificación de si el árbol está vacío
    if (root == nullptr) {
        return result;
    }

    // Cola para almacenar los nodos durante el recorrido en amplitud
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    // Bucle principal del recorrido en amplitud
    while (!nodeQueue.empty()) {
        int levelSize = nodeQueue.size();
        vector<int> currentLevel;

        // Procesar todos los nodos en el nivel actual
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* currentNode = nodeQueue.front();
            nodeQueue.pop();

            // Agregar el valor del nodo actual al nivel actual
            currentLevel.push_back(currentNode->val);

            // Enqueue de los hijos si existen
            if (currentNode->left != nullptr) {
                nodeQueue.push(currentNode->left);
            }
            if (currentNode->right != nullptr) {
                nodeQueue.push(currentNode->right);
            }
        }

        // Agregar el nivel actual al resultado
        result.push_back(currentLevel);
    }

    return result;
}

int main() {
    // Crear un ejemplo de árbol binario
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // Realizar el recorrido por niveles e imprimir los nodos visitados
    vector<vector<int>> result = levelOrder(root);
    cout << "[";
    for (const auto& level : result) {
        cout << "[";
        for (const auto& val : level) {
            cout << val << ",";
        }
        cout << "],";
    }
    cout << "]" << endl;

    // Liberar la memoria de los nodos del árbol (no es necesario en todos los casos)
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
