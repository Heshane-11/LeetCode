class Solution {
public:
    long long solve(int i, int taken, vector<int>& nums, vector<vector<long long>>& dp) {
        if (i == nums.size()) return 0;

        if (dp[i][taken] != -1) return dp[i][taken];

        long long skip = solve(i + 1, taken, nums, dp);

        long long take;
        if (taken == 0)
            take = nums[i] + solve(i + 1, 1, nums, dp);
        else
            take = -nums[i] + solve(i + 1, 0, nums, dp);

        return dp[i][taken] = max(skip, take);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> dp(n, vector<long long>(2, -1));
        return solve(0, 0, nums, dp);
    }
};
