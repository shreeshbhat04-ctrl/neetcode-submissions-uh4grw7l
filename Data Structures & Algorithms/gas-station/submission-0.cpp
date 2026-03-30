class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totg=0,totc=0;
        for(int g:gas){
            totg+=g;
        }
        for(int c:cost){
            totc+=c;
        }
        if(totc>totg)return -1;
        int st=0,curgas=0;
        for(int i=0;i<gas.size();i++){
            curgas+=(gas[i]-cost[i]);
            if(curgas<0){
                st=i+1;
                curgas=0;
            }
        }
        return st;
    }
};
