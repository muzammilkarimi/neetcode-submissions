class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
       int ans = 0,fresh = 0; 
       queue<pair<int,int>> q;
       for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]==2) q.push({i,j});
                else if(grid[i][j]==1) fresh++;
            }
       } 
       if(fresh==0) return 0;
       vector<pair<int,int>> dir={{0,1},{1,0},{-1,0},{0,-1}};
       while(!q.empty()){
            int s = q.size();
            while(s--){
                int x = q.front().first, y = q.front().second;
                q.pop();
                for(int i=0; i<4; i++){
                    int nx = x+dir[i].first, ny = y+dir[i].second;
                    if(nx>=0 and nx<grid.size() and ny>=0 and ny<grid[0].size() and grid[nx][ny]==1){
                        grid[nx][ny]=2;
                        fresh--;
                        q.push({nx,ny});
                    } 
                }
            }
            ans++;
            if(fresh==0) return ans;
       } 
       if(fresh>0) return -1;
       return ans;
    }
};
