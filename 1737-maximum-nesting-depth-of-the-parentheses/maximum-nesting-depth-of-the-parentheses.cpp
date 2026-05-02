// class Solution {
// public:
//     int maxDepth(string s) {
//         stack<char> st;
//         int ans = 0;

//         for(int i = 0; i < s.size(); i++){
//             if(s[i] == '('){
//                 st.push(s[i]);
//                 ans = max(ans, (int)st.size()); // update depth
//             }
//             else if(s[i] == ')'){
//                 if(!st.empty()) st.pop();
//             }
//         }

//         return ans;
//     }
// };



class Solution {
public:
    int maxDepth(string s) {
        int depth = 0;
        int ans = 0;

        for(char c : s){
            if(c == '('){
                depth++;
                ans = max(ans, depth);
            }
            else if(c == ')'){
                depth--;
            }
        }

        return ans;
    }
};