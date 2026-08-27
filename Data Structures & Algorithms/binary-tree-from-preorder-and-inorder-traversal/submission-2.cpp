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
    TreeNode* buildtree(vector<int>& preorder, int pl, int pr, vector<int> inorder, int il, int ir) {
        if(pl == pr) return NULL;
        TreeNode* root  = new TreeNode(preorder[pl]);
        int mid = il;
        for(int i = il; i < ir; ++i){
            if(inorder[i] == preorder[pl]) mid = i;
        }
        root->left = buildtree(preorder, pl+1, pl+(mid-il)+1, inorder, il, mid);
        root->right = buildtree(preorder, pl+(mid-il)+1, pr, inorder, mid+1, ir);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildtree(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
};
