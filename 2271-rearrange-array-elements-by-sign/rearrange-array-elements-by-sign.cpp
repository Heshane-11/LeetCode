/*brute force:
make two diff arrays of pos and neg numbers
merge them in nums acc. to the condition given
*/


/*

Optimal Approach (O(n) Time, O(n) Space)

Observation:

Result array mein positive numbers even indices par aayenge: 0, 2, 4, ...
Negative numbers odd indices par aayenge: 1, 3, 5, ...
Order preserve karna hai.
Algorithm (2 lines)
Create an answer array of size n and maintain two pointers: pos = 0 and neg = 1.
Traverse nums; place positive numbers at ans[pos] and negative numbers at ans[neg], then increment the respective pointer by 2.

*/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n);

        int pos = 0;
        int neg = 1;

        for(int i = 0; i < n; i++) {
            if(nums[i] > 0) {
                ans[pos] = nums[i];
                pos += 2;
            }
            else {
                ans[neg] = nums[i];
                neg += 2;
            }
        }

        return ans;
    }
};