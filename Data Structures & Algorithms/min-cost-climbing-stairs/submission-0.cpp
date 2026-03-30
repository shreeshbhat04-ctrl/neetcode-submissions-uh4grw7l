class Solution {
public:
int f(vector<int>&co,int idx){
    if(idx>=co.size())return 0;
    return co[idx]+min(f(co,idx+1),f(co,idx+2));
}
    int minCostClimbingStairs(vector<int>& cost) {
       // return min(f(cost,0),f(cost,1));
       int n=cost.size();
       vector<int>dp(n,0);
       dp[0]=cost[0];dp[1]=cost[1];
       for(int i=2;i<cost.size();i++){
        dp[i]=min(dp[i-2],dp[i-1])+cost[i];
       }
       return min(dp[n-1],dp[n-2]);
    }
};
