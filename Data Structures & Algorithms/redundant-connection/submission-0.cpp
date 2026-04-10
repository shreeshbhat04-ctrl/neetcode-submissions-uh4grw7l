class disjoint{
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
    void unionbysize(int u,int v){
        int ulp=findupar(u);
        int vlp=findupar(v);
        if(ulp==vlp)return;
        if(size[ulp]<size[vlp]){
            parent[ulp]=vlp;
            size[vlp]+=size[ulp];
        }else{
            parent[vlp]=ulp;
            size[ulp]+=size[vlp];
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        disjoint ds(n);
        vector<int>ans;
        for(auto& it:edges){
            int u=it[0];
            int v=it[1];
            if(ds.findupar(u)==ds.findupar(v)){
                ans.push_back(u);
                ans.push_back(v);
            }else{
                ds.unionbysize(u,v);
            }

        }
        return ans;
    }
};
