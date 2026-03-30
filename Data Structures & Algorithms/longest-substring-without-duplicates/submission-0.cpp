class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>seen;
        int st=0,res=0;
        for(int i=0;i<s.size();i++){
            while(seen.count(s[i])){
                seen.erase(s[st]);
                st++;
            }
            seen.insert(s[i]);
            res=max(res,i-st+1);
        }
        return res;
    }
};
