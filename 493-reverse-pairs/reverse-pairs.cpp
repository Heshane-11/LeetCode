class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        vector<int> s;
        s.push_back(nums[0]);

        for(int j = 1; j < n; j++){
            long long x = 2LL * nums[j];
            auto it = upper_bound(s.begin(), s.end(), x);
            cnt += s.end() - it;
            auto pos = lower_bound(s.begin(), s.end(), nums[j]);
            s.insert(pos, nums[j]);
        }
        return cnt;
    }
};