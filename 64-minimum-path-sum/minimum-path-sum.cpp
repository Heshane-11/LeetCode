class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0){
                    dp[i][j] = grid[i][j];
                    continue;
                }
                int x1 = INT_MAX, x2 = INT_MAX;
                if(i > 0){
                    x1 = dp[i-1][j];
                }
                if(j > 0){
                    x2 = dp[i][j-1];
                }
                dp[i][j] = grid[i][j] + min(x1, x2);
            }
        }
        return dp[m-1][n-1];
    }
};