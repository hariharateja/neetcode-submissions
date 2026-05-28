class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        queue<pair<int,int>> q;
        int dr[] = {1,-1,0,0};
        int dc[] = {0,0,1,-1};
        int i = 0;
        for(int j = 0 ; j < cols ;j++){
            if(board[i][j] == 'O'){
                q.push({i,j});
                board[i][j] = '#';
            }
        }
        i = rows-1;
        for(int j = 0 ; j < cols ;j++){
            if(board[i][j] == 'O'){
                q.push({i,j});
                board[i][j] = '#';
            }
        }
        int j = 0;
        for(i = 0 ; i < rows ;i++){
            if(board[i][j] == 'O'){
                q.push({i,j});
                board[i][j] = '#';
            }
        }
        j = cols-1;
        for(i = 0 ; i < rows ;i++){
            if(board[i][j] == 'O'){
                q.push({i,j});
                board[i][j] = '#';
            }
        }
        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            for(i = 0 ; i<4;i++){
                int nr = r+dr[i];
                int nc = c+dc[i];
                if(nr<0||nr>=rows||nc<0||nc>=cols||board[nr][nc]=='#'){
                    continue;
                }
                if(board[nr][nc]=='O'){
                    q.push({nr,nc});
                    board[nr][nc] = '#';
                }
            }
        }
        for(i=0;i<rows;i++){
            for(j=0;j<cols;j++){
                if(board[i][j]=='O'){
                    board[i][j] = 'X';
                }
            }
        }
        for(i=0;i<rows;i++){
            for(j=0;j<cols;j++){
                if(board[i][j]=='#'){
                    cout<<"hi";
                    board[i][j] = 'O';
                }
            }
        }
    }
};
