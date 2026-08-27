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
    int ans = 0;
    int calculatepath(TreeNode* root){
        if(root == NULL) return 0;
        int l = calculatepath(root->left);
        int r = calculatepath(root->right);
        l = max(l, 0);
        r = max(r, 0);
        ans = max(ans, l+r+root->val);
        return max(0, root->val+max(l, r));
    }

    int maxPathSum(TreeNode* root) {
        ans = root->val;
        calculatepath(root);
        return ans;
    }
};
