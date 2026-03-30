class Solution {
public:
int f(int i,int j,string& wor1,string& wor2, vector<vector<int>>&dp){
    if(i<0)return j+1;
    if(j<0)return i+1;
    if(dp[i][j]!=-1)return dp[i][j];
    if(wor1[i]==wor2[j]){
        return dp[i][j]=f(i-1,j-1,wor1,wor2,dp);
    }
    int delet=1+f(i-1,j-1,wor1,wor2,dp);
    int insert=1+f(i,j-1,wor1,wor2,dp);
    int upda=1+f(i-1,j,wor1,wor2,dp);
    return dp[i][j]=min({delet,insert,upda});
}
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return f(n,m,word1,word2,dp);
    }
};
