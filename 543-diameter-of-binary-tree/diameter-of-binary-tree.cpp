class Solution {
public:

    pair<int, int> find(TreeNode* root){
        if(!root){
            return {0,0};
        }

        auto left = find(root->left);
        auto right = find(root->right);

        int h = 0; 
        int d = 0;

        int l = left.first;
        int r = right.first;
        h = max(l, r) + 1;

        int op1 = left.second;
        int op2 = right.second;
        int op3 = left.first + right.first;
        d = max({op1, op2, op3});           

        return {h, d};
    }

    int diameterOfBinaryTree(TreeNode* root) {
       pair<int, int> p = find(root);
       return p.second;
    }
};