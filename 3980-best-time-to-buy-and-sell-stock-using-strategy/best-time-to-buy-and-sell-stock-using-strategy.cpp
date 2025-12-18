class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = strategy.size();
        long long base = 0;
        for(int i = 0; i < n; i++) base += 1LL * prices[i] * strategy[i];
        vector<long long> pre1(n+1), pre2(n+1);
        for(int i = 0; i < n; i++){
            pre1[i+1] = pre1[i] + -1LL * strategy[i] * prices[i];
            pre2[i+1] = pre2[i] + (1LL - strategy[i]) * prices[i];
        }
        long long ans = base;
        int h = k/2;
        for(int i = 0; i + k <= n; i++){
            long long x = pre1[i+h] - pre1[i];
            long long y = pre2[i+k] - pre2[i+h];
            ans = max(ans, base + x + y);
        }
        return ans;
    }
};
