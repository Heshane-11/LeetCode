class Solution {
public:
    void l(vector<int>& height, vector<int>& hleft){
        hleft[0] = height[0];
        for(int i = 1; i < height.size(); i++){
            hleft[i] = max(hleft[i-1], height[i]);
        }
    }
    void r(vector<int>& height, vector<int>& rleft){
        int n = height.size();
        rleft[n-1] = height[n-1];
        for(int i = n-2; i >= 0; i--){
            rleft[i] = max(rleft[i+1], height[i]);
        }
    }
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> hleft(n, -1);
        vector<int> rleft(n, -1);
        l(height, hleft);
        r(height, rleft);
        int ans = 0;
        for(int i = 1; i < n-1; i++){
            ans += min(hleft[i], rleft[i]) - height[i];
        }
        return ans;
    }
};