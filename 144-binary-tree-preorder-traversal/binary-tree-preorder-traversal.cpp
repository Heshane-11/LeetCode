class Solution {
public: 
    void help(TreeNode* root, vector<int>& ans){
        if(root == nullptr){
            return;
        }
        ans.push_back(root->val);
        help(root->left, ans);
        help(root->right, ans);
        return;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        help(root, ans);
        return ans;
    }
};
