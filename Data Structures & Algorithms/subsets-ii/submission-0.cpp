class Solution {
public:
void backtrack(vector<int>&nums,vector<vector<int>>& ans,int i,vector<int>&sub){
 if(i==nums.size()){
    ans.push_back(sub);
    return;
 }
    sub.push_back(nums[i]);
    backtrack(nums,ans,i+1,sub);
    sub.pop_back();
    int idx=i+1;
    while(idx<nums.size()&&nums[idx]==nums[idx-1])idx++;
     backtrack(nums,ans,idx,sub);
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>sub;
        backtrack(nums,ans,0,sub);
        return ans;
    }
};

   