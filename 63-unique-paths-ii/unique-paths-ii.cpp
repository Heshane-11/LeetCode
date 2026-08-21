class Solution {
public:
    int solve(vector<vector<int>>& obstacleGrid, int i, int j, vector<vector<int>>& dp){
        int m = obstacleGrid.size(); int n = obstacleGrid[0].size();
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
            if(nx >= 0 && nx < m && ny >= 0 && ny < n && obstacleGrid[nx][ny] == 0){
                take += solve(obstacleGrid, nx, ny, dp);
            }
        }
        return dp[i][j] = take;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0] == 1){
            return 0;
        }
        int m = obstacleGrid.size(); int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(obstacleGrid, 0, 0, dp);
    }
};