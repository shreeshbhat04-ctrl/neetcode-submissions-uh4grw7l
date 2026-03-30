class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
     int n=stones.size();
     priority_queue<int>ma;
     for(int x:stones)ma.push(x);
     while(ma.size()>1){
        int y=ma.top();
        ma.pop();
        int x=ma.top();
        ma.pop();
        if(x<y)ma.push(y-x);
     }
       return ma.size()==0?0:ma.top();
    }
};
