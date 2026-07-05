class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int cnt = 1;
        int maxi = 1;
        sort(nums.begin(), nums.end());
        for(int i = nums.size()-1; i > 0; i--){
            if(nums[i] == nums[i-1]){
                nums.erase(nums.begin() + i);
            }
        }
        if(nums.empty()){
            return 0;
        }
        if(nums.size() == 1){
            return 1;
        }
        for(int i = 0; i < nums.size()-1; i++){
            
            if(abs(nums[i] - nums[i+1]) == 1){
                cnt++;
                maxi = max(maxi, cnt);
            }
            else{
                cnt = 1;
            }
        }
        return maxi;
    }
};