class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid,vector<vector<int>>& vis){
        vis[i][j]=1;
        vector<pair<int,int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
        int area = 1;
        for(int k=0; k<4; k++){
            int nx = i+dir[k].first, ny = j+dir[k].second;
            if(nx>=0 and nx<grid.size() and ny>=0 and ny<grid[0].size() and grid[nx][ny]==1 and !vis[nx][ny]){
                area += solve(nx,ny,grid,vis);
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>> vis(row, vector<int>(col,0));
        int ans = 0;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j]==1 and !vis[i][j]){
                    ans = max(ans,solve(i,j,grid,vis));
                }
            }
        }
        return ans;
    }
};
