class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        if(n < 2){
            return 0;
        }
        int ans = 0;
        for(int i = 0; i < n-1; i++){
            int even = 0;
            int odd = 0;
            unordered_set<int> m;
            if(nums[i] % 2 == 0){
                even++;
            }
            else{
                odd++;
            }
            m.insert(nums[i]);
            for(int j = i+1; j < n; j++){
                if (m.find(nums[j]) == m.end()) {
                    if(nums[j] % 2 == 0){
                        even++;
                    }
                    else{
                        odd++;
                    }
                    m.insert(nums[j]);
                }  
                if(odd == even){
                    ans = max(ans, j-i+1);
                    if(ans == n){
                        return ans;
                    }
                }
            }
        }
        return ans;
    }
};
