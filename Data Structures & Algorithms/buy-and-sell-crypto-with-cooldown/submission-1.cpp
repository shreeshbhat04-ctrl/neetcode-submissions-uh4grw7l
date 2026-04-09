class Solution {
public:
int f(int i,vector<int>&prices,bool buy,vector<vector<int>>&dp){
if(i>=prices.size())return 0;
if(dp[i][buy]!=-1)return dp[i][buy];
    int ans1=f(i+1,prices,buy,dp);
    int ans2=0;
    if(buy){
        ans2=-prices[i]+f(i+1,prices,false,dp);
    }else{
        ans2=f(i+2,prices,true,dp)+prices[i];
    }
    return dp[i][buy]=max(ans1,ans2);
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int ans=0;
        vector<vector<int>>dp(n+2,vector<int>(2,-1));
        ans=f(0,prices,true,dp);
        return ans;
    }
};
