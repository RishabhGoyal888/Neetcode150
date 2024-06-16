class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis (n, vector<int>(m,0));
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({{i,j}, 0});
                    vis[i][j] = 1;
                }
            }
        }

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int time = q.front().second;
            ans = max(ans,time);
            q.pop();
            int nrow[] = {0,-1,0,1};
            int ncol[] = {-1,0,1,0};

            for(int i=0;i<4;i++){
                int newrow = r + nrow[i];
                int newcol = c + ncol[i];
                if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m && grid[newrow][newcol] == 1 && !vis[newrow][newcol]){
                    q.push({{newrow,newcol}, time + 1});
                    vis[newrow][newcol] = 1;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1 && !vis[i][j])
                    return -1;
            }
        }
        return ans;
    }
};