#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        traverse(root, result);
        return result;
    }
    
    void traverse(TreeNode* node, vector<int>& result) {
        if (node == nullptr) {
            return;
        }
        traverse(node->left, result);   // Visit left subtree
        traverse(node->right, result);  // Visit right subtree
        result.push_back(node->val);    // Visit node itself
    }
};

int main() {
    // Example binary tree:
    //     1
    //      \
    //       2
    //      /
    //     3
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution sol;
    vector<int> postorder = sol.postorderTraversal(root);

    // Output the postorder traversal
    for (int val : postorder) {
        cout << val << " ";
    }
    return 0;
}