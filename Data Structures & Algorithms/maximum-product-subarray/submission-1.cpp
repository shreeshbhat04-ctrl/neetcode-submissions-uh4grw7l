class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res=nums[0];
        // for(int i=0;i<nums.size();i++){
        //     int cur=nums[i];
        //     res=max(res,cur);
        //     for(int j=i+1;j<nums.size();j++){
        //       cur*=nums[j];
        //       res=max(res,cur);
        //     }
        // }
        // return res;
        int curmin=1,curmax=1;
        for(int num:nums){
            int tmp=curmax*num;
            curmax=max(max(num*curmax,num*curmin),num);
            curmin=min(min(tmp,curmin*num),num);
            res=max(res,curmax);
        }
        return res;
    }
};
