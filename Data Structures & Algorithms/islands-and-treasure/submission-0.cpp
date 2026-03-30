class Solution {
public:
const int INF=2147483647;

int bfs(vector<vector<int>>& grid,int r,int c,int row,int col){
    queue<pair<int,int>>q;
    q.push({r,c});
    vector<vector<bool>>vis(row,vector<bool>(col,false));
    vis[r][c]=true;
    int steps=0;
    int dr[]={-1,0,1,0};
    int dc[]={0,1,0,-1};
    while(!q.empty()){
    int sz=q.size();
    for(int i=0;i<sz;i++){
        int ro=q.front().first;
        int co=q.front().second;
        q.pop();
        if(grid[ro][co]==0)return steps; 
        for(int j=0;j<4;j++){
            int nr=ro+dr[j];
            int nc=co+dc[j];
            if(nr>=0&&nr<row&&nc>=0&&nc<col&&grid[nr][nc]!=-1&&!vis[nr][nc]){
                q.push({nr,nc});
                vis[nr][nc]=true;
            }

        }
    }
    steps++;
    }
    return -1;
}
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size();
        for(int  i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==INF){
                    grid[i][j]=bfs(grid,i,j,r,c);
                }
            }
        }
    }
};