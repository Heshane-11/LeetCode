class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long maxSum = 0;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix.size(); j++){
                maxSum += abs(matrix[i][j]);
            }
        }
        int cnt = 0;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix.size(); j++){
                if(matrix[i][j] <= 0){
                    cnt++;
                }
            }
        }
        if(cnt % 2 == 0){
            return maxSum;
        }
        else{
            int small = INT_MAX;
            for(int i = 0; i < matrix.size(); i++){
                for(int j = 0; j < matrix.size(); j++){
                    small = min(small, abs(matrix[i][j]));
                }
            }
            return maxSum - 2*small ;
        }
    }
};