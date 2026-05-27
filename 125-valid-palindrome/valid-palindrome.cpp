class Solution {
public:
    char low(char c){
        if(c >= 'A' && c <= 'Z'){
            return tolower(c);
        }
        return c;
    }
    bool isPalindrome(string s) {
        string ans = "";
        for(int i = 0; i < s.length(); i++){
            if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
                ans += low(s[i]);
            }
        }
        int i = 0, j = ans.length()-1;
        while(i < j){
            if(ans[i] != ans[j]){
                return false;
            }
            i++;
            j--; 
        }
        return true;
    }
};