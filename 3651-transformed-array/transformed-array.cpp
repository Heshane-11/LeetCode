class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n);
        for(int i = 0; i < n; i++){
            int x = nums[i] + i;
            if(x < 0){
                while(x < 0){
                    x += n;
                }
                v[i] = nums[(x+n) % n];
            }
            else{
                v[i] = nums[(x) % n];
            } 
        }
        return v;
    }
};