class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> mr(n, 0);
        for(int i = 0; i < n; i++){
            for(int j = n-1; j >= 0; j--){
                if(grid[i][j] == 1){
                    mr[i] = j;
                    break;
                }
            }
        }
        int swaps = 0;

        for(int i = 0; i < n; i++){
            int j = i;
            while(j < n && mr[j] > i){
                j++;
            }
            if(j == n) return -1;
            while(j > i){
                swap(mr[j], mr[j-1]);
                swaps++;
                j--;
            }
        }

        return swaps;
    }
};