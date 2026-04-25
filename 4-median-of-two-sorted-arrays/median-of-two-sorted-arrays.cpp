class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if(m > n) return findMedianSortedArrays(nums2, nums1);
        int s = 0;
        int e = m;
        int x = (m+n+1)/2;
        double ans;
        while(s <= e){
            int px = s + (e-s)/2;
            int py = x - px;
            int x1 = px > 0 ? nums1[px-1] : INT_MIN;
            int x2 = py > 0 ? nums2[py-1] : INT_MIN;
            int x3 = px < m ? nums1[px] : INT_MAX;
            int x4 = py < n ? nums2[py] : INT_MAX;
            if(x1 <= x4 && x2 <= x3){
                if((m + n) % 2 == 0){
                    ans = (max(x1, x2) + min(x3, x4)) / 2.0;
                }
                else{
                    ans = max(x1, x2);
                }
                return ans;
            }
            else if(x1 > x4){
                e = px - 1;
            }
            else{
                s = px + 1;
            }
        }
        return ans;
    }
};