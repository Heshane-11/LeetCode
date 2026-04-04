class Solution {
public:
    int minDistance(string a, string b) {
        int n = a.size(), m = b.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        // base cases
        for(int i = 0; i <= n; i++) dp[i][0] = i;
        for(int j = 0; j <= m; j++) dp[0][j] = j;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {

                if(a[i-1] == b[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = 1 + min({
                        dp[i][j-1],   // insert
                        dp[i-1][j],   // delete
                        dp[i-1][j-1]  // replace
                    });
                }
            }
        }

        return dp[n][m];
    }
};