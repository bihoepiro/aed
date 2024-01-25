#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

;

void test(){

    TreeNode* nodo_a = new TreeNode(1);
    TreeNode* nodo_b = new TreeNode(2);
    TreeNode* nodo_c = new TreeNode(3);
    TreeNode* nodo_d = new TreeNode(4);
    nodo_a->right = nodo_b;
    nodo_b->right = nodo_c;
    nodo_c->right = nodo_d;
    assert(Solution().balanceBST(nodo_a) == nodo_c);

    nodo_a = new TreeNode(2);
    nodo_b = new TreeNode(1);
    nodo_c = new TreeNode(3);
    nodo_a->left = nodo_b;
    nodo_a->right = nodo_c;
    assert(Solution().balanceBST(nodo_a) == nodo_a);

}

int main(){
    test();
    return 0;
}
