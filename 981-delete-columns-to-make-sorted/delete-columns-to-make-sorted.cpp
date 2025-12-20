class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int x = strs[0].size();
        int cnt = 0;
        for(int i = 0; i < x; i++){
            for(int j = 0; j < strs.size()-1; j++){
                if(strs[j+1][i]-'a' < strs[j][i]-'a'){
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};