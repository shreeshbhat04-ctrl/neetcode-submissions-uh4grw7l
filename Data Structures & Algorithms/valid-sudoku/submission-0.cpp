class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9]={false};
        bool col[9][9]={false};
        bool grid[9][9]={false};
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')continue;
                int val=board[i][j]-'1';
                int k=(i/3)*3+(j/3);
                if(row[i][val]||col[j][val]||grid[k][val])return false;
                row[i][val]=col[j][val]=grid[k][val]=true;
            }
        }
        return true;
    }
};
