class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int a = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                ans = max(ans, i-a);
                a = i+1;
            }
        }
        if(nums[n-1] == 1){
            ans = max(ans, n-a);
        }
        return ans;
    }
};