class Solution {
public:
    bool checkValidString(string s) {
        stack<int>st,left;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
               left.push(i);
            }else if(s[i]=='*'){
              st.push(i);
            }else{
               if(left.empty()&&st.empty())return false;
               if(!left.empty()){
                  left.pop();
               }else{
                st.pop();
               }
            }
        }
        while(!left.empty()&&!st.empty()){
            if(left.top()>st.top())return false;
            left.pop();
            st.pop();
        }
        return left.empty();
    }
};
