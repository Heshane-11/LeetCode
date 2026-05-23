class Solution {
public:
    bool palin(string& s, int i, int j, vector<vector<bool>>& dp){
        if(i > j){
            return true;
        }
        if(dp[i][j]){
            return true;
        }
        if(s[i] == s[j]){
            return dp[i][j] = palin(s, i+1, j-1, dp);
        }
        return dp[i][j] = false;
    }
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j  = i; j < n; j++){
                if(palin(s, i, j, dp)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};