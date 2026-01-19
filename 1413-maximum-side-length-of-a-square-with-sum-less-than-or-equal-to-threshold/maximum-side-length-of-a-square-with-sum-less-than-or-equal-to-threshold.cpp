class Solution {
public:

    bool tsum(int side, int a, int b, vector<vector<int>>& mat,
              int threshold, vector<vector<int>>& rmat){
        int sum = 0;
        for(int i = a; i < a + side; i++){
            sum += rmat[i][b + side - 1] - (b > 0 ? rmat[i][b - 1] : 0);
            if(sum > threshold) return false; // early break
        }
        return true;
    }

    bool check(int side, vector<vector<int>>& mat,
               int threshold, vector<vector<int>>& rmat){
        int m = mat.size();
        int n = mat[0].size();

        for(int i = 0; i + side - 1 < m; i++){
            for(int j = 0; j + side - 1 < n; j++){
                if(tsum(side, i, j, mat, threshold, rmat)){
                    return true;
                }
            }
        }
        return false;
    }

    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> rmat(m, vector<int>(n));
        for(int i = 0; i < m; i++){
            int sum = 0;
            for(int j = 0; j < n; j++){
                sum += mat[i][j];
                rmat[i][j] = sum;
            }
        }

        int lo = 1, hi = min(m, n), ans = 0;

        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            if(check(mid, mat, threshold, rmat)){
                ans = mid;
                lo = mid + 1;   // try bigger square
            } else {
                hi = mid - 1;   // try smaller square
            }
        }

        return ans;
    }
};
