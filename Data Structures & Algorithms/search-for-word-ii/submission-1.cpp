class Solution {
public:
bool dfs(int r,int c,int idx,vector<vector<char>>& board,string& word){
    int n=board.size(),m=board[0].size();
    if(idx==word.size())return true;
    if(r<0||r>=n||c<0||c>=m)return false;
    if(board[r][c]!=word[idx])return false;
    int dr[]={-1,0,1,0};
    int dc[]={0,1,0,-1};
    char temp=board[r][c];
    board[r][c]='#';
    for(int i=0;i<4;i++){
        int nr=r+dr[i];
        int nc=c+dc[i];
        if(dfs(nr,nc,idx+1,board,word)){
            board[r][c]=temp;
            return true;
        }
    }
    board[r][c]=temp;
    return false;
}
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n=board.size(),m=board[0].size();
        int idx=0;
        unordered_set<string>fo;
        vector<string>res;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(auto& st:words){
                    if(dfs(i,j,idx,board,st)){
                        fo.insert(st);
                    }
                }
            }
        }
        return vector<string>(fo.begin(),fo.end());
    }
};
