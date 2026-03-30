class Solution {
public:
int sum(int n){
    int out=0;
    while(n!=0){
        out+=(n%10)*(n%10);
        n/=10;
    }
    return out;
}
    bool isHappy(int n) {
        int sl=n,fa=sum(n);
        while(sl!=fa){
            fa=sum(fa);
            fa=sum(fa);
            sl=sum(sl);
        }
        return fa==1;
    }
};
