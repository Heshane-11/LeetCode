class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        int targetK = k - 1;

        // Coordinate compression
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
        int m = sorted.size();

        vector<long long> bitSum(m + 1, 0);
        vector<int> bitCount(m + 1, 0);

        int maxPow2 = 1;
        while ((maxPow2 << 1) <= m) maxPow2 <<= 1;

        long long minExtra = LLONG_MAX;

        for (int i = 1; i < n; i++) {
            int rank = lower_bound(sorted.begin(), sorted.end(), nums[i]) - sorted.begin() + 1;
            update(rank, nums[i], 1, bitSum, bitCount, m);

            if (i > dist + 1) {
                int oldRank = lower_bound(sorted.begin(), sorted.end(),
                                          nums[i - dist - 1]) - sorted.begin() + 1;
                update(oldRank, -nums[i - dist - 1], -1, bitSum, bitCount, m);
            }

            if (i >= targetK) {
                minExtra = min(minExtra,
                               query(targetK, bitSum, bitCount, sorted, m, maxPow2));
            }
        }

        return nums[0] + minExtra;
    }

private:
    void update(int idx, int val, int cnt,
                vector<long long>& bSum,
                vector<int>& bCnt,
                int m) {
        while (idx <= m) {
            bSum[idx] += val;
            bCnt[idx] += cnt;
            idx += idx & -idx;
        }
    }

    long long query(int k,
                    vector<long long>& bSum,
                    vector<int>& bCnt,
                    vector<int>& sorted,
                    int m,
                    int maxPow2) {
        int idx = 0, curCnt = 0;
        long long curSum = 0;

        for (int step = maxPow2; step > 0; step >>= 1) {
            if (idx + step <= m && curCnt + bCnt[idx + step] < k) {
                idx += step;
                curCnt += bCnt[idx];
                curSum += bSum[idx];
            }
        }

        if (curCnt < k) {
            curSum += 1LL * (k - curCnt) * sorted[idx];
        }
        return curSum;
    }
};
