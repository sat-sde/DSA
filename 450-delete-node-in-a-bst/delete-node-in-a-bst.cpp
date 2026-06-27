/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;

        // If the key is smaller than the root's value, go to the left subtree
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        // If the key is larger than the root's value, go to the right subtree
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        // If the key is equal to the root's value, delete this node
        else {
            root = helper(root);
        }

        return root;
    }

private:
    TreeNode* helper(TreeNode* root) {
        if (root->left == nullptr) {
            return root->right;
        } else if (root->right == nullptr) {
            return root->left;
        }
        
        // Find the rightmost node in the left subtree
        TreeNode* rightChild = root->right;
        TreeNode* lastRight = findLastRight(root->left);
        lastRight->right = rightChild;
        
        return root->left;
    }

    TreeNode* findLastRight(TreeNode* root) {
        while (root->right != nullptr) {
            root = root->right;
        }
        return root;
    }
};