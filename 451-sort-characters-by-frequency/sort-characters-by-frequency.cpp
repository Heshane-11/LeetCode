class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> m;

        for(char c : s) m[c]++;

        vector<string> bucket(s.size() + 1);

        for(auto &p : m){
            bucket[p.second] += string(p.second, p.first);
        }

        string ans = "";

        for(int i = s.size(); i >= 0; i--){
            ans += bucket[i];
        }

        return ans;
    }
};