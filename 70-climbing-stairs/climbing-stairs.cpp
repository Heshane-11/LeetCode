class Solution {
public:
    int solve(int n, vector<int> &dp){
        if(n <= 1){
            return 1;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int x, y;
        if(n >= 1){
            x = solve(n-1, dp);
        }
        if(n >= 2){
            y = solve(n-2, dp);
        }
        return dp[n] = x + y;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};
