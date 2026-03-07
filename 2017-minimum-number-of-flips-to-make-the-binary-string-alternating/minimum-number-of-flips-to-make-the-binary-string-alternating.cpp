class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        string t = s + s;

        int ans = INT_MAX;
        int cnt1 = 0, cnt2 = 0;

        for(int i = 0; i < 2*n; i++){
            
            if(t[i] != (i % 2 == 0 ? '0' : '1'))
                cnt1++;

            if(t[i] != (i % 2 == 0 ? '1' : '0'))
                cnt2++;

            if(i >= n){
                if(t[i-n] != ((i-n) % 2 == 0 ? '0' : '1'))
                    cnt1--;

                if(t[i-n] != ((i-n) % 2 == 0 ? '1' : '0'))
                    cnt2--;
            }

            if(i >= n-1){
                ans = min(ans, min(cnt1, cnt2));
            }
        }

        return ans;
    }
};