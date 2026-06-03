// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         int i = 0, j = 0;
//         vector<int> ans(nums1.size(), -1);
//         while(i < nums1.size()){
//             if(j >= nums2.size()){
//                 i++;
//                 j = 0;
//                 continue;
//             }
//             if(nums1[i] == nums2[j]){
//                 if(j != nums2.size()-1){
//                     for(int k = j+1; k < nums2.size(); k++){
//                         if(nums2[k] > nums2[j]){
//                             ans[i] = nums2[k];
//                             break;
//                         }
//                     }
//                 }
//                 i++;
//                 j = 0;
//                 continue;
//             }
//             j++;
//         }
//         return ans;
//     }
// };


/*
optimized algo:


nums2 = [1, 3, 4, 2]

Step 1: 1 → push
Stack: [1]

Step 2: 3
3 > 1 → 3 is next greater of 1
Stack: [3]

Step 3: 4
4 > 3 → 4 is next greater of 3
Stack: [4]

Step 4: 2
2 < 4 → push
Stack: [4,2]
*/


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& a, vector<int>& b) {
        unordered_map<int, int> m;
        stack<int> s;
        s.push(b[0]);
        for(int i = 1; i < b.size(); i++){
            while(!s.empty() && b[i] > s.top()){
                m[s.top()] = b[i];
                s.pop();
            }
            s.push(b[i]);
        }
        while(!s.empty()){
            m[s.top()] = -1;
            s.pop();
        }
        vector<int> ans(a.size(), -1);
        for(int i = 0; i < a.size(); i++){
            ans[i] = m[a[i]];
        }
        return ans;
    }
};