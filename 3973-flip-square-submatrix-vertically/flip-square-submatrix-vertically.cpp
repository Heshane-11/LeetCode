class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int i = x;
        int j = x+k-1;

        while(i < j){
            vector<int>v1(k, 0);
            for(int b = y; b < y+k; b++){
                v1[b-y] = grid[i][b];
            }
            for(int b = y; b < y+k; b++){
                grid[i][b] = grid[j][b];
            }
            for(int b = y; b < y+k; b++){
                grid[j][b] = v1[b-y];
            }
            i++;
            j--;
        }
    
        return grid;
    }
};