class Solution {
public:
    string largestOddNumber(string num) {
        string s = "";
        string ans = "";
        for(int i = 0; i < num.size(); i++){
            s += num[i];
            if((num[i] - '0') % 2 != 0){
                ans += s;
                s = "";
            }
        }
        return ans;
    }
};