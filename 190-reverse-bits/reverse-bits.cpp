class Solution {
public:
    int reverseBits(int n) {
        if(n == 0){
            return 0;
        }
        vector<int> v(32, 0);
        int ans = 0;
        int i = 31;
        while(n != 1){
            int x = n%2;
            v[i] = x;
            n = n/2;
            i--;
        }
        v[i] = 1;
        for(int i = 0; i < v.size(); i++){
            ans += v[i] * pow(2,i);
        }
        return ans;
    }
};