class Solution {
public:
void dfs(int i,int j,vector<vector<int>>&vis,vector<vector<char>>&boar){
    int n=boar.size(),m=boar[0].size();
    vis[i][j]=1;
    int dr[]={-1,0,1,0};
    int dc[]={0,1,0,-1};
    for(int k=0;k<4;k++){
        int nr=i+dr[k];
        int nc=j+dc[k];
        if(nr>=0&&nr<n&&nc>=0&&nc<m&&boar[nr][nc]=='O'&&!vis[nr][nc]){
            dfs(nr,nc,vis,boar);
        }
    }
}
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            if(!vis[0][i]&&board[0][i]=='O'){
                dfs(0,i,vis,board);
            }
            if(!vis[n-1][i]&&board[n-1][i]=='O'){
                dfs(n-1,i,vis,board);
            }
        }
         for(int j=0;j<n;j++){
            if(!vis[j][0]&&board[j][0]=='O'){
                dfs(j,0,vis,board);
            }
            if(!vis[j][m-1]&&board[j][m-1]=='O'){
                dfs(j,m-1,vis,board);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]&&board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
        
    }
};
