class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        unordered_map<string, int> m;
        for(int i = 0; i < words.size(); i++){
            string s = "";
            if(words[i][k-1]){
                for(int j = 0; j < k; j++){
                    s += words[i][j];
                }
                m[s]++;
                }
        }
        int cnt = 0;
        for(auto it : m){
            if(it.second > 1){
                cnt++;
            }
        }
        return cnt;
    }
};