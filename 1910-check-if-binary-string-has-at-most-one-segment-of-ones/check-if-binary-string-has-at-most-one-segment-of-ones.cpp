class Solution {
public:
    bool checkOnesSegment(string s) {
        bool x = true;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '0'){
                x = false;
            }
            else if(!x){
                return false;
            }
        }
        return true;
    }
};