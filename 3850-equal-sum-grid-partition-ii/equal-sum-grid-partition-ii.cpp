class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        long long total = 0;

        // frequency arrays
        vector<int> topFreq(100001, 0), bottomFreq(100001, 0);
        vector<int> leftFreq(100001, 0), rightFreq(100001, 0);

        // initialize total + bottom/right
        for (auto &row : grid) {
            for (int x : row) {
                total += x;
                bottomFreq[x]++;
                rightFreq[x]++;
            }
        }

        // ------------------ HORIZONTAL ------------------
        long long sumTop = 0;

        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n; j++) {
                int val = grid[i][j];
                sumTop += val;

                topFreq[val]++;
                bottomFreq[val]--;
            }

            long long sumBottom = total - sumTop;

            if (sumTop == sumBottom) return true;

            long long diff = abs(sumTop - sumBottom);

            if (diff <= 100000) {
                if (sumTop > sumBottom) {
                    // check top section
                    if (check(topFreq, grid, 0, i, 0, n - 1, diff)) return true;
                } else {
                    // check bottom section
                    if (check(bottomFreq, grid, i + 1, m - 1, 0, n - 1, diff)) return true;
                }
            }
        }

        // ------------------ VERTICAL ------------------
        long long sumLeft = 0;

        for (int j = 0; j < n - 1; j++) {
            for (int i = 0; i < m; i++) {
                int val = grid[i][j];
                sumLeft += val;

                leftFreq[val]++;
                rightFreq[val]--;
            }

            long long sumRight = total - sumLeft;

            if (sumLeft == sumRight) return true;

            long long diff = abs(sumLeft - sumRight);

            if (diff <= 100000) {
                if (sumLeft > sumRight) {
                    // check left section
                    if (check(leftFreq, grid, 0, m - 1, 0, j, diff)) return true;
                } else {
                    // check right section
                    if (check(rightFreq, grid, 0, m - 1, j + 1, n - 1, diff)) return true;
                }
            }
        }

        return false;
    }

    // 🔥 SAME helper (correct connectivity logic)
    bool check(vector<int>& freq, vector<vector<int>>& grid,
               int r1, int r2, int c1, int c2, long long diff) {

        int rows = r2 - r1 + 1;
        int cols = c2 - c1 + 1;

        // single cell → cannot remove
        if (rows * cols == 1) return false;

        // 1 row → remove only edges
        if (rows == 1) {
            return (grid[r1][c1] == diff || grid[r1][c2] == diff);
        }

        // 1 column → remove only edges
        if (cols == 1) {
            return (grid[r1][c1] == diff || grid[r2][c1] == diff);
        }

        // 2D grid → any occurrence works
        return freq[diff] > 0;
    }
};