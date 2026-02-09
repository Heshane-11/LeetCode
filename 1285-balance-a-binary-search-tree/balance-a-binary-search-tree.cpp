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
    void inorder(TreeNode* root, vector<int> &v){
        if(root == nullptr){
            return;
        }
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }

    TreeNode* make(int l, int r, vector<int> &v){
        if (l > r) return nullptr;
        int m = (l + r) / 2;
        TreeNode* x = new TreeNode(v[m]);
        x->left = make(l, m-1, v);
        x->right = make(m+1, r, v);
        return x;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        inorder(root, v);
        int l = 0;
        int r = v.size()-1;
        return make(l, r, v);
    }
};