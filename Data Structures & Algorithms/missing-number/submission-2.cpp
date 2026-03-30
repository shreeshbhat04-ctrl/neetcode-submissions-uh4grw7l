class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int st=0,m=nums[n-1];
        for(int i=st;i<=m;i++){
            if(nums[i]!=i)return i;
        }
        return m+1;
    }
};
