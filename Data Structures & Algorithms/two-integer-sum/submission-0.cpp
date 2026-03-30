class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>seen;
        for(int i=0;i<nums.size();i++){
            int othernum=target-nums[i];
            if(seen.count(othernum)){
                return {seen[othernum],i};
            }
            seen[nums[i]]=i;
        }
        return {};
    }
};
