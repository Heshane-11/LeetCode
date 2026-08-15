class Solution {
public:
// solve(i) = LIS ki maximum length jo nums[i] par end hoti hai.
// Difference bas itna hai ki recursion mein hum i se pehle ke saare j check karte hain:
    // int solve(vector<int>& nums, int i) {
    //     int ans = 1;

    //     for(int j = 0; j < i; j++) {
    //         if(nums[j] < nums[i]) {
    //             ans = max(ans, 1 + solve(nums, j));
    //         }
    //     }

    //     return ans;
    // }
    int solve(vector<int>& nums, int i, int prev, vector<vector<int>>& dp){
        if(i >= nums.size()){
            return 0;
        }
        if(dp[i][prev+1] != -1){ // because index cant be negative
            return dp[i][prev+1];
        }
        int t = 0, n = 0;
        if(prev == -1 || nums[i] > nums[prev]){
            t = 1 + solve(nums, i+1, i, dp);
        }
        n = solve(nums, i+1, prev, dp);
        return dp[i][prev+1] = max(t, n);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return solve(nums, 0, -1, dp);
    }
};