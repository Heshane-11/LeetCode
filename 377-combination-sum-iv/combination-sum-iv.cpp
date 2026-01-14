class Solution {
public:

    int help(vector<int>& nums, int target){
        vector<long long> dp(target+1, 0);
        dp[0] = 1;
        for(int t = 1; t <= target; t++){
            for(int i = 0; i < nums.size(); i++){
                if (nums[i] > t) break;
                dp[t] += dp[t - nums[i]];
                if(dp[t] > INT_MAX) dp[t] = INT_MAX;
            }
        }
        return (int)dp[target];
    }

    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return help(nums, target);
    }
};