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
    void solve(TreeNode* root){
        if(!root) return ;
        TreeNode* r = root -> right;
        TreeNode* l = root -> left;
        root -> left = r;
        root -> right = l;
        solve(root->left);
        solve(root -> right);
    }
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        solve(root);
        return root;
    }
};
