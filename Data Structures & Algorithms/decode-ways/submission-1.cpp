class Solution {
public:
int f(string& s,int i,unordered_map<int,int>mp){
    if(i==s.size())return 1;
    if(s[i]=='0')return 0;
    if(mp.count(i))return mp[i];
    int ans=f(s,i+1,mp);
    if(i<s.size()-1){
        if(s[i]=='1'||(s[i]=='2'&&s[i+1]<'7')){
            ans+=f(s,i+2,mp);
        }
    }
    return mp[i]=ans;
}
    int numDecodings(string s) {
        unordered_map<int,int>mp;
        return f(s,0,mp);
    }
};
