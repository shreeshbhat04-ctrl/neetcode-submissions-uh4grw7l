class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int res=nums[0],n=nums.size();
    //    for(int i=0;i<n;i++){
    //     int curr=0;
    //     for(int j=i;j<n;j++){
    //        curr+=nums[j];
    //        res=max(curr,res);
    //     }
    //    }
    int cur=0;
    for(int i:nums){
        if(cur<0){cur=0;}
        cur+=i;
        res=max(res,cur);
    }
       return res;
    }
};
