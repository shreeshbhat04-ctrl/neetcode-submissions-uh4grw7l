class Solution {
public:
bool ispalind(int l,int r,string & s){
    while(l<r){
        if(s[l]!=s[r])return false;
        l++;
        r--;
    }
    return true;
}
void dfs(int i,string&s,vector<vector<string>>&ans,vector<string>&path){
    if(i>=s.size()){
        ans.push_back(path);
        return;
    }
    for(int j=i;j<s.size();j++){
        if(ispalind(i,j,s)){
            path.push_back(s.substr(i,j-i+1));
            dfs(j+1,s,ans,path);
            path.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string> path;
        dfs(0,s,ans,path);
        return ans;
    }
};
