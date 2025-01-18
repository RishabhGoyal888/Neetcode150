class Solution {
public:

    void dfs(int i, int j, vector<vector<int>>& sea, vector<vector<int>>& heights){
        sea[i][j] = 1;
        int nrow[4] = {0,-1,0,1};
        int ncol[4] = {-1,0,1,0};
        int n = heights.size();
        int m = heights[0].size();
        for(int x=0;x<4;x++){
            int nexti = i + nrow[x];
            int nextj = j + ncol[x];
            if(nexti >= 0 && nexti < n && nextj >= 0 && nextj < m && sea[nexti][nextj] == 0 && heights[nexti][nextj] >= heights[i][j]){
                dfs(nexti, nextj, sea, heights);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> atlantic(n, vector<int>(m, 0));
        vector<vector<int>> pacific(n, vector<int>(m, 0));

        for(int i=0;i<n;i++){
            dfs(i, 0, pacific, heights);
            dfs(i, m-1, atlantic, heights);
        }

        for(int j=0;j<m;j++){
            dfs(0, j, pacific, heights);
            dfs(n-1, j, atlantic, heights);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(atlantic[i][j] && pacific[i][j]){
                    res.push_back({i,j});
                }
            }
        }
        return res;
        
    }
};
