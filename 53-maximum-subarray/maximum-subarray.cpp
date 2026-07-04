/*
### 1. Brute Force — O(n³), O(1)

Generate all possible subarrays and calculate the sum of each subarray separately.
Keep track of the maximum sum encountered.

---

### 2. Better (Running Sum) — O(n²), O(1)

Fix a starting index and extend the subarray one element at a time while maintaining the running sum.
Update the maximum sum after each extension.

---

### 3. Optimal (Kadane's Algorithm) — O(n), O(1)

Maintain a running sum; if it becomes negative, reset it to 0 because it can only decrease future sums.
At every step, update the maximum sum using the current running sum.

---

### Interview Summary

| Approach             | Time  | Space |
| -------------------- | ----- | ----- |
| Brute Force          | O(n³) | O(1)  |
| Better (Running Sum) | O(n²) | O(1)  |
| Kadane's Algorithm   | O(n)  | O(1)  |

*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            maxi = max(maxi, sum);
            if(sum < 0){
                sum = 0;
            }
        }
        return maxi;
    }
};

// class Solution {
// public:
//     int help(vector<int>& nums, int i, int sum, int& maxi) {
//         if (i == nums.size()) return maxi;
//         sum = max(nums[i], sum + nums[i]);
//         maxi = max(maxi, sum);
//         return help(nums, i + 1, sum, maxi);
//     }

//     int maxSubArray(vector<int>& nums) {
//         int maxi = nums[0];
//         return help(nums, 0, 0, maxi);
//     }
// };
