class Solution {
public:
set<vector<int>>s;
void back(vector<int>&nums,int idx,int target,vector<vector<int>>&ans,vector<int>&combin){
if(idx==nums.size()||target<0){return;}
if(target==0){
if(!s.count(combin)){
    ans.push_back(combin);
    s.insert(combin);
}return;
}
   combin.push_back(nums[idx]);
   back(nums,idx,target-nums[idx],ans,combin);
   combin.pop_back();
   back(nums,idx+1,target,ans,combin);
}
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>combin;
        back(nums,0,target,ans,combin);
        return ans;
    }
};
