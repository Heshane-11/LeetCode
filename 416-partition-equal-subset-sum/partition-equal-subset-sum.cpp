class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
        if(sum % 2 != 0){
            return false;
        }
        int target = sum/2;
        vector<bool> dp(target + 1, false);
        
        dp[0] = true;  // base case

        if(nums[0] <= target){
            dp[nums[0]] = true;
        }

        for(int i = 1; i < n; i++){
            for(int t = target; t >= 0; t--){  // 🔥 right → left
                bool notTake = dp[t];

                bool take = false;
                if(nums[i] <= t){
                    take = dp[t - nums[i]];
                }

                dp[t] = take || notTake;
            }
        }

        return dp[target];
    }
};