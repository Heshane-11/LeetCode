class Solution {
public:
    int solve(string word1, string word2, int i, int j, vector<vector<int>>& dp){
        if(j == word2.size() || i == word1.size()){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(word1[i] == word2[j]){
            return dp[i][j] = 1 + solve(word1, word2, i+1, j+1, dp);
        }

        return dp[i][j] = max(
            solve(word1, word2, i+1, j, dp),
            solve(word1, word2, i, j+1, dp)
        );
    }

    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        int x = solve(word1, word2, 0, 0, dp);
        return m + n - 2*x;

    }
};