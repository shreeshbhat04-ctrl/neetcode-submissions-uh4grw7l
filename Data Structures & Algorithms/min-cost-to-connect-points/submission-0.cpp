class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        unordered_map<int,vector<pair<int,int>>>adj;
        for(int i=0;i<n;i++){
            int x1=points[i][0];
            int y1=points[i][1];
        for(int j=i+1;j<n;j++){
            int x2=points[j][0];
            int y2=points[j][1];
            int dist=abs(x1-x2)+abs(y1-y2);
            adj[i].push_back({dist,j});
            adj[j].push_back({dist,i});
        }
        }
        int res=0;
        set<int>visted;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minh;
        minh.push({0,0});
        while(visted.size()<n){
            auto cur=minh.top();
            minh.pop();
            int cost=cur.first;
            int i=cur.second;
            if(visted.count(i))continue;
            res+=cost;
            visted.insert(i);
            for(auto& nei:adj[i]){
                int neicost=nei.first;
                int neigh=nei.second;
                if(!visted.count(neigh)){
                    minh.push({neicost,neigh});
                }

            }

        }
        return res;
    }
};
