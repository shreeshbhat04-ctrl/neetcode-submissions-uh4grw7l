
class Solution {
public:
bool f(int i,string& s, vector<string>& word, unordered_map<int,bool>&wordm){
if(wordm.count(i))return wordm[i];
    for(string& w:word){
        if(i+w.size()<=s.size()&&s.substr(i,w.size())==w){
            if(f(i+w.size(),s,word,wordm))return wordm[i]=true;
        }
    }
    return wordm[i]= false;
}
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<int,bool>word;
        word[s.size()]=true;
        return f(0,s,wordDict,word);
    }
};
