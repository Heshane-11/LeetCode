class Solution {
public:
    bool solve(int target, vector<int>& nums, int i, vector<vector<int>>& dp){
        if(target == 0){
            return true;
        }
        if(i >= nums.size()){
            return false;
        }
        if(dp[i][target] != -1){
            return dp[i][target];
        }
        bool take = false;
        bool notake = solve(target, nums, i+1, dp);
        if(nums[i] <= target){
            take = solve(target-nums[i], nums, i+1, dp);
        }
        return dp[i][target] = take || notake;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0){
            return false;
        }
        int target = sum/2;
       vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return solve(target, nums, 0, dp);
    }
};