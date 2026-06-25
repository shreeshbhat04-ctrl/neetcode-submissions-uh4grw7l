class Solution {
public:
bool f(int i,int j,int k,string s1,string s2,string s3, vector<vector<int>>dp){
if(k==s3.size()){
    return (i==s1.size())&&(j==s2.size());
}
if(dp[i][j]!=-1)return dp[i][j];
bool res=false;
    if(i<s1.size()&&s1[i]==s3[k]){
        res=f(i+1,j,k+1,s1,s2,s3,dp);
    }
    if(!res&&j<s2.size()&&s2[j]==s3[k]){
       res=f(i,j+1,k+1,s1,s2,s3,dp);
    }
    dp[i][j]=res;
    return res;
}
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size(),m=s2.size();
        if(n+m!=s3.size())return false;
        vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
        //return f(0,0,0,s1,s2,s3,dp);
        dp[n][m]=true;
        for(int i=n;i>=0;i--){
            for(int j=m;j>=0;j--){
                if(i<n&&s1[i]==s3[i+j]&&dp[i+1][j]){
        dp[i][j]=true;
    }
    if(j<m&&s2[j]==s3[i+j]&&dp[i][j+1]){
       dp[i][j]=true;
    }
            }
        }
        return dp[0][0];
    }
};
