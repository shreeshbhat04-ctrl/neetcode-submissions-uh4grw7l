class Solution {
public:
    bool isPalindrome(string s) {
        string ans="";
        for(char ch:s){
            if(isalnum(ch)){
                ans+=tolower(ch);
            }
        }
        return ans==string(ans.rbegin(),ans.rend());
    }
};
