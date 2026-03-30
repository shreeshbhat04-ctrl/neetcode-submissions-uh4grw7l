class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
     int n=stones.size();
     priority_queue<int>ma;
     for(int x:stones)ma.push(x);
     while(ma.size()>1){
        int fir=ma.top();
        ma.pop();
        int sec=ma.top();
        ma.pop();
        if(sec<fir)ma.push(fir-sec);
     }
       return ma.size()==0?0:ma.top();
    }
};
