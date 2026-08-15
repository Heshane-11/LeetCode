class Solution {
public:
    int solve(vector<int>& nums, int i, vector<int>& dp){
        if(i >= nums.size()){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        // take
        int take = nums[i] + solve(nums, i+2, dp);

        //not take
        int ntake = solve(nums, i+1, dp);
        return dp[i] = max(take, ntake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        int x = solve(nums, 0, dp);
        int y = solve(nums, 1, dp);
        return max(x, y);
    }
};