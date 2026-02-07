class Solution {
public:
    int minimumDeletions(string s) {
        stack<char>st;
        int cnt = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'b'){
                st.push(s[i]);
            }
            else if(!st.empty() && st.top() == 'b'){
                st.pop();
                cnt++;
            }
        }
        return cnt;
    }
};