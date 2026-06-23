class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted(n);
        
        for(int i = 0; i < n; i++){
            int idx = 0;
            for(int j = i; j < n; j++){
                sorted[idx] = nums[j];
                idx++;
            }
            for(int j = 0; j < i; j++){
                sorted[idx] = nums[j];
                idx++;
            }
            bool tell = false;
            for(int j = 0; j < n-1; j++){
                if(sorted[j] > sorted[j+1]){
                    tell = true;
                }
            }
            if(!tell){
                return true;
            }
        }
        return false;
    }
};