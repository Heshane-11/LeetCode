class Solution {
public:
    int solve(int m, int n, int i, int j, vector<vector<int>>& dp){
        if(i == m-1 && j == n-1){
            return 1;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int take = 0;
        vector<int> dirx = {0, 1};
        vector<int> diry = {1, 0};
        for(int a = 0; a < 2; a++){
            int nx = i + dirx[a];
            int ny = j + diry[a];
            if(nx >= 0 && ny >= 0 && nx < m && ny < n){
                take += solve(m, n, nx, ny, dp);
            }
        }
        return dp[i][j] = take;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m, n, 0, 0, dp);
    }
};