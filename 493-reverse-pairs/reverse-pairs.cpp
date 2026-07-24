/* Sorted Container + Binary Search Approach
Maintain a sorted container of all elements seen so far. For each nums[j], use upper_bound(2 * nums[j]) to find the first element greater than 2 * nums[j] and count all elements after it, then insert nums[j] into the container in sorted order using lower_bound.

Time Complexity: O(n²) (binary search is O(log n) but insertion in a vector is O(n) due to shifting, repeated for n elements).
Space Complexity: O(n) for storing the sorted container.
*/


// class Solution {
// public:
//     int reversePairs(vector<int>& nums) {
//         int n = nums.size();
//         int cnt = 0;
//         vector<int> s;
//         s.push_back(nums[0]);

//         for(int j = 1; j < n; j++){
//             long long x = 2LL * nums[j];
//             auto it = upper_bound(s.begin(), s.end(), x);
//             cnt += s.end() - it;
//             auto pos = lower_bound(s.begin(), s.end(), nums[j]);
//             s.insert(pos, nums[j]);
//         }
//         return cnt;
//     }
// };




/* optimal:
merge Sort Approach

Recursively divide the array into two halves. Before merging two sorted halves, use two pointers to count all cross pairs (i, j) such that nums[i] > 2 * nums[j], then perform the normal merge operation to keep the array sorted.

Time Complexity: O(n log n) (each merge level does linear counting and merging, and there are log n levels).
Space Complexity: O(n) for the temporary array used during merging.
*/



class Solution {
public:
    int merge(vector<int>& nums, int l, int r){
        int cnt = 0;
        if(l == r){
            return cnt;
        }
        int m = l + (r-l)/2;
        cnt += merge(nums, l, m);
        cnt += merge(nums, m+1, r);
        int i = l, j = m+1;
        while(i <= m){
            while(j <= r && nums[i] > 2LL * nums[j]){
                j++;
            }
            cnt += (j - (m + 1));
            i++;
        }
        i = l; j = m+1;
        vector<int> temp;
        while(i <= m && j <= r){
            if(nums[i] <= nums[j]){
                temp.push_back(nums[i]);
                i++;
            }
            else{
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i <= m){
            temp.push_back(nums[i]);
            i++;
        }
        while(j <= r){
            temp.push_back(nums[j]);
            j++;
        }
        for(int k = l; k <= r; k++){
            nums[k] = temp[k - l];
        }
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return merge(nums, 0, n-1);
    }
};