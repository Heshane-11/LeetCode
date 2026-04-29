class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp){
        int m = grid.size(), n = grid[0].size();

        // base case
        if(i == m-1 && j == n-1){
            return grid[i][j];
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int x1 = INT_MAX, x2 = INT_MAX;

        if(i < m-1){
            x1 = solve(grid, i+1, j, dp);
        }

        if(j < n-1){
            x2 = solve(grid, i, j+1, dp);
        }

        return dp[i][j] = grid[i][j] + min(x1, x2);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(grid, 0, 0, dp);
    }
};