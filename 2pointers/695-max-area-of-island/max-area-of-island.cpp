class Solution {
public:

    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int row, int col, int &curr, int &ans){
        vis[row][col] = 1;
        curr++;
        ans = max(curr,ans);
        int n = grid.size();
        int m = grid[0].size();
        int nrow[] = {0,-1,0,1};
        int ncol[] = {-1,0,1,0};

        for(int i=0;i<4;i++){
            int newrow = row + nrow[i];
            int newcol = col + ncol[i];
            if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m && grid[newrow][newcol] && !vis[newrow][newcol]){
                    dfs(grid,vis,newrow,newcol,curr, ans);
                    // curr--; no need because imagin t shape island
                }
        } 
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis (n , vector<int> (m,0));
        int curr = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] && !vis[i][j]){
                    curr=0;
                    dfs(grid, vis, i, j,curr, ans);
                }
            }
        }
        return ans;
    }
};
