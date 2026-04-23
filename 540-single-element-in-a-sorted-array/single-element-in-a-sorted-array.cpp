class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s = 0, e = nums.size() - 1;

        while (s < e) {
            int mid = s + (e - s) / 2;

            // make mid even
            if (mid % 2 == 1) mid--;

            if (nums[mid] == nums[mid + 1]) {
                s = mid + 2;  // move right
            } else {
                e = mid;      // move left
            }
        }
        return nums[s];
    }
};