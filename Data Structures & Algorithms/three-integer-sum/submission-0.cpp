class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i>0&&nums[i]==nums[i-1])continue;
        int st=i+1,end=n-1;
        while(st<end){
           int tot=nums[i]+nums[st]+nums[end];
           if(tot>0){
            end--;
           }else if(tot<0){
            st++;
           }else{
            ans.push_back({nums[i],nums[st],nums[end]});
            st++;
            while(nums[st]==nums[st-1]&&st<end){
                st++;
            }
           }
        }}
        return ans;
    }
};
