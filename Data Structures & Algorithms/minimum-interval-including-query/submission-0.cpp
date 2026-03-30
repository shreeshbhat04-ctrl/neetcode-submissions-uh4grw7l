class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int>ans;
        for(int q:queries){
            int cur=-1;
            for(auto& in:intervals){
                int l=in[0],r=in[1];
                if(l<=q&&q<=r){
                if(cur==-1||(r-l+1)<cur){
                    cur=r-l+1;
                }
                }
            }ans.push_back(cur);
        }
        return ans;
    }
};
