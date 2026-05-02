class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        if(strs.size() == 1){
            return ans += strs[0];
        }
        
        for(int j = 0; j < strs[0].size(); j++){
            string str = "";
            for(int i = 0; i < strs.size()-1; i++){
                if(strs[i][j] != strs[i+1][j]){
                    return ans;
                }
                str = strs[i][j];
            }
            ans += str;
        }
        return ans;
    }
};