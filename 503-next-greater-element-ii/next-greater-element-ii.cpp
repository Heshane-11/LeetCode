class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        int n = nums.size();

        vector<int> ans(n, -1);

        stack<int> st;   // indices

        for(int i = 0; i < 2*n; i++) {

            while(!st.empty() && nums[st.top()] < nums[i % n]) {
                ans[st.top()] = nums[i % n];
                st.pop();
            }
            if(i < n) {
                st.push(i);
            }
        }

        return ans;
    }
};

/*
traverse the array twice using i % n to simulate circular traversal. Whenever the current element is greater than the element at the index on the top of the stack, I assign it as the next greater element. Indices are pushed only during the first pass to avoid duplicates.
*/