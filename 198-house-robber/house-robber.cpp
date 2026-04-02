class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev = 0;
        int curr = nums[0];
        for(int i = 2; i <= n; i++){
            int take = nums[i-1] + prev;
            int skip = curr;
            prev = curr;
            curr = max(take, skip);
        }
        return curr;
    }
};