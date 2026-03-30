class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>me;me.push_back(intervals[0]);
        for(int i=0;i<intervals.size();i++){
            vector<int>&last=me.back();
            vector<int>&curr=intervals[i];
            if(curr[0]<=last[1]){
                last[1]=max(curr[1],last[1]);
            }else{
                me.push_back(curr);
            }
        }return me;
    }
};
