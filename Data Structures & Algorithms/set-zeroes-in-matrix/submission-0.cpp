class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row=matrix.size(),col=matrix[0].size();
        vector<bool>ro(row,false);
        vector<bool>co(col,false);
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]==0){
                    ro[i]=true;
                    co[j]=true;
                }
            }
        }
         for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(ro[i]||co[j]){
                    matrix[i][j]=0;
                }
            }
        }
    }
};
