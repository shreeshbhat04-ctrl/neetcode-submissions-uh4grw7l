class Solution {
public:
    double myPow(double x, int n) {
         if(n==0)return 1.0;
             if(x==0)return 0.0;
                  if(x==1)return 1.0;     
                  if(x==-1&&n%2==0)return 1.0;
                  if(x==-1&&n%2!=0)return -1.0;
        
        long binfor=n;
        
        if(n<0){
            x=1/x;
            binfor=-binfor;
        }
        double ans=1.0;
        while(binfor>0){
            if(binfor%2==1){// to check the 1 in n 
                ans*=x;

            }x*=x;
            binfor/=2;

        }return ans;
    }
};
