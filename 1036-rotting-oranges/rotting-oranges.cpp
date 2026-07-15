class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;
        int cnt = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    cnt++;
                }
                else if(grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        int t = 0;

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        while(!q.empty()) {
            int s = q.size();
            bool rot = false;

            while(s--) {
                auto curr = q.front();
                q.pop();

                int x = curr.first;
                int y = curr.second;

                for(int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if(nx >= 0 && nx < m &&
                       ny >= 0 && ny < n &&
                       grid[nx][ny] == 1) {

                        grid[nx][ny] = 2;
                        cnt--;
                        rot = true;

                        q.push({nx, ny});
                    }
                }
            }

            if(rot) {
                t++;
            }
        }

        return cnt == 0 ? t : -1;
    }
};