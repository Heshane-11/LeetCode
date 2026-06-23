// /*
// appr 1: har ek shift ko check kro k voh sorted array form krti h ya nahi.
// */



// class Solution {
// public:
//     bool check(vector<int>& nums) {
//         int n = nums.size();
//         //vector that keeps the values after every shift
//         vector<int> sorted(n);
        
//         for(int i = 0; i < n; i++){
//             int idx = 0;
//             for(int j = i; j < n; j++){
//                 sorted[idx] = nums[j];
//                 idx++;
//             }
//             for(int j = 0; j < i; j++){
//                 sorted[idx] = nums[j];
//                 idx++;
//             }
//             bool tell = false;
//             for(int j = 0; j < n-1; j++){
//                 if(sorted[j] > sorted[j+1]){
//                     tell = true;
//                 }
//             }
//             if(!tell){
//                 return true;
//             }
//         }
//         return false;
//     }
// };
// sc = O(n), TC = O(n2)

/*
appr 2: sabse pehle nums array ko sort krke ek dusre array mein daldia iss kya hua k jo uska ith shifted array hoga uske jth element ki value hogi nums[(i+j) % n]
*/



// class Solution {
// public:
//     bool check(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> sorted(n);
//         for(int i = 0; i < n; i++){
//             sorted[i] = nums[i];
//         }
//         sort(sorted.begin(), sorted.end());
        
//         for(int i = 0; i < n; i++){
//             bool is = true;
//             for(int j = 0; j < n; j++){
//                 if(sorted[j] != nums[(i+j) % n]){
//                     is = false;
//                 }
//             }
//             if(is){
//                 return true;
//             }
//         }
//         return false;
//     }
// };
// sc = O(n), TC = O(n2)[but n2 se thodi kam h]




/*
optimal appr: Start from the minimum element and verify that all elements are in ascending order in circular traversal.
*/


// class Solution {
// public:
//     bool check(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> sorted(n);
//         int mini = 100, idx = 0;
//         for(int i = 0; i < n; i++){
//             if(i>0 && nums[i] == mini && nums[i-1] == mini){
//                 continue;
//             }
//             mini = min(mini, nums[i]);
//             if(mini == nums[i]){
//                 idx = i;
//             }
//         }
        
//         for(int i = idx; i < idx + n-1; i++){
//             if(nums[i%n] > nums[(i+1)%n]){
//                 return false;
//             }
//         }
//         return true;
//     }
// };

// sc = O(1), TC = O(n)



// ek aur optimal approach hai:: finding peaks in our array: if 1 se jada peak h matlb array is not sort.

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted(n);
        int peak;
        for(int i = 0; i < n; i++){
            if(nums[i] > nums[(i+1)%n]){
                peak++;
                if(peak > 1){
                    return false;
                }
            }
        }
        return true;
    }
};

// sc = O(1), TC = O(n)