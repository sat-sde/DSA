/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "null";

        string result;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node) {
                result += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            } else {
                result += "null,";
            }
        }

        // Remove trailing comma
        result.pop_back();
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "null") return nullptr;

        stringstream ss(data);
        string value;
        getline(ss, value, ',');
        TreeNode* root = new TreeNode(stoi(value));

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            // Process left child
            if (getline(ss, value, ',')) {
                if (value != "null") {
                    TreeNode* leftNode = new TreeNode(stoi(value));
                    node->left = leftNode;
                    q.push(leftNode);
                }
            }

            // Process right child
            if (getline(ss, value, ',')) {
                if (value != "null") {
                    TreeNode* rightNode = new TreeNode(stoi(value));
                    node->right = rightNode;
                    q.push(rightNode);
                }
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));