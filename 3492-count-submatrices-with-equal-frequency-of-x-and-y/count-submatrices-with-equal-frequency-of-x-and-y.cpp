class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<pair<int, bool>>> mat(m, vector<pair<int, bool>>(n, {0, false}));
        int cnt = 0;

        vector<vector<pair<int, bool>>> rowsum(m, vector<pair<int, bool>>(n, {0, false}));
        vector<vector<pair<int, bool>>> colsum(m, vector<pair<int, bool>>(n, {0, false}));
        vector<vector<pair<int, bool>>> sq(m, vector<pair<int, bool>>(n, {0, false}));

        // Step 1: convert grid
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 'X'){
                    mat[i][j] = {1, true};
                }
                else if(grid[i][j] == 'Y'){
                    mat[i][j] = {-1, false};
                }
                else{
                    mat[i][j] = {0, false};
                }
            }
        }

        // Step 2: row + col prefix
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                
                // row sum
                rowsum[i][j].first = mat[i][j].first + (j>0 ? rowsum[i][j-1].first : 0);
                rowsum[i][j].second = mat[i][j].second || (j>0 ? rowsum[i][j-1].second : false);

                // col sum
                colsum[i][j].first = mat[i][j].first + (i>0 ? colsum[i-1][j].first : 0);
                colsum[i][j].second = mat[i][j].second || (i>0 ? colsum[i-1][j].second : false);
            }
        }

        // Step 3: full square prefix from (0,0)
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                
                sq[i][j].first = mat[i][j].first
                    + (i>0 ? sq[i-1][j].first : 0)
                    + (j>0 ? sq[i][j-1].first : 0)
                    - (i>0 && j>0 ? sq[i-1][j-1].first : 0);

                sq[i][j].second = mat[i][j].second
                    || (i>0 ? sq[i-1][j].second : false)
                    || (j>0 ? sq[i][j-1].second : false)
                    || (i>0 && j>0 ? sq[i-1][j-1].second : false);
            }
        }

        // Step 4: count valid rectangles from (0,0)
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(sq[i][j].first == 0 && sq[i][j].second == true){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};