class Solution {
public:
    int solve(int n, vector<int>& dp){
        if(n == 0){
            return 0;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int mini = 1e9;
        for(int j = 1; j <= sqrt(n); j++){
            if(pow(j, 2) <= n){
                int x = 1 + solve(n-pow(j, 2), dp);
                mini = min(mini, x);
            }
        }
        return dp[n] = mini;
    }
    int numSquares(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};
