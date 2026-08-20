class Solution {
public:
    int solve(vector<int>& nums, int target, int sum, int i, int &totalsum){
        if(i == nums.size()){
            return (2 * sum - totalsum == target);
        }

        if(i >= nums.size()){
            return 0;
        }

        int take = solve(nums, target, sum+nums[i], i+1, totalsum);
        int notake = solve(nums, target, sum, i+1, totalsum);

        return take+notake;

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalsum = accumulate(nums.begin(), nums.end(), 0);
        return solve(nums, target, 0, 0, totalsum);
    }
};