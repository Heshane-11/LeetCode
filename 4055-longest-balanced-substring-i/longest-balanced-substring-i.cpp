class Solution {
public:
bool allSame(unordered_map<int,int>& mp) {
    if (mp.empty()) return true; 

    int val = mp.begin()->second; 

    for (auto& it : mp) {
        if (it.second != val)
            return false;
    }
    return true;
}

    int longestBalanced(string s) {
        int ans = 0;
        int n = s.length();
        if(n == 1){
            return 1;
        }
        for(int i = 0; i < n-1; i++){
            unordered_map<int, int> mp;
            mp[s[i]]++;
            for(int j = i+1; j < n; j++){
                mp[s[j]]++;
                if(allSame(mp)){
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