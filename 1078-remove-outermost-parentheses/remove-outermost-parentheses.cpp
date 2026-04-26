class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<int> st;
        string ans = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                if(!st.empty()){
                    ans += s[i];
                }
                st.push(s[i]);
            }
            else if(st.top() == '('){
                st.pop();
                if(!st.empty()){
                    ans += s[i];
                }
            }
            else{

            }
        }
        return ans;
    }
};