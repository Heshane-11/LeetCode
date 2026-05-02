class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int ans = 0;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                st.push(s[i]);
                ans = max(ans, (int)st.size()); // update depth
            }
            else if(s[i] == ')'){
                if(!st.empty()) st.pop();
            }
        }

        return ans;
    }
};