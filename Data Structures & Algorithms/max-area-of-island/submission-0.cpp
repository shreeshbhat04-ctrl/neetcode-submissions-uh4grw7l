class Solution {
public:
int dfs(int r,int c,vector<vector<int>>&vis,vector<vector<int>>& grid){
  vis[r][c]=1;
  int n=grid.size(),m=grid[0].size();
 int cnt=1;
 int dr[]={-1,0,1,0};
 int dc[]={0,1,0,-1};
 for(int i=0;i<4;i++){
    int nr=r+dr[i];
    int nc=c+dc[i];
    if(nr>=0&&nr<n&&nc>=0&&nc<m&&vis[nr][nc]!=1&&grid[nr][nc]==1){
        cnt+=dfs(nr,nc,vis,grid);
    }
 }
return cnt;

}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
     int n=grid.size(),m=grid[0].size();
     int maxar=0;
     vector<vector<int>>vis(n,vector<int>(m,0));
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
         if(grid[i][j]==1&&vis[i][j]!=1){
            int area=dfs(i,j,vis,grid);
            maxar=max(maxar,area);
         }
        }
     }
return maxar;
    }
};
