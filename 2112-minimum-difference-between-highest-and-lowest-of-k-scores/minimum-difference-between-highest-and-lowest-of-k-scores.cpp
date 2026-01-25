class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(nums.size() == 1){
            return 0;
        }
        sort(nums.begin(), nums.end());
        int mini = abs(nums[k-1]-nums[0]);
        for(int i = k; i < nums.size(); i++){
            int dif = abs(nums[i-k +1] - nums[i]);
            mini = min(mini, dif);
        }
        return mini;
    }
};