class Solution {
public:
    void traverse(TreeNode* root, vector<int>& ans) {
        if (root == NULL) {
            return;
        }
        traverse(root->left, ans);
        traverse(root->right, ans);
        ans.push_back(root->val);
    }

   vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* lastVisited = nullptr;

        while (root || !st.empty()) {
            if (root) {
                st.push(root);
                root = root->left;
            } else {
                TreeNode* node = st.top();

                if (node->right && lastVisited != node->right) {
                    root = node->right;
                } else {
                    ans.push_back(node->val);
                    lastVisited = node;
                    st.pop();
                }
            }
        }

        return ans;
    }
};
