class Solution {
public:
bool issafe(int col,int n,vector<string>&board,int row){
    for(int j=0;j<n;j++){
        if(board[row][j]=='Q')return false;
    }//horizontal
    for(int i=0;i<n;i++){
        if(board[i][col]=='Q')return false;
    }//vertical
    for(int i=row,j=col;i>=0&&j>=0;i--,j--){
      if(board[i][j]=='Q')return false;
    }
      for(int i=row,j=col;i>=0&&j>=0;i--,j++){
      if(board[i][j]=='Q')return false;
    }


return true;
}
void nqueens(int row,int n,vector<string>&board,vector<vector<string>>&ans){
if(row==n){
    ans.push_back(board);
    return;
}
    for(int j=0;j<n;j++){
        if(issafe(j,n,board,row)){
            board[row][j]='Q';
            nqueens(row+1,n,board,ans);
            board[row][j]='.';
        }
    }
}
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        vector<vector<string>>ans;
        nqueens(0,n,board,ans);
        return ans;
    }
};
