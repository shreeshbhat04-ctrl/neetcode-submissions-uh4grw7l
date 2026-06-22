class Solution {
public:
bool f(int i,int j,string& s,string& p,vector<vector<int>>&dp){
if(i<0&&j<0)return true;
if(i>=0&&j<0)return false;
if(i<0){
    for(int k=j;k>=0;k-=2){
        if(p[k]!='*')return false;
    }
    return true;
}
if(dp[i][j]!=-1)return dp[i][j];
if(s[i]==p[j]||p[j]=='.'){
 return dp[i][j]=f(i-1,j-1,s,p,dp);
}
    if(p[j]=='*'){
        bool zer=f(i,j-2,s,p,dp);
        bool one=(p[j-1]==s[i]||p[j-1]=='.')&&f(i-1,j,s,p,dp);
        return dp[i][j]=zer||one;
    }
    return dp[i][j]=false;
}
    bool isMatch(string s, string p) {
        int n=s.size(),m=p.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,s,p,dp);
    }
};
