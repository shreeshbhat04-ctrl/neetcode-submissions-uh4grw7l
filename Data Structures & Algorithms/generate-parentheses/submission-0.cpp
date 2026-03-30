class Solution {
public:
void backtrack(int open,int close,int n,vector<string>&ans,string & pa){

if(open==close && close==n){
    ans.push_back(pa);
    return;
}
    if(open<n){
        pa+='(';
        backtrack(open+1,close,n,ans,pa);
        pa.pop_back();
    }
    if(close<open){
        pa+=')';
        backtrack(open,close+1,n,ans,pa);
        pa.pop_back();
    }
}
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string st;
        backtrack(0,0,n,ans,st);
        return ans;
    }
};
