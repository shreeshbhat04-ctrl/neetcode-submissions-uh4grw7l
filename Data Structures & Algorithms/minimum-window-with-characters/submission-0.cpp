class Solution {
public:
bool con(string s,string t){
    vector<int>freq(128,0);
    for(char ch:s)freq[ch]++;
    for(char c:t){
        if(freq[c]--<=0)return false;
    }
    return true;
}
    string minWindow(string s, string t) {
        int n=s.size(),mini=INT_MAX,m=t.size();
        string ans="";
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
               string sub=s.substr(i,j-i+1);
                 if(con(sub,t)){
                    if(sub.size()<mini){
                        mini=sub.size();
                        ans=sub;
                    }
                 }
            }
        }
        return ans;
    }
};
