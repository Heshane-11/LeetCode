class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int ans = INT_MAX;
        for(int s = l; s <= r; s++){
            int sum = 0;
            for(int i = 0; i < s; i++){
                sum += nums[i];
            }
            if(sum > 0){
                ans = min(ans, sum);
            }
            
            for(int i = 1; i < n-s+1 ; i++){
                sum = sum + nums[i+s-1] - nums[i-1];
                if(sum > 0){
                    ans = min(ans, sum);
                }
            }
        }
        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};