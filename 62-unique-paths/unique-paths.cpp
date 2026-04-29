class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int j = 0; j < n; j++){
            dp[0][j] = 1;
        }
        for(int i = 0; i < m; i++){
            dp[i][0] = 1;
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                int x1 = 0, x2 = 0;
                if(i > 0){
                    x1 = dp[i-1][j];
                }
                if(j > 0){
                    x2 = dp[i][j-1];
                }
                dp[i][j] = x1 + x2;
            }
        }
        return dp[m-1][n-1];
    }
};