class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        const int INF = 1e9;

        int r = grid.size();
        int c = grid[0].size();
        int N = r * c;

        auto idx = [&](int i, int j) {
            return i * c + j;
        };

        // find maximum value in grid
        int maxVal = 0;
        for (auto &row : grid)
            for (int x : row)
                maxVal = max(maxVal, x);

        // group cells by value
        vector<vector<int>> byValue(maxVal + 1);
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                byValue[grid[i][j]].push_back(idx(i, j));
            }
        }

        // dp[t][pos] = min cost to reach pos using t teleports
        vector<vector<int>> dp(2, vector<int>(N, INF));

        // base DP (0 teleport)
        dp[0][0] = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                int pos = idx(i, j);
                if (i > 0)
                    dp[0][pos] = min(dp[0][pos], dp[0][pos - c] + grid[i][j]);
                if (j > 0)
                    dp[0][pos] = min(dp[0][pos], dp[0][pos - 1] + grid[i][j]);
            }
        }

        vector<int> suffixMin(maxVal + 1);

        // DP for teleports
        for (int t = 1; t <= k; t++) {
            int curr = t & 1;
            int prev = (t - 1) & 1;

            fill(dp[curr].begin(), dp[curr].end(), INF);

            // build suffixMin
            int best = INF;
            for (int val = maxVal; val >= 0; val--) {
                for (int pos : byValue[val]) {
                    best = min(best, dp[prev][pos]);
                }
                suffixMin[val] = best;
            }

            // update dp
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    int pos = idx(i, j);
                    int x = grid[i][j];

                    int ans = min(dp[prev][pos], suffixMin[x]);

                    if (i > 0)
                        ans = min(ans, dp[curr][pos - c] + x);
                    if (j > 0)
                        ans = min(ans, dp[curr][pos - 1] + x);

                    dp[curr][pos] = ans;
                }
            }
        }

        return dp[k & 1][N - 1];
    }
};
