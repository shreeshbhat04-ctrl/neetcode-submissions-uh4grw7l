class Solution {
public:
bool dfs(int i,int j,int idx,vector<vector<char>>& board, string word){
    if(idx==word.size())return true;
    int n=board.size(),m=board[0].size();
    if(i<0||i>=n||j<0||j>=m)return false;
    if(board[i][j]!=word[idx])return false;
   
    int dr[]={-1,0,1,0};
    int col[]={0,1,0,-1};
    char temp=board[i][j];
    board[i][j]='#';
    for(int r=0;r<4;r++){
        int nr=i+dr[r];
        int nc=j+col[r];
        if(dfs(nr,nc,idx+1,board,word)){
            board[i][j]=temp;
            return true;
        }
    }
    board[i][j]=temp;
    return false;

}
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size(),m=board[0].size();
        int idx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dfs(i,j,idx,board,word))return true;
            }
        }
        return false;
    }
};
