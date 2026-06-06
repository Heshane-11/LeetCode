class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            int l = 0, r = 0;
            for(int j = 0; j < i; j++){
                l += nums[j];
            }
            for(int j = i+1; j < n; j++){
                r += nums[j];
            }
            ans[i] = abs(l-r);
        }
        return ans;
    }
};