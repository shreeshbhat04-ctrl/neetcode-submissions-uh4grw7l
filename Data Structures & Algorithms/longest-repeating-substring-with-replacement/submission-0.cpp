class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>freq(26,0);
        int st=0,res=0,maxfreq=0;
        for(int i=0;i<s.size();i++){
            freq[s[i]-'A']++;
            maxfreq=max(maxfreq,freq[s[i]-'A']);
            while((i-st+1)-maxfreq>k){
                freq[s[st]-'A']--;
                st++;
            }
            res=max(res,i-st+1);
        }
        return res;
    }
};
