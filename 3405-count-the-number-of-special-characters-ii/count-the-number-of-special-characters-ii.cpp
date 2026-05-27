class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, pair<bool, int>> m;
        for(int i = 0; i < 26; i++){
            m['A' + i] = {false, 0};
        }
        for(int i = 0; i < word.size(); i++){
            if(word[i] >= 'a' && word[i] <= 'z'){
                if(m.find(toupper(word[i])) == m.end()){
                    continue;
                }
                if(m[toupper(word[i])].second == 1){
                    m.erase(toupper(word[i]));
                }
                else{
                    m[toupper(word[i])].first = true;
                }
            }
            else if(word[i] >= 'A' && word[i] <= 'Z'){
                if(m.find(word[i]) == m.end()){
                    continue;
                }
                if(m[word[i]].first == true){
                    m[word[i]].second = 1;
                }
                else{
                    m.erase(word[i]);
                }
            }
        }
        int cnt = 0;
        for(auto i : m){
            if(i.second.second == 1){
                cnt++;
            }
        }
        return cnt;
    }
};