class CountSquares {
public:
unordered_map<int,unordered_map<int,int>>pt;
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        pt[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        int res=0,x1=point[0],y1=point[1];
        for(auto&[y2,cnt]:pt[x1]){
            int sd=y2-y1;
            if(sd==0)continue;
            int x3=x1+sd,x4=x1-sd;
            res+=cnt*pt[x3][y1]*pt[x3][y2];
            res+=cnt*pt[x4][x1]*pt[x4][y2];
        }
        return res;
    }
};
