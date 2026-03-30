class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n=triplets.size();
        vector<int>tripans(3,0);
        for(auto& t:triplets){
            if(t[0]<=target[0]&&t[1]<=target[1]&&t[2]<=target[2]){
                tripans[0]=max(tripans[0],t[0]);
                tripans[1]=max(tripans[1],t[1]);
                tripans[2]=max(tripans[2],t[2]);
            }
        }
        
        return tripans==target;

    }
};
