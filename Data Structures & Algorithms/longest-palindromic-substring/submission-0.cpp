class Solution {
public:
bool f(int i,int j,string &s){
    if(i>=j)return true;
    return (s[i]==s[j])&&f(i+1,j-1,s);
}
    string longestPalindrome(string s) {
        int n=s.size(),st=0,maxlen=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(f(i,j,s)){
                    if(j-i+1>maxlen){
                        maxlen=j-i+1;
                        st=i;
                    }
                }
            }
        }
        return s.substr(st,maxlen);
    }
};
