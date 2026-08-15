class Solution {
public:
    int solve(vector<int>& coins, int amount, vector<int>& dp){
        if(amount == 0) return 0;
        if(amount < 0) return 1e9;

        if(dp[amount] != -1) return dp[amount];

        int mini = 1e9; // 🔥 important

        for(int j = 0; j < coins. size(); j++){
            int take = 1 + solve(coins, amount - coins[j], dp);
            mini = min(mini, take);
        }

        return dp[amount] = mini;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, 1e9);
        dp[0] = 0;
        for(int i = 1; i < amount+1; i++){
            for(int j = 0; j < coins. size(); j++){
                if(coins[j] <= i){
                    int take = 1 + dp[i-coins[j]];
                    dp[i] = min(dp[i], take);
                }
            }
        }
        return dp[amount] == 1e9 ? -1 : dp[amount];
    }
};