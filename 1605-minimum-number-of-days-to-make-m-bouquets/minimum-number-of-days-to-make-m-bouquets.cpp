class Solution {
public:
    bool check(int mid, vector<int>& bloomDay, int m, int k){
        int b = 0;
        int cnt = 0;
        for(int i = 0; i < bloomDay.size(); i++){
            if(bloomDay[i] <= mid){
                cnt++;
                if(cnt == k){
                    b++;        // one bouquet formed
                    cnt = 0;    // reset for next bouquet
                }
            }
            else{
                cnt = 0;  // break in adjacency
            }
        }
        return b >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int s = *min_element(bloomDay.begin(), bloomDay.end());
        int e = *max_element(bloomDay.begin(), bloomDay.end());
        int res = -1;
        while(s <= e){
            int mid = s + (e-s)/2;
            if(check(mid, bloomDay, m, k)){
                res = mid;
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        return res;
    }
};