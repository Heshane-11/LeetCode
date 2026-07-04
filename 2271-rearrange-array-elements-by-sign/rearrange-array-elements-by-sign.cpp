class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> p;
        vector<int> n;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0){
                p.push_back(nums[i]);
            }
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < 0){
                n.push_back(nums[i]);
            }
        }
        for(int i = 0; i < nums.size(); i++){
            if(i % 2 == 0){
                nums[i] = p[i/2];
            }
            else{
                nums[i] = n[i/2];
            }
        }
        return nums;
    }
};