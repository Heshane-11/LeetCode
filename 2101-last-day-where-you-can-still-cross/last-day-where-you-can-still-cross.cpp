class Solution {
public:
    bool help(vector<vector<int>>& v, int r, int c, vector<vector<bool>>& visited){
        if(r == v.size()-1){
            return true;
        }
        //left
        if(c-1 >= 0 && v[r][c-1] == 0 && !visited[r][c-1]){
            visited[r][c-1] = true;
            if (help(v, r, c-1, visited)) return true;
        }
        //right
        if(c+1 < v[0].size() && v[r][c+1] == 0 && !visited[r][c+1]){
            visited[r][c+1] = true;
            if (help(v, r, c+1, visited)) return true;
        }
        //up
        if(r-1 >= 0 && v[r-1][c] == 0 && !visited[r-1][c]){
            visited[r-1][c] = true;
            if (help(v, r-1, c, visited)) return true;
        }
        //down
        if(r+1 < v.size() && v[r+1][c] == 0 && !visited[r+1][c]){
            visited[r+1][c] = true;
            if (help(v, r+1, c, visited)) return true;
        }
        return false;
    }
    bool correct(vector<vector<int>>& v){
        vector<vector<bool>> visited(v.size(), vector<bool>(v[0].size(), false));
        for(int i = 0; i < v[0].size(); i++){
            visited[0][i] = true;
            if(v[0][i] == 0 && help(v, 0, i, visited)){
                return true;
            }
        }
        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        vector<vector<int>> v(row, vector<int>(col, 0));
        int s = 0;
        int e = cells.size() - 1;
        int m = s + (e - s) / 2;
        int ans = 0;
        while(s<=e){
            v.assign(row, vector<int>(col, 0));
            for(int i = 0; i <= m; i++){
                v[cells[i][0]-1][cells[i][1]-1] = 1;
            }
            if(correct(v)){
                s = m + 1;
                ans = m + 1;
            }
            else{
                e = m - 1;
            }
            m = s + (e - s) / 2;
        }
        return ans;
    }
};