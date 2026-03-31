class Solution {
public:
int f(int i,int total,vector<int>& nums, int target, vector<vector<int>>&dp){
if(i==nums.size()){
    return total==target;
}
if(dp[i][total+1000]!=-1)return dp[i][total+1000];
return dp[i][total+1000]=(f(i+1,total+nums[i],nums,target,dp)+f(i+1,total-nums[i],nums,target,dp));
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(2001,-1));
        return f(0,0,nums,target,dp);
    }
};
