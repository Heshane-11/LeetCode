class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        string ans = "";
        for(int l = 1; l <= n; l++){
            for(int i = 0; i < n-l+1; i++){
                int j = i+l-1;
                if(i == j){
                    dp[i][j] = true;
                }
                else if(j-i == 1){
                    dp[i][j] = (s[i] == s[j]);
                }
                else{
                    dp[i][j] = (s[i] == s[j] && dp[i+1][j-1]);
                }
                if(dp[i][j]){
                    ans = s.substr(i, l);
                }
            }
        }
        return ans;
    }
};