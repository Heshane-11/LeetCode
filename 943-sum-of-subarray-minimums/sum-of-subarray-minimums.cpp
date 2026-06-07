/*
NSL + NSR (Optimal)

Instead of finding minimum of every subarray, find:

For how many subarrays is arr[i] the minimum?

For each element:

left = distance to Previous Smaller Element (NSL)
right = distance to Next Smaller Element (NSR)

Then contribution:

arr[i] * left * right

because:

left choices for starting point
×
right choices for ending point

gives total subarrays where arr[i] is the minimum.

Answer:

ans += arr[i] * left * right;
NSL

Find Previous Smaller Element index.

Use increasing stack.

while(!st.empty() && arr[st.top()] > arr[i])
    st.pop();
NSR

Find Next Smaller Element index.

Traverse from right.

while(!st.empty() && arr[st.top()] >= arr[i])
    st.pop();

Notice:

NSL : >
NSR : >=
This handles duplicates correctly.

Complexity
Approach	TC	SC
Brute Force	O(n²)	O(1)
NSL + NSR (Monotonic Stack)	O(n)	O(n)

*/

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int MOD = 1e9 + 7;

        vector<int> nsl(n), nsr(n);
        stack<int> st;

        // NSL (Previous Smaller)

        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            if(st.empty())
                nsl[i] = -1;
            else
                nsl[i] = st.top();

            st.push(i);
        }

        // NSR (Next Smaller)
        while(!st.empty()) st.pop();

        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if(st.empty())
                nsr[i] = n;
            else
                nsr[i] = st.top();

            st.push(i);
        }

        long long ans = 0;

        for(int i = 0; i < n; i++) {
            long long left = i - nsl[i];
            long long right = nsr[i] - i;

            ans = (ans + (1LL * arr[i] * left % MOD) * right % MOD) % MOD;
        }

        return ans;
    }
};