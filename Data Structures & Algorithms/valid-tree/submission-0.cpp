class Solution {
public:
bool hascyc(int node,int parent,vector<vector<int>>& adj,vector<bool>&vis){
    vis[node]=true;
    for(int it:adj[node]){
        if(!vis[it]){
            if(hascyc(it,node,adj,vis))return true;
        }else if(it!=parent){
            return true;
        }
    }
    return false;
}
    bool validTree(int n, vector<vector<int>>& edges) {
     if(n-1!=edges.size())return false;
      vector<vector<int>>adj(n);
      for(auto& it:edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
      }
      vector<bool>vis(n,false);
      if(hascyc(0,-1,adj,vis))return false;
      for(bool v:vis)if(!v)return false;
      return true;

    }
};
