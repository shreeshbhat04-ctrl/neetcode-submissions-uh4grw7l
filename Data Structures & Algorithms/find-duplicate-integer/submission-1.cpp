class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>fre;
        for(int x:nums)fre[x]++;
        
        for(auto& fr:fre){
            if(fr.second>=2)return fr.first;
        }
        return -1;
    }
};
