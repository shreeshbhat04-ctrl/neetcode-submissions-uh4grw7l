class Solution {
public:
 int f(vector<int>&num,int i,vector<int>&dp){
    if(i<0)return 0;
   if(dp[i]!=-1)return dp[i];
   return dp[i]=max(f(num,i-2,dp)+num[i],f(num,i-1,dp));

 }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return f(nums,n-1,dp);
    }
};
