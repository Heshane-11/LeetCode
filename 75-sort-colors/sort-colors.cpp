// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         int zero = 0, one = 0, two = 0;
//         for (int n : nums) {
//             if (n == 0) zero++;
//             else if (n == 1) one++;
//             else two++;
//         }

//         for (int i = 0; i < nums.size(); ++i) {
//             if (zero > 0) {
//                 nums[i] = 0;
//                 zero--;
//             } else if (one > 0) {
//                 nums[i] = 1;
//                 one--;
//             } else {
//                 nums[i] = 2;
//                 two--;
//             }
//         }
//     }
// };





// 🧠 Idea

// 3 pointers:

// low → 0 ke liye  
// mid → current  
// high → 2 ke liye
// ⚡ Rules
// nums[mid] == 0 → swap(low, mid), low++, mid++
// nums[mid] == 1 → mid++
// nums[mid] == 2 → swap(mid, high), high--
// ✅ Code (1 pass)


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;

        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};


// ⚡ Complexity (optimal)
// Metric	Value
// Time	O(n) (single pass) 🔥
// Space	O(1)