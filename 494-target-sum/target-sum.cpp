class Solution {
public:

    void solve(int idx, vector<int>& nums, int sum, int &cnt, int &target){
        if(idx == nums.size()){
            if(sum == target){
                cnt++;
            }
            return;
        }
            solve(idx+1, nums, sum+nums[idx], cnt, target);
            solve(idx+1, nums, sum-nums[idx], cnt, target);
        return;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int cnt = 0;
        solve(0, nums, 0, cnt, target);
        return cnt;
    }
};