class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        bool x = false;
        for(int i = 1; i < n; i++){
            if(nums[i] > nums[i-1]){
                x = true;
                break;
            }
        }
        if(x == false){
            sort(nums.begin(), nums.end());
            return;
        }
        int i = n-1;
        while(i > 0){
            if(nums[i] > nums[i-1]){
                int j = i;
                int x;
                while(j < n){
                    if(nums[j] > nums[i-1]){
                        x = j;
                        j++;
                    }
                    else{
                        break;
                    }
                }
                swap(nums[i-1], nums[x]);
                sort(nums.begin() + i, nums.end());
                break;
            }
            else{
                i--;
            }
        }
    }
};