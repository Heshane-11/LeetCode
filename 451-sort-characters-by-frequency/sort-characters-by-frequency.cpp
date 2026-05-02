class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> m;
        for(int i = 0; i < s.size(); i++){
            m[s[i]]++;
        }
        priority_queue<pair<int, char>> pq;
        for(auto p : m){
            pq.push({p.second, p.first});
        }
        string ans = "";
        while(!pq.empty()){
            auto[x,y] = pq.top();
            pq.pop();
            while(x>0){
                ans += y;
                x--;
            }
        }
        return ans;
    }
};