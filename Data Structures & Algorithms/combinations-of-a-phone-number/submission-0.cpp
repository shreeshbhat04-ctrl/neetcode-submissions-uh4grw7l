class Solution {
public:
unordered_map<char,string>mp;
vector<string>res;
string path;
void backtrack(string digits,int i){
    if(i==digits.size()){
        res.push_back(path);
        return;
    }
    for(char c:mp[digits[i]]){
        path.push_back(c);
        backtrack(digits,i+1);
        path.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
        if(digits.empty())return {};
        mp={{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
        backtrack(digits,0);
        return res;
    }
};
