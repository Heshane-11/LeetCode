class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(); int n = obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1] == 1 || obstacleGrid[0][0] == 1){
            return 0;
        }

        vector<int> dp(n, 0);
        for(int j = 0; j < n; j++){
            if(obstacleGrid[0][j] == 0){
                dp[j] = 1;
            }
            else{
                break;
            }
        }
    
        for(int i = 1; i < m; i++){
            for(int j = 0; j < n; j++){
                if(obstacleGrid[i][j] == 1){
                    dp[j] = 0;
                }
                else if(j > 0){
                    dp[j] += dp[j-1];
                }
            }
        }
        
        return dp[n-1];
    }
};