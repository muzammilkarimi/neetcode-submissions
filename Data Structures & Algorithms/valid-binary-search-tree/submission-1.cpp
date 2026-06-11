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
    bool isValidBST(TreeNode* root) {
        if(!root) return false;
        stack<TreeNode*> st;
        vector<int> ele;
        while(root or !st.empty()){
            while(root){
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            ele.push_back(root->val);
            root = root->right;
        }
        for(int i=1; i<ele.size(); i++){if(ele[i-1]>=ele[i]) return false;}
        return true;
    }
};
