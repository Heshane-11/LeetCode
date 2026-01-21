class Solution {
public:
int help(vector<int>& days, int n, vector<int>& costs, int i, vector<int>& dp){
    if(i >= n){
        return 0;
    }
    if(dp[i] != -1){
        return dp[i];
    }
        // 1-day pass
        int cost1 = costs[0] + help(days, n, costs, i + 1, dp);

        // 7-day pass
        int j = i;
        while(j < n && days[j] < days[i] + 7) j++;
        int cost7 = costs[1] + help(days, n, costs, j, dp);

        // 30-day pass
        j = i;
        while(j < n && days[j] < days[i] + 30) j++;
        int cost30 = costs[2] + help(days, n, costs, j, dp);

        dp[i] = min({cost1, cost7, cost30});
        return dp[i];

}
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        int n = days.size();
        vector<int> dp(n,-1);
        return help(days, n, costs, 0, dp);
    }
};