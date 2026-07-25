/*
DFS is problem ke liye suitable nahi hai kyunki wo ek direction mein depth tak chala jata hai aur kisi cell tak pahunchne ka minimum time guarantee nahi karta. Rotting process har minute sabhi rotten oranges se ek saath (simultaneously) spread hoti hai, jo level-by-level hoti hai. Isi wajah se Multi-Source BFS use karte hain, kyunki BFS har level ko ek minute maan kar har cell tak minimum time mein pahunchne ki guarantee deta hai.

*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int fresh = 0;
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    fresh++;
                }
                else if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }
        vector<int> dirx = {0, 0, -1, 1};
        vector<int> diry = {1, -1, 0, 0};
        int time = 0;
        while(!q.empty()){
            int s = q.size();
            while(s > 0){
                auto [x,y] = q.front();
                q.pop();
                for(int i = 0; i < 4; i++){
                    int nx = x + dirx[i];
                    int ny = y + diry[i];
                    if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1){
                        grid[nx][ny] = 2;
                        fresh--;
                        q.push({nx, ny});
                    }
                }
                s--;
            }
            if(!q.empty())
                time++;
        }
        return (fresh > 0) ? -1 : time;
    }
};