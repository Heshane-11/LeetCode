class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> m(nums.begin(), nums.end());
       
        int maxi = 0;
        
        for(auto x : m){
            if(m.find(x-1) == m.end()){
                int cnt = 1;
                int sp = x;
                while(m.find(sp+1) != m.end()){
                    cnt++;
                    sp++;
                }
                maxi = max(cnt, maxi);
            }
        }
        return maxi;
    }
};