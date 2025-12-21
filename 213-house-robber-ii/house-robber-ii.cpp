class Solution {
public:

    int help(int i, vector<int>& nums, vector<int>&dp){
        if(i >= nums.size()){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int inc = nums[i] + help(i+2, nums, dp);
        int exc = help(i+1, nums, dp);
        return dp[i] = max(inc,exc);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<int> nums1(nums.begin(), nums.end() - 1);
        vector<int> nums2(nums.begin() + 1, nums.end());

        vector<int> dp1(nums1.size(), -1);
        vector<int> dp2(nums2.size(), -1);

        int a = help(0, nums1, dp1);
        int b = help(0, nums2, dp2);
        return max(a,b);
    }
};