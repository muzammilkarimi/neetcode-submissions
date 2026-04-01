class Solution {
public:
    void solve(int i, int j, vector<vector<char>>& grid,vector<vector<int>> &vis,int row, int col){
        vis[i][j]=1;
        vector<pair<int,int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
        for(int l=0; l<4; l++){
            int nx = dir[l].first+i, ny = dir[l].second+j;
            if(nx>=0 and ny>=0 and nx<row and ny<col and grid[nx][ny]=='1' and !vis[nx][ny]){
                solve(nx,ny,grid,vis,row,col);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<vector<int>> vis(row,vector<int>(col,0));
        int ans = 0;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j]=='1' and !vis[i][j]){
                    solve(i,j,grid,vis,row,col);
                    ans++;
                }
            }
        }
        return ans;
    }
};
