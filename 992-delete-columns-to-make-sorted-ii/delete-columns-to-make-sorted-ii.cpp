class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs.size();
        int n = strs[0].size();
        vector<bool> v(m, true);
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            bool bad = false;
            for (int j = 0; j < m - 1; j++) {
                if (v[j] && strs[j+1][i] < strs[j][i]) {
                    bad = true;
                    cnt++;
                    break;
                }
            }
            if (!bad) {
                for (int j = 0; j < m - 1; j++) {
                    if (strs[j+1][i] > strs[j][i]) {
                        v[j] = false;
                    }
                }
            }
        }
        return cnt;
    }
};
