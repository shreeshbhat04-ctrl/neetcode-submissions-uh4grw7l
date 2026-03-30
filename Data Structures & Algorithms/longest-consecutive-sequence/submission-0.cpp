class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans=0;
        unordered_set<int>sa(nums.begin(),nums.end());
        for(auto& it:nums){
           if(!sa.count(it-1)){
            int cnt=1;
            while(sa.count(it+cnt)){
              cnt++;
            }
            ans=max(ans,cnt);
           }
           
        }
        return ans;
    }
};
