class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 0) return -1;
        if(grid[0][0] == 1) return -1;
        int ans = 1;
        vector<pair<int,int>> directions = {
            {-1,-1}, {-1,0}, {-1,1},
            {0,-1},           {0,1},
            {1,-1},  {1,0},   {1,1}
        };
        queue<pair<int,int>>q;
        q.push({0,0});
        grid[0][0] = 1;
        while(!q.empty()){
            int a = q.size();
            while(a--){
                auto [x,y] = q.front();
                q.pop();
                if (x == n-1 && y == n-1)
                    return ans;
                for(int i = 0; i < directions.size(); i++){
                    int dx = directions[i].first;
                    int dy = directions[i].second;
                    int fx = x+dx;
                    int fy = y+dy;
                    if(fx >= 0 && fx < n && fy >= 0 && fy < n && grid[fx][fy] == 0){
                        q.push({fx,fy});
                        grid[fx][fy] = 1;
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};