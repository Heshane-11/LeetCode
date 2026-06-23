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


/*
appr 2: 
*/



class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted(n);
        for(int i = 0; i < n; i++){
            sorted[i] = nums[i];
        }
        sort(sorted.begin(), sorted.end());
        
        for(int i = 0; i < n; i++){
            bool is = true;
            for(int j = 0; j < n; j++){
                if(sorted[j] != nums[(i+j) % n]){
                    is = false;
                }
            }
            if(is){
                return true;
            }
        }
        return false;
    }
};