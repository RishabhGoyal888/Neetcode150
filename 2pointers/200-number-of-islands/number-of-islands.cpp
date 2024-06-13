class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int row, int col){
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        int nrow[] = {0,-1,0,1};
        int ncol[] = {-1,0,1,0};

        for(int i=0;i<4;i++){
            int newrow = row + nrow[i];
            int newcol = col + ncol[i];
            if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m && grid[newrow][newcol] == '1' && !vis[newrow][newcol]){
                    cout<<"row = "<<row;
                    cout<<"column = "<<col;
                    // vis[newrow][newcol] = 1;
                    dfs(grid,vis,newrow,newcol);
                }
        } 
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis (n , vector<int> (m,0));
        int count = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    count++;
                    cout<<"hi";
                    dfs(grid, vis, i, j);
                }
            }
        }
        return count;
    }
};