class Solution {
public:
    int maxArea(vector<int>& heights) {
        int st=0,end=heights.size()-1,res=0;
        while(st<end){
            int area=min(heights[st],heights[end])*(end-st);
            res=max(res,area);
            if(heights[st]<=heights[end]){
                st++;
            }else{
                end--;
            }
        }
        return res;
    }
};
