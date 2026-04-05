/*🏆 Optimal Solution (Two Pointer from Back)

👉 Trick: End se fill karo (not from front)

🧠 Why from back?
nums1 ke end mein already space hai (0,0,0)
Agar front se merge karoge → shifting lagegi ❌
End se karoge → direct placement ✅
⚡ Idea

3 pointers lo:

i → nums1 ke last valid element (m-1)
j → nums2 ke last element (n-1)
k → nums1 ka last index (m+n-1)

👉 Compare karo:

jo bada hai → usko k pe daalo
pointer move karo
✅ Code (clean & optimal)
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while(i >= 0 && j >= 0){
            if(nums1[i] > nums2[j]){
                nums1[k--] = nums1[i--];
            }
            else{
                nums1[k--] = nums2[j--];
            }
        }

        // agar nums2 ke elements bache ho
        while(j >= 0){
            nums1[k--] = nums2[j--];
        }
    }
};
/*
🔑 Key Points
✅ No extra space
✅ In-place merge
✅ No shifting
⏱️ Complexity
Time: O(m + n) ✅
Space: O(1) ✅
*/