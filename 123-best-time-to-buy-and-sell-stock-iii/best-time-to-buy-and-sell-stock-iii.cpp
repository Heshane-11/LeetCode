class Solution {
public:
    int solve(vector<int>& prices, int i, int buy, int cap, vector<vector<vector<int>>>& dp) {
        
        if(i == prices.size() || cap == 0) {
            return 0;
        }
        if(dp[i][buy][cap] != -1){
            return dp[i][buy][cap];
        }
        if(buy) {
            int take = -prices[i] + solve(prices, i + 1, 0, cap, dp);
            int notTake = solve(prices, i + 1, 1, cap, dp);

            return dp[i][buy][cap] = max(take, notTake);
        }
        else {
            int sell = prices[i] + solve(prices, i + 1, 1, cap - 1, dp);
            int notSell = solve(prices, i + 1, 0, cap, dp);

            return dp[i][buy][cap] = max(sell, notSell);
        }
    }

    int maxProfit(vector<int>& prices) {
        int m = prices.size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(prices, 0, 1, 2, dp);
    }
};