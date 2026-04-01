class Solution {
public:
bool f(int i,vector<int>&nums,int target,vector<vector<int>>&dp){
if(i==nums.size())return target==0;

if(target<0)return false;
if(dp[i][target]!=-1)return dp[i][target];
    return dp[i][target]= f(i+1,nums,target,dp)||f(i+1,nums,target-nums[i],dp);
}
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int x:nums){
            sum+=x;
        }
        int n=nums.size();

        if(sum%2!=0)return false;
        vector<vector<int>>dp(n,vector<int>(sum/2+1,-1));
        return f(0,nums,sum/2,dp);
    }
};
