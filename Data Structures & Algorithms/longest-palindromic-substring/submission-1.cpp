class Solution {
public:
bool f(int i,int j,string &s){
    if(i>=j)return true;
    return (s[i]==s[j])&&f(i+1,j-1,s);
}
    string longestPalindrome(string s) {
        // int n=s.size(),st=0,maxlen=0;
        // for(int i=0;i<n;i++){
        //     for(int j=i;j<n;j++){
        //         if(f(i,j,s)){
        //             if(j-i+1>maxlen){
        //                 maxlen=j-i+1;
        //                 st=i;
        //             }
        //         }
        //     }
        // }
        // return s.substr(st,maxlen);
        int rel=0,rei=0;
        for(int i=0;i<s.size();i++){
            int l=i,r=i;//odd len
            while(l>=0&&r<s.size()&&s[l]==s[r]){
                if(r-l+1>rel){
                    rel=r-l+1;
                    rei=l;
                }
                l--;
                r++;
            } 
              l=i,r=i+1;//even len
            while(l>=0&&r<s.size()&&s[l]==s[r]){
                if(r-l+1>rel){
                    rel=r-l+1;
                    rei=l;
                }
                l--;
                r++;
            } 
        }return s.substr(rei,rel);
    }
};
