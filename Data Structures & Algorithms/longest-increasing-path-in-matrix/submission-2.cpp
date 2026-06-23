class Solution {
public:
int dfs(int r,int c,vector<vector<int>>& matrix,int val,int n,int m,vector<vector<int>>&dp){
    //  if(r<0||r>=n||c<0||c>=m||matrix[r][c]<=val){
    //         return 0;
    //     }
    if(dp[r][c]!=-1)return dp[r][c];
    int dr[]={-1,0,1,0};
    int dc[]={0,1,0,-1};
    int res=1;
    for(int i=0;i<4;i++){
        int nr=r+dr[i];
        int nc=c+dc[i];
        if(nr>=0 && nr<n&&nc>=0&&nc<m&&(matrix[nr][nc]>matrix[r][c])){
       res=max(res,1+dfs(nr,nc,matrix,matrix[nr][nc],n,m,dp));}
    }
    return dp[r][c]=res;
}
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        int maxi=0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
            maxi=max(maxi,dfs(i,j,matrix,INT_MIN,n,m,dp));
          }
        }
        return maxi;
    }
};
