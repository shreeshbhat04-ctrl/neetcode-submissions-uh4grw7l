class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>merge;
        merge.push_back(intervals[0]);
        for(int i=0;i<intervals.size();i++){
            vector<int>&last=merge.back();
            vector<int>&current=intervals[i];
            if(current[0]<=last[1]){
                last[1]=max(last[1],current[1]);
            }else{
                merge.push_back(current);
            }
        }
        return merge;
    }
};
