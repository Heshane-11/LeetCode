class Solution {
public:
static const int MOD = 1e9 + 7;

    void states(vector<string>& colstate, string s, int m, int l, vector<char> &colors, char prev){
        if(l == m){
            colstate.push_back(s);
            return;
        }
        for(int i = 0; i < 3; i++){
            if(colors[i] != prev){
                states(colstate, s+colors[i], m, l+1, colors, colors[i]);
            }
        }
        return;
    }

    int solve(vector<string>& colstate, int previdx, int remcols, int m, vector<vector<int>>& dp){
        if (remcols == 0) return 1;
        if (dp[previdx][remcols] != -1)
            return dp[previdx][remcols];

        int ans = 0;
        string prevstate = colstate[previdx];
        for(int j = 0; j < colstate.size(); j++){
            string currstate = colstate[j];
            if(currstate == prevstate){
                continue;
            }
            bool valid = true;
            for(int k = 0; k < m; k++){
                if(prevstate[k] == currstate[k]){
                    valid = false;
                    break;
                }
            }
            if(valid){
                ans = (ans + solve(colstate, j, remcols-1, m, dp)) % MOD;
            }
        }
        return dp[previdx][remcols] = ans;
    }

    int colorTheGrid(int m, int n) {
        vector<string> colstate;
        vector<char> colors = {'R','B','G'};
        states(colstate, "", m, 0, colors, '#');
        vector<vector<int>> dp(colstate.size(), vector<int>(n, -1));
        int ans = 0;

        for(int i = 0; i < colstate.size(); i++){
            ans = (ans + solve(colstate, i, n-1, m, dp)) % MOD;
        }
        return ans % MOD;
    }
};