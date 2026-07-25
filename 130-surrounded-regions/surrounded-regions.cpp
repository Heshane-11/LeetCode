/*
Algorithm
Saare border cells traverse karo.
Agar kisi border cell par 'O' mile:
Use queue mein daal do.
'T' (ya '#') mark kar do taaki dobara visit na ho.
Jab tak queue empty na ho:
Front cell nikalo.
Uske 4 neighbours (Up, Down, Left, Right) check karo.
Agar neighbour valid hai aur 'O' hai:
Queue mein push karo.
'T' mark kar do.
BFS khatam hone ke baad poori matrix traverse karo:
'O' → 'X' (ye surrounded region tha)
'T' → 'O' (ye border se connected tha, isliye safe hai)
*/

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        queue<pair<int, int>> q;

        for(int i = 0; i < m; i++){
            if(board[i][0] == 'O'){
                q.push({i, 0});
                board[i][0] = 'T';
            }
            if(board[i][n-1] == 'O'){
                q.push({i, n-1});
                board[i][n-1] = 'T';
            }
        }
        for(int j = 0; j < n; j++){
            if(board[0][j] == 'O'){
                q.push({0, j});
                board[0][j] = 'T';
            }
            if(board[m-1][j] == 'O'){
                q.push({m-1, j});
                board[m-1][j] = 'T';
            }
        }

        vector<int> dirx = {0, 0, 1, -1};
        vector<int> diry = {1, -1, 0, 0};

        while(!q.empty()){
            auto[x, y] = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){
                int nx = x + dirx[i];
                int ny = y + diry[i];
                if(nx >= 0 && nx < m && ny >= 0 && ny < n && board[nx][ny] == 'O'){
                    q.push({nx, ny});
                    board[nx][ny] = 'T';
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'T'){
                    board[i][j] = 'O';
                }
                else if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};