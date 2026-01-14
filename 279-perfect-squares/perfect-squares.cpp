class Solution {
public:
    int help(int n, vector<int>&dp){
        if(n == 0){
            return 0;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int mini = INT_MAX;
        for(int i = 1; i * i <= n; i++){
            mini = min(mini, 1 + help(n - i*i, dp));
        }
        return dp[n] = mini;
    }

    int numSquares(int n) {
        vector<int>dp(n+1, -1);
        return help(n, dp);
    }
};
