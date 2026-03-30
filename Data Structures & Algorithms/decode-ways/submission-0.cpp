class Solution {
public:
int f(string& s,int i){
    if(i==s.size())return 1;
    if(s[i]=='0')return 0;
    int ans=f(s,i+1);
    if(i<s.size()-1){
        if(s[i]=='1'||(s[i]=='2'&&s[i+1]<'7')){
            ans+=f(s,i+2);
        }
    }
    return ans;
}
    int numDecodings(string s) {
        return f(s,0);
    }
};
