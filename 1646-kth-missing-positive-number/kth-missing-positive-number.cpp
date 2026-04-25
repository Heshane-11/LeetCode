class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int x = k;
        int n = arr.size();
        for(int i = 1; i <= n + k; i++){
            if(find(arr.begin(), arr.end(), i) == arr.end()){
                x--;
            }
            if(x == 0){
                return i;
            }
        }
        int ans = arr[n-1] + x;
        return ans;
    }
};