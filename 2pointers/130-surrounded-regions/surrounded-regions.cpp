class Solution {
public:

    void dfs(int i, int j, vector<vector<char>>& board, vector<vector<int>>& vis, int n, int m, bool flag){
        vis[i][j] = 1;
        if(flag) board[i][j] = 'S';
        else board[i][j] = 'X';
        int nrow[] = {-1,1,0,0};
        int ncol[] = {0,0,-1,1};
        for(int x=0;x<4;x++){
            int nr = i+nrow[x];
            int nc = j+ncol[x];
            if(nr >=0 && nr < n && nc >=0 && nc < m && vis[nr][nc]==0 && board[nr][nc]=='O'){
                if(flag)
                    dfs(nr,nc,board,vis,n,m,true);
                else
                    dfs(nr,nc,board,vis,n,m,false);
            }
        }
        
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(board[i][0] == 'O')
                dfs(i,0,board, vis, n, m,true);
            if(board[i][m-1] == 'O')    
                dfs(i,m-1,board, vis, n, m,true);
        }

        for(int j=0;j<m;j++){
            if(board[0][j] == 'O')
                dfs(0,j,board, vis, n, m,true);
            if(board[n-1][j] == 'O')    
                dfs(n-1,j,board, vis, n, m,true);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'){
                    board[i][j] = 'X';
                } else if(board[i][j] == 'S'){
                    board[i][j] = 'O';
                }
            }
        }

    }
};
