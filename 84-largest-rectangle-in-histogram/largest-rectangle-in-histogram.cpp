class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> nsl(n), nsr(n);
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty()){
                nsl[i] = -1;
            }
            else{
                nsl[i] = st.top();
            }
            st.push(i);
        }
        // NSR (Next Smaller)
        while(!st.empty()) st.pop();

        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if(st.empty())
                nsr[i] = n;
            else
                nsr[i] = st.top();

            st.push(i);
        }

        int maxi = 0;
        for(int i = 0; i < n; i++){
            int w = nsr[i] - nsl[i] - 1;
            int area = heights[i] * w;
            maxi = max(maxi, area);
        }
        return maxi;
    }
};