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
    if (root == NULL) return ans;

    TreeNode* curr = root;

    while (curr != NULL) {
        if (curr->left) {
            TreeNode* temp = curr->left;

            while (temp->right != NULL && temp->right != curr) {
                temp = temp->right;
            }

            if (temp->right == NULL) {
                ans.push_back(curr->val);   // first time
                temp->right = curr;
                curr = curr->left;
            } else {
                temp->right = NULL;         // remove thread
                curr = curr->right;
            }
        }
        else {
            ans.push_back(curr->val);
            curr = curr->right;
        }
    }
    return ans;
}
};
