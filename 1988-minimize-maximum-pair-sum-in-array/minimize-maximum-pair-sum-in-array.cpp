class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0, j = n-1;
        vector<int> v;
        while(i < j){
            v.push_back(nums[i] + nums[j]);
            i++;
            j--;
        }
        int maxi = INT_MIN;
        for(int i = 0; i < v.size(); i++){
            maxi = max(maxi, v[i]);
        }
        return maxi;
    }
};