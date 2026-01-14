class Solution {
public:

    int help(vector<int>& nums, int target, vector<int>& dp){
        if(target == 0) return 1;
        if(dp[target] != -1) return dp[target];
        dp[target] = 0;
        for(int i = 0; i < nums.size(); i++){
            if(target - nums[i] >= 0){
                dp[target] += help(nums, target-nums[i], dp);
            }
        }
        return dp[target];
    }

    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(target+1,-1);
        sort(nums.begin(), nums.end());
        return help(nums, target, dp);
    }
};