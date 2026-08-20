class Solution {
public:
    int solve(vector<int>& stones, int i, int sum, int ts, vector<vector<int>>& dp){
        if(i >= stones.size()){
            return abs(2*sum - ts);
        }
        if(dp[i][sum] != -1){
            return dp[i][sum];
        }
        int take = 0, notake = 0;
        take = solve(stones, i+1, sum+stones[i], ts, dp);
        notake = solve(stones, i+1, sum, ts, dp);
        return dp[i][sum] = min(take, notake);
    }
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int ts = accumulate(stones.begin(), stones.end(), 0);
        vector<vector<int>> dp(n, vector<int>(ts+1, -1));
        return solve(stones, 0, 0, ts, dp);
    }
};