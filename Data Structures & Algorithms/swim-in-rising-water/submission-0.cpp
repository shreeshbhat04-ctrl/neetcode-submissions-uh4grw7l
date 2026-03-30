class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        dist[0][0]=grid[0][0];
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>>pq;
        pq.push({grid[0][0],0,0});
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        while(!pq.empty()){
            auto [t,r,c]=pq.top();
            pq.pop();
            if(r==n-1 &&c==n-1)return t;
            for(int k=0;k<4;k++){
                int nr=r+dr[k],nc=c+dc[k];
                if(nr<0||nr>=n||nc<0||nc>=n)continue;
                int nt=max(t,grid[nr][nc]);
                if(nt<dist[nr][nc]){
                    dist[nr][nc]=nt;
                    pq.push({nt,nr,nc});
                }
            }
        }
        return -1;
    }
};
