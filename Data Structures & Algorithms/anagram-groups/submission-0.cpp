class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
       unordered_map<string,vector<string>>freq;
       for(auto& it:strs){
        string t=it;
        sort(t.begin(),t.end());
        freq[t].push_back(it);
       }
       for(auto& p:freq){
        ans.push_back(p.second);
       }
       return ans;
    }
};
