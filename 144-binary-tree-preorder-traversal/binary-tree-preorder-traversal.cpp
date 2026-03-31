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
        if(root == nullptr){
            return ans;
        }
        
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();
            ans.push_back(node->val);
            st.pop();
            if(node->right){
                st.push(node->right);
            }
            if(node->left){
                st.push(node->left);
            }
        }
        return ans;
    }
};
