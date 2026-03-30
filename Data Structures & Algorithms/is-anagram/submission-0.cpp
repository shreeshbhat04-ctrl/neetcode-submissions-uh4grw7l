class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())return false;
        vector<int>freq(26);
        for(char ch:s)freq[ch-'a']++;
        for(char ch:t)freq[ch-'a']--;

      for(int c:freq){
        if(c!=0)return false;
      }
      return true;
    }
};
