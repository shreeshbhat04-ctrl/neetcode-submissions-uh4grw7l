class Solution {
public:

void dfs(int r,int c,vector<vector<bool>>&oce,vector<vector<int>>& heights,int n,int m){
   oce[r][c]=true;
    int dr[]={-1,0,1,0};
    int dc[]={0,1,0,-1};
    for(int i=0;i<4;i++){
        int nr=r+dr[i];
        int nc=c+dc[i];
        if(nr>=0&&nr<n&&nc>=0&&nc<m&&!oce[nr][nc]&&heights[nr][nc]>=heights[r][c]){
            dfs(nr,nc,oce,heights,n,m);
        }
    }
}
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        vector<vector<bool>>pac(n,vector<bool>(m,false));
        vector<vector<bool>>atl(n,vector<bool>(m,false));
        for(int c=0;c<m;c++){
            dfs(0,c,pac,heights,n,m);
            dfs(n-1,c,atl,heights,n,m);
        }
        for(int r=0;r<n;r++){
            dfs(r,0,pac,heights,n,m);
            dfs(r,m-1,atl,heights,n,m);
        }
        vector<vector<int>>res;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pac[i][j]&&atl[i][j]){
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }
};
