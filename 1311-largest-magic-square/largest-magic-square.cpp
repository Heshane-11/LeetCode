class Solution {
public:

    bool mc(int side, int i, int j, vector<vector<int>>& grid, vector<vector<int>>& rgrid, vector<vector<int>>& cgrid){
        int target = rgrid[i][j+side-1] - (j > 0 ? rgrid[i][j-1] : 0);
        for(int a = i+1; a < i+side; a++){
            int sum = rgrid[a][j+side-1] - (j > 0 ? rgrid[a][j-1] : 0);
            if(sum != target){
                return false;
            }
        }
        for(int a = j; a < j+side; a++){
            int sum = cgrid[i+side-1][a] - (i > 0 ? cgrid[i-1][a] : 0);
            if(sum != target){
                return false;
            }
        }
        int sum = 0;
        int b = j;
        for(int a = i; a < i+side; a++){
            sum += grid[a][b];
            b++;
        }
        if(sum != target){
            return false;
        }
        sum = 0;
        b = j+side-1;
        for(int a = i; a < i+side; a++){
            sum += grid[a][b];
            b--;
        }

        if(sum != target){
            return false;
        }
        return true;
    }

    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> rgrid(m, vector<int>(n));
        vector<vector<int>> cgrid(m, vector<int>(n));
        int sum = 0;
        for(int i = 0; i < m; i++){
            sum = 0;
            for(int j = 0; j < n; j++){
                rgrid[i][j] = sum + grid[i][j];
                sum = rgrid[i][j];
            }
        }
        sum = 0;
        for(int i = 0; i < n; i++){
            sum = 0;
            for(int j = 0; j < m; j++){
                cgrid[j][i] = sum + grid[j][i];
                sum = cgrid[j][i];
            }
        }
        for(int side = min(m,n); side >= 2; side--){
            for(int i = 0; i + side - 1 < m; i++){
                for(int j = 0; j + side - 1 < n; j++){
                    if(mc(side, i, j, grid, rgrid, cgrid)){
                        return side;
                    }
                }
            }
        }
        return 1;
    }
};