class disjoint {
    public:
    vector<int>parent,size;
    disjoint(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int findupar(int node){
        if(node==parent[node])return node;
        return parent[node]=findupar(parent[node]);
    }
    bool unionbysize(int u,int v){
        int ulp=findupar(u);
        int vlp=findupar(v);
        if(ulp==vlp)return false;
        if(size[ulp]<size[vlp]){
            parent[ulp]=vlp;
            size[vlp]+=size[ulp];
        }else{
            parent[vlp]=ulp;
            size[ulp]+=size[vlp];
        }
        return true;
    }
};
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
    disjoint d(n);
    int res=n;
    for(auto& ed:edges){
        if(d.unionbysize(ed[0],ed[1]))res--;
    }
    return res;
    }
};
