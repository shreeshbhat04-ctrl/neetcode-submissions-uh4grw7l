class Solution {
public:
int f(int i,int j,string& wor1,string& wor2){
    if(i<0)return j+1;
    if(j<0)return i+1;
    if(wor1[i]==wor2[j]){
        return f(i-1,j-1,wor1,wor2);
    }
    int delet=1+f(i-1,j-1,wor1,wor2);
    int insert=1+f(i,j-1,wor1,wor2);
    int upda=1+f(i-1,j,wor1,wor2);
    return min({delet,insert,upda});
}
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        return f(n,m,word1,word2);
    }
};
