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
pair<bool,int> is_balance(TreeNode*root){
    pair<bool,int> p=make_pair(true,0);
    if(root == nullptr){
        return p;
    }
    pair<bool,int> left = is_balance(root->left);
    pair<bool,int> right = is_balance(root->right);

    bool is_balanced_now = left.first && right.first && abs(left.second - right.second) <= 1;
    int height_now = 1 + max(left.second, right.second);

    return {is_balanced_now, height_now};
}

    bool isBalanced(TreeNode*root){
    pair<bool,int> ans = is_balance(root);
    return ans.first;
}
};