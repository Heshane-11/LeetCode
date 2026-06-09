class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        string st;
        for(int i = 0; i < num.size(); i++){
            while(!st.empty() && st.back() > num[i] && k > 0){
                k--;
                st.pop_back();
            }
            st.push_back(num[i]);
        }
        while(k > 0 && !st.empty()) {
            st.pop_back();
            k--;
        }
        int i = 0;
        while(i < st.size() && st[i] == '0')
            i++;

        string ans = st.substr(i);

        return ans.empty() ? "0" : ans;
    }
};