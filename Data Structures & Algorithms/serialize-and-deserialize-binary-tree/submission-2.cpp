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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        preorder(root, ans);
        return ans.substr(1);
    }

    void preorder(TreeNode* root, string& ans) {
        ans += ',';
        if(root == NULL) ans += 'N';
        else {
            ans += to_string(root->val);
            preorder(root->left, ans);
            preorder(root->right, ans);
        }

    }
    int id = 0;

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        id = 0;
        return buildTree(data);
    }

    TreeNode* buildTree(string& data) {
        if(id == data.size())return NULL;
        if(data[id] == 'N'){
            id += 2;
            return NULL;
        }
        int len = 0;
        while(data[len+id] != ','){
            ++len;
        }
        TreeNode* root = new TreeNode(stoi(data.substr(id, len)));
        id += len;
        id += 1;
        root->left = buildTree(data);
        root->right = buildTree(data);
        return root;
    }
};
